
// HelloDirect3D.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHelloDirect3DApp:
// See HelloDirect3D.cpp for the implementation of this class
//

class CHelloDirect3DApp : public CWinApp
{
public:
	CHelloDirect3DApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
};

extern CHelloDirect3DApp theApp;
