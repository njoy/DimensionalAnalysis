namespace std {

template< typename Unit, typename Magnitude >
auto abs( dimwits::Quantity< Unit, Magnitude > arg ){
  arg.value = abs(arg.value);
  return arg;
}

}
