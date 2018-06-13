#include <limits>

namespace std {
template< typename Unit, typename Magnitude >
class numeric_limits< dimwits::quantity::Type< Unit, Magnitude > > :
  public numeric_limits< Magnitude > {

  using Core = numeric_limits< Magnitude >;

public:
  static constexpr bool is_specialized = true;
  static constexpr bool is_integer = false;

#define WRAP( name )\
  static constexpr auto name(){ return Core::name() * Unit{}; }

  WRAP(min)
  WRAP(lowest)
  WRAP(max)
  WRAP(epsilon)
  WRAP(round_error)
  WRAP(infinity)
  WRAP(quiet_NaN)
  WRAP(signaling_NaN)
  WRAP(denorm_min)
#undef WRAP
};

}
