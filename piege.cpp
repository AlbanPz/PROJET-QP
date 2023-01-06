#include "piege.h"
#include "mobile.h"

Piege::Piege (int x, int y, int capa):Element{"Piege", "Piege",x,y}, d_capacite{capa}
{}

int Piege::capacite() const
{
    return d_capacite;
}

void Piege::diminuerCapacite()
{
    d_capacite=d_capacite-1;
}

bool Piege::seDeplacer(Mobile* mobile, int x, int y)
{
    mobile->changerPosition(x, y);

    if (d_capacite > 0)
    {
        diminuerCapacite();
        return true;
    }else
        return false;
}

