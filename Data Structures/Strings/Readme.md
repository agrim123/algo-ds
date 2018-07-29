# Strings

## Ways to initialize strings

1. char*

```c++
char* str = "Random String";
```
- Cannot be modified at later stage but can be pointed to something else but cannot change value present at str.

2. std::string

```c++
string str = "Random String";
```
- Instantiation of the basic_string class template that uses char (i.e., bytes) as its character type.
- In string the particular character can be accessed by the function `str.charAt(index)`.


3. char[]

```c++
char str[] = "Random String";
```
- String can be modified later by using indexes.
- Space is statically allocated which consumes space on stack.
