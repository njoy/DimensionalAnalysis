#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;
namespace hana = boost::hana;

SCENARIO("multiply"){
  auto reference = hana::type_c< Type< 6 , 35 > >;
  auto trial = hana::make_type( Type< 2, 7 >{} * Type< 3, 5 >{} );
  REQUIRE( bool(reference == trial) );
}
