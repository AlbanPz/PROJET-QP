#include "element.h"

Element::Element(const std::string& nom, const std::string& type, int x, int y):
    d_nom{nom}, d_type{type}, d_x{x}, d_y{y}
{}

std::string Element::nom() const
{
    return d_nom;
}

std::string Element::type() const
{
    return d_type;
}

int Element::x() const
{
    return d_x;
}

int Element::y() const
{
    return d_y;
}

void Element::changerPosition(int x, int y)
{
    d_x = x;
    d_y = y;
}

