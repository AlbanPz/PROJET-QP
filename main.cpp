#include <iostream>

#include <memory>

#include "jeu.h"

/**
    Ceci est le projet principal pour le Jeu
*/

using std::cout;
using std::cin;
using std::endl;


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
    int choix = 0;
    cout <<"Quelle difficulte ?"<<endl
         <<"1- Normal" <<endl
         <<"2- Dur (mobilite reduite aux axes horizontaux et verticaux)"<<endl;
    cin>> choix;
    //partie.changerDifficulte(choix);

    // Choix de la carte
    cout <<"1- Carte aleatoire" <<endl
         <<"2- 9 Carte personnalisees : Attention, si la carte n'existe pas, une carte aléatoire sera generee"<<endl;
    cin>> choix;



    /** A continuer lorsque les class le permettront */
}




void menu()
{
    cout<<"Bienvenu dans le jeu des fauves !"<<endl;

    //Demande le choix de l'utilisateur
    std::string choix ="h";
    while ( choix[0] != '0')
    {
        do {
        cout<<"Que voulez vous faire ?"<<endl
            <<"1- Jouer une partie"<<endl
            <<"2- Charger une configuration"<<endl
            <<"3- Creer/Editer une carte"<<endl
            <<"0- Quitter le jeu"<<endl;

        cin>>choix;
        } while (choix == "" || (choix[0] < 0  && choix[0] > 3));

        // agit en fonction de son choix
        switch (choix[0])
         {
             case 0 : break;
             case 1 : menuJouerPartie();  break;
             case 2 : menuChargerUneConfiguration(); break;
             case 3 : menuCreerEditerCarte(); break;
         }
    }
}


int main()
{
//    menu();

    /**
        Nous avons là deux projets bien distincts
    */


    return 0;
}
