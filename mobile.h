#ifndef MOBILE_H
#define MOBILE_H

#include <iostream>
#include "element.h"
#include <cmath>

class Mobile : public Element {
    public :
        Mobile ( const std::string & nom, int x, int y, int force, int typeDeplacement );
        bool peutSeDeplacerSurPosition (int x, int y) const;
        //char affiche()const override;

        int force()const;
        int typeDeplacement()const;


    private :
        bool deplacementVertiHori ( int x , int y )const;
        bool deplacementDiagonale (int x, int y ) const;

        int d_force;
        // 0 == deplacement totale   // 1 == deplacement horizontal - vertical // 2 == deplacement diagonale
        int d_typeDeplacement;
};




#endif // MOBILE_H
