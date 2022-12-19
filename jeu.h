#ifndef JEU_H
#define JEU_H


#include <iostream>
#include <memory>

class Carte;
class AfficheurCarte;

class Jeu {
public :
    // Constructeur par d�faut
    Jeu();
    // constructeur d�ja rempli
    Jeu( const Carte & c, const AfficheurCarte & a );
    //Choisir difficult� cad le type deplacement du joueur
    /** difficult� = 2 --> dur sinon c'est difficult� normal **/
    void changerDifficulte(int difficulte);
    // fait tourner le jeu jusqu'� la fin
    void jouer();

    // affiche la carte � l'aide de l'afficheur
    void afficherCarte()const;
    // renvoit le nombre de fauves tuer total
    int nombreKills()const;
    // renvoit le nombre de tours pass�s
    int nombreTours()const;

    // permet de changer le nombre de tours
    void changerNombreDeTours ( int nombreDetours);
    // permet de changer le nombre de fauves tu�es
    void changerNombreKills ( int score );


    // permet de changer de carte
    void changerCarte ( const Carte & c);
    //permet de changer d'afficheur
    void changerAfficheur ( const AfficheurCarte* &a);
public:
    // fonction intermediaire appel�e par la fonction jouer
    void jouerUnTour();
    std::unique_ptr <AfficheurCarte> d_afficheur;
    Carte d_carte;
    int d_kills;
    int d_nbreToursDeJeu;
};






#endif // JEU_H
