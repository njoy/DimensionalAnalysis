template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto less( Type< n1, d1 >, Type< n2, d2 > ){
  return n1*d2 < n2*d1;
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator<( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return less( r1, r2 );
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator>( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return less( r2, r1 );
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator>=( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return not( r1 < r2 );
}

template< int64_t n1, int64_t n2, int64_t d1, int64_t d2 >
constexpr auto operator<=( Type< n1, d1 > r1, Type< n2, d2 > r2 ){
  return not( r2 < r1 );
}
