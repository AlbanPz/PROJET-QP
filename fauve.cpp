#include "fauve.h"

Fauve::Fauve(const std::string& nom, int x, int y, int force, int typeDeplacement):
    Mobile{nom, "Fauve", x, y, force, typeDeplacement}
{}

bool Fauve::seDeplacer(Mobile* mobile, int x, int y)
{
    if (mobile->type() == "Joueur") return true;

    if (mobile->force() > force())
    {
        mobile->changerPosition(x, y);
        return true;
    }
    else
        return false;
}
