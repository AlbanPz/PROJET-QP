#include "joueur.h"

Joueur::Joueur(const std::string& nom, int x, int y, int force, int typeDeplacement):
    Mobile{nom, "Joueur", x, y, force, typeDeplacement}, d_vie{true}
{}

bool Joueur::seDeplacer(Mobile* mobile, int x, int y)
{
     /** Il n'y a que les fauves qui se déplacent sur le joueur */

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
