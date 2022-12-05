#ifndef JEU_H
#def JEU_H


#include <iostream>

class Carte;

class Jeu {
public :
    Jeu( const Carte & c, const AfficheurCarte & a );
    void jouer();
    void jouerUnTour();
    //
    //DECOUPE DES FONCTIONS JOUER POSSIBLE
    //
    void afficherCarte()const;


    int nombreKills()const;
    int nombreTours()const;

    void changerCarte ( const Carte & c);
    void changerAfficheur ( const AfficheurCarte & a);
public:
    std::unique_prt <AfficheurCarte> d_afficheur;
    Carte d_carte;
    int d_kills;
    int d_nbreToursDeJeu;
};






#endif // JEU_H
