
#include "mobile.h"

Mobile::Mobile ( int x, int y, int force, int typeDeplacement ) : Element{x,y}, d_force { force}, d_typeDeplacement {typeDeplacement}
{}


int Mobile::force()const
{
    return d_force;
}

int Mobile::typeDeplacement()const
{
    return d_typeDeplacement;
}


bool Mobile::deplacementDiagonale (int x, int y ) const
{
    return ( x == Element::x()-1  || x == Element::x() +1 )
        && ( y == Element::y() -1 || y == Element::y() +1 );
}

bool Mobile::deplacementVertiHori ( int x , int y )const
{
    return ( x == Element::x() && abs(y - Element::y())== 1 )
        || ( y == Element::y() && abs(x - Element::x())== 1 );
}
bool Mobile::peutSeDeplacerSurPosition ( int x , int y) const
{
    switch ( d_typeDeplacement)
    {
        // deplacement horizontal - vertical
        case 1:
            return deplacementVertiHori(x,y);

        // deplacement diagonale
        case 2:
            return deplacementDiagonale(x,y);

        // deplacement diagonale - vertical -horizontal
        default :
            return deplacementDiagonale(x,y) || deplacementVertiHori(x,y);

    }
}
