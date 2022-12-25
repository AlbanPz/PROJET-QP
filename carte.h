#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <vector>
#include "joueur.h"

class Fauve;
class Element;
class Piege;
class Bloqueur;

class Carte
{
public:
    Carte(Joueur d_joueur, std::vector<Fauve*> fauve, std::vector<Element*> carte);
    Element*& elementALaPosition(int x, int y); /** trouver une meilleure solution */
    void deplacerLeJoueur();
    void deplacerLesFauves();
    void deplacerMobileSur(Mobile* mobile, Element* element, int x, int y);
    void deplacerMobileSur(Mobile* mobile); /** Pas fini ***/
    void supprimeUnFauve(Fauve*& fauve);
private:
    int directionAleatoire();
    void directionFauve(Fauve* fauve, int& x, int& y);
    void deplacerUnFauve(int i);

    Joueur d_joueur;
    std::vector<Fauve*> d_fauves;
    std::vector<Element*> d_carte;
    int d_dureeVieJoueur;
    int d_nbFauvesMort;
};

#endif // CARTE_H_INCLUDED
