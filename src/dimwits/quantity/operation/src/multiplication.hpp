template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator*
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  using NewUnit = decltype( UnitLeft{} * UnitRight{} );
  using NewMagnitude = decltype( MagnitudeLeft{} * MagnitudeRight{} );
  quantity::Type< NewUnit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value * right.value;
  return returnQuantity;
}

// TEST_CASE( "quantity Type/Type multiplication" ){
//   quantity::Type< Centi<Meter> > length0; length0.value = 2.0;
//   quantity::Type< Centi<Meter> > length1; length1.value = 2.0;

//   using m2 = decltype( Meter{} * Meter{} );
//   using cm2 = decltype( Centi<Meter>{} * Centi<Meter>{} );
  
//   auto area0 = length0 * length1;
//   REQUIRE( area0.value == doctest::Approx(4.0) );
//   REQUIRE( hana::type_c< decltype(area0)::Units > == hana::type_c<cm2> );

//   quantity::Type< m2 > area1 = length0 * length1;
//   REQUIRE( area1.value == doctest::Approx(4E-4) );  
// }

template< typename Magnitude, typename Unit, typename T >
constexpr auto operator*
( quantity::Type< Unit, Magnitude > partial, unit::Primitive<T> primitive ){
  using RightUnit =
    dimwits::unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<1> ) ) ) >;
  using NewUnit = decltype( Unit{} * RightUnit{} );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = partial.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename T, typename Prefix >
constexpr auto operator*
( quantity::Type< Unit, Magnitude > partial,
  scale::Template< T, Prefix > primitive ){
  using RightUnit =
    dimwits::unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<1> ) ) ) >;
  using NewUnit = decltype( Unit{} * RightUnit{} );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = partial.value;
  return returnQuantity;
}

template< typename Magnitude, typename T >
constexpr auto operator*
( Magnitude magnitude, unit::Primitive<T> primitive ){
  using Unit =
    unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<1> ) ) ) >;
  quantity::Type<Unit, Magnitude> returnQuantity;
  returnQuantity.value = magnitude;
  return returnQuantity;
}

template< typename Magnitude, typename T, typename Prefix >
constexpr auto operator*
( Magnitude magnitude, scale::Template< T, Prefix > primitive ){
  using Unit =
    dimwits::unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<1> ) ) ) >;
  quantity::Type<Unit, Magnitude> returnQuantity;
  returnQuantity.value = magnitude;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator*
( quantity::Type< Unit, Magnitude > left, Factor right ){
  using NewMagnitude = decltype( Magnitude{} * Factor{} );
  quantity::Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value * right;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator*
( Factor left, quantity::Type< Unit, Magnitude > right ){
  return right * left;
}
