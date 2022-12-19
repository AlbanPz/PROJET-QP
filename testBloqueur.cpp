#include "doctest.h"
#include "bloqueur.h"
#include <string>

using std::string;

TEST_CASE("Test de la classe Bloqueur")
{
    Bloqueur b("Arbre", 3, 4);
    REQUIRE_EQ(b.nom(), "Arbre");
    REQUIRE_EQ(b.x(), 3);
    REQUIRE_EQ(b.y(), 4);
    REQUIRE_EQ(b.bloqueLePassage(), true);

    b.changerPosition(5, 6);
    REQUIRE_EQ(b.x(), 5);
    REQUIRE_EQ(b.y(), 6);
}
