#include "item.h"

// keep it in item.cpp so function is not redefined in every other file
// const ensures item doesnt get modified
// & makes sure that item is not duplicated

bool Item::operator==(const Item &other) const
{
    return code == other.code &&
           name == other.name &&
           company == other.company;
}

bool Item::operator!=(const Item &other) const
{
    return code != other.code &&
           name != other.name &&
           company != other.company;
}

Item &Item::operator=(const Item &other)
{
    if (this != &other)
    {
        code = other.code;
        name = other.name;
        company = other.company;
    }
    return *this;
}

std::ostream &
operator<<(std::ostream &os, const Item &item)
{
    os << "Code: " << item.getCode() << ", Name: " << item.getName() << ", Company: " << item.getCompany();
    return os;
}

std::istream &operator>>(std::istream &is, Item &item)
{
    int code_;
    std::string name_;
    std::string company_;

    if (is >> code_ >> name_ >> company_)
    {
        item = Item(code_, name_, company_);
    }
    return is;
}