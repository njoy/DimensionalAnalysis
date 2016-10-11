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

/* quantities of the same dimensionality can be implicitly converted */
quantity::Type< Foot > length1 = 1.0 * meter;
std::cout << "1 meter in feet is: " << length0 << std::endl;

/* quantities play nicely with auto */
auto velocity0 = 1.0 * meter / second;
std::cout << "The speed is: " << length0 << std::endl;

}
```

