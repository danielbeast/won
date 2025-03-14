#include "Spinner.h"

using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
Spinner::Spinner()
{
	mMinValue   = 0;
	mMaxValue   = 1000;

	mValue = 0;
	mValueIsValid = true;
	mWrapAround = false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::GetDesiredSize(int &width, int &height)
{
	width = 40;
	height = 22;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::AddedToParent()
{
	if(mUpArrow->GetParent()!=this)
		AddControls();

	Container::AddedToParent();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::AddControls()
{
	mUpArrow->SetButtonFlags(ButtonFlag_RepeatFire,true);
	mDownArrow->SetButtonFlags(ButtonFlag_RepeatFire,true);	

	AddChild(mInputBox);
	AddChild(mUpArrow);
	AddChild(mDownArrow);

	SetRange(mMinValue,mMaxValue,false);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetTextToValue()
{
	if(!mValueIsValid)
	{
		mInputBox->Clear();
		return;
	}

	char aBuf[32];
	sprintf(aBuf,"%d",mValue);
	mInputBox->SetText(aBuf,false);
	mInputBox->SetSel(-1,-1);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool Spinner::KeyDown(int theKey)
{
	if(theKey==KEYCODE_UP)
		IncrementValue();
	else if(theKey==KEYCODE_DOWN)
		DecrementValue();
	else
		return Container::KeyDown(theKey);

	return true;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::EnableHook(bool isEnabled)
{
	Container::EnableHook(isEnabled);

	mInputBox->Enable(isEnabled);
	mUpArrow->Enable(isEnabled);
	mDownArrow->Enable(isEnabled);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::IncrementValue(int theAmount)
{
	bool oldValid = mValueIsValid;
	int oldValue = mValue;

	mValue += theAmount;
	if(mWrapAround)
	{
		if(mValue > mMaxValue)
			mValue = mMinValue;
		else if(mValue < mMinValue)
			mValue = mMaxValue;
	}
	else
		ForceValueCompliance();
	
	SetTextToValue();

	CheckValueChanged(oldValid,oldValue);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::DecrementValue(int theAmount)
{
	IncrementValue(-theAmount);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetMax(int theMax) 
{ 
	SetRange(mMinValue, theMax);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetMin(int theMin) 
{ 
	SetRange(theMin, mMaxValue);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetRange(int theMin, int theMax, bool sendEvent) 
{ 
	bool oldValid = mValueIsValid;
	int oldValue = mValue;

	mMinValue = theMin;
	mMaxValue = theMax;
	ForceValueCompliance();
	SetTextToValue();

	int maxDigits = 0;
	int aNum = mMaxValue;
	do
	{
		maxDigits++;
		aNum/=10;
	} while(aNum>0);

	if(mMinValue<0)
		maxDigits++;

	mInputBox->SetMaxChars(maxDigits);

	if(sendEvent)
		CheckValueChanged(oldValid,oldValue);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetValue(int theValue, bool sendEvent)
{
	bool oldValid = mValueIsValid;
	int oldValue = mValue;

	if(theValue>=mMinValue && theValue<=mMaxValue)
	{
		mValue = theValue;
		mValueIsValid = true;
		SetTextToValue();
		if(sendEvent)
			CheckValueChanged(oldValid,oldValue);
	}


}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::ForceValueCompliance()
{
	if(mMaxValue < mMinValue)
	{
		mValueIsValid = false;
		return;
	}
	
	if(mValue > mMaxValue)
		mValue = mMaxValue;
	else if(mValue < mMinValue)
		mValue = mMinValue;

	mValueIsValid = true;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetWrapAround(bool wrap)
{
	mWrapAround = wrap;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::SetNoType(bool noType)
{
	mInputBox->SetComponentFlags(ComponentFlag_WantFocus,!noType);
	mInputBox->SetAllowSelection(!noType);
	if(noType && mFocusChild==mInputBox)
		ChildRequestFocus(NULL);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::CalcValueFromText()
{
	bool oldValid = mValueIsValid;
	int oldValue = mValue;

	if(mInputBox->GetText().empty())
		mValueIsValid = false;
	else
	{
		mValue = mInputBox->GetText().atoi();
		mValueIsValid = mValue>=mMinValue && mValue<=mMaxValue;
	}

	CheckValueChanged(oldValid, oldValue);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int Spinner::GetValue()
{
	return mValue;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool Spinner::IsValueValid()
{
	return mValueIsValid;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::CheckValueChanged(bool oldValid, int oldValue)
{
	bool changed = false;
	if(oldValid!=mValueIsValid)
		changed = true;
	else if(mValueIsValid && oldValue!=mValue)
		changed = true;

	if(changed)
		FireEvent(ComponentEvent_SpinnerValueChanged);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Spinner::HandleComponentEvent(ComponentEvent* pRawEvent)
{
	if (pRawEvent->mType == ComponentEvent_ButtonPressed)
	{
		int nAdj = 1;
		if ((GetKeyMod() & KEYMOD_SHIFT) != 0)
			nAdj = 10;
		if ((GetKeyMod() & KEYMOD_CTRL) != 0)
			nAdj = 100;

		if (pRawEvent->mComponent == mUpArrow)
		{
			IncrementValue(nAdj);
			return;
		}
		else if (pRawEvent->mComponent == mDownArrow)
		{
			DecrementValue(nAdj);
			return;
		}
	}
	else if (pRawEvent->mType == ComponentEvent_InputTextChanged)
	{
		CalcValueFromText();
		return;
	}

	Container::HandleComponentEvent(pRawEvent);
}
