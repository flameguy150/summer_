#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
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
holds all options in control panel
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
    else if (option == '3')
    {
        find_item();
    }
    else if (option == '4')
    {
        remove_item();
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
            }
            else if (input == '2')
            {
                display_items();
            }
            else if (input == '3')
            {
                find_item();
            }
            else if (input == '4')
            {
                remove_item();
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
    system("Color 0A");
    int choice;

    while (true)
    {
        cout << "\t\tMenu" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Load Data from File" << endl;
        cout << "2. Save Data to File" << endl;
        cout << "3. Manage Store (Control Panel)" << endl;
        cout << "4. Exit (Press ESC)" << endl;
        // cin >> choice;
        choice = _getch();

        switch (choice)
        {

        case '1': // load data
        {
            string filename;
            cout << "Enter filename to load: ";
            cin >> filename;
            cout << "\nLoading..." << endl;
            grabData(store, filename);
            cout << "Data loaded in" << endl;
            break;
        }

        case '2': // save data
        {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            cout << "\nLoading..." << endl;
            saveData(store, filename);
            cout << "Data saved" << endl;
            break;
        }

        case '3': // control panel
        {
            control_panel();
            break;
        }

        case ESCAPE:
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
Function so that i can exit to cntrl panel during functions
i think we need to just need to grab input from this function
*/
bool dept::esc_pressed()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == ESCAPE)
        {
            return true;
        }
    }
    return false;
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
    if (esc_pressed())
    {
        control_panel();
    }
    cout << "\n---------------------------------"
            "---------------------------------"
            "-----\n"
         << endl;

    // item name
    string name_;
    cout << "Item Name: ";
    cin.ignore();
    getline(cin, name_);
    if (esc_pressed())
    {
        return;
    }

    // company name
    string company_;
    cout << "\nCompany Name: ";
    getline(cin, company_);
    if (esc_pressed())
    {
        return;
    }

    // quantity
    int quantity_;
    cout << "\nQuantity: ";
    cin >> quantity_;
    if (esc_pressed())
    {
        return;
    }

    cout << "\n---------------------------------"
            "---------------------------------"
            "-----\n"
         << endl;

    // add item && push to store
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
    if (store.size() == 0)
    {
        cout << "You have no items in your inventory." << endl;
        cout << "\nPlease press (ESC) to exit." << endl;
        int option = 0;
        option = _getch();
        if (option == ESCAPE)
        {
            control_panel();
        }
    }
    else
    {

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
}

/*
Finding specific item
Search by Name or Commpany or Code
*/
void dept::find_item()
{
    system("cls");
    cout << "\t\t\tFind Item" << endl;
    cout << "---------------------------------"
            "---------------------------------"
            "-----"
         << endl;

    cout << "How would you like to find your specific item?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Company" << endl;
    cout << "3. Code" << endl;

    int index;
    cin >> index;
    if (index == 1)
    {
    }
    else if (index == 2)
    {
    }
    else if (index == 3)
    {
        cout << "---------------------------------"
                "---------------------------------"
                "-----\n"
             << endl;
        cout << "Type in the code for your item: " << endl;
        int code;
        cin >> code;
        Item item;
        for (size_t i = 0; i < store.size(); ++i)
        {
            item = store[i];
            if (item.getCode() == code)
            {
                cout << "Found it! Your item:" << endl;
                cout << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Company: "
                     << item.getCompany() << endl;
                cout << "Would you like to find another item? (Y/N) " << endl;
                char response;
                cin.ignore();
                cin >> response;
                response = tolower(response);
                if (response == 'y')
                {
                    find_item();
                }
                else if (response == 'n')
                {
                    control_panel();
                }
            }
        }
        // if item not found
        cout << "Item is not in inventory." << endl;
        cout << "Would you like to search again? (Y/N) " << endl;
        char response;
        cin.ignore();
        cin >> response;
        response = tolower(response);
        if (response == 'y')
        {
            find_item();
        }
        else if (response == 'n')
        {
            control_panel();
        }
    }
}

/*
function for removing item from inventory
remove item - removing item from list
- I want to display all items and let them choose which one to
      delete

*/
void dept::remove_item()
{
    system("cls");
    cout << "\t\t\t   Deleting Item" << endl;
    cout << "---------------------------------"
            "---------------------------------"
            "-----"
         << endl;

    if (store.size() == 0)
    {
        cout << "You have no items in your inventory." << endl;
        cout << "\nPlease press (ESC) to exit." << endl;
        int option = 0;
        option = _getch();
        if (option == ESCAPE)
        {
            control_panel();
        }
    }

    else
    {
        Item item;
        for (size_t i = 0; i < store.size(); ++i)
        {
            // os << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Company: " << item.getCompany();
            item = store[i];
            cout << i << ". " << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Company: "
                 << item.getCompany() << endl;
        }
        cout << "Which item would you like to remove?" << endl;
        int index;
        cin >> index;

        // delete item that is at store[index]
        // change response based on if item exists
        Item removed_ = store[index];
        string question = "";
        auto it = find(store.begin(), store.end(), removed_);
        if (it != store.end())
        {
            store.erase(store.begin() + index);
            question = "Would you like to removed more items? (Y/N) ";
            cout << "Successfully removed " << removed_ << "!\n\n"
                 << endl;
        }
        else
        {
            question = "Would you like to try again? (Y/N) ";
            cout << "Item does not exist" << endl;
        }

        //
        // menu cntrl + add more?
        char response;
        cout << question;
        cin.ignore();
        cin >> response;
        response = tolower(response);
        if (response == 'y')
        {
            remove_item();
        }
        else if (response == 'n')
        {
            control_panel();
        }
    }
}
