template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator<
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  return ( left.value < conversion::factor<UnitRight, UnitLeft> * right.value );
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator>
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  return right < left;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator<=
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  return not (right < left);
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator>=
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  return not (left < right);
}
