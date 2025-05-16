#include <iostream>
#include <vector>
#include "item.h"

// classes to implement
// add, delete, display item
// check, update item

class dept
{

public:
    void menu();
    void control_panel();
    void add_item();
    void display_items();
    void remove_item();

    bool esc_pressed();


    void saveData(const std::vector<Item> &store_, const std::string &filename);
    void grabData(std::vector<Item> &store_, const std::string &filename);

    void options_();
    std::vector<Item> store;

private:
};
