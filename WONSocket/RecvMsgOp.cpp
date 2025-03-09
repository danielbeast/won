#include "RecvMsgOp.h"
#include "NetStats.h"
using namespace WONAPI;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
WONStatus RecvMsgOp::Start()
{
	mState = RECEIVING_LENGTH;
	mNumBytes = mSocket->GetLengthFieldSize();
	if(mNumBytes!=1 && mNumBytes!=2 && mNumBytes!=4)
		return WS_RecvMsg_InvalidLengthFieldSize;


	WONStatus aStatus = StartRecvBytes();
	if(aStatus!=WS_Success)
		return aStatus;
	else 
		return StartMsgRecv();
}
	
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
WONStatus RecvMsgOp::StartMsgRecv()
{
	mState = RECEIVING_MESSAGE;

	ByteBufferPtr aBytes = GetBytes();
	ReadBuffer aBuf(aBytes->data(),aBytes->length());
	DWORD aNewNumBytes = 0;
	switch(aBuf.length())
	{
		case 1: aNewNumBytes = (unsigned char)aBuf.ReadByte(); break;
		case 2: aNewNumBytes = (unsigned short)aBuf.ReadShort(); break;
		case 4: aNewNumBytes = (unsigned long)aBuf.ReadLong(); break;
	}

	if(aNewNumBytes<=aBuf.length() || aNewNumBytes>=1000000)
		return WS_RecvMsg_InvalidMessageLength;

	// extended 2 byte length (0xffff) -> receive 4 byte length for actual length (wastes 2 bytes but it's the easiest way to do it)
	if(aNewNumBytes==0xffff && aBuf.length()==2)
	{
		mNumBytes = 4;
		mState = RECEIVING_LENGTH;

		WONStatus aStatus = StartRecvBytes();
		if(aStatus!=WS_Success)
			return aStatus;
		else 
			return StartMsgRecv();
	}
	
	mState = RECEIVING_MESSAGE;
	mNumBytes = aNewNumBytes - aBuf.length();
	
	WONStatus aStatus = StartRecvBytes();
	if(aStatus==WS_Success)
		return ExtractMsg();
	else
		return aStatus;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
WONStatus RecvMsgOp::ExtractMsg()
{
	NetStats::IncrementMessagesReceived(1);

	mMsg = GetBytes();
	return mSocket->RunRecvMsgTransform(mMsg);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
WONStatus RecvMsgOp::Continue()
{
	WONStatus aStatus = ContinueRecvBytes();
	if(aStatus!=WS_Success)
		return aStatus;

	if(mState==RECEIVING_LENGTH)
		return StartMsgRecv();
	else 
		return ExtractMsg();
}
