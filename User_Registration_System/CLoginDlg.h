#pragma once
#include "afxdialogex.h"


// CLoginDlg dialog

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CLoginDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Username;
	CEdit m_Password;
	afx_msg void OnEnChangeUsername();
	afx_msg void OnEnChangePassword();
	afx_msg void OnBnClickedSubmit();
	afx_msg void OnStnClickedUserName();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedUserPassword();
};
