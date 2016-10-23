template< typename Left, typename Right >
auto multiply( Type<Left>, Type<Right> ){
  
  auto left = Left{};
  auto right = Right{};

  auto units =
    hana::union_( hana::to_set( hana::keys( left ) ),
		  hana::to_set( hana::keys( right ) ) );

  auto sum = [=]( auto map, auto unit ){
    auto sum =
    hana::find( left, unit ).value_or( Ratio<0> )
    + hana::find( right, unit ).value_or( Ratio<0> );

    return hana::if_( hana::bool_c< sum == Ratio<0> >, map,
		      hana::insert( map, hana::make_pair( unit, sum ) ) );
  };

  auto result = hana::fold_left( units, hana::make_map(), sum );
  
  return Type< decltype(result) >{};
}
