#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;
namespace hana = boost::hana;

SCENARIO("subtract"){
  auto reference = hana::type_c< Type< 1, 10 > >;
  WHEN( "arguments shared a denominator" ){
    auto trial = hana::make_type( Type< 2, 10 >{} - Type< 1, 10 >{} );
    REQUIRE( bool(reference == trial) );
  }
  WHEN( "arguments do not share a denominator" ){
    auto trial = hana::make_type( Type< 1, 5 >{} - Type< 1, 10 >{} );
    REQUIRE( bool(reference == trial) );
  }
  WHEN( "unary minus" ){
    auto trial = hana::make_type( -Type< -1, 10 >{} );
    REQUIRE( bool(reference == trial) );
  }
}
