#ifndef PIEGE_H_INCLUDED
#define PIEGE_H_INCLUDED

#include "element.h"
class piege : public Element {

public:
piege (int x,int y,int capa);
int capacite() const;
void diminuerCapacite();

private:
int d_capacite;

};

#endif // PIEGE_H_INCLUDED
