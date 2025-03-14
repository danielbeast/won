#include "MSDisplayContext.h"
#include "MSNativeImage.h"
#include "MSRawImage.h"

using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
NativeImagePtr MSDisplayContext::CreateImage(int theWidth, int theHeight)
{
	return new MSNativeImage(this,theWidth,theHeight);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
RawImage1Ptr MSDisplayContext::CreateRawImage1(int theWidth, int theHeight)
{
	return new MSRawImage1(theWidth,theHeight);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
RawImage8Ptr MSDisplayContext::CreateRawImage8(int theWidth, int theHeight, Palette *thePalette)
{
	return new MSRawImage8(theWidth,theHeight,thePalette);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
RawImage32Ptr MSDisplayContext::CreateRawImage32(int theWidth, int theHeight)
{
	return new MSRawImage32(theWidth,theHeight);
}
