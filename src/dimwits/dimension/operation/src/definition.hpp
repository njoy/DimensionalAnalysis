inline auto definition(){ return hana::make_map(); }

template< int64_t numerator, int64_t denominator,
          typename Basis, typename... Ts >
auto definition( dimwits::basis::Type<Basis> basis,
                 ratio::Type< numerator, denominator > ratio,
                 Ts... ts ){
  auto submap = definition( ts... );
  static_assert( not ( hana::keys(submap) ^hana::contains^ basis ),
                 "Redundant basis encountered in dimension" );
  return hana::insert( submap, hana::make_pair( basis, ratio ) );
}
