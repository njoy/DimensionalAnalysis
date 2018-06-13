template< template<typename> class Type, typename Unit, int64_t n, int64_t d >
auto exponentiation( Type< Unit > , ratio::Type< n, d > r ){
  auto base = Unit{};
  auto keys = hana::keys( base );
  auto exponentiateBase = [=]( auto map, auto element ){
    return hana::insert( map, hana::make_pair( element, base[element] * r ) );
  };
  auto result = hana::fold_left( keys, hana::make_map(), exponentiateBase );
  return Type< decltype(result) >{};
}
