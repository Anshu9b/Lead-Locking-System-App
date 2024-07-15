# Task 1- Lead-Locking-System-App
## Overview- I need to create a leadlocking form with login and create account option as authentication.
## Fields that are provided in the Leadlocking Form -
- ProspectName -> not null;
- Address -> not null;
- StreetAddress  -> not null;
- AddressLine2;
- City;
- State;
- PhoneNumber;
- Email;
- FirstName;
-LastName;
- GSTNumber -> Validated using GSTIN Validator API using lookup in the schema;
- Website;
- SolidCAMOffice;
- SolidCAMSalesperson;
- Country;
- Reseller;
- DateTime;
- DateTime2;
- pStaticImage;
## MFC OVERVIEW AND HISTORY -
It was 1992, and Windows was still running as a 16bit operating system layered on top of MS-DOS when Microsoft introduced its Microsoft Foundation Classes (MFC) to developers. Most applications for Windows had previously been written in C, but C++ was starting to take off, and the C++ developers were craving an object-oriented way of developing Windows applications, to match the ease of VB, which had been released a year earlier, but with the flexibility of C / C++.

Back then, Microsoft’s C++ compiler did not have exception handling, templates, nor did it have a standard library of containers and algorithms that took advantage of the C++ language features. As such, MFC used macros to emulate templates and exceptions and created its own set of containers for generic concepts such as strings, arrays, lookup maps and more. Well beyond the brief of object-oriented and easier access the Windows APIs.

## Sprint
## Day 1 -(21/06/24)
1.MFC Dialog MSDN Docs read.<br/>
2.Steps needed in VS Code to setup a CDialog for First authentication page.
3.Control Management button added
4.Worked on further occured errors 

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

