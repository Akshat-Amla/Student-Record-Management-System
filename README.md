# Student Record Management System

## Project Overview

The **Student Record Management System** is a command-line application designed to manage and maintain student records efficiently. This project supports a user-friendly interface for both faculty and students, enabling secure management and access to student data. Faculty can perform CRUD (Create, Read, Update, Delete) operations on student records, while students can view their records, raise queries, and review resolved queries.

---

## Key Features

### Faculty Module:
- **Add Records**: Faculty can add new student records, including details like name, mobile number, roll number, course, and branch.
- **View Records**: Display all stored student records.
- **Search Records**: Search for specific records by roll number.
- **Modify Records**: Update existing records with new information.
- **Delete Records**: Remove records for students who are no longer part of the system.
- **Query Management**:
  - View all student-raised queries.
  - Resolve queries and save responses.
- **Secure Login**: Faculty access is secured with a password-protected login system.

### Student Module:
- **Search Records**: Students can search for their records by roll number.
- **Raise Queries**: Students can raise queries about any academic or administrative concerns.
- **View Resolved Queries**: Access faculty responses to previously raised queries.

---

## Tech Stack

### Programming Language:
- **C++**

### Libraries and Tools:
1. **Standard Libraries**: 
   - `iostream` for input and output operations.
   - `fstream` for file handling (reading/writing records and queries).
   - `string` for managing student details and queries.
   - `vector` for dynamic data handling (if needed for future scalability).
2. **Console Features**:
   - `windows.h` for cursor positioning (`gotoxy`) and terminal styling.
   - `conio.h` for capturing masked input (secure password entry).
3. **File System**:
   - `Record.txt`: Stores student records in a `|`-separated format.
   - `Query.txt`: Stores student-raised queries.
   - `Solution.txt`: Stores faculty responses to queries.

---

## Benefits and Use Cases

- **Educational Institutes**: Manage large-scale student data efficiently.
- **Secure and Modular**: Segregated roles for faculty and students ensure data integrity.
- **User-Friendly**: Command-line interface for straightforward navigation.
- **Customizable**: Easily extendable to include additional features like report generation or analytics.

---

## Future Enhancements

- **GUI Integration**: Add a graphical interface for better usability.
- **Database Support**: Migrate from flat file storage to relational databases (e.g., MySQL, SQLite) for scalability.
- **Cloud Deployment**: Host the application on cloud platforms for accessibility across multiple locations.

---

This project is a robust and secure solution for educational institutions looking to modernize their student data management systems. 🎓
