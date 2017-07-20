template< typename OutputStream, typename Magnitude, typename Unit >
OutputStream& operator<<
( OutputStream& os, const quantity::Type<Unit, Magnitude>& output ){
  os << ' ' << output.value << ' ' << unit::symbol( Unit{} );
  return os;
}

template< typename OutputStream, typename Magnitude >
OutputStream& operator<<
( OutputStream& os, const quantity::Type<Unitless, Magnitude>& output ){
  os << ' ' << output.value;
  return os;
}
