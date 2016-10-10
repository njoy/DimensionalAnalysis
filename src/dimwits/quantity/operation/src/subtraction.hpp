template< typename MagnitudeLeft, typename MagnitudeRight, typename Unit >
constexpr auto operator-
( quantity::Type< Unit, MagnitudeLeft > left,
  quantity::Type< Unit, MagnitudeRight > right ){
  using NewMagnitude = decltype( MagnitudeLeft{} - MagnitudeRight{} );
  quantity::Type< Unit, NewMagnitude > returnQuantity;
  returnQuantity.value = left.value - right.value;
  return returnQuantity;
}

template< typename MagnitudeLeft, typename UnitLeft,
          typename MagnitudeRight, typename UnitRight >
constexpr auto operator-
( quantity::Type< UnitLeft, MagnitudeLeft > left,
  quantity::Type< UnitRight, MagnitudeRight > right ){
  using NewMagnitude =
    decltype( MagnitudeLeft{} + double{} * MagnitudeRight{} );
  quantity::Type< UnitLeft, NewMagnitude > returnQuantity;
  returnQuantity.value = 
    left.value - conversion::factor<UnitRight, UnitLeft> * right.value;
  return returnQuantity;
}

// TEST_CASE( "quantity Type addition" ){
//   SUBCASE("same unit"){
//     quantity::Type< Meter > length0; length0.value = 2.0;
//     quantity::Type< Meter > length1; length1.value = 1.0;

//     /* units can easily be explicitly specified */
//     quantity::Type< Meter > length2 = length0 - length1;
//     REQUIRE( length2.value == doctest::Approx(1.0) );

//     /* however, dimwits plays nicely with auto */
//     auto length3 = length0 - length1;
//     REQUIRE( length3.value == doctest::Approx(1.0) );

//     /* and the implicit conversion works as well */
//     quantity::Type< Centi<Meter> > length4 = length0 - length1;
//     REQUIRE( length4.value == doctest::Approx(100.0) );
//   }

//   SUBCASE("different unit"){
//     quantity::Type< Meter > length0; length0.value = 1.0;
//     quantity::Type< Centi<Meter> > length1; length1.value = 1.0;

//     /* in subtraction operation,
//      * the unit defaults to that of the left argument */
//     auto /* m */ length2 = length0 /* m */ - length1 /* cm */;
//     REQUIRE( length2.value == doctest::Approx(0.99) );
    
//     auto /* cm */ length3 = length1 /* cm */ - length0 /* m */ ;
//     REQUIRE( length3.value == doctest::Approx(-99.) );

//     /* of course, the default can be overrided by specifying a unit */
//     quantity::Type< Centi<Meter> > length4 = length0 - length1;
//     REQUIRE( length4.value == doctest::Approx(99.) );

//     quantity::Type< Meter > length5 = length1 - length0;
//     REQUIRE( length5.value == doctest::Approx(-.99) );
//   }
// }
