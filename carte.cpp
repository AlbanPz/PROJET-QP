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
    remplirUneCase(d_joueur);

    /** Ajout des fauves */
    for (const auto& f : d_fauves)
    {
        remplirUneCase(f);
    }
}

void Carte::remplirUneCase(Mobile* mobile)
{
    int x = mobile->x(), y = mobile->y();
        d_grille[x][y] = mobile;
}

void Carte::remplirUneCase(Joueur& joueur)
{
    int x = joueur.x(), y = joueur.y();
    d_grille[x][y] = &joueur;
}

void Carte::viderUneCase(int x, int y)
{
    supprimeUnElement(d_grille[x][y]);
}
/*
void Carte::MiseAJourDeLaGrille(int oldX, int oldY, Element* element)
{
    supprimeUnElement(d_grille[oldX][oldY]);

    if (element)
    {
        int x = element->x(), y = element->y();
        d_grille[x][y] = element;
    }
}
*/
void Carte::ajouteElementDansLaGrille(Element* element)
{
    int x = element->x(), y = element->y();
    d_grille[x][y] = element;
}

Element* Carte::elementALaPosition(int x, int y) const
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
            viderUneCase(d_joueur.x(), d_joueur.y());
            d_joueur.changerPosition(x, y);
            remplirUneCase(d_joueur);

            ++d_dureeVieJoueur;
        }else
        {
            if (element->seDeplacer(&d_joueur, x, y))
            {
                viderUneCase(d_joueur.x(), d_joueur.y());
                d_joueur.kill();
            }
            else
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
        Mobile* mobile = d_fauves[i];
        Element* element = elementALaPosition(x, y);
        deplacerMobileSur(mobile, element, x, y);
    }
}

void Carte::deplacerLesFauves()
{
    for (unsigned i{0}; i < d_fauves.size(); ++i)
        deplacerUnFauve(i);
}


void Carte::deplacerMobileSur(Mobile* &mobile, Element* &element, int newX, int newY)
{
    /**
        * Ici, le mobile en question est un fauve
        * Car le joueur est traité à part
    */

    if (element == nullptr)
    {
        viderUneCase(mobile->x(), mobile->y());
        mobile->changerPosition(newX, newY);
        remplirUneCase(mobile);
        return;
    }

    bool ok = element->seDeplacer(mobile, newX, newY);

    if (ok && element->type() == "Fauve")
    {
        viderUneCase(mobile->x(), mobile->y());
        supprimeUnElement(element);
        remplirUneCase(mobile);

        ++d_nbFauvesMort;
    }
    else if (ok && element->type() == "Piege")
    {
        viderUneCase(mobile->x(), mobile->y());
        Element* aux = mobile;
        supprimeUnElement(aux);

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

int Carte::nombreColonnes () const
{
    return d_grille[0].size();
}

int Carte::nombreLignes () const
{
    return d_grille.size();
}

void Carte::supprimeUnElement(Element* &element)
{
    if (element)
    {
        Element* aux = element;
        element = nullptr;
        delete aux;
    }
}

