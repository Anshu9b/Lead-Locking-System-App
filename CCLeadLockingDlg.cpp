// CCLeadLockingDlg.cpp : implementation file

#include "pch.h"
#include "User_Registration_System_2.h"
#include "afxdialogex.h"// auto generated file 
#include "CCLeadLockingDlg.h"
#include "afxwin.h" // for CString
#include <regex>   // For std::regex and std::regex_match
#include <atlstr.h> // string manipulation altering string 
#include <atlimage.h> // For CImage
#include <afxdlgs.h> // For CFileDialog
#include <iostream>         // std::stringstream
#include <sstream>          // std::stringstream
#include <curl/curl.h>      //for http request -> Client URL, or just curl, is a command-line tool for transferring data using various network protocols. It is commonly used by developers to test various applications build on top of HTTP.
#include <single_include/nlohmann/json.hpp> // for json parsing into c++ parsing 
#include <iomanip>// for manipulating the format of input output operstions , 
#include <ctime>// for gmt and ist conversion 
#include <iostream>// for input output operation manipulation of of stream here
#include <fstream>//  for std :: ofstream operation-> it part of this c++ library 
#include <string>  // Include for std::string
#include "UserRoles.h"
#include "CDetails.h"


// CCLeadLockingDlg dialog

IMPLEMENT_DYNAMIC(CCLeadLockingDlg, CDialogEx)

CCLeadLockingDlg::CCLeadLockingDlg(CWnd* pParent )
	: CDialogEx(IDD_Lead_Locking_System, pParent)
{

}

CCLeadLockingDlg::~CCLeadLockingDlg()
{
}

void CCLeadLockingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PROSPECTNAME, m_ProspectName);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDX_Text(pDX, IDC_EDIT_STREET_ADRESS, m_StreetAddress);
	DDX_Text(pDX, IDC_EDIT_ADDRESS_LINE_2, m_AddressLine2);
	DDX_Text(pDX, IDC_EDIT_CITY, m_City);
	DDX_Text(pDX, IDC_EDIT_STATE, m_State);
	DDX_Text(pDX, IDC_EDIT_PHONE_NUMBER, m_PhoneNumber);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_Email);
	//DDX_Text(pDX, IDC_EDIT_CONTACT_NAME, m_ContactName);
	DDX_Text(pDX, IDC_EDIT_LAST_NAME, m_LastName);
	DDX_Text(pDX, IDC_EDIT_FIRST_NAME, m_FirstName);
	DDX_Text(pDX, IDC_EDIT_GST_NUMBER, m_GSTNumber);
	DDX_Text(pDX, IDC_EDIT_website, m_Website);
	DDX_Control(pDX, IDC_COMBO_COUNTRY, m_Country);
	DDX_Control(pDX, IDC_COMBO_SOLIDCAMOFFICE, m_SolidCAMOffice);
	DDX_Control(pDX, IDC_COMBO_SALESPERSON, m_SolidCAMSalesperson);
	DDX_Control(pDX, IDC_COMBO_RESELLER, m_Reseller);

}


BEGIN_MESSAGE_MAP(CCLeadLockingDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_PROSPECTNAME, &CCLeadLockingDlg::OnEnChangeEditProspectname)
	ON_EN_CHANGE(IDC_EDIT_ADDRESS, &CCLeadLockingDlg::OnEnChangeEditAddress)
	ON_EN_CHANGE(IDC_EDIT_STREET_ADRESS, &CCLeadLockingDlg::OnEnChangeEditStreetAdress)
	ON_EN_CHANGE(IDC_EDIT_ADDRESS_LINE_2, &CCLeadLockingDlg::OnEnChangeEditAddressLine2)
	ON_EN_CHANGE(IDC_EDIT_CITY, &CCLeadLockingDlg::OnEnChangeEditCity)
	ON_EN_CHANGE(IDC_EDIT_STATE, &CCLeadLockingDlg::OnEnChangeEditState)
	ON_CBN_SELCHANGE(IDC_COMBO_COUNTRY, &CCLeadLockingDlg::OnCbnSelchangeComboCountry)
	ON_EN_CHANGE(IDC_EDIT_PHONE_NUMBER, &CCLeadLockingDlg::OnEnChangeEditPhoneNumber)
	ON_EN_CHANGE(IDC_EDIT_EMAIL, &CCLeadLockingDlg::OnEnChangeEditEmail)
	ON_EN_CHANGE(IDC_EDIT_FIRST_NAME, &CCLeadLockingDlg::OnEnChangeEditFirstName)
	ON_EN_CHANGE(IDC_EDIT_LAST_NAME, &CCLeadLockingDlg::OnEnChangeEditLastName)
	ON_CBN_SELCHANGE(IDC_COMBO_SOLIDCAMOFFICE, &CCLeadLockingDlg::OnCbnSelchangeComboSolidcamoffice)
	ON_BN_CLICKED(IDC_UPLOAD_CARD, &CCLeadLockingDlg::OnBnClickedUploadCardWrapper)
	ON_EN_CHANGE(IDC_EDIT_GST_NUMBER, &CCLeadLockingDlg::OnEnChangeEditGstNumber)
	ON_EN_CHANGE(IDC_EDIT_website, &CCLeadLockingDlg::OnEnChangeEditwebsite)
	ON_CBN_SELCHANGE(IDC_COMBO_SALESPERSON, &CCLeadLockingDlg::OnCbnSelchangeComboSalesperson)
	ON_CBN_SELCHANGE(IDC_COMBO_RESELLER, &CCLeadLockingDlg::OnCbnSelchangeComboReseller)
	ON_BN_CLICKED(IDOK, &CCLeadLockingDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_VALIDATE_GST, &CCLeadLockingDlg::OnBnClickedButtonValidateGst)
	ON_BN_CLICKED(IDC_EXPORT_CSV, &CCLeadLockingDlg::OnBnClickedExportCsv)
