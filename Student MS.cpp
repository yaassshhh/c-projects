/*
ADMIN USERNAME = " admin123 " PASSWORD = "12345 " 
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void mainmenu();     
void skipmainmenu(); 

class admin
{
    string username, password;
    int c;
    char d;

public:
    void registerStudent();               
    void deleteAllStudents();            
    void deleteStudentbyusername();       
    void checkListOfStudentsRegistered(); 

    void adminlogin()
    {
        cout << "\n                       ADMIN SECTION                         ";
        cout << "\n-------------------------------------------------------------";
        cout << "\n\n Enter username ";
        cin >> username;
        cout << "\n\n Enter password ";
        cin >> password;
        if (username != "admin123" && password != "12345")
        {
            cout << "\nINCORRECT PASSWORD OR USERNAME ..";
            skipmainmenu(); 
        }
        else if (username == "admin123" && password == "12345")
        {

            cout << "\n 1. Register a Student";
            cout << "\n 2. Delete All students name registered";
            cout << "\n 3. Delete student by username";
            cout << "\n 4. Check List of Student registered by userame";
            int ch;
            cout << "\n\n\nEnter your choice \t\t";
            cin >> ch;
            switch (ch)
            {
            case 1:
                registerStudent();
                break;
            case 2:
                deleteAllStudents();
                break;
            case 3:
                deleteStudentbyusername();
                break;
            case 4:
                checkListOfStudentsRegistered();
                break;

            default:
                cout << "\n Invalid choice. Enter again ";
            }
        }
    }
} A;

void admin::registerStudent() 
{
    system("cls");
    char ch;
    cout << "\n ----- Form to Register Student ---- \n";

    string username, password, rollno, address, father, mother, name,s;
    cout<<"\n";
    getline(cin,s);
    cout << "\n Enter Name : ";
    getline(cin, name);
    cout << "\n Enter Username : ";
    getline(cin, username);
    cout << "\n Enter password : ";
    getline(cin, password);
    cout << "\n Enter rollno : ";
    getline(cin, rollno);
    cout << "\n Enter address : ";
    getline(cin, address);
    cout << "\n Enter father : ";
    getline(cin, father);
    cout << "\n Enter mother : ";
    getline(cin, mother);
    ifstream read;
    read.open("db.dat"); 

    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line)) 
        {
            if (line == username + ".dat")
            {
                recordFound = 1;
                break;
            }
        }
        if (recordFound == 1)
        {
            cout << "\n Username already Register. Please choose another username ";
            skipmainmenu(); 
        }
    }

    ofstream out; 
    out.open("db.dat", ios::app);
    out << username + ".dat"
        << "\n";
    out.close();

    ofstream out1;
    string temp = username + ".dat";
    out1.open(temp.c_str());
    out1 << " \n\nNAME       = " << name;
    out1 << " \n\nUSERNAME   = " << username;
    out1 << "\n\nPASSWORD    = " << password;
    out1 << "\n\nROLL NUMBER = " << rollno;
    out1 << "\n\nADDRESS     = " << address;
    out1 << "\n\nFATHER NAME = " << father;
    out1 << "\n\nMOTHER NAME = " << mother;
    out1.close();

    cout << "\n Student Registered Successfully !!";
    cout << "\n Want to registered more students Y or N \t";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        registerStudent();
    }
    else if (ch == 'n' || ch == 'N')
    {
        skipmainmenu();
    }
}

void admin ::deleteAllStudents() 
{
    char ch;
    cout << "\nARE YOU SURE TO DELETE ALL CONTENT ....y || n \t";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        ofstream file;
        file.open("db.dat", ios::out | ios::trunc);
        file.close();
        cout << "\nFILE CONTENT DELETE SUCCFULLY \t";
        skipmainmenu();
    }
    else if (ch == 'N' || ch == 'n')
    {
        skipmainmenu();
    }
}

void admin ::deleteStudentbyusername() 
{
    system("cls");
    char ch;
    string user;
    cout << "T\nENTER THE USERNAME  OF STUDENT \t";
    cin >> user;
    ifstream read;
    read.open("db.dat");

    if (read) 
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            if (line == user + ".dat")
            {
                recordFound = 1;
                cout << "ARE YOU SURE TO DELETE -> " << user << " <- FROM DATABASE..?";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    string user1 = user + ".dat";
                    remove(user1.c_str());

                    cout << "\n"
                         << user1 << " FILE DELETED SUCCFULLY \t";
                    skipmainmenu();
                }
                else if (ch == 'N' || ch == 'n')
                {
                    skipmainmenu();
                }
            }
        }

        if (recordFound == 0) 
        {
            char ch1;
            cout << "\n Username not  Register. Please choose another username ";
            cout << "\n PRESS N TO ENTER USERNAME AGAIN ELSE PRESS ANY OTHER KEY \t";
            cin >> ch1;
            if (ch1 == 'N' || ch1 == 'n')
            {
                deleteStudentbyusername();
            }
            else
            {
                system("cls");
                skipmainmenu();
            }
        }
    }
}
void admin ::checkListOfStudentsRegistered() 
{
    cout << "\n------LIST OF STUDENT REGISTERED-------\n";

    ifstream out;
    string output;
    out.open("db.dat");
    while (!out.eof())
    {

        out >> output;
        cout << output << endl;
    }
    skipmainmenu();
}

/**************************************************************/

class student 
{
    string username1, password1;

public:
    void studentlogin()
    {
        cout << "\n                     STUDENT SECTION                       ";
        cout << "\n-----------------------------------------------------------";
        cout << "\n\n Enter username ";
        cin >> username1;
        cout << "\n\n Enter password ";
        cin >> password1;
        system("cls");
        ifstream read1;
        read1.open("db.dat");

        if (read1)
        {
            int recordFound = 0;
            string line1;
            while (getline(read1, line1))
            {
                if (line1 == username1 + ".dat")
                {
                    recordFound = 1;
                    ifstream out;
                    string output;
                    /*out.open(username1 + ".dat");*/
                    while (!out.eof())
                    {

                        getline(out, output);
                        cout << output << endl;
                    }
                    skipmainmenu();
                }
            }
            if (recordFound == 0)
            {
                cout << "\n Username not Register. Please choose another username ";
                skipmainmenu();
            }
        }
    }

} s;

int main()
{
    mainmenu();

    return 0;
}

void mainmenu() 
{
    system("cls");
    int choice;
    cout << "\n\n********************************************";
    cout << "\n\n     -->  STUDENT MANAGMENT SYSTEM   <--     ";
    cout << "\n\n********************************************";

    cout << "\n\n\n    1. Admin login";
    cout << "\n    2. Student login";
    cout << "\n    3. Exit....";
    cout << "\n\n Enter your choice \t";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        A.adminlogin();
        break;
    case 2:
        s.studentlogin();
        break;
    case 3:
        char c;
        cout << "\n ARE YOU SURE TO EXIT....? \t ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            exit(0);
        }
        else if (c == 'n' || c == 'N')
        {
            mainmenu();
        }

    default:
        cout << "\n Invalid choice. Enter again ";
        mainmenu();
    }
}

void skipmainmenu() 
{
    int d;
    cout << "\n\n Press 1 key to go back to main menu..  \t";
    cin >> d;
    if (d == 1)
    {
        mainmenu();
    }
}

