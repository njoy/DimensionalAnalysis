#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;
namespace dim = dimwits::dimension;

TEST_CASE("operations"){
  REQUIRE( dim::mass == dim::mass );
  REQUIRE( dim::mass != dim::time );
  
  SECTION("multiplication is commutative"){
    REQUIRE( dim::mass * dim::time == dim::time * dim::mass );
    REQUIRE( dim::mass * dim::time * dim::length
             == dim::time * dim::mass * dim::length );
  }

  SECTION("multiplication is associative"){
    REQUIRE( (dim::mass * dim::time) * dim::length == dim::mass * (dim::time * dim::length) );
  }

  SECTION("division is the inverse of multiplication"){
    auto composite = dim::mass * dim::time * dim::length;
    REQUIRE( dim::mass * dim::time == composite / dim::length );
    REQUIRE( dim::mass * dim::length == composite / dim::time );
    REQUIRE( dim::time * dim::length == composite / dim::mass );
    
    auto squareComposite = composite * composite;
    REQUIRE( composite * dim::mass * dim::time
             == squareComposite / dim::length );
    REQUIRE( composite * dim::mass * dim::time * pow( dim::length, Ratio<1,2> )
             == squareComposite / pow( dim::length, Ratio<1,2> ) );
    REQUIRE( dim::less / dim::mass == pow( dim::mass, -Ratio<1> ) );
  }

  SECTION("exponentiation is repeated multiplication"){
    auto composite = dim::mass * dim::mass * dim::mass;
    REQUIRE( pow( dim::mass, Ratio<3> ) == composite );
    REQUIRE( pow( dim::mass, Ratio<-3> ) == dim::less/composite );
    REQUIRE( pow( dim::mass, Ratio<5,2> )
             == composite / pow( dim::mass, Ratio<1,2> ) );
  }

  SECTION("sqrt is halfing the dimension power"){
    REQUIRE( sqrt( pow( dim::mass, Ratio<3> ) ) == pow( dim::mass, Ratio<3,2> ) );
  }
}
