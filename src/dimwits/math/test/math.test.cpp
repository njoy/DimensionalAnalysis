#define CATCH_CONFIG_MAIN

#include <iostream>
#include <array>

#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

SCENARIO("log test"){
  constexpr std::array< double, 39> values
  {{  1E-42, 1E-39, 1E-36, 1E-33, 1E-30,
      1E-27, 1E-24, 1E-21, 1E-18, 1E-15,
      1E-12, 1E-9, 1E-6, 1E-3, 1E-2, 1E-1,
      1E0, 1E1, 1E2, 1E3, 1E4, 1E5, 1E6,
      1E7, 1E8, 1E9, 1E10, 1E11, 1E12, 1E15,
      1E18, 1E21, 1E24, 1E27, 1E30, 1E33,
      1E36, 1E39, 1E42 }};
  
  for ( auto& value : values ) {
    auto trial = math::Log::evaluate(value);
    const auto reference = std::log(value);
    const auto normalization = (std::log(value) == 0.0) ? 1.0 : reference;
    const auto error = std::abs( trial - reference );
    REQUIRE( error / normalization < 1E-15 );
  }
}
