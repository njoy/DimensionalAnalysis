template< typename Definition >
constexpr bool isBasis( Type< Definition > t ){
  return decltype( detail::isBasis(t) )::value;
}
