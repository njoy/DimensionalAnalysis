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
  }

  SECTION("multiplication"){
    quantity::Type< Centi<Meter> > length0;
    length0.value = 2.0;
    auto area0 = length0 * length0;
    REQUIRE( 4.0 == area0.value );

    auto generate_unit = decltype(area0)::Units();
    auto expected_unit = Centi<Meter>() * Centi<Meter>();

    REQUIRE( generate_unit == expected_unit );
  }

  SECTION("division"){
    auto area0 = ( 1.0 * foot * foot * foot ) / ( 12.0 * inch );
    /* Lazy unit conversion in action */
    /* Using auto allows the units to be evaluated lazily. Hence the units
     * of area0 is ft^3/in and the magnitude is 1/ 12 */ 
    REQUIRE( decltype( area0 )::Units() == Foot() * Foot() * Foot() / Inch() );
    REQUIRE( ( 1.0 / 12.0 ) == area0.value );

    /* To get a more intuitive unit, a user need only ask */ 
    quantity::Type< decltype( Foot() * Foot() ) > area1 = area0;
    REQUIRE( std::abs( 1.0 - area1.value ) < 3E-16 );

    /* scalars can divided by quantity values */
    auto inverse = 2.0 / area1;
    REQUIRE( decltype(inverse)::Units() == Unitless() / Foot() / Foot() );
    REQUIRE( inverse.value == Approx(2.0) );
  }

  SECTION("unary minus"){
    quantity::Type< Centi<Meter> > length0 = 1.0 * meter;
    auto length1 = -length0;
    REQUIRE( -100.0 == length1.value );

    auto generate_unit = decltype(length1)::Units();
    REQUIRE( generate_unit == Centi<Meter>{} );
  }

  SECTION("unary plus"){
    quantity::Type< Centi<Meter> > length0 = 1.0 * meter;
    auto length1 = +length0;
    REQUIRE( 100.0 == length1.value );

    auto generate_unit = decltype(length1)::Units();
    REQUIRE( generate_unit == Centi<Meter>{} );
  }

  SECTION("plus equals"){
    SECTION("same unit"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length += 1.0 * meter;
      REQUIRE( 200.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
    }
    SECTION("different unit"){
      quantity::Type< Centi<Meter> > length = 1.0 * meter;
      length += 1.0 * centi(meter);
      REQUIRE( 101.0 == length.value );

      auto generate_unit = decltype(length)::Units();
      REQUIRE( generate_unit == Centi<Meter>{} );
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

    REQUIRE( decltype(area2)::Units() == Foot() * Foot() );
    REQUIRE( decltype(area2)::Units() == decltype(area0)::Units() );

    REQUIRE( decltype(area3)::Units() == Meter() * Meter() );
    REQUIRE( decltype(area3)::Units() == decltype(area1)::Units() );
    
    /* Of course, a unit can also be specified */
    quantity::Type< decltype( Meter() * Meter() ) > area4 = area0 + area1;
    REQUIRE( decltype(area4)::Units() == Meter() * Meter() );

    quantity::Type< decltype( Foot() * Foot() ) > area5 = area0 - area1;
    REQUIRE( decltype(area5)::Units() == Foot() * Foot() );
  }

  SECTION("equality"){
    auto length0 = 1.0 * foot;
    auto length1 = 12.0 * inches;
    auto length2 = 1.0 * angstroms;
    REQUIRE( length0 == length1 );
    REQUIRE( length0 != length2 );
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
  }
  
  SECTION("output operator"){
    auto length0 = 1.0 * foot;
    auto length1 = 11.0 * inches;
    auto length2 = 1.0 * angstroms;

    std::stringstream ss;
    ss << length0 << ' ' << length1 << ' ' << length2 << ' '
       << (length0 * length1 * length2);
    REQUIRE( ss.str() == "1 ft  11 in  1 angstrom  11 angstrom in ft " );
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
