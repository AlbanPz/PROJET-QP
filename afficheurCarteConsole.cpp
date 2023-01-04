#include "carte.h"
#include "afficheurCarteConsole.h"
#include <vector>
void afficheurCarteConsole::afficherCarte(const Carte &c) const
{
    for(int i=0; i<c.d_grille.size;i++)
    {
        for(int j=0;j<c.d_grille[i].size;j++)
        {
          if(d_grille==nullptr)
                cout<<".";
          else
            cout<<d_grille[i][j]->d_nom[0];
        }
        cout<<endl;
    }

}
