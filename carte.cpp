#include <cstdlib>
#include <time.h>
#include "carte.h"
#include "fauve.h"
#include "piege.h"

Carte::Carte(Joueur joueur, std::vector<Fauve*> fauve, std::vector<std::vector<Element*>> grille):
    d_joueur{joueur}, d_fauves{fauve}, d_grille{grille}, d_dureeVieJoueur{0}, d_nbFauvesMort{0}
{
    ajouterLesMobilesDansLaGrille();
    /** Pttr méthode maj de la grille */
}

void Carte::ajouterLesMobilesDansLaGrille()
{
    /** Ajout du joueur */
    int x = d_joueur.x(), y = d_joueur.y();
    d_grille[x][y] = &d_joueur;

    /** Ajout des fauves */
    for (const auto& f : d_fauves)
    {
        int x = f->x(), y = f->y();
        d_grille[x][y] = f;
    }
}

Element* Carte::elementALaPosition(int x, int y)
{
    return d_grille[x][y];
}

void Carte::deplacerLeJoueur(int x, int y)
{
    if (!d_joueur.estVivant()) return;

    if (d_joueur.peutSeDeplacerSurPosition(x, y))
    {
        Element* element = elementALaPosition(x, y);

        if (!element)
        {
            d_joueur.changerPosition(x, y);
            ++ d_dureeVieJoueur;
        }else
        {
            if (!element->seDeplacer(&d_joueur, x, y))
                ++d_dureeVieJoueur;
        }
    }
}

void Carte::directionFauve(Fauve* fauve, int& newX, int& newY)
{
    int xj = d_joueur.x(), yj = d_joueur.y();

    if (xj < fauve->x())
    {
        newX = fauve->x() - 1;
        if (yj < fauve->y())
            newY = fauve->y() - 1;
        else if (yj > fauve->y())
            newY = fauve->y() + 1;
        else
            newY = fauve->y();
    }else if (xj > fauve->x())
    {
        newX = fauve->x() + 1;
        if (yj < fauve->y())
            newY = fauve->y() - 1;
        else if (yj > fauve->y())
            newY = fauve->y() + 1;
        else
            newY = fauve->y();
    }else
    {
        newX = fauve->x();
        if (yj < fauve->y())
            newY = fauve->y() - 1;
        else if (yj > fauve->y())
            newY = fauve->y() + 1;
        else
            newY = fauve->y();
    }
}

void Carte::deplacerUnFauve(int i)
{
    if (!d_fauves[i]) return;

    int x = 0, y = 0;
    directionFauve(d_fauves[i], x, y);

    if (d_fauves[i]->peutSeDeplacerSurPosition(x, y))
    {
        deplacerMobileSur(d_fauves[i], elementALaPosition(x, y), x, y);
    }
}

void Carte::deplacerLesFauves()
{
    for (unsigned i{0}; i < d_fauves.size(); ++i)
        deplacerUnFauve(i);
}


void Carte::deplacerMobileSur(Mobile* mobile, Element* element, int newX, int newY)
{
    /**
        * Ici, le mobile en question est un fauve
        * Car le joueur est traité à part
    */

    if (element == nullptr)
    {
        mobile->changerPosition(newX, newY);
        return;
    }

    bool ok = element->seDeplacer(mobile, newX, newY);

    if (ok && element->type() == "Fauve")
    {
        supprimeUnElement(element);
        ++d_nbFauvesMort;
    }
    else if (ok && element->type() == "Piege")
    {
        supprimeUnElement(mobile);
        ++d_nbFauvesMort;
    }

    /** Si c'est un bloqueur on ne fait rien */
}


int Carte::dureeDeVieDuJoueur() const
{
    return d_dureeVieJoueur;
}

int Carte::nbFauvesMort() const
{
    return d_nbFauvesMort;
}

void Carte::supprimeUnElement(Element* element)
{
    Element* aux = element;
    element = nullptr;
    delete aux;
}

