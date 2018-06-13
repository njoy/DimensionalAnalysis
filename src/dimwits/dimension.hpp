namespace dimension {  
  
/**
 * @brief An struct providing dimensional inference in generic code
 *
 * @tparam Map A hana::map of key types to dimwits::ratios
 */
template< typename Map >
struct Type{ static constexpr auto definition = Map{}; };

#include "dimwits/dimension/src/isBasis.hpp"
#include "dimwits/dimension/operation.hpp"
  
constexpr auto less = detail::definition<Type>();

#define DEFINE( NAME )							\
  									\
  namespace key {							\
  static constexpr struct NAME##_tag :				        \
    hana::type< NAME##_tag > {} NAME{};					\
  }									\
									\
  static constexpr auto NAME = detail::definition<Type>( key::NAME, Ratio<1> )

DEFINE( mass );
DEFINE( length );
DEFINE( time );
DEFINE( current );
DEFINE( temperature );
DEFINE( amount );
DEFINE( luminousIntensity );
DEFINE( planeAngle );
DEFINE( solidAngle );

#undef DEFINE
  
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

