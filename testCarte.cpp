#include "doctest.h"
#include "element.h"
#include "carte.h"
#include "fauve.h"
#include "piege.h"
#include "bloqueur.h"

using std::vector;

TEST_CASE("[Carte] La carte est bien construite")
{
    Joueur j{"DIALLO", 2, 5, 0, 0};
    vector<Fauve*> fauves;
    fauves.push_back(new Fauve{"Fauve", 0, 0, 10, 0});
    fauves.push_back(new Fauve{"Fauve", 1, 1, 5, 2});
    vector<vector<Element*>> grille(5, vector<Element*>(6, nullptr));
    grille[0][5] = new Piege{0, 5, 1};
    grille[1][3] = new Bloqueur{"Arbre", 1, 3};
    Carte carte{j, fauves, grille};

    SUBCASE("L'element a la position x, y est juste")
    {
        SUBCASE("L'element dans une case vide est nullptr")
        {
            Element* elem = carte.elementALaPosition(2, 2);
            REQUIRE_EQ(elem, nullptr);
        }

        SUBCASE("L'element dans une case remplie n'est pas nullptr")
        {
            int x = fauves[0]->x(), y = fauves[0]->y();
            Element* elem = carte.elementALaPosition(x, y);
            REQUIRE_NE(elem, nullptr);
        }

        SUBCASE("Le nom de l'element a la position x, y est juste")
        {
            int x = j.x(), y = j.y();
            Element* elem = carte.elementALaPosition(x, y);
            REQUIRE_EQ(elem->nom(), j.nom());
        }
    }

    SUBCASE("La duree de vie du joueur est correcte")
    {
        SUBCASE("Quand il n'a fait aucun tour")
        {
            REQUIRE_EQ(carte.dureeDeVieDuJoueur(), 0);
        }

        SUBCASE("Quand il a fait au moins un tour")
        {
            carte.deplacerLeJoueur();
            REQUIRE_GE(carte.dureeDeVieDuJoueur(), 0);
        }
    }

    SUBCASE("Faire jouer un fauve est correcte")
    {
        // A faire Ma 20/12
    }

    SUBCASE("Deplacer un element est correcte")
    {
        // A faire Ma 20/12
    }
}

