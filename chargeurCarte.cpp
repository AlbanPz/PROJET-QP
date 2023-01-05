#include "chargeurCarte.h"
#include "fstream"
#include <vector>
#include "element.h"
#include "piege.h"
#include "bloqueur.h"

 void chargeurCarte::chargerCarte(const std::string nomFichier ) const
 {
     std::ifstream fic;
     fic.open(nomFichier);
     if(fic)
     {
         //on crée le tableau de fauves
         std::vector<Fauve*> fauves;
        //variables pour stocker la taille de la grille
        int longeur, largeur; //variables pour stocker la taille de la grille
        // on lit la taille de la grille
        fic>>longeur>>largeur;
        std::vector<std::vector<Element*>> grille;
        //on crée la grille et on change sa taille
        grille.resize(largeur);

        for(int i=0;i<grille.size();i++)
        {
            grille[i].resize(longeur);
        }

        //On lit maintenant le joueur
        int x, y, puis, type_depla, capacite;
        std::string type;
        std::string nom;
        fic>>type>>x>>y>>puis>>type_depla;
        //on crée le joueur
        Joueur j{type,x,y,puis,type_depla};

     fic>>type;
        if(type=="fauve")
        {
            fic>>nom>>x>>y>>puis>>type_depla;
            fauves.push_back(new Fauve{nom,x,y,puis,type_depla})
        }
        else if(type=="piege")
        {
            fic>>nom>>x>>y>>capacite;
            grille[x][y]=new Piege{x,y,capacite};
        }
        else
        {
            fic>>nom>>x>>y;
            grille[x][y]=new Bloqueur{nom,x,y};
        }

        fic.close();
     }
     else
     {
         std::cout<<"impossible de lire le fichier, vérifiez le chemin d'accès";
     }
 }
