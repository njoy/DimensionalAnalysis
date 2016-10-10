template< int64_t n, int64_t d >
std::string to_string( ratio::Type<n, d> ){
  return (d == 1) ? std::to_string(n) :
    ( '(' + std::to_string(n) + '/' + std::to_string(d) + ')' );
}

template< typename Definition >
std::string symbol( Type<Definition> ){
  auto stringify = []( std::string partial, auto element ){
    return ( hana::second(element) == Ratio<1> ) ?
    ( partial + symbol( hana::first(element) ) + ' ' ) :
    ( partial + symbol( hana::first(element) )
      + '^' + to_string( hana::second(element) ) + ' ' );
      
  };
  return hana::fold_left( Definition{}, "", stringify );
}
