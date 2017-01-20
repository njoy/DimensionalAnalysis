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

  double max = 0.0;
  constexpr auto myConstexpr = math::Log::evaluate(values[0]);
  
  for ( auto& value : values ) {
    auto trial = math::Log::evaluate(value);
    const auto reference = std::log(value);
    const auto normalization = (std::log(value) == 0.0) ? 1.0 : reference;
    const auto error = std::abs( trial - reference );
    const auto relative = error / normalization;
    REQUIRE( relative < 2E-16 );
    max = ( relative > max ) ? relative : max;
  }

  std::cout << "Log function max relative error: " << max << std::endl;
}

SCENARIO("exp test"){
  constexpr std::array< double, 9 > values
  {{ -85.0, -10.0, -5.0, -0.25, 0.0, 0.25, 5.0, 10.0, 88.0 }};

  double max = 0.0;
  constexpr auto myConstexpr = math::Exp::evaluate(values[0]);
  
  for ( auto& value : values ) {
    auto trial = math::Exp::evaluate(value);
    const auto reference = std::exp(value);
    const auto error = std::abs( trial - reference );
    const auto relative = error / reference;
    REQUIRE( relative < 2E-16 );
    max = ( relative > max ) ? relative : max;
  }
  std::cout << "Exp function max relative error: " << max << std::endl;
}

SCENARIO("pow test"){
  constexpr std::array< long double, 7> bases
  {{ 0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0 }};
  constexpr std::array< long double, 9> powers
  {{ -30.0, -10.0, -5.0, -0.25, 0.0, 0.25, 5.0, 10.0, 30.0 }};

  double max = 0.0;
  constexpr auto myConstexpr = math::Pow::evaluate( bases[0], powers[0] );

  for (auto& base : bases ) {
    for ( auto& power : powers ) {
      auto trial = math::Pow::evaluate(base, power);
      const auto reference = std::pow(base, power);
      const auto error = std::abs( trial - reference );
      const auto relative = error / reference;
      REQUIRE( relative < 2E-16 );
      max = ( relative > max ) ? relative : max;
    }
  }
  std::cout << "Pow function max relative error: " << max << std::endl;
}
