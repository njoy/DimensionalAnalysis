namespace dimension {

/**
 * @brief An struct providing dimensional inference in generic code
 *
 * @tparam Map A hana::map of dimwits::basis::Types to dimwits::ratios
 */
template< typename Map >
struct Type{ static constexpr auto definition = Map{}; };

#include "dimwits/dimension/src/isBasis.hpp"
#include "dimwits/dimension/operation.hpp"

template< typename... Ts >
constexpr auto define( Ts... ts ){
  return Type< decltype( operation::definition( ts... ) ) >{};
}

constexpr auto less              = define();
constexpr auto mass              = define( basis::mass             , Ratio<1> );
constexpr auto length            = define( basis::length           , Ratio<1> );
constexpr auto time              = define( basis::time             , Ratio<1> );
constexpr auto current           = define( basis::current          , Ratio<1> );
constexpr auto temperature       = define( basis::temperature      , Ratio<1> );
constexpr auto amount            = define( basis::amount           , Ratio<1> );
constexpr auto luminousIntensity = define( basis::luminousIntensity, Ratio<1> );
constexpr auto planeAngle        = define( basis::planeAngle       , Ratio<1> );
constexpr auto solidAngle        = define( basis::solidAngle       , Ratio<1> );

constexpr auto area = length * length;
constexpr auto volume = area * length;
constexpr auto velocity = length / time;
constexpr auto acceleration = velocity / time;
constexpr auto momentum = mass * velocity;
constexpr auto force = mass * acceleration;
constexpr auto pressure = force / area;
constexpr auto energy = force * length;
constexpr auto power = energy / time;
constexpr auto charge = current * time;
constexpr auto electromotiveForce = energy / charge;
constexpr auto resistance = electromotiveForce / current;
constexpr auto conductance = less / resistance;
constexpr auto capacitance = charge / electromotiveForce;
constexpr auto magneticFlux = energy / current;
constexpr auto magneticFluxDensity = magneticFlux / area;

}

