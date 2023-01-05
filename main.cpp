#include <iostream>

#include <memory>

#include "jeu.h"

/**
    Ceci est le projet principal pour le Jeu
*/

using std::cout;
using std::cin;
using std::endl;

int choixUtilisateur(int mini, int maxi)
{
    int choix;
    do
    {
        cout <<"Faites votre choix parmis les options de " <<mini << " a " <<maxi<<'\n';
        cin >> choix;
    }
    while ( choix < mini || choix > maxi);
    return choix;
}




void menuCreerEditerCarte()
{
    /** A continuer lorsque les class le permettront **/
}

void menuChargerUneConfiguration()
{
    /** A continuer lorsque les class le permettront **/

}


void menuJouerPartie()
{

    Joueur jo ( "Joueur", 10 , 15 , 0 ,0 );
    std::vector<Fauve*> fauves {};
    std::vector<std::vector<Element*>> c;




    Carte carte1 (jo, fauves, c );
    //Jeu partie{};


    // Choix de la difficulté

    cout <<"Quelle difficulte ?"<<endl
         <<"1- Normal" <<endl
         <<"2- Dur (mobilite reduite aux axes horizontaux et verticaux)"<<endl;
    int difficulte = choixUtilisateur(1,2);
    //partie.changerDifficulte(choix);

    // Choix de la carte
    cout <<"1-9 Carte personnalisees "<<endl;
    int numeroCarte = choixUtilisateur(1,9);





}





void menu()
{
    cout<<"Bienvenu dans le jeu des fauves !"<<endl;
        int choix = -1;

        while ( choix != 0 )
        {
            cout<<"Que voulez vous faire ?"<<endl
                <<"1- Jouer une partie"<<endl
                <<"2- Charger une configuration"<<endl
                <<"3- Creer/Editer une carte"<<endl
                <<"0- Quitter le jeu"<<endl;
            int choix = choixUtilisateur(0,3);
            switch (choix)
             {
                 case 0 : break;
                 case 1 : menuJouerPartie();  break;
                 case 2 : menuChargerUneConfiguration(); break;
                 case 3 : menuCreerEditerCarte(); break;
             }
        }
    //}
}


int main()
{

   menu();

    /**
        Nous avons là deux projets bien distincts
    */


    return 0;
}
