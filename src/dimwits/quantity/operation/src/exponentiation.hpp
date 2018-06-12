namespace quantity {

template< typename Magnitude, typename Unit, int64_t numerator >
auto pow( const Type< Unit, Magnitude >& base,
          ratio::Type< numerator, 1 > r ){
  using NewUnit = decltype( pow( Unit{}, r ) );
  Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = std::pow( base.value, numerator );
  return returnQuantity;
}

template< typename Magnitude, typename Unit,
          int64_t numerator, int64_t denominator >
auto pow( const Type< Unit, Magnitude >& base,
          ratio::Type< numerator, denominator > r ){
  using NewUnit = decltype( pow( Unit{}, r ) );
  Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = std::pow( base.value, r );
  return returnQuantity;
}

template< typename Magnitude, typename Unit >
constexpr auto sqrt( const Type< Unit, Magnitude >& base ){
  using NewUnit = decltype( pow( Unit{}, Ratio<1,2> ) );
  Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = std::sqrt( base.value );
  return returnQuantity;
}

}
