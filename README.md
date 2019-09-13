# demo_cpp

Collection of short C++ demos:

 * custom simplified implementation of `vector` functionality (`myvec.h`, `demo_vec.cpp`)
 * rvalue references (`demo_rvalue.cpp`, using `myvec.h`)
 * copy and move semantics (`demo_cpmv.cpp`)

The demos are buildable with CMake:

```bash
mkdir build
cmake ..
make
```