#include "doctest.h"
#include "mobile.h"

TEST_CASE("Test du constructeur de Mobile") {
    int x = 2, y = 3;
    Mobile m {x, y};
    REQUIRE_EQ(m.x(), x);
    REQUIRE_EQ(m.y(), y);
}

TEST_CASE("Test de la fonction peutSeDeplacerSurPosition de Mobile") {
    // Création d'un mobile avec une position (1, 1)
    Mobile m(1, 1);
    // Le mobile ne peut pas se déplacer sur la même position
    REQUIRE_EQ(m.peutSeDeplacerSurPosition(1, 1), false);
    // Le mobile peut se déplacer sur une position adjacente
    REQUIRE_EQ(m.peutSeDeplacerSurPosition(1, 2), true);
    // Le mobile ne peut pas se déplacer sur une position éloignée
    REQUIRE_EQ(m.peutSeDeplacerSurPosition(2, 2), false);
}

TEST_CASE("Test de la fonction force de Mobile") {
    // Création d'un mobile avec une force de 10
    Mobile m(1, 1, 10);
    REQUIRE_EQ(m.force(), 10);
}

TEST_CASE("Test de la fonction typeDeplacement de Mobile") {
    // Création d'un mobile avec un type de déplacement 1
    Mobile m(1, 1, 10, 1);
    REQUIRE_EQ(m.typeDeplacement(), 1);
}

TEST_CASE("Test de la fonction seDeplacer de Mobile") {
    Mobile m(1, 1, 1, 2); // Création d'un mobile avec une force de 1 et un type de déplacement de 2
    Mobile m2(2, 2, 2, 1); // Création d'un mobile avec une force de 2 et un type de déplacement de 1

    // On teste la fonction seDeplacer avec un mobile qui peut se déplacer sur la case cible
    REQUIRE_EQ(m.seDeplacer(&m2, 2, 2), true); // La fonction doit renvoyer true
    REQUIRE_EQ(m2.estVivant(), false); // Le mobile m2 doit être détruit
    REQUIRE_EQ(m.force(), 1); // La force du mobile m doit être inchangée

    // On teste la fonction seDeplacer avec un mobile qui ne peut pas se déplacer sur la case cible
    Mobile m3(3, 3, 3, 1); // Création d'un mobile avec une force de 3 et un type de déplacement de 1
    REQUIRE_EQ(m.seDeplacer(&m3, 3, 3), false); // La fonction doit renvoyer false
    REQUIRE_EQ(m3.estVivant(), true); // Le mobile m3 doit être toujours en vie
    REQUIRE_EQ(m.force(), 1); // La force du mobile m doit être inchangée
}


TEST_CASE("Test de la fonction 'deplacementVertiHori' de la classe Mobile")
{
    // Création d'un joueur
    Joueur joueur{0, 0};

    // Test avec un déplacement horizontal valide (à droite)
    REQUIRE_EQ(joueur.deplacementVertiHori(1, 0), true);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 1);

    // Test avec un déplacement horizontal valide (à gauche)
    REQUIRE_EQ(joueur.deplacementVertiHori(-1, 0), true);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);

    // Test avec un déplacement vertical valide (vers le haut)
    REQUIRE_EQ(joueur.deplacementVertiHori(0, -1), true);
    REQUIRE_EQ(joueur.x(), -1);
    REQUIRE_EQ(joueur.y(), 0);

    // Test avec un déplacement vertical valide (vers le bas)
    REQUIRE_EQ(joueur.deplacementVertiHori(0, 1), true);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);

    // Test avec un déplacement diagonal (non autorisé)
    REQUIRE_EQ(joueur.deplacementVertiHori(1, 1), false);
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);
}
TEST_CASE("Tests de la fonction 'deplacementDiagonale' de la classe Mobile")
{
    // Création d'un mobile avec un déplacement diagonale
    Mobile mobile {1, 1, 2, 2, 2};

    // Test de la fonction "peutSeDeplacerSurPosition"
    REQUIRE(mobile.peutSeDeplacerSurPosition(1, 2));
    REQUIRE(mobile.peutSeDeplacerSurPosition(2, 1));
    REQUIRE_FALSE(mobile.peutSeDeplacerSurPosition(3, 3));
    REQUIRE_FALSE(mobile.peutSeDeplacerSurPosition(0, 0));

    // Test de la fonction "force"
    REQUIRE(mobile.force() == 2);

    // Test de la fonction "typeDeplacement"
    REQUIRE(mobile.typeDeplacement() == 2);

    // Test de la fonction "seDeplacer"
    REQUIRE(mobile.seDeplacer(nullptr, 1, 2));
    REQUIRE_FALSE(mobile.seDeplacer(nullptr, 3, 3));
    REQUIRE_FALSE(mobile.seDeplacer(nullptr, 0, 0));
}
