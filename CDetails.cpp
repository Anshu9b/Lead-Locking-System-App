// CDetails.cpp : implementation file
#include "pch.h"
#include "User_Registration_System_2.h"
#include "afxdialogex.h"
#include "CDetails.h"

IMPLEMENT_DYNAMIC(CDetails, CDialogEx)

CDetails::CDetails(CWnd* pParent)
	: CDialogEx(IDD_Details, pParent) // declared here ?
	,m_CompanyName(_T(""))
	,m_CompanyAddress(_T(""))

{

}

CDetails::~CDetails()
{
}

void CDetails::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_COMPANY_NAME, m_CompanyName);
	DDX_Text(pDX, IDC_COMPANY_ADDRESS, m_CompanyAddress);
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CDetails, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDetails::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDetails::OnBnClickedCancel)
END_MESSAGE_MAP()

void CDetails::OnBnClickedOk()
{
	
	UpdateData(TRUE);
	CDialogEx::OnOK();
}

void CDetails::OnBnClickedCancel()
{
	
	CDialogEx::OnCancel();
}
