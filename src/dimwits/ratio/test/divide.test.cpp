#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;
namespace hana = boost::hana;

SCENARIO("divide"){
  auto reference = hana::type_c< Type< 2 , 7 > >;
  auto trial = hana::make_type( Type< 6, 35 >{} / Type< 3, 5 >{} );
  REQUIRE( bool(reference == trial) );
}
