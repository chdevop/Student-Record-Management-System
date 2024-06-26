Student Records Management System
Overview
The Student Records Management System is a console-based application developed in C++ to facilitate efficient management of student data within educational institutions. It provides functionalities for administrators to add, view, update, and delete student records stored in a CSV file format.

Features
Admin Authentication: Secure login mechanism for administrators to access the system.
Data Operations:
Add Records: Input and store student details including roll number, name, college, branch, attendance, and subject marks.
View Records: Display all student records with detailed information.
Delete Records: Remove specific student records based on roll number.
User Interface: Simple command-line interface (CLI) with clear prompts and user-friendly interactions.
File Handling: Utilizes fstream library for handling CSV files, ensuring data integrity and accessibility.
Technologies Used
Language: C++
Libraries: <fstream>, <iostream>, <string>, <sstream>, <vector>
Operating System: Windows (for system("cls") and Sleep() functions)
Usage
Compilation: Compile the source code (main.cpp) using a C++ compiler.
Execution: Run the executable file (main.exe).
Login: Choose between Admin or Student login.
Admin Functions:
Add, view, delete, or update student records.
Navigate through the menu for desired operations.
Student Functions:
View all student records.
Exit to the main menu after viewing.
Future Enhancements
Implement update functionality to modify existing student records.
Enhance user interface with more interactive features.
Integrate database support for scalable data management.
