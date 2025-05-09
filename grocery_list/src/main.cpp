#include <iostream>
#include <fstream>
#include <string>
#include "dept.h"
// Department Store Management System (DSMS)
// First clear out terminal

using namespace std;

void saveData(const vector<Item> &store_, const string &filename)
{
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

void grabData(std::vector<Item> &store_, const string &filename)
{
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

int main()
{
    dept d;
    d.control_panel();

    return 1;
}