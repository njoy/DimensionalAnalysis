template< typename Left, typename Right >
auto multiply( Type<Left>, Type<Right> ){
  auto left = Left{};
  auto right = Right{};

  auto leftUnits = 
    hana::to<hana::set_tag>( hana::keys( left ) );
  auto rightUnits =
    hana::to<hana::set_tag>( hana::keys( right ) );

  auto leftExclusiveUnits =
    hana::difference( leftUnits, rightUnits );
  auto rightExclusiveUnits =
     hana::difference( rightUnits, leftUnits );

  auto makeCondition = []( auto t ){
    return [t]( auto element ){
      return t ^hana::contains^ hana::first(element);
    };
  };

  auto merge = [](auto m1, auto m2) {
    return hana::fold_left(m1, m2, hana::insert);
  };
   
  auto mergedExclusives = 
    merge( hana::to<hana::map_tag>
           ( hana::filter
             ( hana::to<hana::tuple_tag>(left), 
               makeCondition( leftExclusiveUnits ) ) ),
           hana::to<hana::map_tag>
           ( hana::filter
             ( hana::to<hana::tuple_tag>(right), 
               makeCondition( rightExclusiveUnits ) ) ) );

  auto sharedUnits =
    hana::intersection( leftUnits, rightUnits );
   
  auto sum = [=]( auto map, auto unit ){
    auto sum = left[unit] + right[unit];
    return hana::insert( map, hana::make_pair( unit, sum ) );
  };
  auto full = hana::fold_left( sharedUnits, hana::make_map(), sum );
  auto reduce = [=]( auto map, auto unit ){
    return hana::if_( hana::bool_< std::decay_t< decltype( hana::second( unit ) ) >{} == Ratio<0> >{},
                      hana::erase_key( map, hana::first( unit ) ), map );
  };
  auto clean = hana::fold_left( full, full, reduce );
  auto result = merge( clean, mergedExclusives );
  return Type< decltype(result) >{};
}
