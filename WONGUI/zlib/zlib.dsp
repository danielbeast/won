# Microsoft Developer Studio Project File - Name="zlib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104
# TARGTYPE "Xbox Static Library" 0x0b04

CFG=zlib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "zlib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "zlib.mak" CFG="zlib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "zlib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "zlib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "zlib - Win32 Dinkumware Release" (based on "Win32 (x86) Static Library")
!MESSAGE "zlib - Xbox Debug" (based on "Xbox Static Library")
!MESSAGE "zlib - Xbox Release" (based on "Xbox Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Titan/WONAPI/WONLobby/EmpireLobby2", KGMCAAAA"
# PROP Scc_LocalPath "..\..\wonlobby\empirelobby2"

!IF  "$(CFG)" == "zlib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\Lib\zlib_r.lib"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\Lib\zlib_d.lib"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "zlib___Win32_Dinkumware_Release"
# PROP BASE Intermediate_Dir "zlib___Win32_Dinkumware_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "DinkumwareRelease"
# PROP Intermediate_Dir "DinkumwareRelease"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\Lib\zlib_r.lib"
# ADD LIB32 /nologo /out:"..\..\Lib\zlib_dink_r.lib"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "zlib___Xbox_Debug"
# PROP BASE Intermediate_Dir "zlib___Xbox_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Xbox_Debug"
# PROP Intermediate_Dir "Xbox_Debug"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_XBOX" /D "_DEBUG" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_XBOX" /D "_DEBUG" /YX /FD /GZ /Ztmp /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\Lib\zlib_d.lib"
# ADD LIB32 /nologo /out:"Xbox_Debug\zlib_d.lib"

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "zlib___Xbox_Release"
# PROP BASE Intermediate_Dir "zlib___Xbox_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Xbox_Release"
# PROP Intermediate_Dir "Xbox_Release"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GR /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /D "WIN32" /D "_XBOX" /D "NDEBUG" /YX /FD /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\Lib\zlib_r.lib"
# ADD LIB32 /nologo /out:"Xbox_Release\zlib_r.lib"

!ENDIF 

# Begin Target

# Name "zlib - Win32 Release"
# Name "zlib - Win32 Debug"
# Name "zlib - Win32 Dinkumware Release"
# Name "zlib - Xbox Debug"
# Name "zlib - Xbox Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\adler32.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\compress.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\crc32.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\deflate.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\gzio.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\infblock.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\infcodes.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inffast.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inflate.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\inftrees.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\infutil.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\trees.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uncompr.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\zutil.c

!IF  "$(CFG)" == "zlib - Win32 Release"

!ELSEIF  "$(CFG)" == "zlib - Win32 Debug"

!ELSEIF  "$(CFG)" == "zlib - Win32 Dinkumware Release"

!ELSEIF  "$(CFG)" == "zlib - Xbox Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "zlib - Xbox Release"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\deflate.h
# End Source File
# Begin Source File

SOURCE=.\infblock.h
# End Source File
# Begin Source File

SOURCE=.\infcodes.h
# End Source File
# Begin Source File

SOURCE=.\inffast.h
# End Source File
# Begin Source File

SOURCE=.\inffixed.h
# End Source File
# Begin Source File

SOURCE=.\inftrees.h
# End Source File
# Begin Source File

SOURCE=.\infutil.h
# End Source File
# Begin Source File

SOURCE=.\trees.h
# End Source File
# Begin Source File

SOURCE=.\zconf.h
# End Source File
# Begin Source File

SOURCE=.\zlib.h
# End Source File
# Begin Source File

SOURCE=.\zutil.h
# End Source File
# End Group
# End Target
# End Project
