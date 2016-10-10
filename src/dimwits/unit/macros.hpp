#define DEFINE_UNIT( NAME, DIMENSION, SYMBOL, LABEL, RATIO )            \
  constexpr auto NAME = unit::makePrimitive( NEW_TAG() );               \
                                                                        \
  namespace unit {                                                      \
                                                                        \
  inline constexpr auto dimensionality( decltype(NAME) ){               \
    return dimension::DIMENSION;                                        \
  }                                                                     \
                                                                        \
  inline std::string symbol( decltype(NAME) ){                          \
    return #SYMBOL ;                                                    \
  }                                                                     \
                                                                        \
  inline constexpr double referenceUnitRatio( decltype(NAME) ){         \
    return RATIO;                                                       \
  }                                                                     \
                                                                        \
  } /* namespace unit */                                                \
                                                                        \
  using LABEL = unit::CorrespondingType< decltype(NAME) >;

#define DEFINE_BASIS_UNIT( NAME, DIMENSION, SYMBOL, LABEL )             \
  DEFINE_UNIT( NAME, DIMENSION, SYMBOL, LABEL, 1.0 )                    \
                                                                        \
  inline auto                                                           \
  referenceUnitImplementation( decltype(dimension::DIMENSION) dim ){    \
    static_assert( dimension::isBasis(dim), "" );                       \
    return LABEL {};                                                    \
  }