END_MESSAGE_MAP()

    // write function to handle the contents of api response 
size_t CCLeadLockingDlg::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
   //contents: Pointer to the received data.//size: Size of each data element(typically 1).
   //nmemb : Number of data elements // userp : Pointer to user - defined data(specified with CURLOPT_WRITEDATA).
	size_t newLength = size * nmemb;
	try {
		s->append((char*)contents, newLength);
	}
	catch (std::bad_alloc& e){  // exception class defined in new header file
		return 0;               // when new file fails to allocate memory 
	}
	return newLength;
}

BOOL CCLeadLockingDlg::OnInitDialog()
{
	BOOL bResult = CDialogEx::OnInitDialog();
	pStaticImage = (CStatic*)GetDlgItem(IDC_STATIC_IMAGE_DISPLAY);
	CComboBox* m_SolidCAMOffice = (CComboBox*)GetDlgItem(IDC_COMBO_SOLIDCAMOFFICE);
	m_SolidCAMOffice->AddString(_T("BANGALORE"));
	m_SolidCAMOffice->AddString(_T("PUNE"));
	m_SolidCAMOffice->AddString(_T("NEW DELHI"));
	m_SolidCAMOffice->AddString(_T("LUDHIANA"));
	m_SolidCAMOffice->AddString(_T("AHMEDABAD"));
	m_SolidCAMOffice->AddString(_T("CHENNAI"));
	m_SolidCAMOffice->AddString(_T("COIMBATORE"));
	CComboBox* m_Country = (CComboBox*)GetDlgItem(IDC_COMBO_COUNTRY);
	m_Country->AddString(_T("Aland Islands"));
	m_Country->AddString(_T("Afghanistan"));
	m_Country->AddString(_T("Akrotiri"));
	m_Country->AddString(_T("Albania"));
	m_Country->AddString(_T("Algeria"));
	m_Country->AddString(_T("American Samoa"));
	m_Country->AddString(_T("Andorra"));
	m_Country->AddString(_T("Angola"));
	m_Country->AddString(_T("Anguilla"));
	m_Country->AddString(_T("Antarctica"));
	m_Country->AddString(_T("Antigua and Barbuda"));
	m_Country->AddString(_T("Argentina"));
	m_Country->AddString(_T("Armenia"));
	m_Country->AddString(_T("Aruba"));
	m_Country->AddString(_T("Australia"));
	m_Country->AddString(_T("Austria"));
	m_Country->AddString(_T("Azerbaijan"));
	m_Country->AddString(_T("The Bahamas"));
	m_Country->AddString(_T("Bahrain"));
	m_Country->AddString(_T("Bangladesh"));
	m_Country->AddString(_T("Barbados"));
	m_Country->AddString(_T("Belarus"));
	m_Country->AddString(_T("Belgium"));
	m_Country->AddString(_T("Belize"));
	m_Country->AddString(_T("Benin"));
	m_Country->AddString(_T("Bhutan"));
	m_Country->AddString(_T("Bolivia"));
	m_Country->AddString(_T("Bosnia and Herzegovina"));
	m_Country->AddString(_T("Botswana"));
	m_Country->AddString(_T("Brazil"));
	m_Country->AddString(_T("Brunei"));
	m_Country->AddString(_T("Bulgaria"));
	m_Country->AddString(_T("Burkina Faso"));
	m_Country->AddString(_T("Burma"));
	m_Country->AddString(_T("Cambodia"));
	m_Country->AddString(_T("Cameroon"));
	m_Country->AddString(_T("Canada"));
	m_Country->AddString(_T("Cabo Verde"));
	m_Country->AddString(_T("Central African Republic"));
	m_Country->AddString(_T("Chad"));
	m_Country->AddString(_T("Chile"));
	m_Country->AddString(_T("China"));
	m_Country->AddString(_T("Colombia"));
	m_Country->AddString(_T("Comoros"));
	m_Country->AddString(_T("Democratic Republic of the Congo"));
	m_Country->AddString(_T("Republic of the Congo"));
	m_Country->AddString(_T("Costa Rica"));
	m_Country->AddString(_T("Cote d Ivoire"));
	m_Country->AddString(_T("Croatia"));
	m_Country->AddString(_T("Cuba"));
	m_Country->AddString(_T("Curacao"));
	m_Country->AddString(_T("Cyprus"));
	m_Country->AddString(_T("Czechia"));
	m_Country->AddString(_T("Denmark"));
	m_Country->AddString(_T("Djibouti"));
	m_Country->AddString(_T("Dominica"));
	m_Country->AddString(_T("Dominican Republic"));
	m_Country->AddString(_T("East Timor"));
	m_Country->AddString(_T("Ecuador"));
	m_Country->AddString(_T("Egypt"));
	m_Country->AddString(_T("El Salvador"));
	m_Country->AddString(_T("Equatorial Guinea"));
	m_Country->AddString(_T("Eritrea"));
	m_Country->AddString(_T("Estonia"));
	m_Country->AddString(_T("Eswatini"));
	m_Country->AddString(_T("Ethiopia"));
	m_Country->AddString(_T("Fiji"));
	m_Country->AddString(_T("Finland"));
	m_Country->AddString(_T("France"));
	m_Country->AddString(_T("Gabon"));
	m_Country->AddString(_T("Gambia"));
	m_Country->AddString(_T("Georgia"));
	m_Country->AddString(_T("Germany"));
	m_Country->AddString(_T("Ghana"));
	m_Country->AddString(_T("Greece"));
	m_Country->AddString(_T("Grenada"));
	m_Country->AddString(_T("Guatemala"));
	m_Country->AddString(_T("Guinea"));
	m_Country->AddString(_T("Guinea - Bissau"));
	m_Country->AddString(_T("Guyana"));
	m_Country->AddString(_T("Haiti"));
	m_Country->AddString(_T("Holy See"));
	m_Country->AddString(_T("Honduras"));
	m_Country->AddString(_T("Hong Kong"));
	m_Country->AddString(_T("Hungary"));
	m_Country->AddString(_T("Iceland"));
	m_Country->AddString(_T("India"));
	m_Country->AddString(_T("Indonesia"));
	m_Country->AddString(_T("Iran"));
	m_Country->AddString(_T("Iraq"));
	m_Country->AddString(_T("Ireland"));
	m_Country->AddString(_T("Israel"));
	m_Country->AddString(_T("Italy"));
	m_Country->AddString(_T("Jamaica"));
	m_Country->AddString(_T("Japan"));
	m_Country->AddString(_T("Jordan"));
	m_Country->AddString(_T("Kazakhstan"));
	m_Country->AddString(_T("Kenya"));
	m_Country->AddString(_T("Kiribati"));
	m_Country->AddString(_T("Kosovo"));
	m_Country->AddString(_T("Kuwait"));
	m_Country->AddString(_T("Kyrgyzstan"));
	m_Country->AddString(_T("Laos"));
	m_Country->AddString(_T("Latvia"));
	m_Country->AddString(_T("Lebanon"));
	m_Country->AddString(_T("Lesotho"));
	m_Country->AddString(_T("Liberia"));
	m_Country->AddString(_T("Libya"));
	m_Country->AddString(_T("Liechtenstein"));
	m_Country->AddString(_T("Lithuania"));
	m_Country->AddString(_T("Luxembourg"));
	m_Country->AddString(_T("Macau"));
	m_Country->AddString(_T("Madagascar"));
	m_Country->AddString(_T("Malaysia"));
	m_Country->AddString(_T("Maldives"));
	m_Country->AddString(_T("Mali"));
	m_Country->AddString(_T("Malta"));
	m_Country->AddString(_T("Marshall Islands"));
	m_Country->AddString(_T("Mauritania"));
	m_Country->AddString(_T("Mauritius"));
	m_Country->AddString(_T("Mexico"));
	m_Country->AddString(_T("Micronesia"));
	m_Country->AddString(_T("Moldova"));
	m_Country->AddString(_T("Monaco"));
	m_Country->AddString(_T("Mongolia"));
	m_Country->AddString(_T("Montenegro"));
	m_Country->AddString(_T("Morocco"));
	m_Country->AddString(_T("Mozambique"));
	m_Country->AddString(_T("Namibia"));
	m_Country->AddString(_T("Nauru"));
	m_Country->AddString(_T("Nepal"));
	m_Country->AddString(_T("Netherlands"));
	m_Country->AddString(_T("New Zealand"));
	m_Country->AddString(_T("Nicaragua"));
	m_Country->AddString(_T("Niger"));
	m_Country->AddString(_T("Nigeria"));
	m_Country->AddString(_T("North Korea"));
	m_Country->AddString(_T("North Macedonia"));
		m_Country->AddString(_T("Norway"));
		m_Country->AddString(_T("Oman"));
		m_Country->AddString(_T("Pakistan"));
		m_Country->AddString(_T("Palau"));
		m_Country->AddString(_T("Palestinian Territories"));
		m_Country->AddString(_T("Panama"));
		m_Country->AddString(_T("Papua New Guinea"));
		m_Country->AddString(_T("Paraguay"));
		m_Country->AddString(_T("Peru"));
		m_Country->AddString(_T("Philippines"));
		m_Country->AddString(_T("Poland"));
		m_Country->AddString(_T("Portugal"));
		m_Country->AddString(_T("Qatar"));
		m_Country->AddString(_T("Romania"));
		m_Country->AddString(_T("Russia"));
		m_Country->AddString(_T("Rwanda"));
		m_Country->AddString(_T("Saint Kitts and Nevis"));
		m_Country->AddString(_T("Saint Lucia"));
		m_Country->AddString(_T("Saint Vincent and the Grenadines"));
		m_Country->AddString(_T("Samoa"));
		m_Country->AddString(_T("San Marino"));
		m_Country->AddString(_T("Sao Tome and Principe"));
		m_Country->AddString(_T("Saudi Arabia"));
		m_Country->AddString(_T("Serbia"));
		m_Country->AddString(_T("Seychelles"));
		m_Country->AddString(_T("Sierra Leone"));
		m_Country->AddString(_T("Singapore"));
		m_Country->AddString(_T("Sint Maarten"));
		m_Country->AddString(_T("Slovakia"));
		m_Country->AddString(_T("Slovenia"));
		m_Country->AddString(_T("Solomon Islands"));
		m_Country->AddString(_T("Somalia"));
		m_Country->AddString(_T("South Africa"));
	    m_Country->AddString(_T("South Korea"));
		m_Country->AddString(_T("South Sudan"));
		m_Country->AddString(_T("Spain"));
		m_Country->AddString(_T("Sri Lanka"));
		m_Country->AddString(_T("Sudan"));
		m_Country->AddString(_T("Suriname"));
		m_Country->AddString(_T("Swaziland(See Eswatini"));
		m_Country->AddString(_T("Sweden"));
		m_Country->AddString(_T("Switzerland"));
		m_Country->AddString(_T("Syria"));
		m_Country->AddString(_T("Taiwan"));
		m_Country->AddString(_T("Tajikistan"));
		m_Country->AddString(_T("Tanzania"));
		m_Country->AddString(_T("Thailand"));
		m_Country->AddString(_T("Timor - Leste"));
		m_Country->AddString(_T("Togo"));
		m_Country->AddString(_T("Tonga"));
		m_Country->AddString(_T("Trinidad and Tobago"));
		m_Country->AddString(_T("Tunisia"));
		m_Country->AddString(_T("Turkey"));
		m_Country->AddString(_T("Turkmenistan"));
		m_Country->AddString(_T("Tuvalu"));
		m_Country->AddString(_T("Uganda"));
		m_Country->AddString(_T("Ukraine"));
		m_Country->AddString(_T("United Arab Emirates")); 
		m_Country->AddString(_T("United Kingdom"));
		m_Country->AddString(_T("United States"));
		m_Country->AddString(_T("Uruguay"));
		m_Country->AddString(_T("Uzbekistan"));
		m_Country->AddString(_T("Vanuatu"));
		m_Country->AddString(_T("Venezuela"));
		m_Country->AddString(_T("Vietnam"));
		m_Country->AddString(_T("Yemen"));
	CComboBox* m_SolidCAMSalesperson = (CComboBox*)GetDlgItem(IDC_COMBO_SALESPERSON);
	m_SolidCAMSalesperson->AddString(_T("AMOD ONKAR"));
	m_SolidCAMSalesperson->AddString(_T("ANUJ BHANDARI"));
	m_SolidCAMSalesperson->AddString(_T("ARUNKUMAR C V"));
	m_SolidCAMSalesperson->AddString(_T("ARUNKUMAR DEV"));
	m_SolidCAMSalesperson->AddString(_T("KARTHIKEYAN"));
	m_SolidCAMSalesperson->AddString(_T("ASHOK KUMAR"));
	m_SolidCAMSalesperson->AddString(_T("VIKRAM OJHA"));
	m_SolidCAMSalesperson->AddString(_T("PRIYANKA WATTAMWAR"));
	m_SolidCAMSalesperson->AddString(_T("ARUN SHARMA"));
	m_SolidCAMSalesperson->AddString(_T("AMAN SUNDAL"));
	m_SolidCAMSalesperson->AddString(_T("ANKIT SINGHAL"));
	m_SolidCAMSalesperson->AddString(_T("ABHISHEK DHAWAN"));
	m_SolidCAMSalesperson->AddString(_T("PRAGI PATEL"));
	m_SolidCAMSalesperson->AddString(_T("ARUN JAGANATH"));
	CComboBox* m_Reseller = (CComboBox*)GetDlgItem(IDC_COMBO_RESELLER);
	m_Reseller->AddString(_T("SSKV"));
	m_Reseller->AddString(_T("CADVIN"));
	m_Reseller->AddString(_T("SAM AUTOMATION"));
	m_Reseller->AddString(_T("VIASELL"));
	m_Reseller->AddString(_T("RELIABLE SOLUTIONS"));
	m_Reseller->AddString(_T("SPINAK"));
	m_Reseller->AddString(_T("SKS SCANTECH"));
	m_Reseller->AddString(_T("SOLIDCAM INDIA"));
	m_Reseller->AddString(_T("GEMTEK INDIA"));
    SaveDateTime();
	// Saving the csv file on the basis of user is admin or normal user
	CWnd* pCsvButton = GetDlgItem(IDC_EXPORT_CSV);
	if (m_userRole == USER_ADMIN && pCsvButton)
	{
		pCsvButton->EnableWindow(TRUE);
	}
	else if (pCsvButton){
		pCsvButton->EnableWindow(FALSE);
	}
	return TRUE;

}

