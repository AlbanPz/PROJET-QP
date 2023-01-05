#ifndef JEU_H
#define JEU_H


#include <iostream>
#include <memory>
#include "carte.h"
#include"afficheurCarte.h"
#include"afficheurCarteConsole.h"



class Jeu {
public :

    // constructeur déja rempli
    Jeu( const Carte & c, const AfficheurCarte & a );

    // fait tourner le jeu jusqu'à la fin
    void jouer();

    // affiche la carte à l'aide de l'afficheur
    void afficherCarte()const;
    // renvoit le nombre de fauves tuer total
    int nombreKills()const;
    // renvoit le nombre de tours passés
    int nombreTours()const;

    // permet de changer le nombre de tours
    void changerNombreDeTours ( int nombreDetours);
    // permet de changer le nombre de fauves tuées
    void changerNombreKills ( int score );
    Carte& carte();

    // permet de changer de carte
    void changerCarte ( const Carte & c);
    //permet de changer d'afficheur
    void changerAfficheur (  AfficheurCarte* &a);
private:
    // fonction intermediaire appelée par la fonction jouer
    void jouerUnTour();
    AfficheurCarte* d_afficheur; // Ne compile pas
    Carte d_carte;
    int d_kills;
    int d_nbreToursDeJeu;
};






#endif // JEU_H
