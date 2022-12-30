#ifndef PIEGE_H_INCLUDED
#define PIEGE_H_INCLUDED

#include "element.h"
class Piege : public Element {

public:
    Piege (int x, int y, int capa);
    int capacite() const;
    void diminuerCapacite();

    /** Rajout� par Mdou Dian */
    bool seDeplacer(Mobile* mobile, int x, int y) override;
private:
    int d_capacite;

};

#endif // PIEGE_H_INCLUDED
