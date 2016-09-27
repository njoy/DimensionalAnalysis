#ifndef NJOY_DIMWITS
#define NJOY_DIMWITS

#include <cmath>
#include <string>
#include <iostream>
#include "boost/hana.hpp"

#ifndef TEST_DIMWITS
#define DOCTEST_CONFIG_DISABLE
#endif

#include "doctest.h"

namespace dimwits{

namespace hana = boost::hana;

/* Work around for lack of constexpr lambdas in C++14 */
/* Throughout the dimwits source, tag structs are used to create unique
 * instantiations of template classes, which are in turn used as types for 
 * constexpr variables. Ideally these tag structs would require no input on the
 * the part of the implementor. Lambdas are gaurunteed to be of a unique type,
 * and hence seem like a good candidate. However, because lambdas are not 
 * permitted to be specified in an unevaluated context (such as sizeof or 
 * decltype), and cannot be used within the scope of a constant expression 
 * (prior to C++ 17), some shennanigans are required.
 *
 * Here we leverage two properties
 * 1) both branches of the ternary operator must return the same type
 * 2) the nullptr can be implicitly converted to any pointer type as a constexpr
 */
template< typename T >
auto address( T&& t ) { return &t; }

#define NEW_TAG() ( true ? nullptr : address( [](){} ) )
/**
 * The ternary condition is known at compile time so the address function
 * never evaluated but the a unique type it supplies will be deduced for the 
 * ternary return type;
 */

#include "dimwits/ratio.hpp"
#include "dimwits/basis.hpp"
#include "dimwits/dimension.hpp"
#include "dimwits/unit.hpp"
#include "dimwits/scale.hpp"
#include "dimwits/conversion.hpp"
#include "dimwits/quantity.hpp"
#include "dimwits/constants.hpp"

#undef NEW_TAG

}

#ifdef DOCTEST_CONFIG_DISABLE
#undef DOCTEST_CONFIG_DISABLE
#endif

#endif
