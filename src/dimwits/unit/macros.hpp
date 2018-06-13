#define DEFINE_UNIT( NAME, DIMENSION, SYMBOL, LABEL, RATIO )		\
  									\
namespace unit {							\
namespace key {							        \
static constexpr struct NAME##_tag : hana::type< NAME##_tag > {} NAME{};\
									\
inline constexpr auto dimensionality( key::NAME##_tag ){		\
  return dimension::DIMENSION;						\
}									\
                                                                        \
inline std::string symbol( key::NAME##_tag ){				\
  return #SYMBOL;							\
}									\
                                                                        \
inline constexpr double referenceUnitRatio( key::NAME##_tag ){		\
    return RATIO;                                                       \
}									\
									\
} /* namespace key */							\
} /* namespace unit */							\
 									\
static constexpr auto NAME =						\
  detail::definition< unit::Type >( unit::key::NAME, Ratio<1> );	\
 									\
using LABEL = std::decay_t< decltype(NAME) >;

#define DEFINE_BASIS_UNIT( NAME, DIMENSION, SYMBOL, LABEL )             \
  DEFINE_UNIT( NAME, DIMENSION, SYMBOL, LABEL, 1.0 )                    \
                                                                        \
  inline auto                                                           \
  referenceUnitImplementation( decltype(dimension::DIMENSION) dim ){    \
    static_assert( dimension::isBasis(dim), "" );                       \
    return LABEL {};                                                    \
  }
