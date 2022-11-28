#include "element.h"

Element::Element(int x, int y): d_x{x}, d_y{y}
{}

int Element::x() const
{
    return d_x;
}

int Element::y() const
{
    return d_y;
}

