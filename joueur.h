#include "mobile.h"


class Joueur : public Mobile
{
public:
    Joueur(const std::string& nom, int x, int y, int force, int typeDeplacement);

/** Rajouté par Mdou Dian */
    bool seDeplacer(Mobile* mobile, int x, int y) override;
    bool estVivant() const;
    void kill();
private:
    bool d_vie;
};
