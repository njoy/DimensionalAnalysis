Dimwits
=========
...or DIMensional analysis With unITS is a C++14 library for compile-time 
dimensional analysis and unit awareness.

Minimal Example
----------------

```c++
#include "dimwits.hpp"

using namespace dimwits;

int main(){

/* quantities play nicely with auto */
auto myVelocity = 1.0 * meter / second;
std::cout << "The speed is: " << myVelocity << std::endl;

/* quantities of the same dimensionality can be implicitly converted */
quantity::Type< Foot > myLength = 1.0 * meter;
std::cout << "1 meter in feet is: " << myLength << std::endl;

/* si-prefixes can be specified on either side of the assignment */
quantity::Type< Kilo<Gram> > myMass = 1.0 * mega(tonne);
std::cout << "1 megatonne in kilograms is: " << myMass << std::endl;

}
```

