template< typename Map >
auto deduceDimensionality( Type<Map> ){
  auto evaluateDimensionality = []( auto product, auto element ){
    return product * dimension::pow( dimensionality( hana::first(element) ),
                                     hana::second(element) );
  };
  return hana::fold_left( Map{}, dimension::less, evaluateDimensionality );
}

template< typename Map >
constexpr auto dimensionality( Type<Map> t ){
  return decltype( deduceDimensionality(t) ){};
}
