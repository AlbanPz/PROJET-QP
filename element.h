#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

class Element
{
public:
    Element(int x, int y);
    int x() const;
    int y() const;
    virtual char affiche() const =0;
    virtual ~Element() =default;
private:
    int d_x;
    int d_y;
};

#endif // ELEMENT_H_INCLUDED
