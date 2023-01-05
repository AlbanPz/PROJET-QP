#include <iostream>

#include <memory>

#include "jeu.h"
#include "fauve.h"
#include "piege.h"
#include "bloqueur.h"
#include "afficheurCarteConsole.h"


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
    // CARTE FICTIVE
    std::vector<Fauve*> fauves ;
    std::vector<std::vector<Element*>> c;

    c.resize(30);
    for ( int i = 0 ; i < 30 ; i++) c[i].resize(30);


    fauves.push_back(new Fauve{"Lion", 1, 1, 10, 0});
    fauves.push_back(new Fauve{"Tigre", 4, 5, 20, 0});
    fauves.push_back(new Fauve{"Leopard", 8, 10, 30, 0});



/*
    c[10][20] = new Bloqueur {"Arbre", 10, 20};
    c[24][28] = new Bloqueur {"Arbre", 24, 28};
    c[5][7] = new Bloqueur {"Arbre", 5, 7};

    c[17][25] = new Piege { 17, 25 , 2};
    c[24][26] = new Piege { 24, 26 , 2};
    c[2][8] = new Piege { 2, 8 , 2};*/
    // CARTE FICTIVE FIN


    // Choix de la difficulté
    cout <<"Quelle difficulte ?"<<endl
         <<"1- Normal" <<endl
         <<"2- Dur (mobilite reduite aux axes horizontaux et verticaux)"<<endl;
    int difficulte = choixUtilisateur(1,2);
    //partie.changerDifficulte(choix);

    Joueur jo ( "Joueur", 15 , 15 , 0 ,difficulte );

    // Choix de la carte
    cout <<"1-9 Carte personnalisees "<<endl;
    int numeroCarte = choixUtilisateur(1,9);

    AfficheurCarteConsole afficheur;
    Carte carte1 (jo, fauves, c );
    Jeu partie( carte1, afficheur );


    partie.afficherCarte();
<<<<<<< HEAD
    partie.d_carte.deplacerLesFauves();
   // cout <<carte1.d_joueur.x() << " " << carte1.d_joueur.y() << endl;
    partie.d_carte.deplacerLeJoueur(16,15);
   // cout <<carte1.d_joueur.x() << " " << carte1.d_joueur.y() << endl;
    partie.afficherCarte();
=======
    cout <<"ok" <<endl;



    //cout <<carte1.d_joueur.x() << " " << carte1.d_joueur.y() << endl;
    //partie.d_carte.deplacerLeJoueur(16,15);
    //cout <<carte1.d_joueur.x() << " " << carte1.d_joueur.y() << endl;
    partie.afficherCarte();
    int x,y;
    while ( partie.carte().d_joueur.estVivant() && partie.carte().d_fauves.size() > 0)
    {
        cout <<"Ou voulez vous deplacer ?" <<endl;
        cin>>x>>y;
        partie.carte().deplacerLeJoueur(x,y);
        partie.afficherCarte();
        partie.carte().deplacerLesFauves();
        partie.afficherCarte();
    }
>>>>>>> 742377b8d5be6fc5d564813cdddd2cca797a24d3
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
        choix = choixUtilisateur(0,3);
        switch (choix)
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
    menu();

    return 0;
}
