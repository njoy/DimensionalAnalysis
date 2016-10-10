#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("symbol"){
  REQUIRE( "m " == unit::symbol( Meter() ) );
  REQUIRE( "g " == unit::symbol( Gram() ) );
  REQUIRE( "s " == unit::symbol( Second() ) );
  REQUIRE( "A " == unit::symbol( Ampere() ) );
  REQUIRE( "K " == unit::symbol( Kelvin() ) );
  REQUIRE( "mol " == unit::symbol( Mole() ) );
  REQUIRE( "cd " == unit::symbol( Candela() ) );
  REQUIRE( "rad " == unit::symbol( Radian() ) );
  REQUIRE( "sr " == unit::symbol( Steradian() ) );

  REQUIRE( "slug " == unit::symbol( Slug() ) );
  REQUIRE( "Da " == unit::symbol( Dalton() ) );
  REQUIRE( "lb_m " == unit::symbol( PoundMass() ) );
  REQUIRE( "ton " == unit::symbol( Ton() ) );
  REQUIRE( "t " == unit::symbol( Tonne() ) );
  
  REQUIRE( "angstrom " == unit::symbol( Angstrom() ) );
  REQUIRE( "ly " == unit::symbol( LightYear() ) );
  REQUIRE( "AU " == unit::symbol( AstronomicalUnit() ) );
  REQUIRE( "pc " == unit::symbol( Parsec() ) );
  REQUIRE( "in " == unit::symbol( Inch() ) );
  REQUIRE( "ft " == unit::symbol( Foot() ) );
  REQUIRE( "yd " == unit::symbol( Yard() ) );
  REQUIRE( "mi " == unit::symbol( Mile() ) );

  REQUIRE( "L " == unit::symbol( Liter() ) );

  REQUIRE( "shake " == unit::symbol( Shake() ) );
  REQUIRE( "min " == unit::symbol( Minute() ) );
  REQUIRE( "hr " == unit::symbol( Hour() ) );
  REQUIRE( "d " == unit::symbol( Day() ) );
  REQUIRE( "yr " == unit::symbol( Year() ) );

  REQUIRE( "Gal " == unit::symbol( Gal() ) );

  REQUIRE( "b " == unit::symbol( Barn() ) );

  REQUIRE( "N " == unit::symbol( Newton() ) );
  REQUIRE( "dyn " == unit::symbol( Dyne() ) );
  REQUIRE( "lb " == unit::symbol( Pound() ) );

  REQUIRE( "Pa " == unit::symbol( Pascal() ) );
  REQUIRE( "Ba " == unit::symbol( Barye() ) );
  REQUIRE( "bar " == unit::symbol( Bar() ) );
  REQUIRE( "psi " == unit::symbol( PSI() ) );

  REQUIRE( "J " == unit::symbol( Joule() ) );
  REQUIRE( "erg " == unit::symbol( Erg() ) );
  REQUIRE( "eV " == unit::symbol( ElectronVolt() ) );

  REQUIRE( "W " == unit::symbol( Watt() ) );

  REQUIRE( "C " == unit::symbol( Coulomb() ) );

  REQUIRE( "S " == unit::symbol( Seimens() ) );

  REQUIRE( "F " == unit::symbol( Farad() ) );

  REQUIRE( "Wb " == unit::symbol( Weber() ) );
  
  REQUIRE( "T " == unit::symbol( Tesla() ) );

  /* composite units */
  auto jouleSeconds = Joule() * Second();
  REQUIRE( "s J "
           == unit::symbol( jouleSeconds ) );

  /* exponentiated unit */
  auto squareMeter = Meter() * Meter();
  REQUIRE( "m^2 " == unit::symbol( squareMeter ) );

  auto weird = pow( Meter(), Ratio<2,3> );
  REQUIRE( "m^(2/3) " == unit::symbol( weird ) );
}
