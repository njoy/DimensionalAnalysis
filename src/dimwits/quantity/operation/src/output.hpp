template< typename OutputStream, typename Magnitude, typename Unit >
auto operator<<
( OutputStream& os, const quantity::Type<Unit, Magnitude>& output ) ->
  std::enable_if_t< Unit{} != Unitless{}, OutputStream&>
{
  os << ' ' << output.value << ' ' << unit::symbol( Unit{} );
  return os;
}

template< typename OutputStream, typename Magnitude, typename Unit >
auto operator<<
( OutputStream& os, const quantity::Type<Unit, Magnitude>& output ) ->
std::enable_if_t< Unit{} == Unitless{}, OutputStream&>{
  os << ' ' << output.value;
  return os;
}
