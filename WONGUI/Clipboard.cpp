
#include "Clipboard.h"

#ifndef WIN32_NOT_XBOX

using namespace WONAPI;

static GUIString mStr;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
GUIString Clipboard::Get()
{
	return mStr;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Clipboard::Set(const GUIString &theStr)
{
	mStr = theStr;
}

#endif