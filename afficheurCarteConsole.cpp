
#include "carte.h"
#include "afficheurCarteConsole.h"
#include <vector>

void AfficheurCarteConsole::AfficherCarte( const Carte &c) const
{
    // ligne du haut
    std::cout<<' ';
    for(int i=0; i< 3*c.nombreLignes();i++) std::cout<<'_';
    std::cout<<std::endl;


    for(int i=0; i<c.nombreLignes();i++)
    {
        //ligne de gauche
        std::cout<<'|';
        for(int j=0;j<c.nombreColonnes();j++)
        {
          if( c.elementALaPosition(i,j) ==nullptr)
                std::cout<< std::setw(3) <<"." ;
          else
          {
              std::string nomElement = c.elementALaPosition(i,j)->nom();
              std::cout<< std::setw(3) << nomElement[0];
          }


        }
        //ligne de droite
        std::cout<<'|';
        std::cout<<std::endl;
    }


    // ligne du bas
    std::cout<<' ';
    for(int i=0; i< 3*c.nombreLignes();i++) std::cout<<'_';
    std::cout<<std::endl;
}
