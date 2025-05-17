#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <istream>
#include <vector>

class Item
{
public:
    // empty constructor
    Item() : code(0), name(""), company(""), quantity(0) {}
    // no quantity // default constructor
    Item(int code_, std::string name_, std::string company_) : code(code_), name(name_), company(company_), quantity(0) {}
    // all parameters
    Item(int code_, std::string name_, std::string company_, int quantity_) : code(code_), name(name_), company(company_), quantity(quantity_) {}
    // copy constructor
    Item(const Item &other) : code(other.code), name(other.name), company(other.company) {}

    int getCode() const { return code; }
    std::string getName() const { return name; }
    std::string getCompany() const { return company; }
    int getQuantity() const { return quantity; }

    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
    Item &operator=(const Item &other);

private:
    int code;
    std::string name;
    std::string company;
    int quantity;
    double price;
};

std::ostream &operator<<(std::ostream &os, const Item &item);
std::istream &operator>>(std::istream &is, Item &item);

#endif