// We use wrapper function for control events to set their return type
void CCLeadLockingDlg::OnBnClickedUploadCardWrapper()
{
	std::stringstream ss = OnBnClickedUploadCard();

}


void CCLeadLockingDlg::OnEnChangeEditProspectname()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_PROSPECTNAME, m_ProspectName);

}


void CCLeadLockingDlg::OnEnChangeEditAddress()
{

	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	if (m_Address.IsEmpty()) {
		AfxMessageBox(_T("Address field cannot be empty."));
	}

}


void CCLeadLockingDlg::OnEnChangeEditStreetAdress()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_STREET_ADRESS, m_AddressLine2);
}


void CCLeadLockingDlg::OnEnChangeEditAddressLine2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItemText(IDC_Address_Line_2, m_AddressLine2);
}


void CCLeadLockingDlg::OnEnChangeEditCity()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_CITY, m_City);
	
}


void CCLeadLockingDlg::OnEnChangeEditState()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_STATE, m_State);
}


void CCLeadLockingDlg::OnCbnSelchangeComboCountry()
{
	// TODO: Add your control notification handler code here
	int selectedIndex = m_Country.GetCurSel();
	CString selectedText;
	m_Country.GetLBText(selectedIndex, selectedText);

}


void CCLeadLockingDlg::OnEnChangeEditPhoneNumber()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	    UpdateData(TRUE);
		CEdit * phoneNumberEdit = (CEdit*)GetDlgItem(IDC_EDIT_PHONE_NUMBER);
		phoneNumberEdit->GetWindowTextW(m_PhoneNumber);

	if (!IsPhoneNumberValid(m_PhoneNumber))
	{
		
		AfxMessageBox(_T("Invalid phone number format. Please enter exactly 10 digits."));
	}

}


