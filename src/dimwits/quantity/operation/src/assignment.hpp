template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
quantity::Type< Unit, MagnitudeLeft >& operator+=
( quantity::Type< Unit, MagnitudeLeft >& left,
  const quantity::Type< Unit, MagnitudeRight >& right ){
  left.value += right.value;
  return left;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
quantity::Type< UnitLeft, MagnitudeLeft >& operator+=
( quantity::Type< UnitLeft, MagnitudeLeft >& left,
  const quantity::Type< UnitRight, MagnitudeRight >& right ){
  left.value += conversion::factor<UnitRight, UnitLeft> * right.value;
  return left;
}

template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
quantity::Type< Unit, MagnitudeLeft >& operator-=
( quantity::Type< Unit, MagnitudeLeft >& left,
  const quantity::Type< Unit, MagnitudeRight >& right ){
  left.value -= right.value;
  return left;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
quantity::Type< UnitLeft, MagnitudeLeft >& operator-=
( quantity::Type< UnitLeft, MagnitudeLeft >& left,
  const quantity::Type< UnitRight, MagnitudeRight >& right ){
  left.value -= conversion::factor<UnitRight, UnitLeft> * right.value;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator*=
( quantity::Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t< true, decltype(left),
			       decltype( left.value = left.value * right ) >{
  left.value = left.value * right;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator/=
( quantity::Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t< true, decltype(left),
			       decltype( left.value = left.value / right ) >{
  left.value = left.value / right;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator+=
( quantity::Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t< true,
                         std::enable_if_t< Unit{} == Unitless{}, decltype(left) >,
			 decltype( left.value = left.value + right ) >{
  left.value = left.value + right;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator-=
( quantity::Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t< true,
                         std::enable_if_t< Unit{} == Unitless{}, decltype(left) >,
			 decltype( left.value = left.value - right ) >{
  left.value = left.value - right;
  return left;
}
