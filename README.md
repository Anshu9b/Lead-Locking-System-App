# Task 1- Lead-Locking-System-App :
## Overview- I need to create a leadlocking form with login and create account option as authentication.
## Techstack used - MFC (Frontend), C++(Backend), MySQL( Database) connection.
## Fields that are provided in the Leadlocking Form -
- ProspectName -> not null;
- Address -> not null;
- StreetAddress  -> not null;
- AddressLine2 -> not null;
- City -> not null;
- State -> not null;
- PhoneNumber -> not null;
- Email -> not null and non duplicate ;
- FirstName -> not null;
- LastName -> not null;
- GSTNumber -> Validated using GSTIN Validator API using lookup in the schema;
- Website;
- SolidCAMOffice -> not null -> dropdown selction from options ;
- SolidCAMSalesperson -> not null -> dropdown selction from options ;
- Country ->not null -> dropdown selction from options ;
- Reseller ->not null -> dropdown selction from options ;
- DateTime ->not null ;
- pStaticImage- > bussiness card purpose;
## MFC OVERVIEW AND HISTORY -
- The Microsoft Foundation Class (MFC) library provides a set of functions, constants, data types, and classes to simplify creating applications for the Microsoft Windows operating systems. In this tutorial, you will learn all about how to start and create Windows-based applications using MFC.
- It was 1992, and Windows was still running as a 16bit operating system layered on top of MS-DOS when Microsoft introduced its Microsoft Foundation Classes (MFC) to developers. Most applications for Windows had previously been written in C, but C++ was starting to take off, and the C++ developers were craving an object-oriented way of developing Windows applications, to match the ease of VB, which had been released a year earlier, but with the flexibility of C / C++.
- Back then, Microsoft’s C++ compiler did not have exception handling, templates, nor did it have a standard library of containers and algorithms that took advantage of the C++ language features. As such, MFC used macros to emulate templates and exceptions and created its own set of containers for generic concepts such as strings, arrays, lookup maps and more. Well beyond the brief of object-oriented and easier access the Windows APIs.
## Prequirements to know:
1. C++
2. MFC - Dialog Box plus Mfc concepts.
3. SQL and MYSQL Workbench database connection.
4. Http response methods.
    
