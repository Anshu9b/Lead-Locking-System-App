#pragma once
#include "afxdialogex.h"


// IDD_LOGIN_DLG dialog

class IDD_LOGIN_DLG : public CDialog
{
	DECLARE_DYNAMIC(IDD_LOGIN_DLG)

public:
	IDD_LOGIN_DLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~IDD_LOGIN_DLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IDD_LOGIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
