#ifndef FAUVE_H
#define FAUVE_H

#include "mobile.h"

class Fauve : public Mobile
{
public:
    Fauve(const std::string& nom, int x, int y, int force, int typeDeplacement);
    bool seDeplacer(Mobile* mobile, int x, int y) override;
};

#endif // FAUVE_H
