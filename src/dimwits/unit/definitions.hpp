#include "dimwits/unit/macros.hpp"

/* A collection of recognized units */

/* Basis units which define the reference unit for each dimension */
DEFINE_BASIS_UNIT( meter, length, m, Meter )
constexpr auto meters = meter;

DEFINE_BASIS_UNIT( gram, mass, g, Gram )
constexpr auto grams = gram;

DEFINE_BASIS_UNIT( second, time, s, Second )
constexpr auto seconds = second;

DEFINE_BASIS_UNIT( ampere, current, A, Ampere )
constexpr auto amperes = ampere;

DEFINE_BASIS_UNIT( kelvin, temperature, K, Kelvin )
constexpr auto kelvins = kelvin;

DEFINE_BASIS_UNIT( mole, amount, mol, Mole )
constexpr auto moles = mole;

DEFINE_BASIS_UNIT( candela, luminousIntensity, cd, Candela )
constexpr auto candelas = candela;

DEFINE_BASIS_UNIT( radian, planeAngle, rad, Radian )
constexpr auto radians = radian;

DEFINE_BASIS_UNIT( steradian, solidAngle, sr, Steradian )
constexpr auto steradians = steradian;

/* Units are defined using a macro defined in the macro header file.
 * The format of the macro is
 * DEFINE_UNIT( name, dimension, symbol, type, ratio )
 * where: 
 * 'name' is the name of the unit::Primitive constant.
 * 'dimension' is the name of the dimension constant.
 * 'symbol' is the unit symbol.
 * 'type' is the name of the unit::Type.
 * 'ratio' is the unit's ratio relative to the corresponding reference unit
 */

// mass units
// reference unit: 1 gram
DEFINE_UNIT( slug, mass, slug, Slug, 14593.903 )
constexpr auto slugs = slug;

DEFINE_UNIT( dalton, mass, Da, Dalton, 1.660539040E-24 )
constexpr auto daltons = dalton;

DEFINE_UNIT( poundMass, mass, lb_m, PoundMass, 453.59237 )
constexpr auto poundsMass = poundMass;

DEFINE_UNIT( ton, mass, ton, Ton, 907184.74 )
constexpr auto tons = ton;

DEFINE_UNIT( tonne, mass, t, Tonne, 1000000.0 )
constexpr auto tonnes = tonne;

// length units
// reference unit: 1 meter
DEFINE_UNIT( angstrom, length, angstrom, Angstrom, 1E-10 )
constexpr auto angstroms = angstrom;

DEFINE_UNIT( lightYear, length, ly, LightYear, 9.4607304725808E15 )
constexpr auto lightYears = lightYear;

DEFINE_UNIT( astronomicalUnit, length, AU, AstronomicalUnit, 1.495978707E11 )
constexpr auto astronomicalUnits = astronomicalUnit;

DEFINE_UNIT( parsec, length, pc, Parsec, 3.08567758149137E16 )
constexpr auto parsecs = parsec;

DEFINE_UNIT( inch, length, in, Inch, 0.0254 )
constexpr auto inches = inch;

DEFINE_UNIT( foot, length, ft, Foot, 0.3048 )
constexpr auto feet = foot;

DEFINE_UNIT( yard, length, yd, Yard, 0.9144 )
constexpr auto yards = yard;

DEFINE_UNIT( mile, length, mi, Mile, 1609.344 )
constexpr auto miles = mile;

// volume units
// reference unit: 1 meter * meter * meter
DEFINE_UNIT( liter, volume, L, Liter, 1E-3 )
constexpr auto liters = liter;

// time units
// reference unit: 1 second
DEFINE_UNIT( shake, time, shake, Shake, 1E-8 )
constexpr auto shakes = shake;

DEFINE_UNIT( minute, time, min, Minute, 60 )
constexpr auto minutes = minute;

DEFINE_UNIT( hour, time, hr, Hour, 3600 )
constexpr auto hours = hour;

DEFINE_UNIT( day, time, d, Day, 86400 )
constexpr auto days = day;

DEFINE_UNIT( year, time, yr, Year, 31556952 )
constexpr auto years = year;

// acceleration units
// reference unit: 1 meter / second / second
DEFINE_UNIT( gal, acceleration, Gal, Gal, 1E-2 )
constexpr auto gals = gal;

// area units
// reference unit: 1 meter * meter
DEFINE_UNIT( barn, area, b, Barn, 1E-28 )
constexpr auto barns = barn;

// force units
// reference unit: 1 gram * meter / second / second
DEFINE_UNIT( newton, force, N, Newton, 1E3 )
constexpr auto newtons = newton;

DEFINE_UNIT( dyne, force, dyn, Dyne, 1E-2 )
constexpr auto dynes = dyne;

DEFINE_UNIT( pound, force, lb, Pound, 4448.222 )
constexpr auto pounds = pound;

// pressure units
// reference unit: 1 gram / meter / second / second
DEFINE_UNIT( pascal, pressure, Pa, Pascal, 1E3 )
constexpr auto pascals = pascal;

DEFINE_UNIT( barye, pressure, Ba, Barye, 1E2 )
constexpr auto baryes = barye;

DEFINE_UNIT( bar, pressure, bar, Bar, 1E8 )
constexpr auto bars = bar;

DEFINE_UNIT( psi, pressure, psi, PSI, 6894757.29 )

// energy unit
// reference unit: 1 gram * meter * meter / second / second
DEFINE_UNIT( joule, energy, J, Joule, 1E3 )
constexpr auto joules = joule;

DEFINE_UNIT( erg, energy, erg, Erg, 1E-4 )
constexpr auto ergs = erg;

DEFINE_UNIT( electronVolt, energy, eV, ElectronVolt, 1.6021766208E-16 )
constexpr auto electronVolts = electronVolt;

// power unit
// reference unit: 1 gram * meter * meter / second / second / second
DEFINE_UNIT( watt, power, W, Watt, 1E3 )
constexpr auto watts = watt;

// electrical charge
// reference unit: ampere * second
DEFINE_UNIT( coulomb, charge, C, Coulomb, 1 )
constexpr auto coulombs = coulomb;

// electrical conductance
// reference unit: second * second * second * ampere * ampere / meter / meter / gram
DEFINE_UNIT( seimens, conductance, S, Seimens, 1E-3 )

// electrical capacitance
// reference unit: second * second * second * second * ampere * ampere / meter / meter / gram
DEFINE_UNIT( farad, capacitance, F, Farad, 1E-3 )
constexpr auto farads = farad;

// magneticFlux
// reference unit: gram * meter * meter / second / second / ampere 
DEFINE_UNIT( weber, magneticFlux, Wb, Weber, 1E3 )
constexpr auto webers = weber;

// magneticFluxDensity
// reference unit: gram / second / second / ampere 
DEFINE_UNIT( tesla, magneticFluxDensity, T, Tesla, 1E3 )
constexpr auto teslas = tesla;

#undef DEFINE_BASIS_UNIT
#undef DEFINE_UNIT
