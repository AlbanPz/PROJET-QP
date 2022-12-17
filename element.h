#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <string>

class Element
{
public:
    Element(const std::string& nom, int x, int y);
    int x() const;
    int y() const;

    // changer la position de l'élément  A FAIRE
    void changerPosition ( int x, int y);
    std::string nom() const;
private:
    std::string d_nom;
    int d_x;
    int d_y;
};

#endif // ELEMENT_H_INCLUDED
