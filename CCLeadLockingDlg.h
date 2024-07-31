#pragma once
#include "afxdialogex.h"
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>
#include <afxwin.h>// for data binding into pdx and ddx
#include <sstream> // stringstream function
#include <iomanip>
#include <ctime>// cpp libraby for tm structure
#include <curl/curl.h>
#include <iostream>
#include <cppconn/resultset.h>
#include <vector>
#include "UserRoles.h"


class CCLeadLockingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCLeadLockingDlg)

public:
	CCLeadLockingDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCLeadLockingDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lead_Locking_System };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    DECLARE_MESSAGE_MAP()
public:
	// MEMBER VARIABLES DECLARATION
	CString m_ProspectName;
	CString m_Address;
	CString m_StreetAddress;
	CString m_AddressLine2;
	CString m_City;
	CString m_State;
	CString m_PhoneNumber;
	CString m_Email;
	CString m_FirstName;
	CString m_LastName;
	CString m_GSTNumber;
	CString m_Website;
	CComboBox m_SolidCAMOffice;
	CComboBox m_SolidCAMSalesperson;
	CComboBox m_Country;
	CComboBox m_Reseller;
	CString m_currentUsername;
	UserRole m_userRole;// enum variable to store the user role in setrole funtion
	CStatic* pStaticImage; 

	afx_msg void OnDtnDatetimechangeDatetimepicker(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEditProspectname();
	afx_msg void OnEnChangeEditAddress();
	afx_msg void OnEnChangeEditStreetAdress();
	afx_msg void OnEnChangeEditAddressLine2();
	afx_msg void OnEnChangeEditCity();
	afx_msg void OnEnChangeEditState();
	afx_msg void OnCbnSelchangeComboCountry();
	afx_msg void OnEnChangeEditPhoneNumber();
	afx_msg void OnEnChangeEditEmail();
	afx_msg void OnEnChangeEditFirstName();
	afx_msg void OnEnChangeEditLastName();
	afx_msg void OnCbnSelchangeComboSolidcamoffice();
	afx_msg std :: stringstream OnBnClickedUploadCard();
	afx_msg void OnEnChangeEditGstNumber();
	afx_msg void OnEnChangeEditwebsite();
	afx_msg void OnCbnSelchangeComboSalesperson();
	afx_msg void OnCbnSelchangeComboReseller();
	afx_msg void OnStnClickedStaticImageDisplay();
	afx_msg void OnBnClickedButtonValidateGst();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedExportCsv();
	virtual BOOL OnInitDialog();

	//FUNCTION DECLARATIONS
	void OnBnClickedUploadCardWrapper();
	bool IsUserName();
	void SetUserRole(UserRole role);
	bool IsValidPhoneNumber();
	bool ConnectToDatabase();
	bool IsValidEmail(const CString& email);
	bool IsAlphanumeric(const CString& str);
	bool InsertFormData(std::string &datetime, std::string s);
	bool IsEmailDuplicate(const CString& email);
	bool IsPhoneNumberValid(const CString& phoneNumber);
	bool ValidateGST(const CString& m_GSTNumber);
	bool IsGSTDuplicate(const CString& gst);
	std::stringstream SaveDateTime( );
	bool ExportDataToCSV(const std::string &filePath);
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);

	// MySQL connection variables
	sql::Driver* driver;
	std::unique_ptr<sql::PreparedStatement> pstmt;
	std::unique_ptr<sql::ResultSet> res;
	std::unique_ptr<sql::Connection> con;
};
