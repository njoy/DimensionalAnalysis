namespace quantity {

#include "dimwits/quantity/Type.hpp"

template< typename Unit, typename Magnitude >
constexpr auto dimensionality( Type< Unit, Magnitude > ){
  return dimensionality( Unit{} );
}

template<typename T>
struct isType : std::false_type {};

template<typename Unit, typename Magnitude>
struct isType<Type<Unit, Magnitude>> : std::true_type {};

}

#include "dimwits/quantity/operation.hpp"

template< typename Unit, typename Magnitude = double >
using Quantity = quantity::Type< Unit, Magnitude >;
