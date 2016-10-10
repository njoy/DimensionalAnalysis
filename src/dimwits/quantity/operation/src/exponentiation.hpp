template< typename Magnitude, typename Unit, int64_t numerator >
constexpr auto pow
( quantity::Type< Unit, Magnitude > base, ratio::Type< numerator, 1 > r ){
  using NewUnit = decltype( pow( Unit{}, r ) );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = std::pow( base.value, numerator );
  return returnQuantity;
}

template< typename Magnitude, typename Unit,
          int64_t numerator, int64_t denominator >
constexpr auto pow( quantity::Type< Unit, Magnitude > base,
                    ratio::Type< numerator, denominator > r ){
  using NewUnit = decltype( pow( Unit{}, r ) );
  quantity::Type< NewUnit, Magnitude > returnQuantity;
  returnQuantity.value = std::pow( base.value, r );
  return returnQuantity;
}
