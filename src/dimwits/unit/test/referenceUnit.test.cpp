#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("referenceUnit"){
  REQUIRE( Meter() == referenceUnit( dimension::length ) );
  REQUIRE( meter == referenceUnit( dimension::length ) );
  REQUIRE( Gram() == referenceUnit( dimension::mass ) );
  REQUIRE( gram == referenceUnit( dimension::mass ) );
  REQUIRE( Second() == referenceUnit( dimension::time ) );
  REQUIRE( second == referenceUnit( dimension::time ) );
  REQUIRE( Ampere() == referenceUnit( dimension::current ) );
  REQUIRE( ampere == referenceUnit( dimension::current ) );
  REQUIRE( Kelvin() == referenceUnit( dimension::temperature ) );
  REQUIRE( kelvin == referenceUnit( dimension::temperature ) );
  REQUIRE( Mole() == referenceUnit( dimension::amount ) );
  REQUIRE( mole == referenceUnit( dimension::amount ) );
  REQUIRE( Candela() == referenceUnit( dimension::luminousIntensity ) );
  REQUIRE( Radian() == referenceUnit( dimension::planeAngle ) );
  REQUIRE( Steradian() == referenceUnit( dimension::solidAngle ) );
 
  REQUIRE( Meter() * Meter() == referenceUnit( dimension::area ) );
  REQUIRE( Meter() / Second() == referenceUnit( dimension::velocity ) );
}
