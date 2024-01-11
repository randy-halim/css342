# For Lab 1

Helps to convert everything into seconds (smallest unit), then convert it back to the correct amount of hours, seconds, minutes

# C++ Reference Operator

`&` tells C++ to use the address of the specified variable.
In short: two different names to the same value in memory

```cpp
int a = 10; // this is the usual
int& b = a; // b is a reference to a
cout << b << endl; // "10"
cout << &a << endl; // 0x7fffc013fddc
cout << &b << endl; // 0x7fffc013fddc
```

Other examples:

```cpp
int& c; // illegal. needs a value
const int& d = 1; // constant reference to an address that has the value 1
```

# Templates (or Generics)

Keyphrase

```cpp
template <class Type>
// allows you to use Type in place of int, float, string, etc.
```

# C++ Pointers

`*` turns a variable into a variable that stores a memory address (not like the `&`
operator).

Also called "dereferencing the pointer"

```cpp
int x = 25; // address1 (x, 25)
int* p;     // undefined as of now
p = &x;     // p = address1

// &x = 0x7ffee4a29a18
//  p = 0x7ffee4a29a18
// *p = 25
// &p = 0x7ffee4a29a10 - because p is a different variable, not the same
```

# Arrays in C++

Most primitive data structure (including in C++). With no overhead, it is generally
super efficent (compared to a List data type)

Specifically:
- no concepts of `size`, etc
- statically generated during the compile phase
- values can be easily overwritten (unintentionally) or use unwanted memory locations