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
    Carte(Joueur d_joueur, std::vector<Fauve*> fauve, std::vector<std::vector<Element*>> grille);
    Element* elementALaPosition(int x, int y);
    void deplacerLeJoueur(int x, int y);
    void deplacerLesFauves();
    int dureeDeVieDuJoueur() const;
    int nbFauvesMort() const;
private:
    void ajouterLesMobilesDansLaGrille();
    int directionAleatoire();
    void directionFauve(Fauve* fauve, int& newX, int& newY);
    void deplacerUnFauve(int i);
    void deplacerMobileSur(Mobile* mobile, Element* element, int newX, int newY);
    void supprimeUnElement(Element* element);

    Joueur d_joueur;
    std::vector<Fauve*> d_fauves;
    std::vector<std::vector<Element*>> d_grille;
    int d_dureeVieJoueur;
    int d_nbFauvesMort;
};

#endif // CARTE_H_INCLUDED
