#pragma once
#include "afxdialogex.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

// CCreateAccountDlg dialog

class CCreateAccountDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateAccountDlg)

public:
	CCreateAccountDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCreateAccountDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CREATE_ACCOUNT };
#endif

public:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString Username;
	CString Password;
	CString name;
	bool CreateAccount();
	bool ConnectToDatabase();
	bool IsAlphanumeric(const CString& str);
	bool IsValidEmail(const CString& str);
	bool IsEmailDuplicate(const CString& user_name);
	// MySQL connection variables
	sql::Driver* driver;
	std::unique_ptr<sql::Connection> con;
	std::unique_ptr<sql::PreparedStatement> pstmt;
	std::unique_ptr<sql::ResultSet> res;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnEnChangeEditUsername();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeNameField();
	afx_msg void OnEnChangeEditNameField();
};
