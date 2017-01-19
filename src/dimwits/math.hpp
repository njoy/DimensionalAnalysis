namespace math {

template< typename T >
constexpr double e = 2.71828182845904523536028747135266249775724709369995;

struct Exp{
protected:
  template< typename T >
  static constexpr T maclaurinSeries( T x ){
    const auto one = T(1);
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

  
  template< typename T >
  static constexpr T implementation( T x, T state ){
    return
      ( x == T(0) ) ? state :
      ( x < -0.5 ) ? implementation( x + T(1), state / e<T> ) :
      ( x <= 0.5 ) ? state * maclaurinSeries( x ) :
      implementation( x - T(1), state * e<T> );      
  }
  
public:
  template< typename T >
  static constexpr T evaluate( T x ){
    return implementation( x, T(1) );
  }

  template< int64_t numerator, int64_t denominator >
  constexpr double evaluate( ratio::Type< numerator, denominator > x ){
    return evaluate( double(x) );
  }
};

struct Log {
protected:
  
  template< typename T >
  static constexpr T newtonRaphson( T x, T y, int count ){
    if ( count == 0 ){ return y; }
    const auto newY = y + ( x - Exp::evaluate(y) ) / ( x + Exp::evaluate(y) );
    auto difference = newY - y;
    difference *= ( difference < 0 ) ? -1 : 1;
    return ( difference < 1.5E-16 ) ? newY : newtonRaphson( x, newY, count - 1 );
  }

  template< typename T >
  static constexpr T mercatorSeries( T x ){
    const auto one = T(1);
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
  
  template< typename T >
  static constexpr T guess( T x ){
    const auto one = T(1);
    return mercatorSeries( x - one );
  }
  
  template< typename T >
  static constexpr T implementation( T x, T state, bool mode = true ){
    constexpr auto one = T(1);
    return
      ( x == 1 ) ? state :
      ( x < 0.5 ) ? implementation( one / x, state, not mode ) :
      ( x <= 1.5 ) ? state + (mode ? 1 : -1) * newtonRaphson( x, guess(x), 1000 ) :
      implementation( x / e<T>, state + (mode ? 1 : -1) * one, mode );
  }
  
public:
  template< typename T >
  static constexpr T evaluate( T x ){
    return implementation( x, T(0) );
  }
  
};

struct Pow {
public:
  template< typename T >
  static constexpr T evaluate( T base, T exponent ){
    return
      ( exponent == 0 ) ? T(1) :
      ( base == 0 || base == 1 || exponent == 1 ) ? base :
      Exp::evaluate( exponent * Log::evaluate(base) );
  }

  template< typename T, int64_t numeratorRight, int64_t denominatorRight >
  static constexpr T evaluate
  ( T base, ratio::Type< numeratorRight, denominatorRight > exponent ){
    return evaluate( base, T(double(exponent)) );
  }
};

}
