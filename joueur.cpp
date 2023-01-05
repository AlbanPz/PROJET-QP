#include "joueur.h"

Joueur::Joueur(const std::string& nom, int x, int y, int force, int typeDeplacement):
    Mobile{nom, "Joueur", x, y, force, typeDeplacement}, d_vie{true}
{}

bool Joueur::seDeplacer(Mobile* mobile, int x, int y)
{
    // Le joueur ne peut pas se déplacer sur un autre élément mobile.
    // La méthode renvoie donc toujours false.
    return false;
}

bool Joueur::estVivant() const
{
    return d_vie;
}

void Joueur::kill()
{
    d_vie = false;
}
