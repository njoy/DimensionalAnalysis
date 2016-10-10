#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("referenceUnitRatio"){ 
  REQUIRE( 1E24  == referenceUnitRatio( yotta(meter) ) );
}
