// Exercise4.h : main header file for the Exercise4 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise4App
// See Exercise4.cpp for the implementation of this class
//

class CExercise4App : public CWinApp
{
public:
	CExercise4App();

// Overrides
public:
	virtual BOOL InitInstance();

	static void AddLine();

	DECLARE_MESSAGE_MAP()
};
