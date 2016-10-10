#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;
namespace hana = boost::hana;

SCENARIO("reduce"){
  GIVEN( "two positive values" ){
    THEN( "the reduction will be equal to the reference"){
      auto reference = hana::type_c< Type< 22, 51 > >;
      auto trial = hana::make_type( reduce< 462, 1071 >() );
      REQUIRE( bool(reference == trial) );
    }
  }
  
  GIVEN( "two negative values" ){
    THEN( "the reduction will be equal to the reference"){
      auto reference = hana::type_c< Type< 22, 51 > >;
      auto trial = hana::make_type( reduce< -462, -1071 >() );
      REQUIRE( bool(reference == trial) );
    }
  }
  
  GIVEN( "a negative numerator" ){
    THEN( "the reduction will be equal to the reference"){
      auto reference = hana::type_c< Type< -22, 51 > >;
      auto trial = hana::make_type( reduce< -462, 1071 >() );
      REQUIRE( bool(reference == trial) );
    }
  }

  GIVEN( "a negative denominator" ){
    THEN( "the reduction will be equal to the reference"){
      auto reference = hana::type_c< Type< -22, 51 > >;
      auto trial = hana::make_type( reduce< 462, -1071 >() );
      REQUIRE( bool(reference == trial) );
    }
  }

  GIVEN( "a negative numerator and denominator" ){
    THEN( "the reduction will be equal to the reference"){
      auto reference = hana::type_c< Type< 22, 51 > >;
      auto trial = hana::make_type( reduce< -462, -1071 >() );
      REQUIRE( bool(reference == trial) );
    }
  }
}
