inline auto map(){ return hana::make_map(); }

template< int64_t numerator, int64_t denominator,
          typename Key, typename... Ts >
auto map( Key dimensionKey,
	  ratio::Type< numerator, denominator > ratio,
	  Ts... ts ){
  auto submap = map( ts... );
  static_assert( not hana::contains( hana::keys(submap), dimensionKey ),
                 "Redundant basis encountered in dimension" );
  return hana::insert( submap, hana::make_pair( dimensionKey, ratio ) );
}
