#include "mobile.h"


class Fauve : public Mobile{
public:
    Fauve(const std::string& nom, int x, int y, int force, int typeDeplacement);

    /** Rajouté par Mdou Dian */
    bool seDeplacer(Mobile* mobile, int x, int y) override;
};
