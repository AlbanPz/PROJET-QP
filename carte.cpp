#include <cstdlib>
#include <time.h>
#include "carte.h"
#include "fauve.h"
#include "piege.h"

Carte::Carte(Joueur joueur, std::vector<Fauve*> fauve, std::vector<std::vector<Element*>> carte):
    d_joueur{joueur}, d_fauves{fauve}, d_carte{carte}, d_dureeVieJoueur{0}, d_nbFauvesMort{0}
{}

Element* Carte::elementALaPosition(int x, int y)
{
    return d_carte[x][y];
}

int Carte::directionAleatoire()
{
    std::srand(time(0));

    return rand()%8;
}

void Carte::deplacerLeJoueur()
{
    int dir = directionAleatoire();

    switch(dir)
    {
        case 0: // Devant
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x()+1, d_joueur.y()))
            {
                if (elementALaPosition(d_joueur.x()+1, d_joueur.y()) == nullptr)
                    d_joueur.changerPosition(d_joueur.x()+1, d_joueur.y());
            }
            break;

        case 1: // Diagonal devant à gauche
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x()+1, d_joueur.y()+1))
            {
                if (elementALaPosition(d_joueur.x()+1, d_joueur.y()+1) == nullptr)
                    d_joueur.changerPosition(d_joueur.x()+1, d_joueur.y()+1);
            }
            break;

        case 2: // Haut
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x(), d_joueur.y()+1))
            {
                if (elementALaPosition(d_joueur.x(), d_joueur.y()+1) == nullptr)
                    d_joueur.changerPosition(d_joueur.x(), d_joueur.y()+1);
            }
            break;

        case 3: // Diagonal derrière à droite
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x()-1, d_joueur.y()+1))
            {
                if (elementALaPosition(d_joueur.x()-1, d_joueur.y()+1) == nullptr)
                    d_joueur.changerPosition(d_joueur.x()-1, d_joueur.y()+1);
            }
            break;

        case 4: // Derrière
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x()-1, d_joueur.y()))
            {
                if (elementALaPosition(d_joueur.x()-1, d_joueur.y()) == nullptr)
                    d_joueur.changerPosition(d_joueur.x()-1, d_joueur.y());
            }
            break;

        case 5: // Diagonal derrière à gauche
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x()-1, d_joueur.y()-1))
            {
                if (elementALaPosition(d_joueur.x()-1, d_joueur.y()-1) == nullptr)
                    d_joueur.changerPosition(d_joueur.x()-1, d_joueur.y()-1);
            }
            break;

        case 6: // Bas
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x(), d_joueur.y()-1))
            {
                if (elementALaPosition(d_joueur.x(), d_joueur.y()-1) == nullptr)
                    d_joueur.changerPosition(d_joueur.x(), d_joueur.y()-1);
            }
            break;

        case 7: // Diagonal devant à droite
            if (d_joueur.peutSeDeplacerSurPosition(d_joueur.x()+1, d_joueur.y()-1))
            {
                if (elementALaPosition(d_joueur.x()+1, d_joueur.y()-1) == nullptr)
                    d_joueur.changerPosition(d_joueur.x()+1, d_joueur.y()-1);
            }
            break;
    }

    ++d_dureeVieJoueur;
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
    int x = 0, y = 0;
    directionFauve(d_fauves[i], x, y);

    if (d_fauves[i] && d_fauves[i]->peutSeDeplacerSurPosition(x, y))
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
        * Le mobile en question est un fauve
        * Car le joueur ne se déplace que sur des cases vides
    */

    if (element == nullptr)
    {
        mobile->changerPosition(newX, newY);
        return;
    }

    bool ok = element->seDeplacer(mobile, newX, newY);

    if (ok && element->nom() == "Fauve")
    {
        supprimeUnElement(element);
        ++d_nbFauvesMort;
    }
    else if (ok && element->nom() == "Piege")
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

