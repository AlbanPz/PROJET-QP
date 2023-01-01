#include "fauve.h"

Fauve::Fauve(const std::string& nom, int x, int y, int force, int typeDeplacement) :
    Mobile{nom, x, y, force, typeDeplacement}
{}


/** Rajouté par Mdou Dian */
bool Fauve::seDeplacer(Mobile* mobile, int x, int y)
{
    if (mobile->force() > force())
    {
        mobile->changerPosition(x, y);
        return true;
    }else
        return false;
}

