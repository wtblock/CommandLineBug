/////////////////////////////////////////////////////////////////////////////
// Copyright © 2023 by W. T. Block, all rights reserved
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "CommandLineBug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// The one and only application object
CWinApp theApp;

using namespace std;

// a simple command line application to illustrate a bug in command line
// processing
int _tmain( int argc, TCHAR* argv[], TCHAR* envp[] )
{
	HMODULE hModule = ::GetModuleHandle( NULL );
	if ( hModule == NULL )
	{
		_tprintf( _T( "Fatal Error: GetModuleHandle failed\n" ) );
		return 1;
	}

	// initialize MFC and error on failure
	if ( !AfxWinInit( hModule, NULL, ::GetCommandLine(), 0 ) )
	{
		_tprintf( _T( "Fatal Error: MFC initialization failed\n " ) );
		return 2;
	}

	// write to console
	CStdioFile fOut( stdout );
	CString csMessage;

	// display the number of arguments
	fOut.WriteString( _T( ".\n" ) );
	csMessage.Format( _T( "The number of parameters are %d\n.\n" ), argc );
	fOut.WriteString( csMessage );

	// display the arguments
	for ( int i = 0; i < argc; i++ )
	{
		csMessage.Format( _T( "Parameter %d is %s\n.\n" ), i, argv[ i ] );
		fOut.WriteString( csMessage );
	}

	return 0;
}
