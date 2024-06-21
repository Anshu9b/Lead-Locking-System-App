// CLoginDlg.cpp : implementation file
//

#include "pch.h"
#include "User_Registration_System.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"


// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LOGIN_DLG, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_EN_CHANGE(IDC_USERNAME, &CLoginDlg::OnEnChangeUsername)
	ON_EN_CHANGE(IDC_PASSWORD, &CLoginDlg::OnEnChangePassword)
	ON_BN_CLICKED(IDC_SUBMIT, &CLoginDlg::OnBnClickedSubmit)
	ON_STN_CLICKED(IDC_USER_NAME, &CLoginDlg::OnStnClickedUserName)
	ON_BN_CLICKED(IDC_Cancel, &CLoginDlg::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_USER_PASSWORD, &CLoginDlg::OnStnClickedUserPassword)
END_MESSAGE_MAP()


// CLoginDlg message handlers


void CLoginDlg::OnEnChangeUsername()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLoginDlg::OnEnChangePassword()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLoginDlg::OnBnClickedSubmit()
{
	// TODO: Add your control notification handler code here
}


void CLoginDlg::OnStnClickedUserName()
{
	// TODO: Add your control notification handler code here
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
}


void CLoginDlg::OnStnClickedUserPassword()
{
	// TODO: Add your control notification handler code here
}
