template< typename Magnitude, typename Unit >
constexpr auto operator-( quantity::Type< Unit, Magnitude > argument ){
  argument.value *= -1;
  return argument;
}

template< typename Magnitude, typename Unit >
constexpr auto operator+( quantity::Type< Unit, Magnitude > argument ){
  return argument;
}
