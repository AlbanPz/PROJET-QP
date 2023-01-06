#include "chargeurCarte.h"
#include "fstream"
#include <vector>
#include "piege.h"
#include "element.h"
#include "fauve.h"
#include "bloqueur.h"
#include "joueur.h"
#include "carte.h"

Carte chargeurCarte::chargerCarte(const std::string nomFichier)
 {
     std::ifstream fic;
     fic.open(nomFichier);
  //si le fichier est ouvert
     if(fic)
     {
         //on crée le tableau de fauves
         std::vector<Fauve*> fauves1;
        //variables pour stocker la taille de la terrain
        int longeur, largeur; //variables pour stocker la taille de la terrain
        // on lit la taille de la terrain
        fic>>longeur>>largeur;
        std::vector<std::vector<Element*>> terrain;
        //on crée la terrain et on change sa taille
        terrain.resize(largeur);

        for(unsigned int i=0;i<terrain.size();i++)
        {
            terrain[i].resize(longeur);
        }

        //On lit maintenant le joueur
        int x, y, puis, type_depla, capacite;
        std::string type;
        std::string nom;
        fic>>type>>x>>y>>puis>>type_depla;
        //on crée le joueur
        Joueur j1{type,x,y,puis,type_depla};
  // on lit le type de l'élément si fauve -> on crée un fauve
  int nbElem=0;
  int i=0;
  while(i!=nbElem)
  {
     fic>>type;
        if(type=="fauve")
        {
            fic>>nom>>x>>y>>puis>>type_depla;
            fauves1.push_back(new Fauve{nom,x,y,puis,type_depla});
        }
      //si piège -> on crée un piège
        else if(type=="piege")
        {
            fic>>nom>>x>>y>>capacite;
            terrain[x][y]=new Piege{x,y,capacite};
        }
      //sinon on crée un bloqueur
        else
        {
            fic>>nom>>x>>y;
            terrain[x][y]=new Bloqueur{nom,x,y};
        }
        i++;
     }
     // on ferme le fichier
     fic.close();
     Carte carte1{j1, fauves1, terrain};
     return carte1;
     }

  //si le fichier ne s'ouvre pas, on prévient l'utilisateur
     else
     {
         std::cout<<"impossible de lire le fichier, vérifiez le chemin d'accès, carte vide chargée";
         //création d'une carte vide
         Joueur j{"Impossible",0,0,0,0};
         std::vector<Fauve*> nul;
         std::vector<std::vector<Element*>> elNul;
         Carte cartenul{j,nul,elNul};
         return cartenul;
     }

 }
