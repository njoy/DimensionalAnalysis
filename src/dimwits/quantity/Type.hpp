template< typename Unit, typename Magnitude = double >
struct Type{
  using Units = Unit;
  
  /* fields */
  Magnitude value;
  
public:
  /* methods */
  constexpr Type() : value(0.0){}
  
  template< typename OtherUnit, typename OtherMagnitude >
  constexpr Type( const Type< OtherUnit, OtherMagnitude >& other ) :
    value( conversion::factor< OtherUnit, Unit > * other.value ){}
  
  template< typename OtherMagnitude >
  constexpr Type( const Type< Unit, OtherMagnitude >& other ) :
    value( other.value ){}
};

template< typename Magnitude >
struct Type< Unitless, Magnitude >{
  using Units = Unitless;
  
  /* fields */
  Magnitude value;
  
public:
  /* methods */
  constexpr Type() : value(0.0){}
  
  template< typename OtherUnit, typename OtherMagnitude >
  constexpr Type( const Type< OtherUnit, OtherMagnitude >& other ) :
    value( conversion::factor< OtherUnit, Unitless > * other.value ){}
  
  template< typename OtherMagnitude >
  constexpr Type( const Type< Unitless, OtherMagnitude >& other ) :
    value( other.value ){}

  constexpr Type( Magnitude value ) : value( value ){}

  constexpr operator Magnitude() const { return this->value; }
};
