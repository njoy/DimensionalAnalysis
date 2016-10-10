namespace ratio {

template< int64_t numerator, int64_t denominator >
struct Type {
  static_assert( denominator > 0 , "" );
  constexpr Type(){}
  constexpr Type( const Type& ){}
  constexpr Type( Type&& ){}  
  constexpr operator double() const { return numerator / double(denominator); }
};

#include "dimwits/ratio/src/greatestCommonFactor.hpp"
#include "dimwits/ratio/src/reduce.hpp"
#include "dimwits/ratio/src/make.hpp"
#include "dimwits/ratio/src/add.hpp"
#include "dimwits/ratio/src/subtract.hpp"
#include "dimwits/ratio/src/multiply.hpp"
#include "dimwits/ratio/src/divide.hpp"
#include "dimwits/ratio/src/equality.hpp"
#include "dimwits/ratio/src/less.hpp"

}

template< int64_t numerator, int64_t denominator = 1 >
constexpr auto Ratio = ratio::make<numerator, denominator>();
