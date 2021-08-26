
// CarsDB.h : main header file for the CarsDB application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCarsDBApp:
// See CarsDB.cpp for the implementation of this class
//

class CCarsDBApp : public CWinApp
{
public:
	CCarsDBApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCarsDBApp theApp;
