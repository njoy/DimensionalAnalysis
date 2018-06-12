template< typename Definition >
constexpr bool isComposite( Type< Definition > t ){
  return not decltype( detail::isBasis(t) )::value;
}
