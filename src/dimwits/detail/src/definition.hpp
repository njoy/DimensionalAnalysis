template< template<typename> class Type, typename... Args >
constexpr auto definition( Args... args ){
  using map_t = decltype( detail::map( args... ) );
  return Type< map_t >{};
}
