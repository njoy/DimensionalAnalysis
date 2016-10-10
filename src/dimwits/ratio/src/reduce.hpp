template< int64_t numerator, int64_t denominator >
constexpr auto reduce( std::true_type ){
  constexpr auto gcf = greatestCommonFactor( numerator, denominator );
  return Type< numerator/gcf, denominator/gcf >();
}

template< int64_t numerator, int64_t denominator >
constexpr auto reduce( std::false_type ){
  return reduce< -numerator, -denominator >( std::true_type() );
}

/** @brief simplify a numerator/denominator pair */
template< int64_t numerator, int64_t denominator >
constexpr auto reduce(){
  return reduce< numerator, denominator >
    ( std::integral_constant<bool, (denominator > 0) >() );
}
