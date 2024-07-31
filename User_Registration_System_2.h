
// User_Registration_System_2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CUserRegistrationSystem2App:
// See User_Registration_System_2.cpp for the implementation of this class
//

class CUserRegistrationSystem2App : public CWinApp
{
public:
	CUserRegistrationSystem2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CUserRegistrationSystem2App theApp;
