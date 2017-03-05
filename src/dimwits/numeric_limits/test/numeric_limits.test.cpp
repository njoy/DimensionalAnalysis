#define CATCH_CONFIG_MAIN

#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("numeric limits"){
  using reference = std::numeric_limits< double >;
  using trial = std::numeric_limits< quantity::Type< Meter, double > >;
  SECTION( "static members" ){
#define MATCH(member)\
    REQUIRE( reference::member == trial::member )

    MATCH(is_specialized);
    MATCH(is_signed);
    MATCH(is_integer);
    MATCH(is_exact);
    MATCH(has_infinity);
    MATCH(has_quiet_NaN);
    MATCH(has_signaling_NaN);
    MATCH(has_denorm);
    MATCH(has_denorm_loss);
    MATCH(round_style);
    MATCH(is_iec559);
    MATCH(is_bounded);
    MATCH(is_modulo);
    MATCH(digits);
    MATCH(digits10);
    MATCH(max_digits10);
    MATCH(radix);
    MATCH(min_exponent);
    MATCH(min_exponent10);
    MATCH(max_exponent);
    MATCH(max_exponent10);
    MATCH(traps);
    MATCH(tinyness_before);
#undef MATCH    
  }

  SECTION( "static methods" ){
#define MATCH(method)\
    REQUIRE( reference::method() * dimwits::meters == trial::method() )

    MATCH(min);
    MATCH(lowest);
    MATCH(max);
    MATCH(epsilon);
    MATCH(round_error);
    MATCH(infinity);
    MATCH(denorm_min);
#undef MATCH
    
    REQUIRE( std::isnan( trial::quiet_NaN().value ) );
    REQUIRE( std::isnan( trial::signaling_NaN().value ) );
  }
}
