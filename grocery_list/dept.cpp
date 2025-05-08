#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "dept.h"

#define ESCAPE 27
using namespace std;

/*
control panel that spawns at beginning

*/
void dept::control_panel()
{
    system("cls");
    system("Color 0A");
    cout
        << "*********************************"
           "*********************************"
        << endl;

    cout << "\n\n\t\tDepartment Store Management System" << endl;

    cout << "\n\n\t\t\tControl Panel\n\n"
         << endl;

    cout << "*********************************"
            "*********************************\n\n"
         << endl;

    cout << "1. Add Item"
         << endl;
    cout << "2. Display Items"
         << endl;
    cout << "3. Check Specific Item"
         << endl;
    cout << "4. Remove Item"
         << endl;
    cout << "5. Exit (Press Escape)"
         << endl;

    cout << "\nChoose:" << endl;

    // user inputs option
    int option = 0;
    option = _getch();

    // pages
    if (option == '1') // add
    {
        add_item();
    }
    else if (option == ESCAPE) // exit
    {
        system("cls");
        return;
    }
    else
    {
        cout << "That is not a setting. Please enter a valid setting" << endl;
    }
}

/*
adding item to department store
this means you add the item code and name
and company name

data structure to hold item: vector of items? will probably need == operator

implement error detection (if im not lazy)
*/
void dept::add_item()
{
    system("cls");
    cout << "\t\t\t\tAdd Item" << endl;
    cout << "---------------------------------"
            "---------------------------------"
            "-----"
         << endl;
    // adding item
    // code
    int code_;
    cout << "Item Code: ";
    cin >> code_;
    cout << "\n---------------------------------"
            "---------------------------------"
            "-----\n"
         << endl;

    // item name
    string name_;
    cout << "Item Name: ";
    cin.ignore();
    getline(cin, name_);

    // company name
    string company_;
    cout << "\nCompany Name: ";
    getline(cin, company_);

    // quantity
    int quantity_;
    cout << "\nQuantity: ";
    cin >> quantity_;

    cout << "\n---------------------------------"
            "---------------------------------"
            "-----\n"
         << endl;

    // add item
    // push to store

    // menu cntrl + add more?
    char response;
    cout << "Would you like to add more items? (Y/N) ";
    cin.ignore();
    cin >> response;
    response = tolower(response);
    if (response == 'y')
    {
        add_item();
    }
    else if (response == 'n')
    {
        control_panel();
    }

    // user inputs option - this has its own problems tho
    // int option = 0;
    // option = _getch();

    // // controls
    // if (option == ESCAPE) // exit
    // {
    //     control_panel();
    // }
}