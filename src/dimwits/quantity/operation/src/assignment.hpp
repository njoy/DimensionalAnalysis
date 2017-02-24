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
