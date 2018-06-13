namespace unit {

/**
 * @tparam Map a hana::map relating unit key types to unit::Ratios
 */
template< typename Map >
struct Type{ static constexpr auto definition = Map{}; };

#include "dimwits/unit/src/isComposite.hpp"
#include "dimwits/unit/src/dimensionality.hpp"
#include "dimwits/unit/src/symbol.hpp"
#include "dimwits/unit/operation.hpp"

static constexpr auto less = detail::definition<unit::Type>();
  
}

using Unitless = decltype( unit::less );

#include "dimwits/unit/definitions.hpp"
#include "dimwits/unit/src/referenceUnit.hpp"
