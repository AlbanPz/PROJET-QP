#include "bloqueur.h"

Bloqueur::Bloqueur(const std::string& nom, int x, int y):
    Element{nom, "Bloqueur", x, y}
{}

bool Bloqueur::seDeplacer(Mobile* mobile, int x, int y)
{
    return false;
}
