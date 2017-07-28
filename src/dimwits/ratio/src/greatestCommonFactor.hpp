/** @brief constexpr implementation of Euclid's algorithm for int64_t */
constexpr int64_t greatestCommonFactor( int64_t t1, int64_t t2 ){
  return
    ( t1 == 0 ) ? 1 :
    ( t1 < 0 )  ? greatestCommonFactor( -t1, t2 ) :
    ( t2 < 0 )  ? greatestCommonFactor( t1, -t2 ) :
    ( t1 < t2 ) ? greatestCommonFactor( t2, t1 ) :
    ( t2 < 2 )  ? 1:
    ( t1 % t2 ) ? greatestCommonFactor( t2, t1 % t2 ):
                  t2;
}
