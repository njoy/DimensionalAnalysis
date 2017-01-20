#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

TEST_CASE("factorValue"){
  REQUIRE( conversion::factorValue( Foot(), Kilo<Meter>() )
           == Approx(0.0003048) );
  
  SECTION("Same to same"){
    REQUIRE( conversion::factorValue( Meter(), Meter() ) == 1.0 );
    REQUIRE( conversion::factorValue( Kilo<Meter>(), Kilo<Meter>() ) == 1.0 );
    REQUIRE( conversion::factorValue( Kilo<Meter>() * Foot(),
                                      Foot() * Kilo<Meter>() ) == 1.0 );
    REQUIRE( conversion::factorValue( Newton() * Meter(),
                                      Meter() * Newton() ) == 1.0 );
  }

  SECTION("Scaled"){
    REQUIRE( conversion::factorValue( Kilo<Meter>(), Meter() ) == 1E3 );
    REQUIRE( conversion::factorValue( Meter(), Kilo<Meter>() ) == 1E-3 );
    REQUIRE( conversion::factorValue( Kilo<Meter>() * Foot(),
                                      Meter() * Foot() ) == 1E3 );
    REQUIRE( conversion::factorValue( Meter() * Foot(),
                                      Kilo<Meter>() * Foot() ) == 1E-3 );
  }
  SECTION("Compound"){
    auto tol = []( auto reference, auto trial ){
      return std::abs( reference - trial ) / reference < 1E-9;
    };
    REQUIRE( tol( conversion::factorValue( Slug() * Foot() / Hour(),
                                           Gal() * Shake() * Tonne() ),
		  12356.1712 ) );
  }
}
