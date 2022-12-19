#include "doctest.h"
#include "joueur.h"
#include <string>

using std::string;

TEST_CASE("Test du constructeur de Joueur") {
    // Test avec des valeurs de base valides
    Joueur joueur("Joueur 1", 0, 0, 10, 1);
    CHECK(joueur.nom() == "Joueur 1");
    CHECK(joueur.x() == 0);
    CHECK(joueur.y() == 0);
    CHECK(joueur.force() == 10);
    CHECK(joueur.typeDeplacement() == 1);

    // Test avec des valeurs limites valides
    Joueur joueur2("Joueur 2", 0, 0, std::numeric_limits<int>::max(), 1); 
    // std::numeric_limits<int>::max() : la valeur maximale que peut prendre un type entier
    CHECK(joueur2.nom() == "Joueur 2");
    CHECK(joueur2.x() == 0);
    CHECK(joueur2.y() == 0);
    CHECK(joueur2.force() == std::numeric_limits<int>::max());
    CHECK(joueur2.typeDeplacement() == 1);
}

TEST_CASE("Test de la méthode peutSeDeplacerSurPosition de Joueur") {
    Joueur joueur("Joueur 1", 0, 0, 10, 1);

    // Test avec des positions valides
    CHECK(joueur.peutSeDeplacerSurPosition(-1, 0));
    CHECK(joueur.peutSeDeplacerSurPosition(1, 0));
    CHECK(joueur.peutSeDeplacerSurPosition(0, -1));
    CHECK(joueur.peutSeDeplacerSurPosition(0, 1));

    // Test avec des positions non valides
    CHECK_FALSE(joueur.peutSeDeplacerSurPosition(-1, -1));
    CHECK_FALSE(joueur.peutSeDeplacerSurPosition(1, 1));
    CHECK_FALSE(joueur.peutSeDeplacerSurPosition(2, 0));
    CHECK_FALSE(joueur.peutSeDeplacerSurPosition(0, 2));
}
