#ifndef BLOQUEUR_H
#define BLOQUEUR_H

#include "element.h"

class Bloqueur : public Element
{
public:
    Bloqueur(const std::string& nom, int x, int y);
    bool bloqueLePassage() const { return true; } // renvoie toujours true car il indique que l'obstacle bloque le passage
    bool seDeplacer(Mobile* mobile, int x, int y) override;
};

#endif // BLOQUEUR_H
