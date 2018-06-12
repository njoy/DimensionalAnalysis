namespace quantity {

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator*
( const Type< UnitLeft, MagnitudeLeft >& left,
  const Type< UnitRight, MagnitudeRight >& right ){
  using NewUnit = decltype( UnitLeft{} * UnitRight{} );
  using NewMagnitude = decltype( MagnitudeLeft{} * MagnitudeRight{} );
  Type< NewUnit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value * right.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename T >
constexpr auto operator*
( const Type< Unit, Magnitude >& partial, unit::Type<T> rightUnit ){
  using NewUnit = decltype( Unit{} * rightUnit );
  Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = partial.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator*
( const Type< Unit, Magnitude >& left, const Factor& right ){
  using NewMagnitude = decltype( Magnitude{} * Factor{} );
  Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value * right;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator*
( const Factor& left, const Type< Unit, Magnitude >& right ){
  return right * left;
}

} // namespace quantity

namespace unit {

template< typename Magnitude, typename T >
constexpr auto operator*( const Magnitude& magnitude, unit::Type<T> ){
  quantity::Type<unit::Type<T>, Magnitude> returnQuantity;
  returnQuantity.value = magnitude;
  return returnQuantity;
}

} // namespace unit
