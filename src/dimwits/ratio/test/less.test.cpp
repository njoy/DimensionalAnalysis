#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;

SCENARIO("less"){
  auto lesser = Type<1,1>{};
  auto greater = Type<2,1>{};

  REQUIRE( lesser < greater );
  REQUIRE( not(lesser < lesser) );
  REQUIRE( not(greater < lesser) );

  REQUIRE( greater > lesser );
  REQUIRE( not(lesser > lesser) );
  REQUIRE( not(lesser > greater) );
  
  REQUIRE( lesser <= lesser );
  REQUIRE( lesser <= greater );
  REQUIRE( not(greater <= lesser) );
  
  REQUIRE( greater >= lesser );
  REQUIRE( greater >= greater );
  REQUIRE( not(lesser >= greater) );
}
