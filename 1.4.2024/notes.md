# Compiling Multiple C++ Files
```sh
g++ File1.cpp File2.cpp # creates a.out
g++ -c File1.cpp # creates File1.o
g++ -c File2.cpp # creates File2.o
g++ File1.o File2.o -o Program.exe # creates Program.exe (like a.out)
```

# .h and .cpp Files
`.h` files are **header** files
`.cpp` files are **source code** files

in a `.cpp` file:
```cpp
#include FILENAME.h
```

avoiding multiple inclusions of the same file:
```cpp
#ifndef SOME_HEADER.h
#include SOME_HEADER.h
#endif
```
*(i think? don't quote me yet)*