void CCLeadLockingDlg::OnEnChangeEditEmail()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_EMAIL, m_Email);
	if (IsValidEmail(m_Email) && IsEmailDuplicate(m_Email))
	{
		AfxMessageBox(_T("Please enter a valid email address. Email either duplicate or invalid "));
	}
	
}


void CCLeadLockingDlg::OnEnChangeEditFirstName()
{
	GetDlgItemText(IDC_EDIT_LAST_NAME, m_FirstName);
}


void CCLeadLockingDlg::OnEnChangeEditLastName()
{
	GetDlgItemText(IDC_EDIT_LAST_NAME, m_LastName);
}

void CCLeadLockingDlg::OnCbnSelchangeComboSolidcamoffice()
{

	int selectedIndex = m_SolidCAMOffice.GetCurSel();
	CString selectedText;
	m_SolidCAMOffice.GetLBText(selectedIndex, selectedText);
}

std::stringstream CCLeadLockingDlg::OnBnClickedUploadCard()
{
	std::stringstream ss;

	CFileDialog fileDlg(TRUE, _T("jpg"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("Image Files (*.jpg;*.jpeg;*.png;*.bmp)|*.jpg;*.jpeg;*.png;*.bmp|"));
	//All Files(*.*) | *.* ||
	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();
		CImage originalImage;
		HRESULT hr = originalImage.Load(filePath);
		if (FAILED(hr))
		{
			AfxMessageBox(_T("Failed to load image."));
			return ss;
			CFile file;
			if (!file.Open(filePath, CFile::modeRead | CFile::typeBinary))
			{
				AfxMessageBox(_T("Failed to open image file."));
				return ss;
			}

			DWORD fileSize = file.GetLength();
			BYTE* pBuffer = new BYTE[fileSize];
			file.Read(pBuffer, fileSize);
			file.Close();

			ss.write(reinterpret_cast<const char*>(pBuffer), fileSize);
			delete[] pBuffer;

			// Display the image in the static control
			if (pStaticImage != nullptr)
			{
				int maxWidth = 200;
				int maxHeight = 150;

				int imageWidth = originalImage.GetWidth();
				int imageHeight = originalImage.GetHeight();

				if (imageWidth > maxWidth || imageHeight > maxHeight)
				{
					int newWidth, newHeight;
					if (imageWidth > maxWidth)
					{
						newWidth = maxWidth;
						newHeight = (maxWidth * imageHeight) / imageWidth;  // Maintain aspect ratio
					}
					else
					{
						newWidth = imageWidth;
						newHeight = imageHeight;
					}
					CImage resizedImage;
					resizedImage.Create(newWidth, newHeight, originalImage.GetBPP());
					CDC dc;
					dc.CreateCompatibleDC(NULL);
					HDC hdc = dc.GetSafeHdc();
					originalImage.StretchBlt(hdc, 0, 0, newWidth, newHeight, 0, 0, imageWidth, imageHeight, SRCCOPY);
					pStaticImage->SetBitmap((HBITMAP)resizedImage.Detach());
				}
				else
				{
					pStaticImage->SetBitmap((HBITMAP)originalImage.Detach());
				}
			}
		}

		return ss;
	}

}


