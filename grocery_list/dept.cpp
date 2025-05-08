#include <iostream>
#include <cstdlib>
#include "dept.h"

using namespace std;

/*
control panel that spawns at beginning
*/
void dept::beginning()
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
            "*********************************"
         << endl;
}