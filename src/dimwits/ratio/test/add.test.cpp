#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;
namespace hana = boost::hana;

SCENARIO("ratio add"){
  WHEN( "arguments shared a denominator" ){
    auto reference = hana::type_c< Type< 1, 5 > >;
    auto trial = hana::make_type( Type< 1, 10 >{} + Type< 1, 10 >{} );
    REQUIRE( bool(reference == trial) );
  }
  WHEN( "arguments do not share a denominator" ){
    auto reference = hana::type_c< Type< 3 , 4 > >;
    auto trial = hana::make_type( Type< 3, 6 >{} + Type< 1, 4 >{} );
    REQUIRE( bool(reference == trial) );
  }
}