void CCLeadLockingDlg::OnEnChangeEditGstNumber()
{

	// TODO:  If this is a RICHEDIT control, the control will not
	GetDlgItemText(IDC_EDIT_GST_NUMBER, m_GSTNumber);
	if (IsGSTDuplicate(m_GSTNumber))
	{
		AfxMessageBox(_T("GsT is dulplicate "));
	}

}


void CCLeadLockingDlg::OnEnChangeEditwebsite()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	GetDlgItemText(IDC_EDIT_website, m_Website);
}


void CCLeadLockingDlg::OnCbnSelchangeComboSalesperson()
{
	// TODO: Add your control notification handler code here
	int selectedIndex = m_SolidCAMSalesperson.GetCurSel();
	CString selectedText;
	m_SolidCAMSalesperson.GetLBText(selectedIndex, selectedText);
}

                                                                                                
void CCLeadLockingDlg::OnCbnSelchangeComboReseller()
{
	// TODO: Add your control notification handler code here
	int selectedIndex = m_Reseller.GetCurSel();
	CString selectedText;
	m_Reseller.GetLBText(selectedIndex, selectedText);
}



void CCLeadLockingDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	
	if ( m_ProspectName.IsEmpty() || m_Address.IsEmpty() ||
		m_PhoneNumber.IsEmpty() || m_Email.IsEmpty() ||
		m_LastName.IsEmpty() || m_FirstName.IsEmpty() ||
		m_StreetAddress.IsEmpty() || m_AddressLine2.IsEmpty() || (IsValidEmail(m_Email) && IsEmailDuplicate(m_Email))||
		m_City.IsEmpty() || m_State.IsEmpty() || m_PhoneNumber.IsEmpty() ||
		 m_SolidCAMOffice.GetCurSel() == CB_ERR ||
		m_SolidCAMSalesperson.GetCurSel() == CB_ERR ||
		m_Country.GetCurSel() == CB_ERR || m_Reseller.GetCurSel() == CB_ERR|| m_GSTNumber.IsEmpty() || IsGSTDuplicate(m_GSTNumber))
	{
		AfxMessageBox(_T("Please enter all the important field values"));
		return;
	}
	std :: string dateTimeStr = SaveDateTime().str();
	std :: string s1 =  OnBnClickedUploadCard().str() ; 
	if (InsertFormData(dateTimeStr, s1))
	{
		AfxMessageBox(_T("Data inserted successfully"));
		}
	else {
		AfxMessageBox(_T("Account not created successfully"));
	}
	EndDialog(IDOK); 
}

