# Class `this`

Formatted as `this->property`

Unlike Java, declare members in a `.h` file

# Class Destructors

Last method called before garbage collection. Format:

```cpp
void ClassName::~ClassName() {
  // code here
}
```

# Operation Overloads

Normal operators: `+ - * /`

Declaration operators: `+= -= *- /=`

Comparison operators: `> < >= <=`

Can be overloaded like so:

```cpp
ClassName operator*(const) const // e.g. overloading multiplication operator
{
  // do something here... such as multiplication
}

ClassName& operator*=(const ClassName& className)
// e.g. overloading multiplication equals operator
{
  // do something here... such as multiplication and setting
}
```
