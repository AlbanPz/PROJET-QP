#include "compteur.h"

namespace utils
{
    Compteur::Compteur(int valeur) : d_valeur{valeur}
    {}

    int Compteur::valeur() const
    {
        return d_valeur;
    }
}
