namespace scale {

struct Tag{};

template< typename BaseUnit, typename Identifier >
struct Template : hana::type< hana::tuple< BaseUnit, Identifier > >{};

template< typename Prefix, typename T >
constexpr auto primitive( Prefix, dimwits::unit::Primitive< T > ){
  static_assert( std::is_base_of<Tag, Prefix>::value, "" );
  return Template< dimwits::unit::Primitive< T >, Prefix >{};
}

template< typename Prefix, typename Definition >
constexpr auto type( Prefix, dimwits::unit::Type< Definition > t ){
  static_assert( not dimwits::unit::isComposite( t ), "" );
  auto definition = Definition{};
  auto unscaledPrimitive =
    hana::first( hana::to_tuple( definition )[ hana::size_c<0> ] );
  auto scaledPrimitive = primitive( Prefix{}, unscaledPrimitive );
  using ScaledDefinition =
    decltype( hana::make_map( hana::make_pair( scaledPrimitive, Ratio<1> ) ) );
  return dimwits::unit::Type< ScaledDefinition >{};
}

}

#define DEFINE_SCALE( LABEL, VALUE, NAME, SYMBOL )                       \
  namespace scale {                                                      \
    struct LABEL : Tag {};                                               \
    inline constexpr double factor( LABEL ){ return VALUE; }                       \
  }                                                                      \
                                                                         \
  template< typename T >                                                 \
  constexpr auto NAME( unit::Primitive< T > t ){                         \
    return decltype( scale::primitive( scale::LABEL{}, t ) ){};          \
  }                                                                      \
                                                                         \
  template< typename T >                                                 \
  using LABEL = decltype( scale::type( scale::LABEL{}, T{} ) );          \
                                                                         \
  namespace unit {                                                       \
                                                                         \
  template< typename T >                                                 \
  std::string symbol                                                     \
  ( dimwits::scale::Template< Primitive< T >, dimwits::scale::LABEL > ){ \
    return #SYMBOL + symbol( Primitive<T>{} );                           \
  }                                                                      \
                                                                         \
  }
  
DEFINE_SCALE( Yotta, 1E24, yotta, Y )
DEFINE_SCALE( Zetta, 1E21, zetta, Z )
DEFINE_SCALE( Exa, 1E18, exa, E )
DEFINE_SCALE( Peta, 1E15, peta, P )
DEFINE_SCALE( Tera, 1E12, tera, T )
DEFINE_SCALE( Giga, 1E9, giga, G )
DEFINE_SCALE( Mega, 1E6, mega, M )
DEFINE_SCALE( Kilo, 1E3, kilo, k )
DEFINE_SCALE( Hecto, 1E2, hecto, h )
DEFINE_SCALE( Deka, 10, deka, da )
DEFINE_SCALE( Deci, 0.1, deci, d )
DEFINE_SCALE( Centi, 1E-2, centi, c )
DEFINE_SCALE( Milli, 1E-3, milli, m )
DEFINE_SCALE( Micro, 1E-6, micro, u )
DEFINE_SCALE( Nano, 1E-9, nano, n )
DEFINE_SCALE( Pico, 1E-12, pico, p )
DEFINE_SCALE( Femto, 1E-15, femto, f )
DEFINE_SCALE( Atto, 1E-18, atto, a )
DEFINE_SCALE( Zepto, 1E-21, zepto, z )
DEFINE_SCALE( Yocto, 1E-24, yocto, y )

#undef DEFINE_SCALE

namespace unit{

template< typename Prefix, typename T >         
constexpr auto dimensionality( scale::Template< Primitive< T >, Prefix > ){ 
  return dimensionality( Primitive<T>{} );
}

template< typename BaseUnit, typename Identifier >
constexpr double referenceUnitRatio( scale::Template< BaseUnit, Identifier > ){
  return scale::factor( Identifier{} ) * referenceUnitRatio( BaseUnit{} );
}

}
