#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h> // For getch()

using namespace std;

class Student {
public:
    string name, mobile, course, branch;
    int rollno;

    void inputStudent() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Mobile Number: ";
        getline(cin, mobile);
        cout << "Enter Roll No: ";
        cin >> rollno;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
        cout << "Enter Branch: ";
        getline(cin, branch);
    }

    void displayStudent() const {
        cout << "Name: " << name << "\nMobile: " << mobile
             << "\nRoll No: " << rollno << "\nCourse: " << course
             << "\nBranch: " << branch << endl;
    }
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void add() {
    ofstream file("Record.txt", ios::app);
    Student student;
    cin.ignore(); // Flush the input buffer
    student.inputStudent();
    file << student.rollno << "|" << student.name << "|" << student.mobile
         << "|" << student.course << "|" << student.branch << endl;
    cout << "Record added successfully!" << endl;
    file.close();
}

void view() {
    ifstream file("Record.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void search() {
    ifstream file("Record.txt");
    string line;
    int rollno;
    bool found = false;

    cout << "Enter Roll No to search: ";
    cin >> rollno;
    cin.ignore();

    while (getline(file, line)) {
        size_t pos = line.find('|');
        int fileRollNo = stoi(line.substr(0, pos));
        if (fileRollNo == rollno) {
            cout << "Record Found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found with Roll No " << rollno << endl;
    }
    file.close();
}

void modify() {
    ifstream file("Record.txt");
    ofstream temp("Temp.txt");
    string line;
    int rollno;
    bool found = false;

    cout << "Enter Roll No to modify: ";
    cin >> rollno;
    cin.ignore();

    while (getline(file, line)) {
        size_t pos = line.find('|');
        int fileRollNo = stoi(line.substr(0, pos));
        if (fileRollNo == rollno) {
            found = true;
            Student student;
            cout << "Enter new details for Roll No " << rollno << ":\n";
            student.inputStudent();
            temp << student.rollno << "|" << student.name << "|" << student.mobile
                 << "|" << student.course << "|" << student.branch << endl;
        } else {
            temp << line << endl;
        }
    }
    if (!found) {
        cout << "No record found with Roll No " << rollno << endl;
    }
    file.close();
    temp.close();

    remove("Record.txt");
    rename("Temp.txt", "Record.txt");

    if (found) {
        cout << "Record modified successfully!" << endl;
    }
}

void deleterec() {
    ifstream file("Record.txt");
    ofstream temp("Temp.txt");
    string line;
    int rollno;
    bool found = false;

    cout << "Enter Roll No to delete: ";
    cin >> rollno;
    cin.ignore();

    while (getline(file, line)) {
        size_t pos = line.find('|');
        int fileRollNo = stoi(line.substr(0, pos));
        if (fileRollNo == rollno) {
            found = true;
            continue; // Skip writing this record to the temp file
        }
        temp << line << endl;
    }
    if (!found) {
        cout << "No record found with Roll No " << rollno << endl;
    } else {
        cout << "Record deleted successfully!" << endl;
    }

    file.close();
    temp.close();

    remove("Record.txt");
    rename("Temp.txt", "Record.txt");
}

void Raise_Query() {
    ofstream queryFile("Query.txt", ios::app);
    string name, query;
    char choice = 'y';

    while (choice == 'y') {
        cin.ignore();
        cout << "What is your name? ";
        getline(cin, name);
        cout << "Write your query: ";
        getline(cin, query);

        queryFile << name << " : " << query << endl;

        cout << "Want to enter more queries? (y/n): ";
        cin >> choice;
    }
    queryFile.close();
}

void Resolve_Query() {
    ifstream queryFile("Query.txt");
    ofstream solutionFile("Solution.txt", ios::app);
    string query, solution;
    int i = 1;

    while (getline(queryFile, query)) {
        cout << i << " query is: " << query << "\nWrite down your reply: ";
        cin.ignore();
        getline(cin, solution);

        solutionFile << solution << endl;
        i++;
    }
    queryFile.close();
    solutionFile.close();
}

void Resolved_Queries() {
    ifstream solutionFile("Solution.txt");
    string line;

    while (getline(solutionFile, line)) {
        cout << line << endl;
    }
    solutionFile.close();
}

void print_queries() {
    ifstream queryFile("Query.txt");
    string line;

    while (getline(queryFile, line)) {
        cout << line << endl;
    }
    queryFile.close();
}

void Admin_login() {
    string userId, password;
    int attempts = 0;

    while (attempts < 3) {
        system("cls");
        cout << "USER ID: ";
        cin >> userId;
        cout << "PASSWORD: ";
        password = "";

        char ch;
        while ((ch = getch()) != 13) { // 13 is Enter key
            password += ch;
            cout << '*';
        }

        if (userId == "1234" && password == "1234") {
            cout << "\nLogin Successful!" << endl;
            return;
        } else {
            cout << "\nInvalid Username or Password!\n";
            attempts++;
        }
    }
    exit(0);
}

void menu() {
    system("cls");
    cout << "Want to login as Faculty or Student?\n";
    cout << "Enter 1 for Faculty, 0 otherwise: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Admin_login();

        while (true) {
            system("cls");
            cout << "<--MENU-->\n";
            cout << "1: Add Record\n2: View Record\n3: Search Record\n4: Modify Record\n";
            cout << "5: Delete Record\n6: Print Queries\n7: Resolve Query\n8: Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: add(); break;
                case 2: view(); break;
                case 3: search(); break;
                case 4: modify(); break;
                case 5: deleterec(); break;
                case 6: print_queries(); break;
                case 7: Resolve_Query(); break;
                case 8: exit(0); break;
                default: cout << "Invalid Choice.\n";
            }
        }
    } else {
        while (true) {
            system("cls");
            cout << "1: Search Record\n2: Raise Query\n3: View Resolved Queries\n4: Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: search(); break;
                case 2: Raise_Query(); break;
                case 3: Resolved_Queries(); break;
                case 4: exit(0); break;
                default: cout << "Invalid Choice.\n";
            }
        }
    }
}

int main() {
    system("cls");
    system("color 74");
    gotoxy(45, 5);
    cout << "<--:Student Record Management System:-->\n";
    gotoxy(1, 30);
    cout << "Press any key to continue.";
    getch();
    menu();
    return 0;
}
