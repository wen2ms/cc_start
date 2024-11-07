### Difference

- For template functions, explicitly specifying tpyes will call implicit type conversion, and automatic type deduction will not.


### Calling rules

1. Both ordinary functions and template functions can be called, and ordinary functions are called first.

2. Template functions can be forced to be called with an empty argument list.

3. Template functions can also be overloaded.

4. If template functions are more suitable for matching, it will be called first. 

