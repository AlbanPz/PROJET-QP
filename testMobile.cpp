#include "doctest.h"
#include "mobile.h"

/*

TEST_CASE("[Point] Les points sont bien construits") {
//constructeur avec x et y
double x {31.21}, y {-32.3};
point p1 {x,y};
REQUIRE( p1.x() == x );
REQUIRE( p1.y() == y );
//constructeur par défaut
point p2 {};
REQUIRE( p2.x() == 0.0 );
REQUIRE( p2.y() == 0.0 );
}
*/


/** Cette partie ne compilait pas Cedric */


TEST_CASE("[Mobile] Le mobile est bien construit") {
 // constructeur avec x, y, force et typeDeplacement
 int x = 10, y = 15, force = 30, typeDeplacement = 10;

    Mobile a {"test",x,y,force,typeDeplacement};

    REQUIRE( a.x() == x );
    REQUIRE( a.y() == y );
    REQUIRE( a.force() == force );
    REQUIRE( a.typeDeplacement() == typeDeplacement );

}

