inline auto referenceUnitImplementation( decltype(dimension::less) ){
  return Unitless{};
}

template< typename Definition >
auto referenceUnitImplementation( dimension::Type<Definition> ){
  auto collect = []( auto partial, auto element ){
    auto basis = hana::first(element);
    auto power = hana::second(element);
    auto basisDimension = detail::definition<dimension::Type>( basis, Ratio<1> );
    auto basisUnit = referenceUnitImplementation( basisDimension );
    return partial * unit::pow( basisUnit, power ); 
  };

  return hana::fold_left( Definition{}, Unitless{}, collect );
}

template< typename Definition >
constexpr auto referenceUnit( dimension::Type<Definition> t ){
  return decltype( referenceUnitImplementation(t) ){};
}

