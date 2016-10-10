template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto subtract( Type< n1, d1 > r1, Type< n2, d2 > ){
  return add( r1, Type< -n2, d2 >() );
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator-( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return subtract( r1, r2 );
}

template< int64_t n1, int64_t d1 >
constexpr auto operator-( Type< n1, d1 > ){
  return Type< -n1, d1 >();
}
