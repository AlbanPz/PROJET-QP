#include "piege.h"
#include "mobile.h"

Piege::Piege (int x, int y, int capa):Element{"Piege",x,y},d_capacite{capa}
{}

int Piege::capacite() const
{
    return d_capacite;
}

void Piege::diminuerCapacite()
{
    d_capacite=d_capacite-1; /** tu peux écrire --d_capacite; */
}

/** Rajouté par Mdou Dian */
bool Piege::seDeplacer(Mobile* mobile, int x, int y)
{
    if (d_capacite > 0)
    {
        mobile->changerPosition(x, y);
        diminuerCapacite();
        return true;
    }else
        return false;
}

