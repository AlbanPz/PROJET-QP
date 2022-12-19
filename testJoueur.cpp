#include "doctest.h"
#include "joueur.h"
#include <string>

using std::string;

TEST_CASE("Test du constructeur de Joueur") {
    // Test avec des valeurs de base valides
    Joueur joueur("Joueur 1", 0, 0, 10, 1);
    REQUIRE_EQ(joueur.nom(), "Joueur 1");
    REQUIRE_EQ(joueur.x(), 0);
    REQUIRE_EQ(joueur.y(), 0);
    REQUIRE_EQ(joueur.force(), 10);
    REQUIRE_EQ(joueur.typeDeplacement(), 1);

    // Test avec des valeurs limites valides
    Joueur joueur2("Joueur 2", 0, 0, std::numeric_limits<int>::max(), 1); 
    // std::numeric_limits<int>::max() : la valeur maximale que peut prendre un type entier
    REQUIRE_EQ(joueur2.nom(), "Joueur 2");
    REQUIRE_EQ(joueur2.x(), 0);
    REQUIRE_EQ(joueur2.y(), 0);
    REQUIRE_EQ(joueur2.force(), std::numeric_limits<int>::max());
    REQUIRE_EQ(joueur2.typeDeplacement(), 1);
}

TEST_CASE("Test de la méthode peutSeDeplacerSurPosition de Joueur") {
    Joueur joueur("Joueur 1", 0, 0, 10, 1);

    // Test avec des positions valides
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(-1, 0), true);
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(1, 0), true);
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(0, -1), true);
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(0, 1), true);

    // Test avec des positions non valides
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(-1, -1), false);
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(1, 1), false);
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(2, 0), false);
    REQUIRE_EQ(joueur.peutSeDeplacerSurPosition(0, 2), false);
}
