namespace quantity {

#include "dimwits/quantity/Type.hpp"

template< typename Unit, typename Magnitude >
constexpr auto dimensionality( Type< Unit, Magnitude > ){
  return dimensionality( Unit{} );
}

}

#include "dimwits/quantity/operation.hpp"

template< typename Unit, typename Magnitude = double >
using Quantity = quantity::Type< Unit, Magnitude >;
