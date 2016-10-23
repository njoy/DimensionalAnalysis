template< typename Left, typename Right >
auto multiply( Type< Left >, Type< Right > ){
  
  auto left = Left{};
  auto right = Right{};

  auto dimensions =
    hana::union_( hana::to_set( hana::keys( left ) ),
		  hana::to_set( hana::keys( right ) ) );
   
  auto sum = [=]( auto map, auto dimension ){
    auto sum =
    hana::find( left, dimension ).value_or( Ratio<0> )
    + hana::find( right, dimension ).value_or( Ratio<0> );

    return hana::if_( hana::bool_c< sum == Ratio<0> >, map,
		      hana::insert( map, hana::make_pair( dimension, sum ) ) );
  };
  
  auto result = hana::fold_left( dimensions, hana::make_map(), sum );
  return Type< decltype(result) >{};
}
