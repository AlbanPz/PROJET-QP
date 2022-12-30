#include "doctest.h"
#include "mobile.h"






TEST_CASE("[Mobile] Le mobile est bien construit") {
 // constructeur avec x, y, force et typeDeplacement
 int x = 10, y = 15, force = 30, typeDeplacement = 10;


    Mobile a {"test",x,y,force,typeDeplacement};


    REQUIRE( a.x() == x );
    REQUIRE( a.y() == y );
    REQUIRE( a.force() == force );
    REQUIRE( a.typeDeplacement() == typeDeplacement );

}





