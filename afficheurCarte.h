#ifndef AFFICHEURCARTE_H_INCLUDED
#define AFFICHEURCARTE_H_INCLUDED
#include "carte.h"
class afficheurCarte{
public:
    virtual void afficherCarte(const Carte &c) const = 0;
    virtual ~afficheurCarte() = default;
};


#endif // AFFICHEURCARTE_H_INCLUDED
