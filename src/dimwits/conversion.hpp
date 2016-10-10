namespace unit {

struct CompoundFunctor{
  template< typename Pair >
  constexpr double operator()( double compoundFactor, Pair pair ){
    auto pairFactor =
      std::pow( unit::referenceUnitRatio
                ( std::decay_t< decltype( hana::first( pair ) ) >{} ),
                std::decay_t< decltype( hana::second( pair ) ) >{} );
    return compoundFactor * pairFactor;
  }
};   
  
template< typename Definition >
constexpr double referenceUnitRatio( unit::Type<Definition> ){
  auto definition = Definition{};
  return hana::fold_left( definition, 1.0, CompoundFunctor{} );
}

}

namespace conversion {

template< typename From, typename To >
constexpr double factorValue( unit::Type<From> from, unit::Type<To> to ){
  static_assert( unit::dimensionality( to ) == unit::dimensionality( from ),"");
  return unit::referenceUnitRatio( from ) / unit::referenceUnitRatio( to );
}

template< typename From, typename To >
const double factor = factorValue( From{}, To{} );

}
