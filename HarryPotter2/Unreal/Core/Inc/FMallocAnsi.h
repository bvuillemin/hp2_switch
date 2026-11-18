/*=============================================================================
	FMallocAnsi.h: ANSI memory allocator.
	Copyright 1997-1999 Epic Games, Inc. All Rights Reserved.

	Revision history:
		* Created by Tim Sweeney
=============================================================================*/

#include "UnStat.h"

//
// ANSI C memory allocator.
//
class FMallocAnsi : public FMalloc
{
public:
	// FMalloc interface.
	void* Malloc( DWORD Size, const TCHAR* Tag )
	{
#if !defined(__SWITCH__)
		guard(FMallocAnsi::Malloc);
		Clock(GStat.MemTime);
#endif
		checkSlow(Size>0);
		void* Ptr = malloc( Size );
		checkSlow(Ptr);
		return Ptr;
#if !defined(__SWITCH__)
		unguard;
#endif
	}
	void* Realloc( void* Ptr, DWORD NewSize, const TCHAR* Tag )
	{
#if !defined(__SWITCH__)
		guard(FMallocAnsi::Realloc);
		Clock(GStat.MemTime);
#endif
		checkSlow(NewSize>=0);
		void* Result;
		if( Ptr && NewSize )
		{
			Result = realloc( Ptr, NewSize );
		}
		else if( NewSize )
		{
			Result = malloc( NewSize );
		}
		else
		{
			if( Ptr )
				free( Ptr );
			Result = NULL;
		}
		return Result;
#if !defined(__SWITCH__)
		unguardf(( TEXT("%p %i %s"), Ptr, NewSize, Tag ));
#endif
	}
	void Free( void* Ptr )
	{
#if !defined(__SWITCH__)
		guard(FMallocAnsi::Free);
		Clock(GStat.MemTime);
#endif
		free( Ptr );
#if !defined(__SWITCH__)
		unguard;
#endif
	}
	void DumpAllocs()
	{
		guard(FMallocAnsi::DumpAllocs);
		debugf( NAME_Exit, TEXT("Allocation checking disabled") );
		unguard;
	}
	void HeapCheck()
	{
		guard(FMallocAnsi::HeapCheck);
#if 0 && _MSC_VER
		INT Result = _heapchk();
		check(Result!=_HEAPBADBEGIN);
		check(Result!=_HEAPBADNODE);
		check(Result!=_HEAPBADPTR);
		check(Result!=_HEAPEMPTY);
		check(Result==_HEAPOK);
#endif
		unguard;
	}
	void Init()
	{
		guard(FMallocAnsi::Init);
		unguard;
	}
	void Exit()
	{
		guard(FMallocAnsi::Exit);
		unguard;
	}
};

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/
