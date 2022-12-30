#include <cstdlib>
#include <time.h>
#include "carte.h"
#include "fauve.h"
#include "piege.h"

Carte::Carte(Joueur joueur, std::vector<Fauve*> fauve, std::vector<Element*> carte):
    d_joueur{joueur}, d_fauves{fauve}, d_carte{carte}, d_dureeVieJoueur{0}, d_nbFauvesMort{0}
{}

Element* Carte::elementALaPosition(int x, int y)
{
    for (auto& carte : d_carte)
        if (carte->x() == x && carte->y() == y)
            return carte;

    return nullptr;
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

void Carte::directionFauve(Fauve* fauve, int & x, int& y)
{
    int xj = d_joueur.x(), yj = d_joueur.y();

    if (xj < fauve->x())
    {
        x = fauve->x() - 1;
        if (yj < fauve->y())
            y = fauve->y() - 1;
        else if (yj > fauve->y())
            y = fauve->y() + 1;
        else
            y = fauve->y();
    }else if (xj > fauve->x())
    {
        x = fauve->x() + 1;
        if (yj < fauve->y())
            y = fauve->y() - 1;
        else if (yj > fauve->y())
            y = fauve->y() + 1;
        else
            y = fauve->y();
    }else
    {
        x = fauve->x();
        if (yj < fauve->y())
            y = fauve->y() - 1;
        else if (yj > fauve->y())
            y = fauve->y() + 1;
        else
            y = fauve->y();
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


void Carte::deplacerMobileSur(Mobile* mobile, Element* element, int x, int y)
{
    /** Pour le moment on part du principe que le mobile en question est un fauve */
    if (element == nullptr)
    {
        mobile->changerPosition(x, y);
        return;
    }

    if (element->nom() == "Joueur")
    {
        mobile->changerPosition(x, y);
        //d_joueur.kill(true); Tuer le joueur
    }else if (element->nom() == "Fauve")
    {
        deplacerMobileSur(mobile, element, x, y);
    }else if (element->nom() == "Piege")
    {
        mobile->changerPosition(x, y);
        // Ne compile pas
        //deplacerMobileSur(mobile, element); /** il faut que element soit un piege */
    }

    /** Si c'est un bloqueur on ne fait rien */
}



void Carte::deplacerMobileSur(Mobile* mobile, Fauve* fauve, int x, int y)
{
    if (mobile->force() > fauve->force())
    {
        mobile->changerPosition(x, y);
        supprimeUnMobile(fauve);
    }
}

void Carte::deplacerMobileSur(Mobile* mobile, Piege* piege)
{
    if (piege->capacite() > 0)
    {
        supprimeUnMobile(mobile);
        piege->diminuerCapacite();
    }
}

void Carte::supprimeUnMobile(Mobile* mobile)
{
    Mobile* aux = mobile;
    mobile = nullptr;
    delete aux;
}

