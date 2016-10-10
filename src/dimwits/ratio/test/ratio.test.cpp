#define CATCH_CONFIG_MAIN

#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("ratio template variable"){
  auto left = Ratio<2,4>;
  auto right = Ratio<1,2>;
  REQUIRE( left == right );
}














