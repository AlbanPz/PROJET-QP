#include "piege.h"

Piege::Piege (int x, int y, int capa):Element{"Piege",x,y},d_capacite{capa}
{}

int Piege::capacite() const
{
    return d_capacite;
}

void Piege::diminuerCapacite()
{
    d_capacite=d_capacite-1;
}

