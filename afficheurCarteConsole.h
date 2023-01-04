#ifndef AFFICHEURCARTECONSOLE_H_INCLUDED
#define AFFICHEURCARTECONSOLE_H_INCLUDED
#include "afficheurCarte.h"

class afficheurCarteConsole : public afficheurCarte
{
public:
    virtual void afficherCarte(const Carte &c)const override;
};


#endif // AFFICHEURCARTECONSOLE_H_INCLUDED
