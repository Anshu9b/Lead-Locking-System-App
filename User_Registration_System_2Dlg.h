
// User_Registration_System_2Dlg.h : header file
#pragma once
#
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "CCreateAccountDlg.h" 
#include "UserRoles.h"

// CUserRegistrationSystem2Dlg dialog
class CUserRegistrationSystem2Dlg : public CDialogEx
{
	// Construction
public:
	//CCreateAccountDlg createAccountDlg;
	CUserRegistrationSystem2Dlg(CWnd* pParent = nullptr);	// standard constructor

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_REGISTRATION_SYSTEM_2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	DECLARE_MESSAGE_MAP();
// Implementation
public:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	// database connection 
	bool ConnectToDatabase();
	UserRole DoesUserExist();
	bool IsAlphanumeric(const CString& str);
	bool IsValidEmail_username(const CString& str);
	//bool CreateAccount();
	// MySQL connection variables
	sql::Driver* driver;
	std::unique_ptr<sql::Connection> con;
	std::unique_ptr<sql::PreparedStatement> pstmt;
	std::unique_ptr<sql::ResultSet> res;
	CString Username;
	CString Password;
//	CString newUsername; // Add this line
//	CString newPassword;
	// DECLARE_MESSAGE_MAP()
	afx_msg void OnEnChangeEditUsername();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnBnClickedCreateAccount();
	afx_msg void OnBnClickedSubmit();
};