bool CCLeadLockingDlg::ConnectToDatabase() {
	
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

bool CCLeadLockingDlg::IsValidEmail(const CString& email)
{
	// pattern definition
	const std::regex pattern(
		R"((\w+)(\.{1}\w+)*@(\w+)(\.(\w+))+)"//
	);
	std::string emailStr = CT2CA(email);
	return std::regex_match(emailStr, pattern);
}

bool  CCLeadLockingDlg::IsAlphanumeric(const CString& str)
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

bool CCLeadLockingDlg::InsertFormData(std::string& datetime, std::string s)
{	

	if (!ConnectToDatabase()) {
		AfxMessageBox(_T("Failed to connect to the database."));   
		return false; 
	}
		try {
			std::unique_ptr<sql::PreparedStatement> pstmt;
			pstmt.reset(con->prepareStatement(
			"INSERT INTO leadlocking (ProspectName, Address, StreetAddress, AddressLine2, City, State, PhoneNumber, Email,"
			" FirstName, LastName, GSTNumber, Website, Country, SolidCAMOffice, SolidCAMSalesperson, Reseller, bussinesscard , new_date )"
			"VALUES (?, ?, ?, ?, ? ,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?, ?)"));

		CStringA prospectA(m_ProspectName);
		pstmt->setString(1, std::string(prospectA));

		CStringA addressA(m_Address);
		pstmt->setString(2, std::string(addressA));

		CStringA streetAddressA(m_StreetAddress);
		pstmt->setString(3, std::string(streetAddressA));

		CStringA addressLine2A(m_AddressLine2);
		pstmt->setString(4, std::string(addressLine2A));

		CStringA cityA(m_City);
		pstmt->setString(5, std::string(cityA));

		CStringA stateA(m_State);
		pstmt->setString(6, std::string(stateA));

		CStringA phoneNumberA(m_PhoneNumber);
		pstmt->setString(7, std::string(phoneNumberA));

		CStringA emailA(m_Email);
		pstmt->setString(8, std::string(emailA));


		CStringA firstNameA(m_FirstName);
		pstmt->setString(9, std::string(firstNameA));

		CStringA lastNameA(m_LastName);
		pstmt->setString(10, std::string(lastNameA));

		CStringA GSTNumberA(m_GSTNumber);
		pstmt->setString(11, std::string(GSTNumberA));

		CStringA websiteA(m_Website);
		pstmt->setString(12, std::string(websiteA));

		CString country;
		m_Country.GetWindowText(country);
		CStringA countryA(country);
		pstmt->setString(13, std::string(countryA));

		CString solidCAMOffice;
		m_SolidCAMOffice.GetWindowText(solidCAMOffice);
		CStringA solidCAMOfficeA(solidCAMOffice);
		pstmt->setString(14, std::string(solidCAMOfficeA));

		CString solidCAMSalesperson;
		m_SolidCAMSalesperson.GetWindowText(solidCAMSalesperson);
		CStringA solidCAMSalespersonA(solidCAMSalesperson);
		pstmt->setString(15, std::string(solidCAMSalespersonA));

		CString reseller;
		m_Reseller.GetWindowText(reseller);
		CStringA resellerA(reseller);
		pstmt->setString(16, std::string(resellerA));
		// difference between istringstream and string stream 
		std::istringstream* ss_bussinesscard = new std::istringstream(s);
		pstmt->setBlob(17, ss_bussinesscard);

		pstmt->setString(18, datetime);
		pstmt->executeUpdate();
		return true;
	}
	catch (sql::SQLException& e) {
		CString errorMessage;
		errorMessage.Format(_T("Could not insert form data. MySQL error: %S"),(e.what()));
		AfxMessageBox(errorMessage);
		return false;
	}

}
bool CCLeadLockingDlg::IsEmailDuplicate(const CString& email)
{
	try {
		
		if (!ConnectToDatabase())
			return false;
		std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT COUNT(*) FROM leadlocking WHERE Email = ?"));
		pstmt->setString(1, std::string(CT2CA(email)));
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		if (res->next()) {
			return res->getInt(1) > 0;
		}
	}
	catch (sql::SQLException& e) {
		AfxMessageBox(_T("Error checking email: ") + CString(e.what()));
	}
	return false;
}
bool CCLeadLockingDlg::IsGSTDuplicate (const CString& gst)
{
	try {

		if (!ConnectToDatabase())
			return false;
		std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT COUNT(*) FROM leadlocking WHERE GSTNumber = ?"));// peak into definition 
		pstmt->setString(1, std::string(CT2CA(gst)));//
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

		if (res->next()) {
			return res->getInt(1) > 0;
		}
	}
	catch (sql::SQLException& e) {
		AfxMessageBox(_T("Error checking GST: ") + CString(e.what()));
	}
	return false;
}
bool CCLeadLockingDlg::IsPhoneNumberValid(const CString& phoneNumber)
{
	
	for (int i = 0; i < phoneNumber.GetLength(); i++)
	{
		if (!_istdigit(phoneNumber[i]))
		{
			return false;
		}
	}

	return true;
}


//using curl library of curljson
bool CCLeadLockingDlg::ValidateGST(const CString& m_GSTNumber)
{
	CString apiKey = _T("324d71a65bff6f229c0b6cea861f2b13");
	CString apiEndpoint;
	apiEndpoint.Format(_T("http://sheet.gstincheck.co.in/check/%s/%s"), apiKey, m_GSTNumber);
	CW2AEX<128> endpoint(apiEndpoint);// CONVERTS THE APIENDPOINT WHICH IS A CSTRING TO std::(apiEndpointstr) convert to pass url to curl library
	std::string apiEndpointStr(endpoint);
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, apiEndpointStr.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			CString errorMsg;
			errorMsg.Format(_T("curl_easy_perform() failed: %s"), curl_easy_strerror(res));
			AfxMessageBox(errorMsg);
			curl_easy_cleanup(curl);
			return false;
		}
		else {
			try {
				nlohmann::json jsonResponse = nlohmann::json::parse(readBuffer);
				if (jsonResponse.contains("data") && jsonResponse["data"].contains("gstin")) {
					std::string gstNumber = jsonResponse["data"]["gstin"];
					std::string companyName = jsonResponse["data"]["lgnm"];
					std::string companyAddress = jsonResponse["data"]["pradr"]["adr"];
					
					CString companyNameCStr(companyName.c_str());
					CString companyAddressCStr(companyAddress.c_str());
					// Open new dialog with the company details
					CDetails companyDetailsDlg;
					companyDetailsDlg.m_CompanyName = companyNameCStr;
					companyDetailsDlg.m_CompanyAddress = companyAddressCStr;
					companyDetailsDlg.DoModal();
					curl_easy_cleanup(curl);
					return true;
				}
				else {
					AfxMessageBox(_T("GST number is not present"));
					curl_easy_cleanup(curl);
					return false; 
				}
			}
			catch (const std::exception& e) {
				CString errorMsg;
				errorMsg.Format(_T("JSON parsing error: %s"), e.what());
				AfxMessageBox(errorMsg);
				curl_easy_cleanup(curl);
				return false;
			}
		}
	}
	else {
		AfxMessageBox(_T("Failed to initialize curl"));
		return false; 
	}
}

