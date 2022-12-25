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
    Carte(Joueur d_joueur, std::vector<Fauve*> fauve, std::vector<Element*> element);
    void supprimeUnFauve(Fauve*& fauve);
    void deplacerLeJoueur();
    void deplacerLesFauves();
    Element*& elementALaPosition(int x, int y);
    void deplacerMobileSur(Fauve*& fauve);
    void deplacerMobileSur(Element*& immobile);
private:
    void deplacerUnFauve(int i);

    Joueur d_joueur;
    std::vector<Fauve*> d_fauves;
    std::vector<Element*> d_carte;
    int dureeVieJoueur;
    int nbFauvesMort;
};

#endif // CARTE_H_INCLUDED
