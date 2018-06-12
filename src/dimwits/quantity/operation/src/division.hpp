template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator/
( const quantity::Type< UnitLeft, MagnitudeLeft >& left,
  const quantity::Type< UnitRight, MagnitudeRight >& right ){
  using NewUnit = decltype( UnitLeft{} / UnitRight{} );
  using NewMagnitude = decltype( MagnitudeLeft{} / MagnitudeRight{} );
  quantity::Type< NewUnit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value / right.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename T >
constexpr auto operator/
( const quantity::Type< Unit, Magnitude >& partial, unit::Type<T> rightUnit ){
  using NewUnit = decltype( Unit{} / rightUnit );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = partial.value;
  return returnQuantity;
}

template< typename Magnitude, typename T >
constexpr auto operator/
( const Magnitude& magnitude, unit::Type<T> rightUnit ){
  using Unit = decltype( pow(rightUnit, Ratio<-1> ) );
  quantity::Type<Unit, Magnitude> returnQuantity;
  returnQuantity.value = magnitude;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator/
( const quantity::Type< Unit, Magnitude >& left,
  const Factor& right ){
  using NewMagnitude = decltype( Magnitude{} / Factor{} );
  quantity::Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value / right;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator/
( const Factor& left,
  const quantity::Type< Unit, Magnitude >& right ){
  using NewMagnitude = decltype( Factor{} / Magnitude{} );
  using NewUnit = decltype( pow(Unit{}, Ratio<-1> ) );
  quantity::Type< NewUnit, NewMagnitude > returnQuantity;
  returnQuantity.value = left / right.value;
  return returnQuantity;
}
