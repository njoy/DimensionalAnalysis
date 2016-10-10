template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto divide( Type< n1, d1 > r1, Type< n2, d2 > ){
  static_assert( n2 != 0, "" );
  return multiply( r1, Type< d2, n2 >() );
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator/( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return divide( r1, r2 );
}
