namespace unit {

/**
 * @brief The building blocks of unit types
 */
template< typename T >
struct Primitive : hana::type< T >{};

/**
 * @tparam Map a hana::map relating unit::Primitives to unit::Ratios
 */
template< typename Map >
struct Type{ static constexpr auto definition = Map{}; };

#include "dimwits/unit/src/isComposite.hpp"
#include "dimwits/unit/src/dimensionality.hpp"
#include "dimwits/unit/src/symbol.hpp"
#include "dimwits/unit/operation.hpp"

template< typename T >
constexpr auto makePrimitive( T ){ return Primitive< T >{}; }

template< typename T >
using CorrespondingType =
  Type< decltype( hana::make_map( hana::make_pair( T{}, Ratio<1> ) ) ) >;

}

using Unitless = unit::Type< decltype( hana::make_map() ) >;

#include "dimwits/unit/definitions.hpp"
#include "dimwits/unit/src/referenceUnit.hpp"
