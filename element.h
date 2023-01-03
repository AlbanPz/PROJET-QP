#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <string>

class Mobile;

class Element
{
public:
    Element(const std::string& nom, const std::string& type, int x, int y);
    std::string nom() const;
    std::string type() const;
    int x() const;
    int y() const;
    void changerPosition (int x, int y);
    virtual bool seDeplacer(Mobile* mobile, int x, int y) = 0;
    virtual ~Element() = default;
private:
    std::string d_nom;
    std::string d_type;
    int d_x;
    int d_y;
};

#endif // ELEMENT_H_INCLUDED
