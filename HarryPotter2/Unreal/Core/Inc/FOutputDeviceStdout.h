/*=============================================================================
	FOutputDeviceStdout.h: ANSI stdout output device.
	Copyright 1997-1999 Epic Games, Inc. All Rights Reserved.

	Revision history:
		* Created by Tim Sweeney
=============================================================================*/

#if defined(__SWITCH__)
#include <stdio.h>
extern "C" void SwitchLog( const char* Fmt, ... );
#endif

//
// ANSI stdout output device.
//
class FOutputDeviceStdout : public FOutputDevice
{
public:
	void Serialize( const TCHAR* V, EName Event )
	{
#if defined(__SWITCH__)
		char Buffer[2048];
		if( appToUtf8InPlace( Buffer, V, ARRAY_COUNT(Buffer) ) )
			SwitchLog( "%s\n", Buffer );
		else
			SwitchLog( "%ls\n", V );
#endif
		// TCHAR is wchar_t on this platform: "%s" would print only the
		// first character and stop at its zero byte. "%ls" converts the
		// whole wide string to multibyte output.
		fprintf( stdout, "%ls\n", V );
		fflush( stdout );
	}
};

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/
