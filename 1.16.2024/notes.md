# Heap and Stack

(most modern OS' randomize memory addresses, so they are not physically co-located.)

**Stack**: a stack data structure. size is not as large as heap, but faster access
**Heap**: objects get allocated randomly. larger size but not as fast to access

request an object to be allocated on the heap by the `new` keyword, e.g.

```cpp
Circle circle = new Circle;
```

# Vector

~~with direction and magnitude~~

like C++ arrays, but smarter (as in dynamic). similar to a JavaScript array
which can be dynamically allocated as needed.

basic syntax:

```cpp
vector<T> v1 = { /* ... */ };

vector<int> v2 = { 1, 2, 3 };

vector<Circle> v3;
v3.push_back(1);
v3.push_back(2);
v3.push_back(3);
```
