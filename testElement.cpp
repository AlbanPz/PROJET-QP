#include "doctest.h"
#include "element.h"
#include "fauve.h"
#include <string>

using std::string;

TEST_CASE("[Element] L'element est bien construit")
{
    string nom{"Lion"};
    int x = 0, y = 0;
    Fauve f{nom, x, y, 10, 2};

    SUBCASE("Le nom de l'element est correct")
    {
        REQUIRE_EQ(f.nom(), nom);
    }

    SUBCASE("La position de l'element est juste")
    {
        REQUIRE_EQ(f.x(), x);
        REQUIRE_EQ(f.y(), y);
    }
}

TEST_CASE("[Element] Le changement de position est correct")
{
    string nom{"Lion"};
    int x = 0, y = 0;
    Fauve f{nom, x, y, 10, 2};
    f.changerPosition(x+1, y-1);

    REQUIRE_EQ(f.x(), x+1);
    REQUIRE_EQ(f.y(), y-1);
}

