template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator/
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  using NewUnit = decltype( UnitLeft{} / UnitRight{} );
  using NewMagnitude = decltype( MagnitudeLeft{} / MagnitudeRight{} );
  quantity::Type< NewUnit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value / right.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename T >
constexpr auto operator/
( quantity::Type< Unit, Magnitude > partial, unit::Primitive<T> primitive ){
  using RightUnit =
    dimwits::unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<-1> ) ) ) >;
  using NewUnit = decltype( Unit{} * RightUnit{} );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = partial.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename T, typename Prefix >
constexpr auto operator/
( quantity::Type< Unit, Magnitude > partial,
  scale::Template< T, Prefix > primitive ){
  using RightUnit =
    dimwits::unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<-1> ) ) ) >;
  using NewUnit = decltype( Unit{} * RightUnit{} );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = partial.value;
  return returnQuantity;
}

template< typename Magnitude, typename T >
constexpr auto operator/
( Magnitude magnitude, unit::Primitive<T> primitive ){
  using Unit =
    unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<-1> ) ) ) >;
  quantity::Type<Unit, Magnitude> returnQuantity;
  returnQuantity.value = magnitude;
  return returnQuantity;
}

template< typename Magnitude, typename T, typename Prefix >
constexpr auto operator/
( Magnitude magnitude, scale::Template< T, Prefix > primitive ){
  using Unit =
    dimwits::unit::Type
    < decltype( hana::make_map( hana::make_pair( primitive, Ratio<-1> ) ) ) >;
  quantity::Type<Unit, Magnitude> returnQuantity;
  returnQuantity.value = magnitude;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator/
( quantity::Type< Unit, Magnitude > left, Factor right ){
  using NewMagnitude = decltype( Magnitude{} / Factor{} );
  quantity::Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value / right;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator/
( Factor left, quantity::Type< Unit, Magnitude > right ){
  using NewMagnitude = decltype( Factor{} / Magnitude{} );
  using NewUnit = decltype( pow(Unit{}, Ratio<-1> ) );
  quantity::Type< NewUnit, NewMagnitude > returnQuantity;
  returnQuantity.value = left / right.value;
  return returnQuantity;
}
