template< typename Left, typename Right >
constexpr auto operator*( Type< Left > t0, Type< Right > t1 ){
  return decltype( detail::operation::multiply(t0, t1) ){};
}

template< typename Left, typename Right >
constexpr auto operator/( Type< Left > t0, Type< Right > t1 ){
  return decltype( detail::operation::divide(t0, t1) ){};
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
  return decltype( detail::operation::exponentiation( t, r ) ){};
}

template< typename Dimension >
constexpr auto sqrt( Type< Dimension > t ){
  return decltype( detail::operation::exponentiation( t, Ratio<1,2> ) ){};
}