void CCLeadLockingDlg::OnBnClickedButtonValidateGst()
{
	GetDlgItemText(IDC_EDIT_GST_NUMBER, m_GSTNumber);
	ValidateGST(m_GSTNumber);
}
std :: stringstream CCLeadLockingDlg::SaveDateTime()
{
	std::stringstream dateTime;
	time_t rawTime;
	struct tm timeInfo;
	//time_t rawTime;
	//Declares a variable rawTime of type time_t which is typically an alias for a numerical type (usually an integer) representing the number of seconds since the Unix epoch (00:00:00 UTC on 1 January 1970).
	// time(&rawTime);: The time function gets the current calendar time and stores it as a time_t object in rawTime. Essentially, it captures the current time in seconds since the Unix epoch.
    // struct tm timeInfo;: Declares a variable timeInfo of type struct tm, which is a structure that holds the broken-down time (year, month, day, hour, minute, second, etc.).
	//gmtime_s(&timeInfo, &rawTime); : The gmtime_s function converts the time_t value pointed to by rawTime to a tm structure representing the corresponding UTC time.The result is stored in the timeInfo structure.
	/*Assume the current date and time is July 26, 2024, at 14:35 : 00 UTC.Here’s what happens :

	time(&rawTime); :

		rawTime might be assigned a value like 1722027300 (the exact number of seconds since the Unix epoch to this date and time).
		gmtime_s(&timeInfo, &rawTime); :

		gmtime_s converts 1722027300 to a tm structure with the following values :
	timeInfo.tm_year = 124 (years since 1900, so 124 + 1900 = 2024)
		timeInfo.tm_mon = 6 (months since January, so 6 = July)
		timeInfo.tm_mday = 26 (day of the month)
		timeInfo.tm_hour = 14 (hours since midnight)
		timeInfo.tm_min = 35 (minutes after the hour)
		timeInfo.tm_sec = 0 (seconds after the minute)*/
	time(&rawTime);
	gmtime_s(&timeInfo, &rawTime);
	// ADJUSTING TIME TO IST ( UTC + 5:30)
	timeInfo.tm_hour += 5;
	timeInfo.tm_min += 30;
	mktime(&timeInfo);
	dateTime << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
	return dateTime;

}

void CCLeadLockingDlg::SetUserRole(UserRole role)
{
	m_userRole = role;
	
}


void CCLeadLockingDlg::OnBnClickedExportCsv()
{
	CFileDialog fileDlg(FALSE, _T("csv"), _T(""), OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, _T("CSV Files(*.csv)|*.csv|All Files (*.*)|*.*||"), this);

	if (fileDlg.DoModal() == IDOK) {
		CString filePath = fileDlg.GetPathName();
		// Macro Purpose: CT2CA is used to perform conversion from a CString to a const char* (ANSI C-style string), which is commonly used with functions and libraries that do not handle Unicode characters.
        //Usage: The macro converts a Unicode CString into an ANSI std::string or C - style string for compatibility with functions that expect ANSI encoding.
		std::string filePathStr = CT2CA(filePath); // Convert CString to std::string
		ExportDataToCSV(filePathStr);
		
	}
}

