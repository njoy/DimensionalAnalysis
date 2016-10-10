template< int64_t n1, int64_t n2, int64_t d >
constexpr auto add( Type< n1, d >, Type< n2, d > ){
  return reduce< n1 + n2, d >();
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto add( Type< n1, d1 >, Type< n2, d2 > ){
  return add( Type< n1 * d2, d1 * d2 >(), Type< n2 * d1, d1 * d2 >() );
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator+( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return add( r1, r2 );
}
