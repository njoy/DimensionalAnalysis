/** 
 * @brief 
 * an alias to the reduce function which better describes intent for some uses
 */ 
template< int64_t numerator, int64_t denominator >
constexpr auto make(){
  return reduce< numerator, denominator >();
}