## Setup Requirement :
1. Visual Studio 2022 
2. MySQL Server 8.0.0 version (Windows 64 bit)[https://downloads.mysql.com/archives/community/]
3. MySQL Workbench 8.0.0 version [https://downloads.mysql.com/archives/community/]
4. MySQL C++ Connector Library(Windows 64 bit) [https://dev.mysql.com/downloads/connector/cpp/]
5. CURL (Client URL) 8.8.0 library [https://curl.se/download.html]
6. Nlohmann Json -( 3 party library to generate schema in C++) [https://github.com/nlohmann/json/tree/develop/single_include/nlohmann]

 ## Sprint✅
## Day 1 -(21/06/24)
1. MFC Dialog MSDN Docs read.<br/>
2. Steps needed in VS Code to setup a CDialog for First authentication page.
3. Control Management button added
4. Worked on further occured errors 

## Day 2- (22/06/24)
1. Created the Username and Password button and worked on related functions.
2. Learned about Modal and Modalless Dialog boxes.
3.  Extensively checked for CDialog and CdialogEx classes and which is more flexible to use.
   
## Modal and Modaless Dialog Box
- You can use class CDialog to manage two kinds of dialog boxes:
- Modal dialog boxes, which require the user to respond before continuing the program
- Modeless dialog boxes, which stay on the screen and are available for use at any time but permit other user activities
- The resource editing and procedures for creating a dialog template are the same for modal and modeless dialog boxes.
- Creating a dialog box for your program requires the following steps:
- Use the dialog editor to design the dialog box and create its dialog-template resource.
- Create a dialog class.
- Connect the dialog resource's controls to message handlers in the dialog class.
- Add data members associated with the dialog box's controls and to specify dialog data exchange and dialog data validations for the controls.
- ![image](https://github.com/user-attachments/assets/eb56dc4f-f471-4b72-ab0b-33ce2b0c4761)


# Creating Modal Dialog boxes in MFC
To create a modal dialog box, call either of the two public constructors declared in CDialog. Next, call the dialog object's DoModal member function to display the dialog box and manage interaction with it until the user chooses OK or Cancel. This management by DoModal is what makes the dialog box modal. For modal dialog boxes, DoModal loads the dialog resource.
# Usage in Lead Locking form 
- ![image](https://github.com/user-attachments/assets/2128da38-cad0-4040-8b52-4cceacbf6749)
- 

## Day 3- (23/06/24)
1. Warpped up the user_login dialog box.
2. Started Linking the create account button using modal dialog with userlogin dialog page.
3. Further resolved errors occured

## KeyNotes
- CDialogEx why used and not why CDialog dialog box: CDialogEx vs. CDialog
   -CDialogEx is an extended version of the CDialog class provided by MFC. Here are some key differences and reasons for using CDialogEx over CDialog:
  -Enhanced Features:
    1.CDialogEx includes additional features such as support for dynamic resizing, task dialogs, and visual styles.
     It can handle dialog templates that include newer Windows control types and styles.
     Better Layout and Control Handling:
    2.CDialogEx provides better mechanisms for handling modern UI elements and more complex layouts.
    3.It is often used in newer applications that require more sophisticated dialog interfaces.
      Backward Compatibility:
    4.CDialogEx is backward compatible with CDialog, so it can be used as a drop-in replacement without losing any functionality provided by CDialog.
- Difference between GetDlgItem, GetDlgItemText,Get WindowText and GetWindowTextLength:
  1. GetDlgItem Function: Retrieves a handle to a control in a dialog box.
    -Usage: Use this when you need to get a control's handle and manipulate it directly. 
  2. GetDlgItemText Function: Retrieves the text of a control in a dialog box.
    -Usage: Use this when you want to get the text content from a specific control.
  3.GetWindowText Function: Retrieves the text of the window or control. 
  4.GetWindowTextLength Function: Retrieves the length, in characters, of the text associated with a window or control.
 -Usage: Use this to determine the length of the text before retrieving it, which can help in allocating sufficient buffer size.
- Usage of CString , CStringA, std:: string: CString:
 1.CString :
 - Type: A class provided by MFC.
- Character Set: Can be either ANSI or Unicode depending on the project settings.
- Usage: Commonly used in MFC applications for string manipulations, providing extensive functionality for handling strings.
- eg: CString str = _T("Hello, World!");
2. CStringA
- Type: A specialization of CString specifically for ANSI (8-bit) characters.
- Usage: Use this when you need to explicitly handle ANSI strings within an MFC application.
- Eg: CStringA strA = "Hello, ANSI World!";
3. std::string
- Type: A standard C++ class from the STL.
- Character Set: Always uses ANSI (8-bit) characters.
- Usage: Preferred for standard C++ applications that do not depend on MFC. Provides a wide range of functionality for string manipulations and integrates well with the C++ standard library.
- Eg: std::string str = "Hello, Standard World!";

## Day 4- (24/06/24)

1. Setup Mysql for database, configured the version
2. Downloaded and setup the MYSQL Workbench.
3. Reasearched on connection OF DATABASE with Mfc as frontend and C++ as backend.
4. Further resolved the errors
   
## Key Learnings
- Mysql Database connection can be done for MFC based application with C++ with Myql connector library
- MySQL Connector/C++ is a MySQL database connector for C++. It lets you develop C++ and 
  C applications that connect to MySQL Server.
- It provides a set of libraraies to be used in Mfc application in C++ for connection.
- I configured the libraries one for [ C/C++ -> #inclue purpose, Linker library -> linking connections]
- Libraries used in my application:  
1. #include <mysql_driver.h>
2. #include <mysql_connection.h>
3. #include <cppconn/resultset.h>
4. #include <cppconn/statement.h>
5. #include <cppconn/prepared_statement.h>
6. Mysql Variables initializations:
  ![image](https://github.com/user-attachments/assets/e09a8b9e-bfe9-4bff-8a92-0ac132bf319f)
  
## Day5- (25/06/24)
1. Checked on - Edge cases function implementation to do.
2. Username and Password type should be string and alphanumeric.
3. Worked on Sql connection functions:
  ![image](https://github.com/user-attachments/assets/db7e3880-6156-4763-aad2-a4cd9de2eaef)

## Key Learnings
- ConnectToDatabase () function implementation:
  ![image](https://github.com/user-attachments/assets/f23f4234-5ed6-4a16-a95f-e7b89debaca3)

## Purpose
The function ConnectToDatabase aims to establish a connection to a MySQL database. It returns true if the connection is successful and false otherwise.

## Detailed Explanation

- bool CUserRegistrationSystem2Dlg::ConnectToDatabase() {
- Return Type: bool - Indicates whether the connection to the database was successful (true) or not (false).
- Class Scope: CUserRegistrationSystem2Dlg:: - This function is a member of the: CUserRegistrationSystem2Dlg class.

## Variable Declaration and Initialization

- sql::mysql::MySQL_Driver* driver
- sql::mysql::get_mysql_driver_instance(); 
- sql::mysql::MySQL_Driver* driver: Declares a pointer to a MySQL_Driver instance.
- sql::mysql::get_mysql_driver_instance(): Static method that returns a pointer to the MySQL driver singleton instance. This driver is necessary for connecting to a MySQL database.
  
## Establishing Connection

- con = std::unique_ptr<sql::Connection>(driver->connect("tcp://127.0.0.1:3306", "root", "Missspacegirl@09"));
- con: Assumes con is a member variable of type std::unique_ptr<sql::Connection>, which manages the database connection.
- driver->connect("tcp://127.0.0.1:3306", "root", "Missspacegirl@09"): Establishes a connection to the MySQL server at the specified address (127.0.0.1:3306). The connect method requires:
- The server address (tcp://127.0.0.1:3306).
- The username (root).
- The password (Missspacegirl@09).
- Setting the Database Schema 
- con->setSchema("user_register");
- con->setSchema("user_register"): Sets the default schema (database) for the connection to user_register. This means all subsequent SQL queries will operate within the user_register database unless 
  specified otherwise.
- Returning Success
  return true;
- If all previous operations are successful, the function returns true, indicating the connection was successful.
- Exception Handling:
  catch (sql::SQLException& e) {
  catch (sql::SQLExcept)

## Day 6- (26/06/24)
 Resolved errors in database connection.
## Day 7- (27/06/24)(sat)
 Resolved errors in database connection.
## Day 8- (28/06/24)(sun)
 Resolved errors in database connection.
## Day 9- (29/06/24)
1. Successfully connected database connection with user login dialog.
2. Implemented the Edge cases function ->
 -  ![image](https://github.com/user-attachments/assets/f20d0fcc-8b5c-44a8-a61a-37534425238a)
3. OnClickedButtonSubmit()
- ![image](https://github.com/user-attachments/assets/6ac7a404-9cbb-4d6c-a556-1b647c2e0f51)

## Purpose
- The function DoesUserExist checks if a user with the specified username and password exists in the database.
- bool CUserRegistrationSystem2Dlg::DoesUserExist() {
- Return Type: bool - Indicates whether the user exists (true) or not (false).

### Common For all Dialog Boxes- CUserRegistrationDlg, CCreateAccountDlg, CCLeadLockingDlg: Function ConnectToDatabase():

### Step 1: Connect to the Database
-if (!ConnectToDatabase())
    return false;
-ConnectToDatabase(): Calls the ConnectToDatabase method to establish a connection to the database.
-Check Connection: If the connection fails, the function returns false.

### Step 2: Query Execution within a Try-Catch Block
- Declaration and Preparation of SQL Statement
try {
    std::unique_ptr<sql::PreparedStatement> pstmt;
    std::unique_ptr<sql::ResultSet> res;
    pstmt.reset(con->prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?"));
- pstmt: A unique pointer to a PreparedStatement object for executing parameterized SQL queries.
- res: A unique pointer to a ResultSet object to store the query results.
  ## Imp
- con->prepareStatement(...): Prepares the SQL statement with placeholders (?) for the username and password parameters to prevent SQL injection.
- Setting Parameters and Executing the Query
- CStringA usernameA(Username);
- CStringA passwordA(Password);
- pstmt->setString(1, std::string(usernameA));
- pstmt->setString(2, std::string(passwordA));
- res.reset(pstmt->executeQuery());
- CStringA usernameA(Username);: Converts Username (assumed to be a CString member variable) to CStringA (ANSI string).
- CStringA passwordA(Password);: Converts Password (assumed to be a CString member variable) to CStringA (ANSI string).
- pstmt->setString(1, std::string(usernameA));: Sets the first parameter (username) of the prepared statement.
- pstmt->setString(2, std::string(passwordA));: Sets the second parameter (password) of the prepared statement.
- res.reset(pstmt->executeQuery());: Executes the query and stores the result in res.
- return res->next();
- res->next(): Advances the cursor to the next row in the result set. If a row exists, it returns true, indicating the user was found. If no rows are returned, it returns false.
- catch (sql::SQLException& e) {
    CString errorMessage;
    errorMessage.Format(_T("Query execution failed: %S"), e.what());
    AfxMessageBox(errorMessage);
    return false;
}
- catch (sql::SQLException& e): Catches any sql::SQLException that might be thrown during the execution of the SQL query.
- Error Message: Formats an error message with the exception details and displays it using AfxMessageBox.
- Return False: If an exception occurs, the function returns false.
  
### Summary
-Connect to Database: Attempts to connect to the database. Returns false if the connection fails.
-Prepare Statement: Prepares an SQL statement to select the user based on username and password.
-Set Parameters: Sets the username and password parameters in the prepared statement.
-Execute Query: Executes the query and checks if any results are returned.
-Return Result: Returns true if a user is found, false otherwise.
-Exception Handling: Catches any SQL exceptions, displays an error message, and returns false.
- This function effectively handles database connectivity and query execution, ensuring that the application can verify user credentials securely and robustly.
  
## Day 10- (30/06/24)
- Implementation of CreateAccount() function for inserting into database new user.
 ![image](https://github.com/user-attachments/assets/907690ba-1556-4c3e-9f28-3de242d87ede)
- Resolving errors related to create account dialog with user login dialog.
  ### Key Learnings
- Implementation of try- catch block of insert function of create account.
   - try {
	-  std::unique_ptr<sql::PreparedStatement> pstmt;
	- pstmt.reset(con->prepareStatement("INSERT INTO users (`username`, `password`) VALUES (?, ?)"));
  - CStringA usernameA(Username); // used for ANSI
	- CStringA passwordA(Password);
	- pstmt->setString(1, std::string(usernameA));
	- pstmt->setString(2, std::string(passwordA));
	- pstmt->executeUpdate();
	- return true;
}
- catch (sql::SQLException& e) {
	CString errorMessage;
	errorMessage.Format(_T("Account creation failed: %S"), e.what()); // %S for wide-character CString
	AfxMessageBox(errorMessage);
	return false;

}
## Day 11- (01/07/24)

- Creating Layout of the LeadLocking Form with different fields required.
- Defining the properties and type of the fields and drawn an overview to implement it.
- Different properties of field values are-
    ## Edit Controls for Input of text values-
   - ProspectName -> not null;
   - Address -> not null;
   - StreetAddress  -> not null;
   - AddressLine2;
   - City;
   - State;
   - FirstName;
   -LastName;
   - Website;
   - Email;
  ## Combo Box for Dropdown selection-
  - SolidCAMOffice;
  - SolidCAMSalesperson;
  - Country;
  - Reseller;
## Day 12 - (02/07/24)
### OverView of Combo Box and implementation- 
-A combo box consists of a list box combined with either a static control or edit control. it is represented by CComboBox class. The list-box portion of the control may be displayed at all times or may 
 only drop down when the user selects the drop-down arrow next to the control.
- Initialization
  CBN_SELCHANGE	ON_CBN_SELCHANGE( <id>, <memberFxn> ):The selection in the list box of a combo box is about to be changed as a result of the user either clicking in the list box or changing the 
  selection by using the arrow keys.
- Explanation of :
  -  int selectedIndex = m_Reseller.GetCurSel();
     CString selectedText;
     m_Reseller.GetLBText(selectedIndex, selectedText);
  1. CString selectedText;
  2. m_Reseller.GetLBText(selectedIndex, selectedText): int selectedIndex = m_Reseller.GetCurSel();
  3. m_Reseller: This is an instance of the CComboBox class, which represents a combo box control in an MFC application.
  4. GetCurSel(): This method retrieves the index of the currently selected item in the combo box. If no item is selected, it returns CB_ERR.
  5. selectedIndex: This variable will hold the index of the currently selected item.
  - CString selectedText;
   1. CString: This is a string class provided by MFC for handling text. It can handle both ANSI and Unicode strings depending on the project settings.
   2. selectedText: This variable will be used to store the text of the selected item.
   3. m_Reseller.GetLBText(selectedIndex, selectedText);
   4. GetLBText(int nIndex, CString& rString): This method retrieves the text of the item at the specified index (nIndex) in the combo box and stores it in the provided CString variable (rString).
   5. selectedIndex: The index of the currently selected item, obtained from GetCurSel().
   6. selectedText: The CString variable where the text of the selected item will be stored.
 -Explanation of : CComboBox* m_SolidCAMSalesperson = (CComboBox*)GetDlgItem(IDC_COMBO_SALESPERSON);CComboBox* m_SolidCAMSalesperson
  1.CComboBox*: This declares a pointer to a CComboBox object, which represents a combo box control.
  2. (CComboBox*)GetDlgItem(IDC_COMBO_SALESPERSON): GetDlgItem(int nID): This method retrieves a pointer to the control with the specified ID (nID) in the dialog box. The control must be a child of the 
  dialog.
  3. COMBO_SALESPERSON: This is the ID of the combo box control as defined in the resource file.
  (CComboBox*): This casts the CWnd* returned by GetDlgItem to a CComboBox*. This is necessary because GetDlgItem returns a generic CWnd* pointer, and you need to cast it to the specific control type you 
  are working with (CComboBox in this case).
- Explanation of :m_SolidCAMSalesperson.GetCurSel() == CB_ERR
- m_SolidCAMSalesperson->GetCurSel()
- m_SolidCAMSalesperson: This is a pointer to a CComboBox object.
- GetCurSel(): This method retrieves the index of the currently selected item in the combo box. If no item is selected, it returns CB_ERR.
- CB_ERR: This is a constant defined in the Windows API, which signifies an error or that no item is selected in the combo box.
- m_SolidCAMSalesperson->GetCurSel() == CB_ERR: This expression checks if no item is selected in the combo box. If GetCurSel() returns CB_ERR, it means that no item is currently selected.
  ![image](https://github.com/user-attachments/assets/5383bceb-a9e2-40bb-a7e4-650628216f26)

 ## Keynotes 
- What the full statement means : const std::regex pattern(
	R"((\w+)(\.{1}\w+)*@(\w+)(\.(\w+))+)"/'
- \w+:
 1. \w: Matches any word character (alphanumeric character plus underscore). <br>
 2. +: Matches one or more of the preceding element.
 3. (\w+): Captures one or more word characters. This corresponds to the local part of the email before any dots.
- (\.{1}\w+)*:
 1.  \.: Matches a literal dot (.).
 2. {1}: Matches exactly one occurrence of the preceding element.
 3. \w+: Matches one or more word characters following the dot.
 4. (\.{1}\w+)*: This entire group matches zero or more occurrences of a dot followed by one or more word characters. This allows for email addresses with dots in the local part (e.g., john.doe).
- @:
 Matches the literal @ symbol, separating the local part from the domain part of the email.
-(\w+): Matches one or more word characters. This corresponds to the initial part of the domain name.
- (\.(\w+))+:
1. \.: Matches a literal dot.
2. (\w+): Matches one or more word characters. This captures the top-level domain (e.g., com, net).
3. (\.(\w+))+: This group matches one or more occurrences of a dot followed by one or more word characters. This allows for multiple levels in the domain (e.g., example.co.uk).



### Static Text
-A static control displays a text string, box, rectangle, icon, cursor, bitmap, or enhanced metafile. It is represented by CStatic class. It can be used to label, box, or separateother controls. A static 
 control normally takes no input and provides no output.

### Phone Number - implementation 
- Not able to take all the values and then check if total digit is 10 or not.
- So implement function- IsPhonenoValiud() and check whenever a new digit is pressed.
- Code Snippet:  ![image](https://github.com/user-attachments/assets/e687da81-b980-4b6f-8dcd-e9213c11a9c8)

## GST Validation - We need to validate using GST Validate in schema and do lookup in that.
- Perform GET request on it.
- So we need to use client url- curl libraray
  
### CURL LIBRARY Implementaion  
-Client URL, or just curl, is a command-line tool for transferring data using various network protocols. It is commonly used by developers to test various applications build on top of HTTP.
-That said, curl itself is just a wrapper around libcurl. The library is written in C and has well documented API.

## Imp
- If you use libcurl from a C++ program, it is important to remember that you cannot pass in a string object where libcurl expects a string. ## It has to be a null terminated C string. Usually you can 
  make this happen with the c_str() method.
- For example, keep the URL in a string object and set that in the handle:
  std::string url("https://example.com/");
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

## STEPS TO DO CURL OPERATION 

- Before you do anything libcurl related in your program, you should do a global libcurl initialize call with curl_global_init(). This is necessary because some underlying libraries that libcurl might be  
  using need a call ahead to get setup and initialized properly.
- curl_global_init() is, unfortunately, not thread safe, so you must ensure that you only do it once and never simultaneously with another call. It initializes global state so you should only call it 
  once, and once your program is completely done using libcurl you can call curl_global_cleanup() to free and clean up the associated global resources the init call allocated.
- libcurl is built to handle the situation where you skip the curl_global_init() call, but it does so by calling it itself instead (if you did not do it before any actual file transfer starts) and it then 
 uses its own defaults
- Easy handle.The fundamentals you need to learn with libcurl.First you create an "easy handle", which is your handle to a transfer, really:
- CURL *easy_handle = curl_easy_init();
- You then set options in that handle to control the upcoming transfer. This example sets the URL:
- ![image](https://github.com/user-attachments/assets/d4973659-5230-4771-8a5f-f56ef773a3e4)
- Eg from code 
- ![image](https://github.com/user-attachments/assets/87d108c2-22a2-4f03-95ca-f146503a5036)
- CString: CString is a string class provided by MFC that simplifies string manipulation. It handles memory management automatically, making it easier to work with strings compared to raw character arrays.
- CString::Format: The Format method of CString works similarly to the printf function in C. It allows you to create formatted strings by inserting variables into a format string. Here, apiEndpoint.Format 
  constructs the complete API endpoint URL by inserting apiKey and m_GSTNumber into the format string.
- Compatibility: Using _T ensures that the code can be compiled for both Unicode and ANSI builds without modification.
- Ease of Use: CString provides convenient methods for string manipulation, reducing the likelihood of errors compared to manually managing character arrays.
- Readability: The Format method makes it easy to see how the URL is constructed, improving code readability.
- Alternative Approach without _T and CString::Format
- If you are working exclusively with standard C++ strings and don't need MFC compatibility, you could use std::string and std::stringstream:
 - #include <string>
 - #include <sstream>
 - std::string apiKey = "f4f459b60c3351483570f552eaa3cb79";
 - std::string m_GSTNumber = "someGSTNumber"; // Assume m_GSTNumber is a std::string
 - std::stringstream ss;
 - ss << "http://sheet.gstincheck.co.in/check/" << apiKey << "/" << m_GSTNumber;
 - ::string apiEndpoint = ss.str();
- res = curl_easy_setopt(easy_handle, CURLOPT_URL, "http://example.com/");
- If curl_easy_setopt() returns CURLE_OK, we know it stored the option fine.
  ### STEP1- CURL* curl= pointer
  ### STEP2 - CURLcode res= variable to store code as ok or not ok result of operation
  ### STEP3- std:: string readbuffer -> string to store read data from the api and 
   store as buffer.
  ### STEP4- curl= curl_easy_init() function ->  Initializes the CURL library for 
   making HTTP requests (curl is a handle to the CURL session).
  ## curl_easy_setopt()- consists of 3 parameters
- curl_easy_setopt: function from the libcurl library used to set various options for a CURL session handle. This function allows you to specify details about the transfer, such as the URL to fetch, 
 how to handle the response data, timeouts, and more.
-  CURLcode curl_easy_setopt(CURL *handle, CURLoption option, parameter);
- handle: The CURL session handle obtained from curl_easy_init.
- option: The specific option to set, defined by the CURLoption enum.
- parameter: The value to set for the specified option, which can vary in type depending on the option.
- curl_easy_setopt(): Sets various options for the CURL session:
- CURLOPT_URL: Sets the URL to fetch. 1. CURLOPT_URL
- Purpose: Sets the URL for the HTTP request.
- curl_easy_setopt(curl, CURLOPT_URL, apiEndpointStr.c_str());
- curl: The CURL session handle.
- CURLOPT_URL: Option to set the URL to fetch.
- apiEndpointStr.c_str(): The URL as a null-terminated C string.
 -Explanation: This option specifies the URL to which the request should be sent. In 
  your case, apiEndpointStr contains the complete URL constructed from the API key and 
  GST number.
- CURLOPT_WRITEFUNCTION: Sets a callback function (WriteCallback) to handle the response data.
  
  ### Eg- Calculate the Total Size of the Data Received
  
 - size_t newLength = size * nmemb;
 - size: The size of each data element (typically 1 byte for char data).
 - nmemb: The number of data elements received.
 - newLength: The total size of the data received in bytes. This is calculated by multiplying size by nmemb.
 - Append the Data to the String
  try {
    s->append((char*)contents, newLength);
  }
  catch (std::bad_alloc& e) {
    return 0;
  }
- s: Pointer to a std::string passed through the userp parameter.
- (char)contents*: Casts the contents pointer to a char pointer, which is the appropriate type for appending to a std::string.
- newLength: Specifies the number of bytes to append.
- *s->append((char)contents, newLength)**: Appends the received data to the std::string object.
- try-catch block: Catches std::bad_alloc exceptions that might be thrown if memory allocation fails while appending data. If an exception occurs, the function returns 0, indicating an error.
- Return the Number of Bytes Handled
- return newLength: Returns the number of bytes successfully appended to the std::string. This indicates to CURL how many bytes were handled. Returning a value less than newLength would indicate a failure 
  to handle all the data, which CURL would treat as an error.
- Calculate the size: size * nmemb computes the total size of the data block received.
- Append to string: The data block is appended to the std::string object pointed to by s.
- Handle exceptions: If memory allocation fails (std::bad_alloc), the function returns 0 to indicate failure.
- Return handled bytes: The function returns the number of bytes successfully appended.
- CURLOPT_WRITEDATA: Passes &readBuffer to receive the response data.
  
  ### STEP 5- res= curl_easy_perform (curl)
  
- curl_easy_perform(): Performs the HTTP GET request. If an error occurs (res != CURLE_OK), it displays an error message using AfxMessageBox and returns false.
  
- ![image](https://github.com/user-attachments/assets/17d981f5-76a7-421b-b260-b809987da0d0)
- ![image](https://github.com/user-attachments/assets/c6259032-8f1e-4979-be92-80ce83215817)
- ![image](https://github.com/user-attachments/assets/27c3d679-61cf-4585-8da2-2500a9871d3f)
- ![image](https://github.com/user-attachments/assets/4aaeb5b9-d435-469c-b636-dc5aed7d8ec9)
- ![image](https://github.com/user-attachments/assets/460523f0-3d23-4f1d-9c22-8aff9ef39713)
- ![image](https://github.com/user-attachments/assets/1d8cf0f0-dcbd-410e-b927-f322a3850905)
- ![image](https://github.com/user-attachments/assets/aadf8b68-fe12-4c47-8469-92861083110b)
- ![image](https://github.com/user-attachments/assets/402014df-d1a1-4143-a9dc-3addab64b625)
- ![image](https://github.com/user-attachments/assets/39d2c8f1-807d-4d7b-811c-3eab2c42a3a9)
- ![image](https://github.com/user-attachments/assets/444b5e3b-e279-4cee-b1ae-9bd8b7c20c2b)

  
## Nlohmann Library About- Why used?
- Used in C++ code for parsing the schema from since C++ doesnt have its native library for parsing.
- Need to configure the json.hpp library which is a single include header file in project configuration
- About:
- ![image](https://github.com/user-attachments/assets/83f1478c-9078-4748-95b4-567955b6cc4a)
- ![image](https://github.com/user-attachments/assets/2be51054-3cb7-45ee-87cf-77b5f4c83de6)

  
  ### STEPS OF PARSING :
- step1: Parse the JSON Response
  nlohmann::json jsonResponse = nlohmann::json::parse(readBuffer);
  readBuffer: This is a std::string containing the raw JSON response data received from the HTTP request.
  nlohmann::json::parse(readBuffer): This function parses the readBuffer string into a nlohmann::json object. If the JSON data is malformed, this function will throw an exception.
- step2: Check for Specific Fields in the JSON
 if (jsonResponse.contains("data") && jsonResponse["data"].contains("gstin")) {
 jsonResponse.contains("data"): This checks if the parsed JSON object contains a key named "data".
 jsonResponse["data"].contains("gstin"): If the "data" key exists, this further checks if the "data" object contains a key named "gstin".
  This double check ensures that the response has the necessary structure and the specific field you're interested in.
- step3: Extract the GST Number
 std::string gstNumber = jsonResponse["data"]["gstin"];
 jsonResponse["data"]["gstin"]: Accesses the value associated with the key "gstin" inside the "data" object. This value is expected to be a string containing the GST number.
 std::string gstNumber: Stores the extracted GST number in a std::string variable.

## Json Parsing 
 ![image](https://github.com/user-attachments/assets/b9efe3e3-9b5b-4bf5-9cd7-165e6f72633e)
 - Eg in code:
 ![image](https://github.com/user-attachments/assets/ab165aa3-3b21-468b-b92f-65703a59fbfa)

### Keynotes
- What will happen if curl easy handler is not initialized ?

### New Updates  

-	Make gst no validated in database and duplicate msg to show.
-	Admin button to export in csv
-	Phone no msg- one time.
-	Datetime stored in database without user able to see.
-	Username should have email form.
-	Button of upload bussinesscard
## Assumptions in Time 
-Assume the current date and time is July 26, 2024, at 14:35 : 00 UTC.
- time(&rawTime); :
- rawTime might be assigned a value like 1722027300 (the exact number of seconds since the Unix epoch to this date and time).
- gmtime_s(&timeInfo, &rawTime); :
- gmtime_s converts 1722027300 to a tm structure with the following values :
- timeInfo.tm_year = 124 (years since 1900, so 124 + 1900 = 2024)
- timeInfo.tm_mon = 6 (months since January, so 6 = July)
- timeInfo.tm_mday = 26 (day of the month)
- timeInfo.tm_hour = 14 (hours since midnight)
- timeInfo.tm_min = 35 (minutes after the hour)
- timeInfo.tm_sec = 0 (seconds after the minute)*/
- time_t rawTime;
- Declares a variable rawTime of type time_t which is typically an alias for a numerical type (usually an integer) representing the number of seconds since the Unix epoch (00:00:00 UTC on 1 January 1970).
-  time(&rawTime);: The time function gets the current calendar time and stores it as a time_t object in rawTime. Essentially, it captures the current time in seconds since the Unix epoch.
- struct tm timeInfo;: Declares a variable timeInfo of type struct tm, which is a structure that holds the broken-down time (year, month, day, hour, minute, second, etc.).
- gmtime_s(&timeInfo, &rawTime); : The gmtime_s function converts the time_t value pointed to by rawTime to a tm structure representing the corresponding UTC time.The result is stored in the timeInfo structure.

## OnbuttonclockUploadCsv
//std::unique_ptr<sql::PreparedStatement>: This creates a unique pointer to a sql::PreparedStatement object.Using a unique pointer ensures that the prepared statement will be automatically destroyed when it goes out of scope, preventing memory leaks.
//	con->prepareStatement("SELECT * FROM leadlocking") : This method prepares an SQL statement to select all columns from the leadlocking table.
//	con : This is a pointer to an active database connection.
//	prepareStatement : This method is used to create a precompiled SQL statement.The statement can be executed multiple times more efficiently than executing the same query string each time.
//	"SELECT * FROM leadlocking" : This SQL query selects all records from the leadlocking table.You can adjust this query as needed to select specific columns or filter records.
//	Executing the SQL Query
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
