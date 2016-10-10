#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("isComposite"){
  REQUIRE( not unit::isComposite( Meter{} ) );
  auto squareMeter = Meter{} * Meter{};
  REQUIRE( unit::isComposite( squareMeter ) );

  REQUIRE( not unit::isComposite( Joule{} ) );
  auto jouleSeconds = Joule{} * Second{};
  REQUIRE( unit::isComposite( jouleSeconds ) );
}
