// CCreateAccountDlg.cpp : implementation file
#include "pch.h"
#include "User_Registration_System_2.h"
#include "User_Registration_System_2Dlg.h"
#include "afxdialogex.h" // autogenerated file
#include "CCreateAccountDlg.h"
#include "CCLeadLockingDlg.h"
#include "afxwin.h"// for control values binding purpose- DDX 
#include <regex>

IMPLEMENT_DYNAMIC(CCreateAccountDlg, CDialogEx)

CCreateAccountDlg::CCreateAccountDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CREATE_ACCOUNT, pParent)
{

}

CCreateAccountDlg::~CCreateAccountDlg()
{
}

void CCreateAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, Username);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, Password);
	DDX_Text(pDX, IDC_EDIT_NAME_FIELD , name);

}

BEGIN_MESSAGE_MAP(CCreateAccountDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_USERNAME, &CCreateAccountDlg::OnEnChangeEditUsername)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CCreateAccountDlg::OnEnChangeEditPassword)
	ON_BN_CLICKED(IDC_OK, &CCreateAccountDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCreateAccountDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_NAME_FIELD, &CCreateAccountDlg::OnEnChangeEditNameField)
END_MESSAGE_MAP()

void CCreateAccountDlg::OnEnChangeEditUsername()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItem(IDC_OK)->EnableWindow(IsAlphanumeric(Password));

}


void CCreateAccountDlg::OnEnChangeEditPassword()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItem(IDC_OK)->EnableWindow((IsValidEmail(Username) && IsEmailDuplicate(Username)));

}

void CCreateAccountDlg::OnBnClickedOk()
{
	UpdateData(TRUE); 
	if (Username.IsEmpty() || Password.IsEmpty() || name.IsEmpty() || IsEmailDuplicate(Username))
	{
		AfxMessageBox(_T("Either any field is empty or Usermail is duplicate"));
		return;
	}

	if (CreateAccount())
	{
		AfxMessageBox(_T("Account created successfully"));
		CCLeadLockingDlg leadLockingDlg;
		leadLockingDlg.DoModal();
	}
	else {
		AfxMessageBox(_T("Account not created successfully"));
	}
	EndDialog(IDC_OK); 
}


void CCreateAccountDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDCANCEL);;
}

bool CCreateAccountDlg::CreateAccount()
{
	if (!ConnectToDatabase())
		return false;

	try {
		std::unique_ptr<sql::PreparedStatement> pstmt;

		pstmt.reset(con->prepareStatement("INSERT INTO users (`username`, `password`, `name_field`) VALUES (?, ?, ?)"));

		CStringA usernameA(Username);
		CStringA passwordA(Password);
		CStringA nameA(name);

		pstmt->setString(1, std::string(usernameA));
		pstmt->setString(2, std::string(passwordA));
		pstmt->setString(3, std::string(nameA));

		pstmt->executeUpdate();
		return true;
	}
	catch (sql::SQLException& e) {
		CString errorMessage;
		errorMessage.Format(_T("Account creation failed: %S"), e.what()); // %S for wide-character CString
		AfxMessageBox(errorMessage);
		return false;
	}
}
bool CCreateAccountDlg::ConnectToDatabase()
{

	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		con = std::unique_ptr<sql::Connection>(driver->connect("tcp://127.0.0.1:3306", "root", "Missspacegirl@09"));
		con->setSchema("user_register");
		return true;
	}
	catch (sql::SQLException& e) {
		CString errorMessage;
		errorMessage.Format(_T("Database connection failed: %S"), e.what());
		AfxMessageBox(errorMessage);
		return false;
	}
}
	//Why used const ?
bool CCreateAccountDlg::IsAlphanumeric(const CString& str)
{
	for (int i = 0; i < str.GetLength(); ++i)
	{
		if (!isalnum(str[i]))
		{
			return false;
		}
	}
	return true;
}

bool CCreateAccountDlg::IsValidEmail(const CString& str)
{
	const std::regex pattern(
		R"((\w+)(\.{1}\w+)*@(\w+)(\.(\w+))+)"
	);
	std::string emailStr = CT2CA(str);
	return std::regex_match(emailStr, pattern);
}

void CCreateAccountDlg::OnEnChangeEditNameField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItem(IDC_OK)->EnableWindow(IsAlphanumeric(name));
	
}

bool CCreateAccountDlg::IsEmailDuplicate(const CString& user_name)
{
	try {

		if (!ConnectToDatabase())
			return false;
		std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT COUNT(*) FROM users WHERE username = ?"));
		pstmt->setString(1, std::string(CT2CA(user_name)));
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		if (res->next()) {
			return res->getInt(1) > 0;
		}
	}
	catch (sql::SQLException& e) {
		AfxMessageBox(_T("Error checking usermail: ") + CString(e.what()));
	}
	return false;
}