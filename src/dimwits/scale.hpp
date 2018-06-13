namespace scale {

template< typename Prefix, typename BaseKey >
struct Key : hana::type< hana::basic_tuple< Prefix, BaseKey > >{};

/* the `key` and `type` functions are only used in unevaluated contexts
 * to deduce a return type, and as such, need not be vetted for performance.
 */

template< typename Prefix, typename BaseKey >
constexpr auto key( Prefix, BaseKey ){
  return Key< Prefix, BaseKey >{};
}

// !!!!!!!!!!!!!!!!!!!!!!!!
// intentionally undefined
// !!!!!!!!!!!!!!!!!!!!!!!!
/*
 * This overload is the best match if a user tries to add a 
 * prefix to a prefix-ed unit, e.g. kilo(mega(gram))
 * Because the overload isn't defined, doing so results in a 
 * compilation error.
 */
template< typename Prefix, typename OtherPrefix, typename BaseKey >
constexpr auto key( Prefix, Key<OtherPrefix, BaseKey> );

template< typename Prefix, typename Definition >
constexpr auto type( Prefix, dimwits::unit::Type< Definition > t ){
  static_assert( not dimwits::unit::isComposite( t ), "" );
  auto definition = Definition{};
  auto unscaledKey =
    hana::first( hana::to_tuple( definition )[ hana::size_c<0> ] );
  auto scaledKey = key( Prefix{}, unscaledKey );
  using ScaledDefinition =
    decltype( hana::make_map( hana::make_pair( scaledKey, Ratio<1> ) ) );
  return dimwits::unit::Type< ScaledDefinition >{};
}

} // namespace scale

#define DEFINE_SCALE( LABEL, VALUE, NAME, SYMBOL )                       \
  namespace scale {                                                      \
    struct LABEL{};							 \
    inline constexpr double factor( LABEL ){ return VALUE; }  		 \
  }                                                                      \
                                                                         \
  template< typename Definition >					 \
  constexpr auto NAME( unit::Type< Definition > t ){			 \
    return decltype( scale::type( scale::LABEL{}, t ) ){};               \
  }                                                                      \
                                                                         \
  template< typename T >                                                 \
  using LABEL = decltype( scale::type( scale::LABEL{}, T{} ) );          \
                                                                         \
  namespace scale {                                                       \
                                                                         \
  template< typename BaseKey >					         \
  std::string symbol                                                     \
  ( dimwits::scale::Key< dimwits::scale::LABEL, BaseKey > ){		 \
    return #SYMBOL + symbol( BaseKey{} );                                \
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

namespace scale{

template< typename Prefix, typename BaseKey >         
constexpr auto dimensionality( scale::Key< Prefix, BaseKey >){ 
  return dimensionality( BaseKey{} );
}

template< typename Prefix, typename BaseKey >
constexpr double referenceUnitRatio( scale::Key< Prefix, BaseKey > ){
  return scale::factor( Prefix{} ) * referenceUnitRatio( BaseKey{} );
}

}