# Creating Modal Dialog boxes in MFC
To create a modal dialog box, call either of the two public constructors declared in CDialog. Next, call the dialog object's DoModal member function to display the dialog box and manage interaction with it until the user chooses OK or Cancel. This management by DoModal is what makes the dialog box modal. For modal dialog boxes, DoModal loads the dialog resource.
# Usage in Lead Locking form 
![image](https://github.com/user-attachments/assets/2128da38-cad0-4040-8b52-4cceacbf6749)

4.Worked on further occured errors 

## Day 3- (23/06/24)
1. Warpped up the user_login dialog box.
2. Started Linking the create account button using modal dialog with userlogin dialog page.
3. Further resolved errors occured

## KeyNotes
- CDialogEx why used and not why CDialog dialog box.
- Difference between GetDlgItem, GetDlgItemText,GetWindowText and GetWindowTextLength
- Usage of CString , CStringA, std:: string

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
  
- #include <mysql_driver.h>
- #include <mysql_connection.h>
- #include <cppconn/resultset.h>
- #include <cppconn/statement.h>
- #include <cppconn/prepared_statement.h>
- Mysql Variables initializations
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
bool CUserRegistrationSystem2Dlg::ConnectToDatabase() {
- Return Type: bool - Indicates whether the connection to the database was successful (true) or not (false).
- Class Scope: CUserRegistrationSystem2Dlg:: - This function is a member of the - 
 CUserRegistrationSystem2Dlg class.

## Variable Declaration and Initialization
- sql::mysql::MySQL_Driver* driver
- sql::mysql::get_mysql_driver_instance(); 
- sql::mysql::MySQL_Driver* driver: Declares a pointer to a MySQL_Driver instance.
- sql::mysql::get_mysql_driver_instance(): Static method that returns a pointer to the MySQL driver singleton instance. This driver is necessary for connecting to a MySQL database.
## Establishing Connection
- con = std::unique_ptr<sql::Connection>(driver->connect("tcp://127.0.0.1:3306", "root", "Missspacegirl@09"));
con: Assumes con is a member variable of type
- std::unique_ptr<sql::Connection>, which manages the database connection.
- driver->connect("tcp://127.0.0.1:3306", "root", "Missspacegirl@09"): Establishes a connection to the MySQL server at the specified address (127.0.0.1:3306). The connect method requires:
- The server address (tcp://127.0.0.1:3306).
- The username (root).
- The password (Missspacegirl@09).
- Setting the Database Schema 
- con->setSchema("user_register");
- con->setSchema("user_register"): Sets the default schema (database) for the connection to user_register. This means all subsequent SQL queries will operate within the user_register database unless specified otherwise.
- Returning Success
return true;
If all previous operations are successful, the function returns true, indicating the connection was successful.
-Exception Handling
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
 ![image](https://github.com/user-attachments/assets/f20d0fcc-8b5c-44a8-a61a-37534425238a)
3. OnClickedButtonSubmit()
![image](https://github.com/user-attachments/assets/6ac7a404-9cbb-4d6c-a556-1b647c2e0f51)

## Purpose
The function DoesUserExist checks if a user with the specified username and password exists in the database.
- bool CUserRegistrationSystem2Dlg::DoesUserExist() {
Return Type: bool - Indicates whether the user exists (true) or not (false).
### Common For all Dialog Boxes- CUserRegistrationDlg, CCreateAccountDlg, CCLeadLockingDlg
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
- con->prepareStatement(...): Prepares the SQL statement with placeholders (?) for the username and password parameters to prevent SQL injection.
- Setting Parameters and Executing the Query
    CStringA usernameA(Username);
    CStringA passwordA(Password);
    pstmt->setString(1, std::string(usernameA));
    pstmt->setString(2, std::string(passwordA));
    res.reset(pstmt->executeQuery());
- CStringA usernameA(Username);: Converts Username (assumed to be a CString member variable) to CStringA (ANSI string).
- CStringA passwordA(Password);: Converts Password (assumed to be a CString member variable) to CStringA (ANSI string).
- pstmt->setString(1, std::string(usernameA));: Sets the first parameter (username) of the prepared statement.
- pstmt->setString(2, std::string(passwordA));: Sets the second parameter (password) of the prepared statement.
- res.reset(pstmt->executeQuery());: Executes the query and stores the result in res.
return res->next();
res->next(): Advances the cursor to the next row in the result set. If a row exists, it returns true, indicating the user was found. If no rows are returned, it returns false.
### Step 3: Exception Handling
} catch (sql::SQLException& e) {
    CString errorMessage;
    errorMessage.Format(_T("Query execution failed: %S"), e.what());
    AfxMessageBox(errorMessage);
    return false;
}
catch (sql::SQLException& e): Catches any sql::SQLException that might be thrown during the execution of the SQL query.
-Error Message: Formats an error message with the exception details and displays it using AfxMessageBox.
-Return False: If an exception occurs, the function returns false.
Summary
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
catch (sql::SQLException& e) {
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
   -  ProspectName -> not null;
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
### OverView of Combo Box and implementation- 
A combo box consists of a list box combined with either a static control or edit control. it is represented by CComboBox class. The list-box portion of the control may be displayed at all times or may only drop down when the user selects the drop-down arrow next to the control.

- Initialization
CBN_SELCHANGE	ON_CBN_SELCHANGE( <id>, <memberFxn> )	The selection in the list box of a combo box is about to be changed as a result of the user either clicking in the list box or changing the selection by using the arrow keys.
![image](https://github.com/user-attachments/assets/5383bceb-a9e2-40bb-a7e4-650628216f26)
- Static Text
A static control displays a text string, box, rectangle, icon, cursor, bitmap, or enhanced metafile. It is represented by CStatic class. It can be used to label, box, or separateother controls. A static control normally takes no input and provides no output.

### 

Date & Time Picker
The date and time picker control (CDateTimeCtrl) implements an intuitive and recognizable method of entering or selecting a specific date. The main interface of the control is similar in functionality to a combo box. However, if the user expands the control, a month calendar control appears (by default), allowing the user to specify a particular date. When a date is chosen, the month calendar control automatically disappears.

  

 
