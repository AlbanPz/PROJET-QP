#include "doctest.h"
#include "piege.h"
#include <string>

TEST_CASE ("le piège fonctionne")
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
        std::string name = "piège";
        REQUIRE_EQ(p.nom(),name);
    }
    SUBCASE ("la capacité est correcte")
    {
        int capacite =10;
        REQUIRE_EQ(p.capacite(),capacite);
    }
}
SUBCASE("diminuer la capacité est correcte")
{
    int cap = 8;
    piege p{1,2,cap};
    p.diminuerCapacite();
    REQUIRE_EQ(p.capacite(),cap-1);
}
}
