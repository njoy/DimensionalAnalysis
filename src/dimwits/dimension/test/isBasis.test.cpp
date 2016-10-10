#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::dimension;

SCENARIO("isBasis"){
  REQUIRE( isBasis( length ) );
  REQUIRE( not isBasis( area ) );
}
