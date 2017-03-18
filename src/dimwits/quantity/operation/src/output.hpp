template< typename OutputStream, typename Magnitude, typename Unit >
OutputStream& operator<<
( OutputStream& os, const quantity::Type<Unit, Magnitude>& output ){
  os << ' ' << output.value << ' ' << unit::symbol( Unit{} );
  return os;
}
