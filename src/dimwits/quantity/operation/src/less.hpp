namespace quantity {

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator<
( const Type< UnitLeft, MagnitudeLeft >& left,
  const Type< UnitRight, MagnitudeRight >& right )
  -> std::conditional_t<true, bool, decltype(left + right)>
{
  return ( left.value < conversion::factor<UnitRight, UnitLeft> * right.value );
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator<
( const Type< Unit, Magnitude >& left, const Scalar& right ) ->
  std::conditional_t<true, std::enable_if_t<Unit{} == Unitless{}, bool>,
                     decltype(left.value < right)>
{
  return left.value < right;
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator>=
( const Type< Unit, Magnitude >& left, const Scalar& right )->
  decltype(left < right)
{
  return not(left < right);
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator<=
( const Type< Unit, Magnitude >& left, const Scalar& right )->
  decltype(left < right)
{
  return (left < right) or (left == right);
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator>
( const Type< Unit, Magnitude >& left, const Scalar& right )->
  decltype(left < right)
{
  return not(left <= right);
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator<
( const Scalar& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t<true, std::enable_if_t<Unit{} == Unitless{}, bool>,
                     decltype(right.value < left)>
{
  return right > left;
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator>=
( const Scalar& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t<true, std::enable_if_t<Unit{} == Unitless{}, bool>,
                     decltype(right.value < left)>
{
  return right <= left;
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator<=
( const Scalar& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t<true, std::enable_if_t<Unit{} == Unitless{}, bool>,
                     decltype(right.value < left)>
{
  return right >= left;
}

template< typename Magnitude, typename Unit, typename Scalar>
constexpr auto operator>
( const Scalar& left, const Type< Unit, Magnitude >& right ) ->
  std::conditional_t<true, std::enable_if_t<Unit{} == Unitless{}, bool>,
                     decltype(right.value < left)>
{
  return right < left;
}

}