bool CCLeadLockingDlg::ExportDataToCSV(const std::string &filePath)
	{
		if (!ConnectToDatabase()) {
			AfxMessageBox(_T("Failed to connect to the database."));
			return false;
		}

		//std::unique_ptr<sql::PreparedStatement>: This creates a unique pointer to a sql::PreparedStatement object.Using a unique pointer ensures that the prepared statement will be automatically destroyed when it goes out of scope, preventing memory leaks.
		//	con->prepareStatement("SELECT * FROM leadlocking") : This method prepares an SQL statement to select all columns from the leadlocking table.
		//	con : This is a pointer to an active database connection.
		//	prepareStatement : This method is used to create a precompiled SQL statement.The statement can be executed multiple times more efficiently than executing the same query string each time.
		//	"SELECT * FROM leadlocking" : This SQL query selects all records from the leadlocking table.You can adjust this query as needed to select specific columns or filter records.
		//	Executing the SQL Query
		//	cpp
		//	Copy code
		//	std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		//  std::unique_ptr<sql::ResultSet>: This creates a unique pointer to a sql::ResultSet object, which holds the results of the query.
		//	pstmt->executeQuery() : This method executes the prepared SQL statement and returns a result set containing the data retrieved by the query.
		//	Opening the CSV File
		//	cpp
		//	Copy code
		//	std::ofstream csvFile(filePath);
		//  std::ofstream: This is an output file stream used to create files and write information to them.
		//	csvFile(filePath) : This opens a file at the specified filePath for writing.If the file does not exist, it will be created.If the file does exist, its contents will be overwritten.
		//	filePath : This parameter is the path to the file where the CSV data will be written.
		//	Explanation of Purpose
        //  This loop iterates over each row in the result set returned by the SQL query.
		//  res->next() advances to the next row and returns true if there is another row available.If there are no more rows, it returns false and the loop exits.
		//  res->getString("ColumnName") is a method provided by the MySQL Connector/C++ library that retrieves the value of the specified column in the current row as a std::string.
		//  For example, res->getString("ProspectName") retrieves the value of the "ProspectName" column in the current row and converts it to a std::string
		// Compatibility with std::ofstream:

			/*Writing data to a file using std::ofstream is straightforward with std::string as it supports the << operator for writing strings to a file.
        	The std::ofstream object csvFile is used to write data to the CSV file.Data Handling in C++:
        	Using std::string to hold the values of the columns allows easy manipulation and formatting of */
		
		try 
		{
				std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT * FROM leadlocking")); // Adjust the query as needed
				std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
				std::ofstream csvFile(filePath);
				//ofstream to used to open the file to write in it
				if (!csvFile.is_open())
				{
					AfxMessageBox(_T("Failed to open file for writing."));
					return false;
				}
				//>> means read , << means write 
				csvFile << "ProspectName,Address,StreetAddress,AddressLine2,City,State,PhoneNumber,Email,Firstname,LastName,GSTNumber,Website,Country,SolidCAMOffice,SolidCAMSalesperson,Reseller,new_date\n";
				
				//res->next() advances to the next row and returns true if there is another row available.If there are no more rows, it returns false and the loop exits.
				// res->getString("ColumnName") is a method provided by the MySQL Connector/C++ library that retrieves the value of the specified column in the current row as a std::string.
				//For example, res->getString("ProspectName") retrieves the value of the "ProspectName" column in the current row and converts it to a std::string
				
				//res->getString("ColumnName") is a method provided by the MySQL Connector/C++ library that retrieves the value of the specified column in the current row as a std::string.
				// For example, res->getString("ProspectName") retrieves the value of the "ProspectName" column in the current row and converts it to a std::string
				
				while (res->next())
				{
					std::string prospectName = res->getString("ProspectName");
					std::string address = res->getString("Address");
					std::string streetAddressLine2 = res->getString("StreetAddress");
					std::string addressLine2 = res->getString("AddressLine2");
					std::string city = res->getString("City");
					std::string state = res->getString("State");
					std::string phoneNumber = res->getString("PhoneNumber");
					std::string email = res->getString("Email");
					std::string firstname = res->getString("Firstname");
					std::string lastname = res->getString("LastName");
					std::string gstNumber = res->getString("GSTNumber");
					std::string website = res->getString("Website");
					std::string country = res->getString("Country");
					std::string solidCAMOffice = res->getString("SolidCAMOffice");
					std::string solidCAMSalesperson = res->getString("SolidCAMSalesperson");
					std::string reseller = res->getString("Reseller");
					std::string newDate = res->getString("new_date");
					csvFile << prospectName << ','
						<< address << ','
						<< streetAddressLine2 << ','
						<< addressLine2 << ','
						<< city << ','
						<< state << ','
						<< phoneNumber << ','
						<< email << ','
						<< firstname << ','
						<< lastname << ','
						<< gstNumber << ','
						<< website << ','
						<< country << ','
						<< solidCAMOffice << ','
						<< solidCAMSalesperson << ','
						<< reseller << ','
						<< newDate << '\n';
				}
				csvFile.close();
				AfxMessageBox(_T("Data exported successfully."));
			}
			catch (sql::SQLException& e)
			{
				CString errorMessage;
				errorMessage.Format(_T("Query execution failed: %S"), e.what());
				AfxMessageBox(errorMessage);
				return false;
			}

			return true;
	}
	