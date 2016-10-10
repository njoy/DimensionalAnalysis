template< typename Left, typename Right >
auto multiply( Type< Left >, Type< Right > ){
  
  auto left = Left{};
  auto right = Right{};

  auto leftDimensions = hana::to_set( hana::keys( left ) );
  
  auto rightDimensions = hana::to_set( hana::keys( right ) );

  auto leftExclusiveDimensions =
    hana::difference( leftDimensions, rightDimensions );

  auto rightExclusiveDimensions =
    hana::difference( rightDimensions, leftDimensions );

  auto makeCondition = []( auto t ){
    return [t]( auto element ){
      return t ^hana::contains^ hana::first(element);
    };
  };

  auto conditionalInsert = []( auto condition ){
    return [ condition ]( auto map, auto element ){
      return hana::if_
      ( condition( element ),
        hana::insert( map, element ), map );
    };
  };
  
  auto merge = [](auto m1, auto m2) {
    return hana::fold_left( m2, m1, hana::insert );
  };
  
  auto leftExclusive = 
    hana::fold_left
    ( left, hana::make_map(), conditionalInsert
      ( makeCondition( leftExclusiveDimensions ) ) );
  
  auto rightExclusive =
    hana::fold_left
    ( right, hana::make_map(), conditionalInsert
      ( makeCondition( rightExclusiveDimensions ) ) );
  
  auto mergedExclusives = merge( leftExclusive, rightExclusive );

  auto sharedDimensions =
    hana::intersection( leftDimensions, rightDimensions );
   
  auto sum = [=]( auto map, auto dimension ){
    auto sum = left[dimension] + right[dimension];
    return hana::insert( map, hana::make_pair( dimension, sum ) );
  };
  
  auto full = hana::fold_left( sharedDimensions, hana::make_map(), sum );
  auto reduce = [=]( auto map, auto dimension ){
    return hana::if_( hana::bool_c< hana::second( dimension ) == Ratio<0> >,
                      hana::erase_key( map, hana::first( dimension ) ), map );
  };
  auto clean = hana::fold_left( full, full, reduce );
  auto result = merge( clean, mergedExclusives );
  return Type< decltype(result) >{};
}
