#include <iostream>
#include <vector>
#include "item.h"

// classes to implement
// add, delete, display item
// check, update item

class dept
{

public:
    void control_panel();
    void add_item();
    void display_items();

private:
    std::vector<Item> store;
};
