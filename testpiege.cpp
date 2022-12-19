#include "doctest.h"
#include "piege.h"
#include <string>

TEST_CASE ("le pi�ge fonctionne")
{

SUBCASE("le constructeur fonctionne")
{
    piege p{0,3,10};
    SUBCASE("la position est correcte")
    {
    int x=0, y=3;
    REQUIRE_EQ(p.x(),x);
    REQUIRE_EQ(p.y(),y);
    }
    SUBCASE ("le nom est correcte")
    {
        std::string name = "pi�ge";
        REQUIRE_EQ(p.nom(),name);
    }
    SUBCASE ("la capacit� est correcte")
    {
        int capacite =10;
        REQUIRE_EQ(p.capacite(),capacite);
    }
}
SUBCASE("diminuer la capacit� est correcte")
{
    int cap = 8;
    piege p{1,2,cap};
    p.diminuerCapacite();
    REQUIRE_EQ(p.capacite(),cap-1);
}
}
