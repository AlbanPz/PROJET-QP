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
    Carte(Joueur d_joueur, std::vector<Fauve*> fauve, std::vector<std::vector<Element*>> carte);
    Element* elementALaPosition(int x, int y);
    void deplacerLeJoueur();
    void deplacerLesFauves();
    int dureeDeVieDuJoueur() const;
    int nbFauvesMort() const;
    void supprimeUnElement(Element* element);
private:
    int directionAleatoire();
    void directionFauve(Fauve* fauve, int& newX, int& newY);
    void deplacerUnFauve(int i);
    void deplacerMobileSur(Mobile* mobile, Element* element, int newX, int newY);

    Joueur d_joueur;
    std::vector<Fauve*> d_fauves;
    std::vector<std::vector<Element*>> d_carte;
    int d_dureeVieJoueur;
    int d_nbFauvesMort;
};

#endif // CARTE_H_INCLUDED
