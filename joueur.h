#include "mobile.h"


class Joueur : public Mobile{
public:
    Joueur(const std::string& nom, int x, int y, int force, int typeDeplacement);
};
