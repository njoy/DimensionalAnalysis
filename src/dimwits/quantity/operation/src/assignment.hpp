namespace quantity {

template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
Type< Unit, MagnitudeLeft >& operator+=
( Type< Unit, MagnitudeLeft >& left,
  const Type< Unit, MagnitudeRight >& right ){
  left.value += right.value;
  return left;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
Type< UnitLeft, MagnitudeLeft >& operator+=
( Type< UnitLeft, MagnitudeLeft >& left,
  const Type< UnitRight, MagnitudeRight >& right ){
  left.value += conversion::factor<UnitRight, UnitLeft> * right.value;
  return left;
}

template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
Type< Unit, MagnitudeLeft >& operator-=
( Type< Unit, MagnitudeLeft >& left,
  const Type< Unit, MagnitudeRight >& right ){
  left.value -= right.value;
  return left;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
Type< UnitLeft, MagnitudeLeft >& operator-=
( Type< UnitLeft, MagnitudeLeft >& left,
  const Type< UnitRight, MagnitudeRight >& right ){
  left.value -= conversion::factor<UnitRight, UnitLeft> * right.value;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator*=
( Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t< true, decltype(left),
                               decltype( left.value *= right ) >
{
  left.value *= right;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator/=
( Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t< true, decltype(left),
                               decltype( left.value /= right ) >
{
  left.value /= right;
  return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator+=
( Type< Unit, Magnitude >& left, const Factor& right ) ->
  std::conditional_t
  < true,
    std::enable_if_t
    < Unit{} == Unitless{} and not isType<Factor>::value,
      decltype(left) >,
    decltype( left.value += right ) >
{
   left.value += right;
   return left;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator-=
( Type< Unit, Magnitude >& left, const Factor& right )
  -> std::conditional_t
     < true,
       std::enable_if_t
       < Unit{} == Unitless{} and not isType<Factor>::value,
         decltype(left) >,
       decltype( left.value -= right ) >
{
  left.value -= right;
  return left;
}


template< typename Magnitude, typename Unit, typename Factor >
auto operator*=
( Factor& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t
  < true,
    std::enable_if_t
    < Unit{} == Unitless{} and not isType<Factor>::value,
      decltype(left) >,
    decltype( left *= right.value ) >
{
  return left *= right.value;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator/=
( Factor& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t
  < true,
    std::enable_if_t
    < Unit{} == Unitless{} and not isType<Factor>::value,
      decltype(left) >,
    decltype( left /= right.value ) >
{
  return left /= right.value;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator+=
( Factor& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t
  < true,
    std::enable_if_t
    < Unit{} == Unitless{} and not isType<Factor>::value,
      decltype(left) >,
    decltype( left += right.value ) >
{
  return left += right.value;
}

template< typename Magnitude, typename Unit, typename Factor >
auto operator-=
( Factor& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t
  < true,
    std::enable_if_t
    < Unit{} == Unitless{} and not isType<Factor>::value,
      decltype(left) >,
    decltype( left -= right.value ) >
{
  return left -= right.value;
}

}
