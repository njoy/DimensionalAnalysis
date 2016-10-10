template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto multiply( Type< n1, d1 >, Type< n2, d2 > ){
  return reduce< n1 * n2, d1 * d2 >();
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator*( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return multiply( r1, r2 );
}
