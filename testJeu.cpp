#include "doctest.h"
#include "jeu.h"
#include "carte.h"
#include "afficheurCarte.h"

// Définition de constantes pour les tests
const int DIFFICULTE_FACILE = 1;
const int DIFFICULTE_MOYENNE = 2;
const int DIFFICULTE_DURE = 3;

TEST_CASE("Test du constructeur par défaut de Jeu")
{
    Jeu jeu;
    REQUIRE_EQ(jeu.nombreKills(), 0);
    REQUIRE_EQ(jeu.nombreTours(), 0);
    REQUIRE_EQ(jeu.difficulte(), DIFFICULTE_FACILE);
}

TEST_CASE("Test du constructeur avec paramètres de Jeu")
{
// Création d'un terrain et d'un afficheur de carte pour les tests
    Carte terrain;
    AfficheurCarte afficheur;
    Jeu jeu(terrain, afficheur);
    REQUIRE_EQ(jeu.nombreKills(), 0);
    REQUIRE_EQ(jeu.nombreTours(), 0);
    REQUIRE_EQ(jeu.difficulte(), DIFFICULTE_FACILE);
}

TEST_CASE("Test de la fonction changerDifficulte() de Jeu")
{
    Jeu jeu;
    jeu.changerDifficulte(DIFFICULTE_MOYENNE);
    REQUIRE_EQ(jeu.difficulte(), DIFFICULTE_MOYENNE);
    jeu.changerDifficulte(DIFFICULTE_DURE);
    REQUIRE_EQ(jeu.difficulte(), DIFFICULTE_DURE);
}

TEST_CASE("Test de la fonction nombreKills() de Jeu")
{
    Jeu jeu;
    REQUIRE_EQ(jeu.nombreKills(), 0);
    jeu.changerNombreKills(10);
    REQUIRE_EQ(jeu.nombreKills(), 10);
    jeu.changerNombreKills(5);
    REQUIRE_EQ(jeu.nombreKills(), 5);
}

TEST_CASE("Test de la fonction nombreTours() de Jeu")
{
    Jeu jeu;
    REQUIRE_EQ(jeu.nombreTours(), 0);
    jeu.changerNombreDeTours(10);
    REQUIRE_EQ(jeu.nombreTours(), 10);
    jeu.changerNombreDeTours(5);
    REQUIRE_EQ(jeu.nombreTours(), 5);
}

TEST_CASE("Test de la fonction changerCarte() de Jeu")
{
    Jeu jeu;
    Carte terrain1;
    jeu.changerCarte(terrain1);
    REQUIRE_EQ(jeu.carte(), terrain1);
    Carte terrain2;
    jeu.changerCarte(terrain2);
    REQUIRE_EQ(jeu.carte(), terrain2);
}

TEST_CASE("Test de la fonction changerAfficheur() de Jeu")
{
    Jeu jeu;
    AfficheurCarte afficheur1;
    jeu.changerAfficheur(afficheur1);
    REQUIRE_EQ(jeu.afficheur(), afficheur1);
    AfficheurCarte afficheur2;
    jeu.changerAfficheur(afficheur2);
    REQUIRE_EQ(jeu.afficheur(), afficheur2);
}

TEST_CASE("Test de la fonction afficherCarte() de Jeu")
{
// Création d'un terrain et d'un afficheur de carte pour les tests
    Carte terrain;
    AfficheurCarte afficheur;
    Jeu jeu(terrain, afficheur);

// Modification du terrain et vérification que l'affichage est correct
    terrain.ajouterObjetTerrain(1, 1, Fauve(LION));
    terrain.ajouterObjetTerrain(2, 2, Piège());
    jeu.afficherCarte();
// Afficheur doit afficher une représentation du terrain avec un lion en (1,1) et un piège en (2,2)
}

TEST_CASE("Test de la fonction jouer() de Jeu")
{
// Création d'un terrain et d'un afficheur de carte pour les tests
    Carte terrain;
    AfficheurCarte afficheur;
    Jeu jeu(terrain, afficheur);

// Modification du terrain et vérification de la fin de la partie
    terrain.ajouterObjetTerrain(1, 1, Fauve(LION));
    jeu.jouer();
// Jeu doit s'arrêter lorsque le joueur est dévoré par le lion
    REQUIRE_EQ(jeu.partieTerminee(), true);

// Modification du terrain et vérification de la fin de la partie
    terrain.ajouterObjetTerrain(1, 1, Fauve(LION));
    terrain.ajouterObjetTerrain(2, 2, Piège());
    jeu.jouer();
    REQUIRE_EQ(jeu.partieTerminee(), true);
}
