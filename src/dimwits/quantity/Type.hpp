template< typename Unit, typename Magnitude = double >
struct Type{
protected:
  template<typename U>
  using IsScalar = std::enable_if_t<U{} == Unitless{}, bool>;

public:
  using Units = Unit;
  static constexpr auto units(){ return Units{}; }
 
  /* fields */
  Magnitude value;
  
  /* methods */
  constexpr Type() : value(0.0){}
  constexpr Type( const Type& ) = default;
  
  template< typename OtherUnit, typename OtherMagnitude >
  constexpr Type( const Type< OtherUnit, OtherMagnitude >& other ) :
    value( conversion::factor< OtherUnit, Unit > * other.value ){}
  
  template< typename OtherMagnitude >
  constexpr Type( const Type< Unit, OtherMagnitude >& other ) :
    value( other.value ){}

  template<typename U = Unit, IsScalar<U> = true>
  constexpr Type( Magnitude value ) : value( value ){}

  template<typename U = Unit, IsScalar<U> = true>
  constexpr operator Magnitude&() { return this->value; }

  template<typename U = Unit, IsScalar<U> = true>
  constexpr operator const Magnitude&() const { return this->value; }

  template< typename Factor, typename U = Unit >
  auto operator=( const Factor& right )->
    std::conditional_t
    < true, std::enable_if_t<U{} == Unitless{}, Type&>,
      decltype( this->value = static_cast< const Magnitude& >(right) ) >
  {
    this->value = static_cast<const Magnitude&>(right);
    return *this;
  }
};

