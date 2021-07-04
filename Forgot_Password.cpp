#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;
int heading_color = 4;
int output_color = 6;
int default_color = 7;

bool IsLoggedIn()
{
    string username, password, un, pw;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password)
        return true;
    else
        return false;
}

int Entry()
{
    int id;
    int i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
    for (i = 0; i < 150; i++)
    {
        printf("-");
    }
    printf(" \nForgot Password \n");
    for (i = 0; i < 150; i++)
    {
        printf("-");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);

    string Name, Pass; /*Temp*/
    printf("\n\tName (In All Caps):");
    cin >> Name;
    printf("\n\tPassword:");
    cin >> Pass;

    id = 1; /*Temp*/

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return id;
}

int Home(int id)
{
    int i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heading_color);
    for (i = 0; i < 150; i++)
    {
        printf("*");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);
    printf("\n\tSelect:\n\t1 - Add new entry\n\t2 - Retrieve Password\n\t3 - Exit\n\t");
aa:
    int choice;
    cin >> choice;
    while (choice > 3 || choice < 1)
    {
        cout << "Invalid input, please try again\n";
        cin >> choice;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return choice;
}

int Add_New_Pass(int id)
{
    int i;
    /*Add New Password*/
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heading_color);
    for (i = 0; i < 73; i++)
    {
        printf("-");
    }
    printf(" Add New Password ");
    for (i = 0; i < 73; i++)
    {
        printf("-");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);
    string Service, U_Name, Pass; //Temp - Replace with SQL var
    cout << "\n\n\tService: ";
    cin >> Service;
    cout << "\n\tUsername: ";
    cin >> U_Name;
    cout << "\n\tPassword: ";
    cin >> Pass;
    /*Trial*/
    cout << "\n\tS=" << Service << " U=" << U_Name << " P=" << Pass;

adding:
    char Ans;
    cout << "\n\n\t Search for another answer (Y/N): ";
    cin >> Ans;
    while (Ans != 'y' && Ans != 'Y' && Ans != 'n' && Ans != 'N')
    {
        cout << "\n\tInvalid Answer, Please try again!";
        cout << "\n\n\t Search for another answer (Y/N): ";
        cin >> Ans;
    }
    if (Ans == 'y' || Ans == 'Y')
    {
        goto adding;
    }
    else if (Ans == 'n' || Ans == 'N')
    {
        Home(id);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return 0;
}

int Ret_Pass(int id)
{
    int i;
    /*Retrieve Password*/
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heading_color);
    for (i = 0; i < 150; i++)
    {
        printf("-");
    }
    printf("\n Retrieve Password \n");
    for (i = 0; i < 150; i++)
    {
        printf("-");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);

    /* Print Table*/
    cout << "\n\tTable will be printed here\n";

searching:
    cout << "\n\tEnter the Serial Number here: ";
    int serial_no;
    cin >> serial_no;

    /*Search from The table*/
    cout << "\n\tHere it will search the serial No. from the table and show:\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heading_color);
    for (i = 0; i < 150; i++)
    {
        printf("*");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);

    string Server = "Server", U_Name = "Temp_Username", Pass = "Temp_Password"; //Temp - Replace with SQL var
    cout << "\n\tServer: " << Server;
    cout << "\n\t\tUsername: " << U_Name;
    cout << "\n\t\tPassword: " << Pass;

    char Ans;
    cout << "\n\n\t Search for another answer (Y/N): ";
    cin >> Ans;
    while (Ans != 'y' && Ans != 'Y' && Ans != 'n' && Ans != 'N')
    {
        cout << "\n\tInvalid Answer, Please try again!";
        cout << "\n\n\t Search for another answer (Y/N): ";
        cin >> Ans;
    }
    if (Ans == 'y' || Ans == 'Y')
    {
        goto searching;
    }
    else if (Ans == 'n' || Ans == 'N')
    {
        Home(id);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return 0;
}

int main()
{
    int id = 0;
    int choice, login;
    cout << "1: Register\n2: Login\nYour Choice: ";
    cin >> login;
    if (login == 1)
    {
        string username, password;
        cout << "select a username: ";
        cin >> username;
        cout << "select a password: ";
        cin >> password;
        ofstream file;
        file.open(username + ".txt");
        file << username << endl
             << password;
        file.close();
        main();
    }
    else if (login == 2)
    {
        bool status = IsLoggedIn();
        if (!status)
        {
            cout << "False Login Details!" << endl;
            main();
        }
        else
        {
            cout << "Successfully logged in!" << endl;
            system("PAUSE");
        }
    }
    id = Entry();
    choice = Home(id);
    if (choice == 1)
    {
        Add_New_Pass(id);
    }
    else if (choice == 2)
    {
        Ret_Pass(id);
    }
    else
    {
        goto exit;
    }
exit:
    return 0;
}