#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("factor"){
  REQUIRE( 1E24  == scale::factor( scale::Yotta() ) );
  REQUIRE( 1E21  == scale::factor( scale::Zetta() ) );
  REQUIRE( 1E18  == scale::factor( scale::Exa() ) );
  REQUIRE( 1E15  == scale::factor( scale::Peta() ) );
  REQUIRE( 1E12  == scale::factor( scale::Tera() ) );
  REQUIRE( 1E9   == scale::factor( scale::Giga() ) );
  REQUIRE( 1E6   == scale::factor( scale::Mega() ) );
  REQUIRE( 1E3   == scale::factor( scale::Kilo() ) );
  REQUIRE( 1E2   == scale::factor( scale::Hecto() ) );
  REQUIRE( 10    == scale::factor( scale::Deka() ) );
  REQUIRE( 0.1   == scale::factor( scale::Deci() ) );
  REQUIRE( 1E-2  == scale::factor( scale::Centi() ) );
  REQUIRE( 1E-3  == scale::factor( scale::Milli() ) );
  REQUIRE( 1E-6  == scale::factor( scale::Micro() ) );
  REQUIRE( 1E-9  == scale::factor( scale::Nano() ) );
  REQUIRE( 1E-12 == scale::factor( scale::Pico() ) );
  REQUIRE( 1E-15 == scale::factor( scale::Femto() ) );
  REQUIRE( 1E-18 == scale::factor( scale::Atto() ) );
  REQUIRE( 1E-21 == scale::factor( scale::Zepto() ) );
  REQUIRE( 1E-24 == scale::factor( scale::Yocto() ) );
}
