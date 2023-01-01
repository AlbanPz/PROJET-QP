#ifndef MOBILE_H
#define MOBILE_H

#include <iostream>
#include "element.h"
#include <cmath>

class Mobile : public Element {
    public :
        Mobile ( int x, int y, int force, int typeDeplacement );
        bool peutSeDeplacerSurPosition (int x, int y) const;
        //char affiche()const override;

        int force()const;
        int typeDeplacement()const;

        /** Rajouté par Mdou Dian */
        bool seDeplacer(Mobile* mobile, int x, int y) override = 0;
    private :
        bool deplacementVertiHori ( int x , int y )const;
        bool deplacementDiagonale (int x, int y ) const;

        int d_force;
        int d_typeDeplacement;
};




#endif // MOBILE_H
