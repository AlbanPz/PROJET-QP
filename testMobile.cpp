#include "doctest.h"
#include "mobile.h"

TEST_CASE("Test du constructeur de Mobile") {
    int x = 2, y = 3;
    Mobile m {x, y};
    REQUIRE_EQ(m.x(), x);
    REQUIRE_EQ(m.y(), y);
}

TEST_CASE("Test de la fonction peutSeDeplacerSurPosition de Mobile") {
    Mobile m(1, 1);
    REQUIRE_EQ(m.peutSeDeplacerSurPosition(1, 1), false);
    REQUIRE_EQ(m.peutSeDeplacerSurPosition(1, 2), true);
    REQUIRE_EQ(m.peutSeDeplacerSurPosition(2, 2), false);
}

TEST_CASE("Test de la fonction force de Mobile") {
    Mobile m(1, 1, 10);
    REQUIRE_EQ(m.force(), 10);
}

TEST_CASE("Test de la fonction typeDeplacement de Mobile") {
    Mobile m(1, 1, 10, "Lent");
    REQUIRE_EQ(m.typeDeplacement(), "Lent");
}

TEST_CASE("Test de la fonction seDeplacer de Mobile") {
    Mobile m(1, 1, 1, 2); 
    Mobile m2(2, 2, 2, 1); 

    REQUIRE_EQ(m.seDeplacer(&m2, 2, 2), true); 
    REQUIRE_EQ(m2.estVivant(), false); 
    REQUIRE_EQ(m.force(), 1); 

    Mobile m3(3, 3, 3, 1);
    REQUIRE_EQ(m.seDeplacer(&m3, 3, 3), false); 
    REQUIRE_EQ(m3.estVivant(), true);
    REQUIRE_EQ(m.force(), 1); 
}


TEST_CASE("Test de la fonction 'deplacementVertiHori' de la classe Mobile")
{
    Joueur joueur{0, 0};

    REQUIRE_EQ(joueur.deplacementVertiHori(1, 0), true);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 1);

    REQUIRE_EQ(joueur.deplacementVertiHori(-1, 0), true);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);

    REQUIRE_EQ(joueur.deplacementVertiHori(0, -1), true);
    REQUIRE_EQ(joueur.x(), -1);
    REQUIRE_EQ(joueur.y(), 0);

    REQUIRE_EQ(joueur.deplacementVertiHori(0, 1), true);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);

    REQUIRE_EQ(joueur.deplacementVertiHori(1, 1), false);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);
}
TEST_CASE("Tests de la fonction 'deplacementDiagonale' de la classe Mobile")
{
    Mobile mobile {1, 1, 2, 2, 2};

    REQUIRE(mobile.peutSeDeplacerSurPosition(1, 2));
    REQUIRE(mobile.peutSeDeplacerSurPosition(2, 1));
    REQUIRE_FALSE(mobile.peutSeDeplacerSurPosition(3, 3));
    REQUIRE_FALSE(mobile.peutSeDeplacerSurPosition(0, 0));

    REQUIRE(mobile.force() == 2);

    REQUIRE(mobile.typeDeplacement() == 2);

    REQUIRE(mobile.seDeplacer(nullptr, 1, 2));
    REQUIRE_FALSE(mobile.seDeplacer(nullptr, 3, 3));
    REQUIRE_FALSE(mobile.seDeplacer(nullptr, 0, 0));
}
