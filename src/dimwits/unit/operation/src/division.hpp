template< typename Left, typename Right >
auto divide( Type< Left > left, Type< Right > right ){
  return multiply( left, exponentiation( right, Ratio<-1> ) );
}
