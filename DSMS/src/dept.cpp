#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include "dept.h"

#define ESCAPE 27
using namespace std;

/*
saving data so program can retain items everytime on open
*/
void dept::saveData(const vector<Item> &store_, const string &filename)
{
    // ofstream used to write to files
    ofstream file(filename);
    if (file.is_open())
    {
        for (size_t i = 0; i < store_.size(); ++i)
        {
            file << store_[i] << endl;
        }
        file.close();
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}

/*
loading saved data
*/
void dept::grabData(vector<Item> &store_, const string &filename)
{
    // ifstream used to read from flies
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing." << endl;
    }

    Item temp;
    while (file >> temp)
    {
        store_.push_back(temp);
    }
    file.close();
}

/*
helper function to organize code
*/
void dept::options_()
{
    int option = 0;
    option = _getch();

    // pages
    if (option == '1') // add
    {
        add_item();
    }
    else if (option == '2')
    {
        display_items();
    }
    else if (option == ESCAPE) // exit
    {
        system("cls");
        return;
    }
    else
    {
        while (true)
        {
            char input = _getch();
            if (input == '1') // add
            {
                add_item();
                break;
            }
            else if (input == '2')
            {
                display_items();
                break;
            }
            else if (input == ESCAPE) // exit
            {
                menu();
            }
        }
    }
}

void dept::menu()
{
    system("cls");
    int choice;

    while (true)
    {
        cout << "\t\tMenu" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Load Data from File" << endl;
        cout << "2. Save Data to File" << endl;
        cout << "3. Manage Store (Control Panel)" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1: // load data
        {
            string filename;
            cout << "Enter filename to load: ";
            cin >> filename;
            cout << "\nLoading..." << endl;
            grabData(store, filename);
            cout << "Data loaded in" << endl;
            break;
        }

        case 2: // save data
        {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            cout << "\nLoading..." << endl;
            saveData(store, filename);
            cout << "Data saved" << endl;
            break;
        }

        case 3: // control panel
        {
            control_panel();
            break;
        }

        case 4:
        {
            system("cls");
            return;
        }

        default:
            cout << "Please press a valid option" << endl;
        }
    }
}

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
    options_();
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
    Item current(code_, name_, company_, quantity_);
    store.push_back(current);

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

void dept::display_items()
{
    system("cls");
    cout << "\t\t\tDisplaying Items" << endl;
    cout << "---------------------------------"
            "---------------------------------"
            "-----"
         << endl;
    Item item;
    for (size_t i = 0; i < store.size(); ++i)
    {
        // os << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Company: " << item.getCompany();
        item = store[i];
        cout << i << ". " << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Company: "
             << item.getCompany() << endl;
    }
    cout << "\n\nPress Esc to exit to main menu!";

    // menu cntrl + add more?
    int option = 0;
    option = _getch();

    if (option == ESCAPE)
    {
        control_panel();
    }
    else
    {
        // try again, dont let other buttons push
        cout << "\nPlease press Escape to return to the main menu" << endl;
        while (true)
        {
            char input = _getch();
            if (input == ESCAPE)
            {
                control_panel();
                break;
            }
            else
            {
                cout << "Please press Escape to return to the main menu" << endl;
            }
        }
    }
}
