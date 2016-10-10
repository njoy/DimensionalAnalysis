#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;

SCENARIO("make"){
  auto reference = reduce< 462, 1071 >();
  auto trial = make< 462, 1071 >();
  REQUIRE( reference == trial );
}
