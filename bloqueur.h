#include "element.h"


class Bloqueur : public Element {
public:
    Bloqueur(const std::string& nom, int x, int y);
    bool bloqueLePassage() const { return true; } // renvoie toujours true car elle indique que l'obstacke bloque le passage

    /** Rajout� par Mdou Dian */
    bool seDeplacer(Mobile* mobile, int x, int y) override = 0;
};
