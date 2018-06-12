#include <sstream>

#include "dimwits.hpp"
#include "catch.hpp"

using namespace dimwits;

TEST_CASE("operations"){
  SECTION("assignments"){
    SECTION( "same unit assignment" ){
      quantity::Type< Meter > length0;
      length0.value = 1.0;
      quantity::Type< Meter > length1 = length0;
      REQUIRE( 1.0 == length1.value );
    }

    SECTION( "different unit assignment" ){
      /* implicit conversions between quantities of 
       * the same dimensionality are provided */
      quantity::Type< Centi<Meter> > length0;
      length0.value = 1.0;
      quantity::Type< Meter > length1 = length0;
      REQUIRE( 0.01 == length1.value );
    }

    SECTION( "unitless assignment" ){
      /* implicit conversions between quantities of 
       * the same dimensionality are provided */
      quantity::Type< Unitless > scalar;
      scalar = 1.0;
      //      REQUIRE( 1.0 == scalar );
    }
  }

  SECTION("multiplication"){
    quantity::Type< Centi<Meter> > length0;
    length0.value = 2.0;
    auto area0 = length0 * length0;
    REQUIRE( 4.0 == area0.value );

    auto generate_unit = area0.units();
    auto expected_unit = centi(meter) * centi(meter);

    REQUIRE( generate_unit == expected_unit );
  }

  SECTION("division"){
    auto area0 = ( 1.0 * foot * foot * foot ) / ( 12.0 * inch );
    /* Lazy unit conversion in action */
    /* Using auto allows the units to be evaluated lazily. Hence the units
     * of area0 is ft^3/in and the magnitude is 1/ 12 */ 
    REQUIRE( area0.units() == foot * foot * foot / inch );
    REQUIRE( ( 1.0 / 12.0 ) == area0.value );

    /* To get a more intuitive unit, a user need only ask */ 
    quantity::Type< decltype( foot * foot ) > area1 = area0;
    REQUIRE( std::abs( 1.0 - area1.value ) < 3E-16 );

    /* scalars can divided by quantity values */
    auto inverse = 2.0 / area1;
    REQUIRE( inverse.units() == unit::less / foot / foot );
    REQUIRE( inverse.value == Approx(2.0) );

    /* or vice-versa */
    auto otherInverse = area1 / 2.0;
    REQUIRE( otherInverse.units() == foot * foot );
    REQUIRE( std::abs( otherInverse.value ) == Approx(0.5) );
  }

  SECTION("unary minus"){
    quantity::Type< Centi<Meter> > length0 = 1.0 * meter;
    auto length1 = -length0;
    REQUIRE( -100.0 == length1.value );

    auto generate_unit = length1.units();
    REQUIRE( generate_unit == centi(meter) );
  }

  SECTION("unary plus"){
    quantity::Type< Centi<Meter> > length0 = 1.0 * meter;
    auto length1 = +length0;
    REQUIRE( 100.0 == length1.value );

    auto generate_unit = length1.units();
    REQUIRE( generate_unit == centi(meter) );
  }

  SECTION("plus equals"){
    SECTION("same unit"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length += 1.0 * meter;
      REQUIRE( 200.0 == length.value );

      auto generate_unit = length.units();
      REQUIRE( generate_unit == centi(meter) );
    }
    SECTION("different unit"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length += 1.0 * centi(meter);
      REQUIRE( 101.0 == length.value );

      auto generate_unit = length.units();
      REQUIRE( generate_unit == centi(meter) );
    }
    SECTION("unitless"){
      quantity::Type< Unitless > scalar = 1.0;
      scalar += 1;
      REQUIRE( 2.0 == scalar );
    }
  }

  SECTION("minus equals"){
    SECTION("same unit"){
      quantity::Type< Centi<Meter> > length = 3.0 * meter;
      length -= 1.0 * meter;
      REQUIRE( 200.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
    SECTION("different unit"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length -= 1.0 * centi(meter);
      REQUIRE( 99.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
    SECTION("unitless"){
      quantity::Type< Unitless > scalar = 2.0;
      scalar -= 1;
      REQUIRE( 1.0 == scalar );
    }
  }

  SECTION("times equals"){
    SECTION("scalar"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length *= 5.0;
      REQUIRE( 500.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
    SECTION("unitless"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length *= 5.0 * meter / meter;
      REQUIRE( 500.0 == length.value );

      auto generate_unit = length.units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
  }

  SECTION("divide equals"){
    SECTION("scalar"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length /= 2.0;
      REQUIRE( 50.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
    SECTION("different unit"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length /= 2.0 * meter / meter;
      REQUIRE( 50.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
  }
  
  SECTION("addition and subtraction"){
    /* In addition and subtraction, there is an choice to be made:
     * Given the left and right operand are expressed in differing units,
     * in which unit should the result be expressed in when using auto?
     *
     * In dimwits, precedence is given to the units associated to the left
     * operand. 
     */
    auto area0 = 1.0 * foot * foot;
    auto area1 = 1.0 * meter * meter;

    auto area2 = area0 + area1;
    auto area3 = area1 + area0;

    REQUIRE( area2.units() == foot * foot );
    REQUIRE( area2.units() == area0.units() );

    REQUIRE( area3.units() == meter * meter );
    REQUIRE( area3.units() == area1.units() );
    
    /* Of course, a unit can also be specified */
    quantity::Type< decltype( meter * meter ) > area4 = area0 + area1;
    REQUIRE( area4.units() == meter * meter );

    quantity::Type< decltype( foot * foot ) > area5 = area0 - area1;
    REQUIRE( area5.units() == foot * foot );
  }

  SECTION("equality"){
    auto length0 = 1.0 * foot;
    auto length1 = 12.0 * inches;
    auto length2 = 1.0 * angstroms;
    REQUIRE( length0 == length0 );
    REQUIRE( length0 == length1 );
    REQUIRE( length0 != length2 );

    auto scalar = 1.0 * foot / foot;
    REQUIRE( scalar == 1.0 * unit::less );
    REQUIRE( scalar == 1.0 );
  }

  SECTION("less"){
    auto length0 = 1.0 * foot;
    auto length1 = 11.0 * inches;
    auto length2 = 1.0 * angstroms;
    REQUIRE( not( length0 < length1 ) );
    REQUIRE( not( length1 < length2 ) );
    REQUIRE( length2 < length1 );

    REQUIRE( length1 <= length1 );
    REQUIRE( not( length1 <= length2 ) );
    REQUIRE( length2 <= length1 );

    REQUIRE( not( length1 > length0 ) );
    REQUIRE( length1 > length2 );
    REQUIRE( not( length2 > length1 ) );
    
    REQUIRE( length1 >= length1 );
    REQUIRE( length1 >= length2 );
    REQUIRE( not( length2 >= length1 ) );

    auto scalar = 1.0 * meter / meter;
    REQUIRE( scalar < 2 );
    REQUIRE( scalar <= 2 );
    REQUIRE( scalar <= 1.0 );
    REQUIRE( scalar >= 1.0 );
    REQUIRE( scalar >= 0.5 );
    REQUIRE( scalar > 0.5 );
    REQUIRE( 2 > scalar );
    REQUIRE( 2 >= scalar );
    REQUIRE( 1.0 >= scalar );
    REQUIRE( 1.0 <= scalar );
    REQUIRE( 0.5 <= scalar );
    REQUIRE( 0.5 < scalar );
  }
  
  SECTION("output operator"){
    {
      auto length0 = 1.0 * foot;
      auto length1 = 11.0 * inches;
      auto length2 = 1.0 * angstroms;

      std::stringstream ss;
      ss << length0 << length1 << length2 << (length0 * length1 * length2);
      REQUIRE( ss.str() == " 1 ft 11 in 1 angstrom 11 angstrom in ft" );
    }
    {
      auto scalar = 2.0 * constant::unitless;
      std::stringstream ss;
      ss << scalar;
      REQUIRE( ss.str() == " 2" );
    }
    
  }
}

TEST_CASE( "less operator"){
  auto length0 = 1.0 * meter;
  auto length1 = 2.0 * meter;
  auto length2 = 1.0 * centi(meter);
  auto length3 = 500.0 * centi(meter);

  REQUIRE( not( length0 < length0 ) );
  REQUIRE( length0 < length1 );
  REQUIRE( not( length1 < length0 ) );
  REQUIRE( length2 < length1 );
  REQUIRE( not( length1 < length2 ) );
  REQUIRE( length1 < length3 );
  REQUIRE( not( length3 < length3 ) );  
}

TEST_CASE( "greater operator"){
  auto length0 = 1.0 * meter;
  auto length1 = 2.0 * meter;
  auto length2 = 1.0 * centi(meter);
  auto length3 = 500.0 * centi(meter);

  REQUIRE( not( length0 > length0 ) );
  REQUIRE( length1 > length0 );
  REQUIRE( not( length0 > length1 ) );
  REQUIRE( length1 > length2 );
  REQUIRE( not( length2 > length1 ) );
  REQUIRE( length3 > length2 );
  REQUIRE( not( length3 > length3 ) );  
}

TEST_CASE( "less or equal operator"){
  auto length0 = 1.0 * meter;
  auto length1 = 2.0 * meter;
  auto length2 = 1.0 * centi(meter);
  auto length3 = 500.0 * centi(meter);
  quantity::Type< Meter > length4 = length3;

  REQUIRE( length0 <= length0 );
  REQUIRE( length0 <= length1 );
  REQUIRE( not( length1 <= length0 ) );
  REQUIRE( length2 <= length1 );
  REQUIRE( not( length1 <= length2 ) );
  REQUIRE( length1 <= length3 );
  REQUIRE( length3 <= length3 );
  REQUIRE( length4 <= length3 ); 
}

TEST_CASE( "greater or equal operator"){
  auto length0 = 1.0 * meter;
  auto length1 = 2.0 * meter;
  auto length2 = 1.0 * centi(meter);
  auto length3 = 500.0 * centi(meter);
  quantity::Type< Meter > length4 = length3;

  REQUIRE( length0 >= length0 );
  REQUIRE( length1 >= length0 );
  REQUIRE( not( length0 >= length1 ) );
  REQUIRE( length1 >= length2 );
  REQUIRE( not( length2 >= length1 ) );
  REQUIRE( length3 >= length1 );
  REQUIRE( length3 >= length3 );
  REQUIRE( length3 >= length4 ); 
}

TEST_CASE( "exponentiation"){
  auto length0 = 1.0 * meter;
  REQUIRE( length0 * length0 == pow( length0, Ratio<2> ) );
  REQUIRE( length0 == sqrt( pow( length0, Ratio<2> ) ) );
}

TEST_CASE( "absolute value"){
  auto length0 = -1.0 * meter;
  auto length1 =  1.0 * meter;
  REQUIRE( std::abs(length0) == length1 );
  REQUIRE( std::abs(length1) == length1 );
}
