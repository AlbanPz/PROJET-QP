#ifndef AFFICHEURCARTECONSOLE_H_INCLUDED
#define AFFICHEURCARTECONSOLE_H_INCLUDED
#include "afficheurCarte.h"

class AfficheurCarteConsole : public AfficheurCarte
{
public:
    virtual void AfficherCarte(const Carte &c)const override;
};


#endif // AFFICHEURCARTECONSOLE_H_INCLUDED
