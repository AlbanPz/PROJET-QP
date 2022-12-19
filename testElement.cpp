#include "doctest.h"
#include "element.h"
#include <string>

using std::string;

TEST_CASE("[Element] L'element est bien construit")
{
    string nom{"Lyon"};
    int x = 0, y = 0;
    Element e{nom, x, y};

    REQUIRE_EQ(nom, e.nom());
    REQUIRE_EQ(x, e.x());
    REQUIRE_EQ(y, e.y());
}
