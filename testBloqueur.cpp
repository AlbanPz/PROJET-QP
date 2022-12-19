#include "doctest.h"
#include "bloqueur.h"
#include <string>

using std::string;

TEST_CASE("Test de la classe Bloqueur")
{
    Bloqueur b("Arbre", 3, 4);
    CHECK(b.nom() == "Arbre");
    CHECK(b.x() == 3);
    CHECK(b.y() == 4);
    CHECK(b.bloqueLePassage() == true);

    b.changerPosition(5, 6);
    CHECK(b.x() == 5);
    CHECK(b.y() == 6);
}
