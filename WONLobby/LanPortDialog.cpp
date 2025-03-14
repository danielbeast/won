#include "LanPortDialog.h"

#include "WONGUI/GUIConfig.h"
#include "WONGUI/InputBox.h"
#include "WONGUI/Label.h"


using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
LanPortDialog::LanPortDialog()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
LanPortDialog::~LanPortDialog()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanPortDialog::InitComponent(ComponentInit &theInit)
{
	Dialog::InitComponent(theInit);
	if(theInit.mType==ComponentInitType_ComponentConfig)
	{
		ComponentConfigInit &anInit = (ComponentConfigInit&)theInit;
		ComponentConfig *aConfig = anInit.mConfig;

		WONComponentConfig_Get(aConfig,mPortInput,"PortInput");
		mPortInput->SetTransform(InputBox::NumericFilter);

		WONComponentConfig_Get(aConfig,mGamePortLabel,"GamePortLabel");
		WONComponentConfig_Get(aConfig,mOKButton,"OKButton");
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanPortDialog::Reset()
{
	mPortInput->RequestFocus();
	UpdateOKButton();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanPortDialog::SetPort(unsigned short thePort)
{
	char aBuffer[10];
	sprintf(aBuffer,"%d",thePort);
	mPortInput->SetText(aBuffer);
	mPortInput->SetSel();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanPortDialog::SetGamePort(unsigned short thePort)
{
	mGamePort = thePort;
	char aBuffer[10];
	sprintf(aBuffer,"%d",thePort);
	mGamePortLabel->SetText(aBuffer);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
unsigned short LanPortDialog::GetPort(void)
{
	unsigned short aPort = mPortInput->GetText().atoi();
	return aPort;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanPortDialog::UpdateOKButton()
{
	int aPort = mPortInput->GetText().atoi();

	if ((aPort!=mGamePort) && (aPort>4999) && (aPort<65536))
	{
		// Valid range - Enable the ok button if disabled
		if (mOKButton->Disabled())
			mOKButton->Enable(true);
	}
	else
	{
		// Invalid range - Disable the ok button if enabled
		if (!mOKButton->Disabled())
			mOKButton->Enable(false);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanPortDialog::HandleComponentEvent(ComponentEvent *theEvent)
{
	if (theEvent->mType==ComponentEvent_InputTextChanged && theEvent->mComponent == mPortInput)
		UpdateOKButton();
	else
		Dialog::HandleComponentEvent(theEvent);
}

