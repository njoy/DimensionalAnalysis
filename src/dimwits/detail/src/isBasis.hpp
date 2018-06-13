template< template<typename> class Type, typename Definition >
auto isBasis( Type< Definition > ){
  auto singular = []( auto scan, auto element ){
    constexpr bool elementConforms = hana::second( element ) == Ratio<1>;
    return hana::and_( scan, hana::bool_c< elementConforms > );
  };
  
  return
    hana::if_
    ( hana::greater( hana::length( Definition{} ), hana::size_c<1> ),
      hana::false_c,
      hana::fold_left( Definition{}, hana::true_c, singular ) );
}
