#include "ReadBuffer.h"
#include "LittleEndian.h"
using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

ReadBuffer::ReadBuffer()
{
	SetData(NULL,0);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ReadBuffer::ReadBuffer(const void *theData, unsigned long theDataLen) 
{
	SetData(theData,theDataLen);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ReadBuffer::SetData(const void *theData, unsigned long theDataLen)
{
	mData = (const char*)theData;
	mDataLen = theDataLen;

	mCurBit = 0;	
	mCurByte = 0;

	Rewind();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
const void* ReadBuffer::ReadBytes(unsigned long theAmount)
{
	if(length() - mReadPos < theAmount)
		throw ReadBufferException("Attempt to read past end of buffer.");

	const char *aBufPtr = data() + mReadPos;
	mReadPos+=theAmount;
	return aBufPtr;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool ReadBuffer::ReadBit()
{
	if(mCurBit==0)
	{
		mCurByte = ReadByte();
		mCurBit = 1;
	}

	bool aVal = mCurByte&mCurBit?true:false;
	mCurBit <<= 1;
	return aVal;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool ReadBuffer::ReadBool()
{
	return ReadByte()!=0;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
char ReadBuffer::ReadByte()
{
	return *(char*)ReadBytes(1);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
short ReadBuffer::ReadShort()
{
	return ShortFromLittleEndian(*(short*)ReadBytes(2));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
long ReadBuffer::ReadLong()
{
	return LongFromLittleEndian(*(long*)ReadBytes(4));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
__int64 ReadBuffer::ReadInt64()
{
	return Int64FromLittleEndian(*(__int64*)ReadBytes(8));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
unsigned long ReadBuffer::ReadLength(unsigned char theLengthFieldSize)
{
	switch(theLengthFieldSize)
	{
		case 1: return ReadByte(); break;
		case 2: return ReadShort(); break;
		case 4: return ReadLong(); break; 
		default: return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ReadBuffer::ReadRawString(std::string &theStr, unsigned long theNumChars)
{
	theStr.erase();
	theStr.append((char*)ReadBytes(theNumChars),theNumChars);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ReadBuffer::ReadString(std::string &theStr, unsigned char theLengthFieldSize)
{
	ReadRawString(theStr, ReadLength(theLengthFieldSize));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ReadBuffer::ReadRawWString(std::wstring &theWStr, unsigned long theNumChars)
{
	theWStr.erase();

	if(IsLittleEndian() && sizeof(wchar_t)==2)
		theWStr.append((wchar_t*)ReadBytes(theNumChars*2),theNumChars);
	else
	{
		for(int i=0; i<theNumChars; i++)
			theWStr+=(wchar_t)ReadShort();
	}

}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ReadBuffer::ReadWString(std::wstring &theWStr, unsigned char theLengthFieldSize)
{
	ReadRawWString(theWStr, ReadLength(theLengthFieldSize));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ByteBufferPtr ReadBuffer::ReadBuf(unsigned char theLengthFieldSize)
{
	unsigned long aLen = ReadLength(theLengthFieldSize);	
	return new ByteBuffer(ReadBytes(aLen),aLen);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ReadBuffer::Rewind()
{
	mReadPos = 0;
}

