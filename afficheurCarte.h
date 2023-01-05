#ifndef AFFICHEURCARTE_H_INCLUDED
#define AFFICHEURCARTE_H_INCLUDED
#include "carte.h"
#include <iostream>

class AfficheurCarte{
public:
    virtual void AfficherCarte(const Carte &c) const = 0;
    virtual ~AfficheurCarte() = default;
};


#endif // AFFICHEURCARTE_H_INCLUDED
