namespace basis {

/**
 * @brief 
 * The basis::Type template provides a mechanism to limit the scope of 
 * generic functions to apply to basis class instances.
 *
 * @details
 * The choice to inherit from--rather than alias--the hana type class was made
 * for two reason:
 * 1) to avoid interoperability with arbitrary hana type code
 * 2) to allow for parameter deduction, which isn't possible with the hana type
 */
template< typename T >
struct Type : hana::type< T >{};

template< typename T >
constexpr auto makeType( T ){ return Type< T >{}; }

constexpr auto mass = makeType( NEW_TAG() );
constexpr auto length = makeType( NEW_TAG() );
constexpr auto time = makeType( NEW_TAG() );
constexpr auto current = makeType( NEW_TAG() );
constexpr auto temperature = makeType( NEW_TAG() );
constexpr auto amount = makeType( NEW_TAG() );
constexpr auto luminousIntensity = makeType( NEW_TAG() );
constexpr auto planeAngle = makeType( NEW_TAG() );
constexpr auto solidAngle = makeType( NEW_TAG() );

}
