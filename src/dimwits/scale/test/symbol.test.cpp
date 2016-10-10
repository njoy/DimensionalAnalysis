#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("symbol"){
  REQUIRE( "Ym"  == symbol( yotta(meter) ) );
  REQUIRE( "Zm"  == symbol( zetta(meter) ) );
  REQUIRE( "Em"  == symbol( exa(meter) ) );
  REQUIRE( "Pm"  == symbol( peta(meter) ) );
  REQUIRE( "Tm"  == symbol( tera(meter) ) );
  REQUIRE( "Gm"  == symbol( giga(meter) ) );
  REQUIRE( "Mm"  == symbol( mega(meter) ) );
  REQUIRE( "km"  == symbol( kilo(meter) ) );
  REQUIRE( "hm"  == symbol( hecto(meter) ) );
  REQUIRE( "dam" == symbol( deka(meter) ) );
  REQUIRE( "dm"  == symbol( deci(meter) ) );
  REQUIRE( "cm"  == symbol( centi(meter) ) );
  REQUIRE( "mm"  == symbol( milli(meter) ) );
  REQUIRE( "um"  == symbol( micro(meter) ) );
  REQUIRE( "nm"  == symbol( nano(meter) ) );
  REQUIRE( "pm"  == symbol( pico(meter) ) );
  REQUIRE( "fm"  == symbol( femto(meter) ) );
  REQUIRE( "am"  == symbol( atto(meter) ) );
  REQUIRE( "zm"  == symbol( zepto(meter) ) );
  REQUIRE( "ym"  == symbol( yocto(meter) ) );
}
