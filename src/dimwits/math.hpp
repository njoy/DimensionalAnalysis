namespace math {

/* This namespace provide for compile time evaluation of common 
 * mathematical functions. While these functions can be called at runtime,
 * the user is advised to prefer the standard library implementations
 * for runtime evaluation.
 */

constexpr long double zero = (long double) 0;
constexpr long double one = (long double) 1;
constexpr long double two = (long double) 2;
constexpr long double e = 2.718281828459045235360287471352662497757247093699959574966;
constexpr long double exp2 = 7.389056098930650227230427460575007813180315570551847324087;
constexpr long double ln2 = 0.693147180559945309417232121458176568075500134360255254120;

struct Exp{
protected:
  static constexpr long double maclaurinSeries( long double x ){
    /* evaluated via Horner's method */
    return
      (one + x *
       (one + x / ( 2 * one ) *
	(one + x / ( 3 * one ) *
	 (one + x / ( 4 * one ) *
	  (one + x / ( 5 * one ) *
	   (one + x / ( 6 * one ) *
	    (one + x / ( 7 * one ) *
	     (one + x / ( 8 * one ) *
	      (one + x / ( 9 * one ) *
	       (one + x / ( 10 * one ) *
		(one + x / ( 11 * one ) *
		 (one + x / ( 12 * one ) *
		  (one + x / ( 13 * one ) *
		   (one + x / ( 14 * one ) *
		    (one + x / ( 15 * one ) *
		     (one + x / ( 16 * one ) *
		      (one + x / ( 17 * one ) *
		       (one + x / ( 18 * one )
			 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) );
  }

  static constexpr long double square( long double x ){
    return x * x;
  }
  
  static constexpr long double implementation( long double x ){
    return
      ( x < -0.5 ) ?  one / implementation( -x ) :
      ( x == zero ) ? one :
      ( x <= 0.5 ) ? maclaurinSeries( x ) :
      square( implementation( x / two ) );
  }
  
public:
  static constexpr long double evaluate( long double x ){
    return implementation( x );
  }

  template< int64_t numerator, int64_t denominator >
  constexpr double evaluate( ratio::Type< numerator, denominator > x ){
    return evaluate( double(x) );
  }
};

struct Log {
protected:
  
  static constexpr long double
  newtonRaphson( long double x, long double y, int count ){
    if ( count == 0 ){ return y; }
    const auto newY = y + ( x - Exp::evaluate(y) ) / ( x + Exp::evaluate(y) );
    auto difference = newY - y;
    difference *= ( difference < 0 ) ? -1 : 1;
    return ( difference < 1.5E-16 ) ? newY : newtonRaphson( x, newY, count - 1 );
  }

  static constexpr long double mercatorSeries( long double x ){
    /* evaluated via Horner's method */
    return
      x / one *
      ( one - one * x / ( 2 * one ) *
	( one - ( 2 * one ) * x / ( 3 * one ) *
	  ( one - ( 3 * one ) * x / ( 4 * one ) *
	    ( one - ( 4 * one ) * x / ( 5 * one ) *
	      ( one - ( 5 * one ) * x / ( 6 * one ) *
		( one - ( 6 * one ) * x / ( 7 * one ) *
		  ( one - ( 7 * one ) * x / ( 8 * one ) *
		    ( one - ( 8 * one ) * x / ( 9 * one ) *
		      ( one - ( 9 * one ) * x / ( 10 * one )
			) ) ) ) ) ) ) ) );
  }
  
  static constexpr long double guess( long double x ){
    return mercatorSeries( x - one );
  }
  
  static constexpr long double implementation( long double x ){
    return
      ( x == 1 ) ? zero :
      ( x < 0.5 ) ? -implementation( one / x ) :
      ( x <= 1.5 ) ? newtonRaphson( x, guess(x), 1000 ) :
      implementation( x / two ) + ln2;
  }
  
public:
  static constexpr long double evaluate( long double x ){
    return implementation( x );
  }  
};

struct Pow {
protected:
  static constexpr long double
  implementation( long double base, int exponent ){
    return 
      ( exponent == zero ) ? one :
      ( base == zero || base == one || exponent == one ) ? base :
      implementation( base * base, exponent / 2 )
      * implementation( base , exponent % 2 );
  }

  static constexpr long double
  implementation( long double base, long double exponent ){
    return Exp::evaluate( exponent * Log::evaluate( base ) );
  }
  
public:
  static constexpr long double
  evaluate( long double base, long double exponent ){
    if ( exponent < zero ){ return one / evaluate( base, -exponent ); }
    const int integerExponent = exponent;
    const long double fractionalExponent = exponent - integerExponent;      
    return implementation( base, integerExponent )
           * implementation( base, fractionalExponent );
  }

  template< int64_t numeratorRight, int64_t denominatorRight >
  static constexpr long double evaluate
  ( long double base, ratio::Type< numeratorRight, denominatorRight > exponent ){
    return evaluate( base, (long double) double(exponent) );
  }
};

}
