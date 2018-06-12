template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
constexpr auto operator+
( const quantity::Type< Unit, MagnitudeLeft >& left,
  const quantity::Type< Unit, MagnitudeRight >& right ){
  using NewMagnitude = decltype( MagnitudeLeft{} + MagnitudeRight{} );
  quantity::Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value + right.value;
  return returnQuantity;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator+
( const quantity::Type< UnitLeft, MagnitudeLeft >& left,
  const quantity::Type< UnitRight, MagnitudeRight >& right ){
  using NewMagnitude =
    decltype( MagnitudeLeft{} + MagnitudeRight{} );
  quantity::Type< UnitLeft, NewMagnitude > returnQuantity;
  returnQuantity.value =
    left.value + conversion::factor<UnitRight, UnitLeft> * right.value;
  return returnQuantity;
}
