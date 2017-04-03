namespace operation {

#include "dimwits/unit/operation/src/multiply.hpp"
#include "dimwits/unit/operation/src/exponentiation.hpp"
#include "dimwits/unit/operation/src/division.hpp"

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
  return Left{} == Right{};
}

template< typename Left, typename Right >
constexpr auto operator!=( Type< Left > t0, Type< Right > t1 ){
  return not(t0 == t1);
}

template< typename Unit, int64_t n, int64_t d >
constexpr auto pow( Type< Unit > t, ratio::Type< n, d > r ){
    return decltype( operation::exponentiation( t, r ) ){};
}

template< typename Unit >
constexpr auto pow( Type< Unit > t ){
  return decltype( operation::exponentiation( t, Ratio< 1, 2 > ) ){};
}
