#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;

SCENARIO("greatestCommonFactor"){  
  // a simple use demonstration
  REQUIRE( 21 == greatestCommonFactor( 1071, 462 ) );
  
  GIVEN("one arguement has an absolute value of 1"){
    THEN("the result will always be one"){
      REQUIRE( 1 == greatestCommonFactor( 1, 10 ) );
      REQUIRE( 1 == greatestCommonFactor( 1, -10 ) );
      REQUIRE( 1 == greatestCommonFactor( -1, 10 ) );
      REQUIRE( 1 == greatestCommonFactor( -1, -10 ) );
      REQUIRE( 1 == greatestCommonFactor( 10, 1 ) );
      REQUIRE( 1 == greatestCommonFactor( 10, -1 ) );
      REQUIRE( 1 == greatestCommonFactor( -10, 1 ) );
      REQUIRE( 1 == greatestCommonFactor( -10, -1 ) );
    }
  }

  GIVEN("two arguments"){
    THEN("the order and sign don't matter"){
      REQUIRE( 3 == greatestCommonFactor( 3, 6 ) );
      REQUIRE( 3 == greatestCommonFactor( 3, -6 ) );
      REQUIRE( 3 == greatestCommonFactor( -3, 6 ) );
      REQUIRE( 3 == greatestCommonFactor( -3, -6 ) );
      REQUIRE( 3 == greatestCommonFactor( 6, 3 ) );
      REQUIRE( 3 == greatestCommonFactor( 6, -3 ) );
      REQUIRE( 3 == greatestCommonFactor( -6, 3 ) );
      REQUIRE( 3 == greatestCommonFactor( -6, -3 ) );
    }
  }
}
