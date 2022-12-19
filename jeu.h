#ifndef JEU_H
#define JEU_H


#include <iostream>
#include <memory>

class Carte;
class AfficheurCarte;

class Jeu {
public :
    // Constructeur par défaut
    Jeu();
    // constructeur déja rempli
    Jeu( const Carte & c, const AfficheurCarte & a );
    //Choisir difficulté cad le type deplacement du joueur
    /** difficulté = 2 --> dur sinon c'est difficulté normal **/
    void changerDifficulte(int difficulte);
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


    // permet de changer de carte
    void changerCarte ( const Carte & c);
    //permet de changer d'afficheur
    void changerAfficheur ( const AfficheurCarte* &a);
public:
    // fonction intermediaire appelée par la fonction jouer
    void jouerUnTour();
    std::unique_ptr <AfficheurCarte> d_afficheur;
    Carte d_carte;
    int d_kills;
    int d_nbreToursDeJeu;
};






#endif // JEU_H
