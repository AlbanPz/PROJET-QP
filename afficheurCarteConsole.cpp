#include "carte.h"
#include "afficheurCarteConsole.h"
#include <vector>
void afficheurCarteConsole::afficherCarte(const Carte &c) const
{
    for(int i=0; i<c.ligne();i++)
    {
        for(int j=0;j<c.colonne();j++)
        {
          if(c.elementALaPosition(i,j)==nullptr)
                std::cout<<".";
          else
            std::cout<<c.elementALaPosition(i,j)->d_nom[0];
        }
        std::cout<<endl;
    }

}
