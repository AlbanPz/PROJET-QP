#include "piege.h"

piege::piege (int x, int y, int capa):Element{"piège",x,y},d_capacite{capa}
{}

int piege::capacite() const
{
    return d_capacite;
}

void piege::diminuerCapacite()
{
    d_capacite=d_capacite-1;
}

