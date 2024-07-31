#pragma once
#include "afxdialogex.h"
class CDetails : public CDialogEx
{
	DECLARE_DYNAMIC(CDetails)

public:
	CDetails(CWnd* pParent = nullptr);  
	virtual ~CDetails();
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Details };
#endif

public:
	virtual void DoDataExchange(CDataExchange* pDX); 
	CString m_CompanyName;
	CString m_CompanyAddress;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
