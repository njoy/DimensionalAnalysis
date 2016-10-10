#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dimwits.hpp"

using namespace dimwits;

template< typename T >
constexpr bool isDistinct( T, T ){ return false; }

template< typename T0, typename T1 >
constexpr bool isDistinct( T0, T1 ){ return true; }

TEST_CASE( "Verify the basis instances are of distinct types" ){
  REQUIRE( isDistinct( basis::mass, basis::length ) );
  REQUIRE( isDistinct( basis::mass, basis::time ) );
  REQUIRE( isDistinct( basis::mass, basis::current ) );
  REQUIRE( isDistinct( basis::mass, basis::temperature ) );
  REQUIRE( isDistinct( basis::mass, basis::amount ) );
  REQUIRE( isDistinct( basis::mass, basis::luminousIntensity ) );
  REQUIRE( isDistinct( basis::mass, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::mass, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::length, basis::time ) );
  REQUIRE( isDistinct( basis::length, basis::current ) );
  REQUIRE( isDistinct( basis::length, basis::temperature ) );
  REQUIRE( isDistinct( basis::length, basis::amount ) );
  REQUIRE( isDistinct( basis::length, basis::luminousIntensity ) );
  REQUIRE( isDistinct( basis::length, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::length, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::time, basis::current ) );
  REQUIRE( isDistinct( basis::time, basis::temperature ) );
  REQUIRE( isDistinct( basis::time, basis::amount ) );
  REQUIRE( isDistinct( basis::time, basis::luminousIntensity ) );
  REQUIRE( isDistinct( basis::time, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::time, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::current, basis::temperature ) );
  REQUIRE( isDistinct( basis::current, basis::amount ) );
  REQUIRE( isDistinct( basis::current, basis::luminousIntensity ) );
  REQUIRE( isDistinct( basis::current, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::current, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::temperature, basis::amount ) );
  REQUIRE( isDistinct( basis::temperature, basis::luminousIntensity ) );
  REQUIRE( isDistinct( basis::temperature, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::temperature, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::amount, basis::luminousIntensity ) );
  REQUIRE( isDistinct( basis::amount, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::amount, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::luminousIntensity, basis::planeAngle ) );
  REQUIRE( isDistinct( basis::luminousIntensity, basis::solidAngle ) );
  REQUIRE( isDistinct( basis::planeAngle, basis::solidAngle ) );
}
