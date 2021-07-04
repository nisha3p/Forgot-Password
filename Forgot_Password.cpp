#include<iostream>
#include<windows.h>
#include <fstream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;
int heading_color=4;
int output_color=6;
int default_color=7;

/* List of All the Functions*/
int Entry();
bool IsLoggedIn();
int CheckEntry();
int Home(int);
int Add_New_Pass(int);
int Ret_Pass(int);

/*Main Username and Password*/
string Name, PassCode;
string un, pw;

int Entry()
{
    int id=0;
    int i;
    clrscr();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
    for (i = 0; i < 73; i++)
    {
        printf("-");
    }
    printf(" Forgot Password ");
    for (i = 0; i < 73; i++)
    {
        printf("-");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);
    CheckEntry();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return id;
}

bool IsLoggedIn()
{
    cout << "Enter Username: ";
    cin >> Name;
    cout << "Enter Password: ";
    cin >> PassCode;
    ifstream read(Name + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == Name && pw == PassCode)
        return true;
    else
        return false;
}

int CheckEntry()
{
    int ans;
    cout<<"\n\tSelect:\n\t1 - Login\n\t2 - SignUp\n\t";
    cin>>ans;
    while(ans!=1&&ans!=2)
    {
        cout<<"Invalid Choice, Please select again.\n";
        cin>>ans;
    }
    if(ans==1)
    {
        bool status = IsLoggedIn();
        if (!status)
        {
            cout << "Invalid Login Details, Please Try again." << endl;
            CheckEntry();
        }
        else
        {
            cout << "Successfully logged in!" << endl;
            system("PAUSE");
        }
    }
    else
    {
        cout << "Set a Username: ";
        cin >> Name;
        cout << "Set a Password: ";
        cin >> PassCode;
        ofstream file;
        file.open(Name +".txt");
        file << Name << endl
             << PassCode;
        file.close();
        CheckEntry();
    }
    return 0;
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
    int choice;
    printf("\n\tSelect:\n\t1 - Add new entry\n\t2 - Retrieve Password\n\t3 - Exit\n\t");
    cin>>choice;
    while(choice>3||choice<1)
    {
        cout<<"Invalid input, please try again\n";
        cin >> choice;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return choice;
}

int Add_New_Pass(int id)
{
    int i;
    /*Add New Password*/
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for (i = 0; i < 170; i++)
    {
        printf("-");
    }
    printf("\n Add New Password \n");
    for (i = 0; i < 170; i++)
    {
        printf("-");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);
    string Service, U_Name, Pass; //Temp - Replace with SQL var
    cout<<"\n\n\tService: ";
    cin>>Service;
    cout << "\n\tUsername: ";
    cin>>U_Name;
    cout << "\n\tPassword: ";
    cin >> Pass;   
    /*Trial*/
    ofstream file;
    file.open(un + "Credentials" + ".txt", ios_base::app);
    file << Service << endl
         << U_Name << endl
         << Pass <<endl;
    file.close();
    cout<<"\n\tS="<<Service<<" U="<<U_Name<<" P="<<Pass;
    char Ans;
    cout << "\n\n\t Do you want to add another service? (Y/N): ";
    cin >> Ans;
    while (Ans != 'y' && Ans != 'Y' && Ans != 'n' && Ans != 'N')
    {
        cout << "\n\tInvalid Service Name, Please try again!";
        cout << "\n\n\tDo you want to add another service? (Y/N): ";
        cin >> Ans;
    }
    if (Ans == 'y' || Ans == 'Y')
    {
        Add_New_Pass(id);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for (i = 0; i <170; i++)
    {
        printf("-");
    }
    printf("\n Retrieve Password \n");
    for (i = 0; i < 170; i++)
    {
        printf("-");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);

    /* Print Table*/
    cout<<"\n\tTable will be printed here\n";
    
    searching:
    cout<<"\n\tEnter the Serial Number here: ";
    int serial_no;
    string serve,uname,pass;
    cin>>serial_no;

    /*Search from The table*/
    //ncout<<"\n\tHere it will search the serial No. from the table and show:\n";
    ifstream read(un+"Credentials"+".txt");
    getline(read, serve);
    getline(read, uname);
    getline(read, pass);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), heading_color);
    for (i = 0; i < 150; i++)
    {
        printf("*");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), output_color);

    //string Server="Server", U_Name="Temp_Username", Pass="Temp_Password"; //Temp - Replace with SQL var
    cout<<"\n\tServer: "<<serve;
    cout << "\n\t\tUsername: "<<uname;
    cout << "\n\t\tPassword: "<<pass;

    char Ans;
    cout<<"\n\n\tDo you want to search for another Service (Y/N): ";
    cin>>Ans;
    while(Ans!='y'&&Ans!='Y'&&Ans!='n'&&Ans!='N')
    {
        cout<<"\n\tInvalid Service Name, Please try again!";
        cout << "\n\n\t Search for another Service (Y/N): ";
        cin >> Ans;
    }
    if(Ans=='y'||Ans=='Y')
    {
        goto searching;
    }
    else if(Ans=='n'||Ans=='N')
    {
        Home(id);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), default_color);
    return 0;
}

int main()
{
    int id;
    int choice;
    id=Entry();
    choice=Home(id);
    if(choice==1)
    {
        Add_New_Pass(id);
    }
    else if(choice==2)
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