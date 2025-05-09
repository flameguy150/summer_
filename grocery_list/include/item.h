#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <istream>
#include <vector>

class Item
{
public:
    Item() : code(0), name(""), company("") {}
    Item(int code_, std::string name_, std::string company_) : code(code_), name(name_), company(company_) {}
    int getCode() const { return code; }
    std::string getName() const { return name; }
    std::string getCompany() const { return company; }

    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
    Item &operator=(const Item &other);

private:
    int code;
    std::string name;
    std::string company;
};

std::ostream &operator<<(std::ostream &os, const Item &item);
std::istream &operator>>(std::istream &is, Item &item);

#endif