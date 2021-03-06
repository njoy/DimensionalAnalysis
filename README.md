Dimwits
=========
...or DIMensional analysis With unITS is a C++14 library for compile-time
dimensional analysis and unit awareness.

Minimal Example
----------------

```c++
#include <iostream>
#include "dimwits.hpp"

using namespace dimwits;

int main(){

/* quantities play nicely with auto */
auto myVelocity = 1.0 * meter / second;
std::cout << "The speed is: " << myVelocity << std::endl;

/* quantities are constexpr friendly */
constexpr Quantity< Inch > myLength = 1.0 * meter;
std::cout << "1 meter in inches is: " << myLength << std::endl;

/* quantities of the same dimensionality can be implicitly converted
 * (conversions are also constexpr friendly) */
constexpr Quantity< Foot > otherLength = myLength;
std::cout << "1 meter in feet is: " << otherLength << std::endl;

/* si-prefixes can be specified on either side of the assignment */
Quantity< Kilo<Gram> > myMass = 1.0 * mega(tonne);
std::cout << "1 megatonne in kilograms is: " << myMass << std::endl;

/* NIST values for common physical constants are provided */
std::cout << "The speed of light is: " << constant::lightSpeed << std::endl;

}
```

This example has the following output:

```
The speed is:  1 s^-1 m
1 meter in inches is:  39.3701 in
1 meter in feet is:  3.28084 ft
1 megatonne in kilograms is:  1e+09 kg
The speed of light is:  2.99792e+08 s^-1 m
```
