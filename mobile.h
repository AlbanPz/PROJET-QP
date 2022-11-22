#ifndef MOBILE_H
#define MONILE_H

#include <iostream>


class mobile: public element
{
public :

    void avancer ( element& );
    bool peutSeDeplacer( const element&)const;
private:


};



#endif // MOBILE_H
