#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "item.h"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("Example Test")
{
    CHECK(1 + 2 == 3);
}

TEST_CASE("First Test Case")
{
    string name_ = "pokemonCards";
    string company_ = "gameFreak";
    int code_ = 4;

    Item object1(code_, name_, company_);
    Item object2(code_, name_, company_);

    CHECK(object1 == object2);
}

TEST_CASE("!= operator")
{
    string name_ = "pokemonCards";
    string company_ = "gameFreak";
    int code_ = 4;
    int code_2 = 5;

    Item object1(code_, name_, company_);
    Item object2(code_2, name_, company_);

    CHECK(object1 != object2);
}

TEST_CASE("Item Copy")
{
    string name_ = "pokemonCards";
    string company_ = "gameFreak";
    int code_ = 4;

    Item object1(code_, name_, company_);
    Item copied = object1;

    CHECK(copied == object1);
}