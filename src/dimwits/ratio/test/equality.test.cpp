#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits::ratio;

SCENARIO("equality"){
  auto reference = Type<1, 2>{};
  auto equal = reference;
  auto notEqual = Type<1, 1>{} + reference;
  REQUIRE( reference == equal );
  REQUIRE( not(reference == notEqual) );
  REQUIRE( reference != notEqual );
  REQUIRE( not(reference != equal ));
}
