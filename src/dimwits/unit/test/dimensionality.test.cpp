#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("dimensionality"){
  REQUIRE( dimension::length == unit::dimensionality( Meter() ) );
  REQUIRE( dimension::mass == unit::dimensionality( Gram() ) );
  REQUIRE( dimension::time == unit::dimensionality( Second() ) );
  REQUIRE( dimension::current == unit::dimensionality( Ampere() ) );
  REQUIRE( dimension::temperature == unit::dimensionality( Kelvin() ) );
  REQUIRE( dimension::amount == unit::dimensionality( Mole() ) );
  REQUIRE( dimension::luminousIntensity == unit::dimensionality( Candela() ) );
  REQUIRE( dimension::planeAngle == unit::dimensionality( Radian() ) );
  REQUIRE( dimension::solidAngle == unit::dimensionality( Steradian() ) );

  REQUIRE( dimension::mass == unit::dimensionality( Slug() ) );
  REQUIRE( dimension::mass == unit::dimensionality( Dalton() ) );
  REQUIRE( dimension::mass == unit::dimensionality( PoundMass() ) );
  REQUIRE( dimension::mass == unit::dimensionality( Ton() ) );
  REQUIRE( dimension::mass == unit::dimensionality( Tonne() ) );
  
  REQUIRE( dimension::length == unit::dimensionality( Angstrom() ) );
  REQUIRE( dimension::length == unit::dimensionality( LightYear() ) );
  REQUIRE( dimension::length == unit::dimensionality( AstronomicalUnit() ) );
  REQUIRE( dimension::length == unit::dimensionality( Parsec() ) );
  REQUIRE( dimension::length == unit::dimensionality( Inch() ) );
  REQUIRE( dimension::length == unit::dimensionality( Foot() ) );
  REQUIRE( dimension::length == unit::dimensionality( Yard() ) );
  REQUIRE( dimension::length == unit::dimensionality( Mile() ) );

  REQUIRE( dimension::volume == unit::dimensionality( Liter() ) );

  REQUIRE( dimension::time == unit::dimensionality( Shake() ) );
  REQUIRE( dimension::time == unit::dimensionality( Minute() ) );
  REQUIRE( dimension::time == unit::dimensionality( Hour() ) );
  REQUIRE( dimension::time == unit::dimensionality( Day() ) );
  REQUIRE( dimension::time == unit::dimensionality( Year() ) );

  REQUIRE( dimension::acceleration == unit::dimensionality( Gal() ) );

  REQUIRE( dimension::area == unit::dimensionality( Barn() ) );

  REQUIRE( dimension::force == unit::dimensionality( Newton() ) );
  REQUIRE( dimension::force == unit::dimensionality( Dyne() ) );
  REQUIRE( dimension::force == unit::dimensionality( Pound() ) );

  REQUIRE( dimension::pressure == unit::dimensionality( Pascal() ) );
  REQUIRE( dimension::pressure == unit::dimensionality( Barye() ) );
  REQUIRE( dimension::pressure == unit::dimensionality( Bar() ) );
  REQUIRE( dimension::pressure == unit::dimensionality( PSI() ) );

  REQUIRE( dimension::energy == unit::dimensionality( Joule() ) );
  REQUIRE( dimension::energy == unit::dimensionality( Erg() ) );
  REQUIRE( dimension::energy == unit::dimensionality( ElectronVolt() ) );

  REQUIRE( dimension::power == unit::dimensionality( Watt() ) );

  REQUIRE( dimension::charge == unit::dimensionality( Coulomb() ) );

  REQUIRE( dimension::conductance == unit::dimensionality( Seimens() ) );

  REQUIRE( dimension::capacitance == unit::dimensionality( Farad() ) );

  REQUIRE( dimension::magneticFlux == unit::dimensionality( Weber() ) );
  
  REQUIRE( dimension::magneticFluxDensity == unit::dimensionality( Tesla() ) );

  /* composite units */
  auto squareMeter = Meter() * Meter();
  REQUIRE( dimension::area == unit::dimensionality( squareMeter ) );

  auto jouleSeconds = Joule() * Second();
  REQUIRE( dimension::energy * dimension::time
           == unit::dimensionality( jouleSeconds ) );

  REQUIRE( dimension::energy
           == unit::dimensionality( Gram() * Meter() * Meter()
                                    / Second() / Second() ) );

  REQUIRE( sqrt( dimension::mass ) ==
           unit::dimensionality( pow( Gram(), Ratio<1,2> ) ) );

  REQUIRE( sqrt( dimension::mass ) / dimension::energy ==
           unit::dimensionality( pow( Gram(), Ratio<1,2> )
                                 / Joule() ) );

  REQUIRE( sqrt( dimension::mass ) / sqrt( dimension::energy ) ==
           unit::dimensionality( pow( Gram(), Ratio<1,2> )
                                 * pow( ElectronVolt(), Ratio<1,2> )
                                 / Joule() ) );

  REQUIRE( sqrt( dimension::mass )
           / sqrt( dimension::energy )
           / dimension::time
           == unit::dimensionality( pow( Gram(), Ratio<1,2> )
                                    / pow( Joule(), Ratio<1,2> ) / Second() ) );

  REQUIRE( sqrt( dimension::mass )
           / sqrt( dimension::energy )
           / dimension::time ==
           unit::dimensionality( pow( Gram(), Ratio<1,2> )
                                 * pow( ElectronVolt(), Ratio<1,2> )
                                 / Joule() / Second() ) );
  
  REQUIRE( sqrt( dimension::mass )
           / sqrt( dimension::energy )
           / dimension::time == pow( dimension::length, Ratio<-1> ) );
  
  REQUIRE( pow( dimension::length, Ratio<-1> )
           == unit::dimensionality( pow( Gram(), Ratio<1,2> )
                                    * pow( Joule(), Ratio<1,2> )
                                    / Joule() / Second() ) );
  
}
