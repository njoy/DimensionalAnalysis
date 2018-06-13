namespace quantity {

template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
constexpr auto operator-
( const Type< Unit, MagnitudeLeft >& left,
  const Type< Unit, MagnitudeRight >& right ){
  using NewMagnitude = decltype( MagnitudeLeft{} - MagnitudeRight{} );
  Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value - right.value;
  return returnQuantity;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator-
( const Type< UnitLeft, MagnitudeLeft >& left,
  const Type< UnitRight, MagnitudeRight >& right ){
  using NewMagnitude =
    decltype( MagnitudeLeft{} + MagnitudeRight{} );
  Type< UnitLeft, NewMagnitude > returnQuantity;
  returnQuantity.value =
    left.value - conversion::factor<UnitRight, UnitLeft> * right.value;
  return returnQuantity;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator-
( Type< Unit, Magnitude > left, const Factor& right )
  -> std::conditional_t
     < true, std::enable_if_t< Unit{} == Unitless{}, decltype(left) >,
             decltype(left.value -= right)>
{
  left.value -= right;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
constexpr auto operator-
( Factor left, const Type< Unit, Magnitude >& right )
  -> std::conditional_t
     < true, std::enable_if_t< Unit{} == Unitless{}, decltype(left) >,
             decltype(left -= right.value)>
{
  left -= right.value;
  return left;
}

}
