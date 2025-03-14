#include "RehupOp.h"

using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
RehupOp::RehupOp(ServerContext* theServerContextP) : ServerRequestOp(theServerContextP)
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
RehupOp::RehupOp(const IPAddr &theAddr) : ServerRequestOp(theAddr)
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
WONStatus RehupOp::GetNextRequest()
{
	WriteBuffer aMsg(GetLengthFieldSize());
	aMsg.AppendLong(1);					// CommonService
	aMsg.AppendLong(4);					// Rehup

	mRequest = aMsg.ToByteBuffer();
	return WS_ServerReq_Recv;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
WONStatus RehupOp::CheckResponse()
{
	ReadBuffer aMsg(mResponse->data(),mResponse->length());
	unsigned char aHeaderType = aMsg.ReadByte();
	unsigned short aServiceType = aMsg.ReadShort();
	unsigned short aMessageType = aMsg.ReadShort();

	if(aHeaderType!=5 || aServiceType!=1 || aMessageType!=15)
		return InvalidReplyHeader();

	short aStatus = aMsg.ReadShort();
	return (WONStatus)aStatus;
}
