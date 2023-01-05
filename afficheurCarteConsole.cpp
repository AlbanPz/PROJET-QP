#include "carte.h"
#include "afficheurCarteConsole.h"
#include <vector>
void AfficheurCarteConsole::AfficherCarte(const Carte &c) const
{
    for(int i=0; i<c.nombreLignes();i++)
    {
        for(int j=0;j<c.nombreColonnes();j++)
        {
          if( c.elementALaPosition(i,j) ==nullptr)
                std::cout<<".";
          else
          {
              std::string nomElement = c.elementALaPosition(i,j)->nom();
              std::cout<<nomElement[0];
          }

        }
        std::cout<<std::endl;
    }

}
