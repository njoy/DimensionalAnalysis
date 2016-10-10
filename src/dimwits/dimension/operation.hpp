namespace operation {

#include "dimwits/dimension/operation/src/multiply.hpp"
#include "dimwits/dimension/operation/src/exponentiation.hpp"
#include "dimwits/dimension/operation/src/division.hpp"
#include "dimwits/dimension/operation/src/definition.hpp"

}

template< typename Left, typename Right >
constexpr auto operator*( Type< Left > t0, Type< Right > t1 ){
  return decltype( operation::multiply(t0, t1) ){};
}

template< typename Left, typename Right >
constexpr auto operator/( Type< Left > t0, Type< Right > t1 ){
  return decltype( operation::divide(t0, t1) ){};
}

template< typename Left, typename Right >
constexpr auto operator==( Type< Left >, Type< Right > ){
  return bool(Left{} == Right{});
}

template< typename Left, typename Right >
constexpr auto operator!=( Type< Left > t0, Type< Right > t1 ){
  return not(t0 == t1);
}

template< typename Dimension, int64_t n, int64_t d >
constexpr auto pow( Type< Dimension > t, ratio::Type< n, d > r ){
  return decltype( operation::exponentiation( t, r ) ){};
}
