#include "LobbyFriend.h"
#include "LobbyClient.h"

using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
LobbyFriend::LobbyFriend(const GUIString& theName, unsigned long theWONUserId) : 
	mName(theName) 
{ 
	mWONUserId = theWONUserId;
	mFlags = 0;
	mOpsOutstanding = 0;
	mLastLocateTime = 0;
	mReportLocationRoomSpec = 0;

	mAnonymous = false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyFriend::NotifyOnServer(const IPAddr &theAddr, const GUIString &theName, int theFlags)
{
	mServerIP = theAddr;
	mServerName = theName;
	mFlags = theFlags;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyFriend::NotifyLeftServer()
{
	mServerIP = IPAddr();
	mServerName.erase();
	mFlags = 0;
	mLastLocateTime = 0; // so you can search for the friend immediately
	mAnonymous = false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyFriend::UpdateFlagsFromClient(LobbyClient *theClient)
{
	int aFlags = 0;
	if(theClient->InChat())
		aFlags |= FriendFlag_InChat;
	if(theClient->InGame())
		aFlags |= FriendFlag_InGame;
	
	mFlags = aFlags;
	mAnonymous = theClient->IsAnonymous();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyFriend::SetAnonymous(bool isAnonymous)
{
	mAnonymous = isAnonymous;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyFriend::StartSearch(int theReportLocationRoomSpec)
{
	mReportLocationRoomSpec = theReportLocationRoomSpec;
	mFlags = FriendFlag_Searching;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LobbyFriend::EndSearch(time_t theTime)
{
	mFlags &= ~FriendFlag_Searching;
	mLastLocateTime = theTime;
}

