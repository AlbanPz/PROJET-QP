#include <iostream>
#include "jeu.h"

using std::cout;
using std::cin;
using std::endl;

// constructeur d?ja rempli
Jeu::Jeu( const Carte & c, const AfficheurCarte & a ):
    d_carte {c}, d_afficheur {new AfficheurCarteConsole{}},d_kills{0}, d_nbreToursDeJeu {0}
{}

Carte& Jeu::carte()
{
    return d_carte;
}

// fait tourner le jeu jusqu'? la fin
bool Jeu::jouer()
{
    afficherCarte();
    int x,y;
    while (d_carte.joueur().estVivant())
    {
        cout <<"Ou voulez vous deplacer ?" <<endl;
        cin>>x>>y;
        d_carte.deplacerLeJoueur(x,y);
        d_carte.deplacerLesFauves();

        afficherCarte();
    }

    return d_carte.joueur().estVivant();
}

// affiche la carte ? l'aide de l'afficheur
void Jeu::afficherCarte()const
{
    d_afficheur->AfficherCarte(d_carte);
}
// renvoit le nombre de fauves tuer total
int Jeu::nombreKills()const
{
    return d_kills;
}
// renvoit le nombre de tours pass?s
int Jeu::nombreTours()const
{
    return d_nbreToursDeJeu;
}

// permet de changer le nombre de tours
void Jeu::changerNombreDeTours ( int nombreDetours)
{
    d_nbreToursDeJeu = nombreDetours;
}
// permet de changer le nombre de fauves tu?es
void Jeu::changerNombreKills ( int score )
{
    d_kills = score;
}

// permet de changer de carte
void Jeu::changerCarte ( const Carte & c)
{
    d_carte = c;
}
//permet de changer d'afficheur
void Jeu::changerAfficheur (  AfficheurCarte* &a)
{
    d_afficheur = a;
}

