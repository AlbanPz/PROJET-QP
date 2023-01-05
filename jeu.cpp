#include "jeu.h"




    // constructeur déja rempli
    Jeu::Jeu( const Carte & c, const AfficheurCarte & a ): d_carte { c}, d_afficheur { std::make_unique<AfficheurCarte>(a)}, d_kills{0}, d_nbreToursDeJeu {0}
    {

    }

    //Choisir difficulté cad le type deplacement du joueur
    /** difficulté = 2 --> dur sinon c'est difficulté normal **/
    void Jeu::changerDifficulte(int difficulte)
    {

    }

    // fait tourner le jeu jusqu'à la fin
    void Jeu::jouer()
    {

    }


    // affiche la carte à l'aide de l'afficheur
    void Jeu::afficherCarte()const
    {

    }
    // renvoit le nombre de fauves tuer total
    int Jeu::nombreKills()const
    {
        return d_kills;
    }
    // renvoit le nombre de tours passés
    int Jeu::nombreTours()const
    {
        return d_nbreToursDeJeu;
    }

    // permet de changer le nombre de tours
    void Jeu::changerNombreDeTours ( int nombreDetours)
    {
        d_nbreToursDeJeu = nombreDetours;
    }
    // permet de changer le nombre de fauves tuées
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
    void Jeu::changerAfficheur ( const AfficheurCarte* &a)
    {
        d_afficheur = std::make_unique<AfficheurCarte> (a) ;
    }

