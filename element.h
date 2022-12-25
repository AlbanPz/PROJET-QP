#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <string>

class Element
{
public:
    Element(const std::string& nom, int x, int y);
    std::string nom() const;
    int x() const;
    int y() const;
    void changerPosition (int x, int y);
private:
    std::string d_nom;
    int d_x;
    int d_y;
};

#endif // ELEMENT_H_INCLUDED
