#ifndef PIEGE_H
#define PIEGE_H

#include "element.h"

class Piege : public Element
{
public:
    Piege(int x, int y, int capa);
    int capacite() const;
    void diminuerCapacite();
    bool seDeplacer(Mobile* mobile, int x, int y) override;
private:
    int d_capacite;
};

#endif // PIEGE_H
