template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
constexpr auto operator-
( quantity::Type< Unit, MagnitudeLeft > left,
  quantity::Type< Unit, MagnitudeRight > right ){
  using NewMagnitude = decltype( MagnitudeLeft{} - MagnitudeRight{} );
  quantity::Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value - right.value;
  return returnQuantity;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator-
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  using NewMagnitude =
    decltype( MagnitudeLeft{} + double{} * MagnitudeRight{} );
  quantity::Type< UnitLeft, NewMagnitude > returnQuantity;
  returnQuantity.value = 
    left.value - conversion::factor<UnitRight, UnitLeft> * right.value;
  return returnQuantity;
}
