#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("dimensionality"){
  REQUIRE( dimension::length == dimensionality( kilo(meter) ) );
  REQUIRE( dimension::energy == dimensionality( micro(joule) ) );
}
