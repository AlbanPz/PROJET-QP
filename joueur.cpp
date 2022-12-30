#include "joueur.h"


/**
* Constructeur de joueru

Joueur::Joueur(const std::string& nom, int x, int y, int force, int typeDeplacement) :
    Mobile{nom, x, y, force, typeDeplacement}, d_vie{true}
{}
*/

/** Rajouté par Mdou Dian */

bool Joueur::seDeplacer(Mobile* mobile, int x, int y)
{
    kill();
    mobile->changerPosition(x, y);
    return estVivant();
}

bool Joueur::estVivant() const
{
    return d_vie;
}

void Joueur::kill()
{
    d_vie = false;
}

