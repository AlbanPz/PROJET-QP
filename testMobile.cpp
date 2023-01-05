#include "doctest.h"
#include "mobile.h"

TEST_CASE("Test du constructeur de Mobile") {
    int x = 2, y = 3;
    Mobile m {x, y};
    REQUIRE_EQ(m.x(), x);
    REQUIRE_EQ(m.y(), y);
}
