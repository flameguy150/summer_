#include <iostream>
#include <vector>

// classes to implement
// add, delete, display item
// check, update item

class dept
{
public:
    struct Item
    {
        int code;
        std::string name;
        std::string company;
        Item(int code_, std::string name_, std::string company_) : code(code_), name(name_), company(company_) {}
    };

    void control_panel();
    void add_item();

private:
    std::vector<std::string> store;
};
