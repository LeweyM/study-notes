# Chapter 3.10 - Pointers And Stack Vulnerabilities

### Pointers

Pointers represent a location in memory and always have a value associated with them, even if the value is the special ``NULL`` value.

Pointers are very closely related to arrays and can be directly translated between them: ``A[3]`` is the same as ``*(A+3)``

In C it also possible to create **function pointers** which creates a reference to a block of code.

``` 
int fun(int x, int *p);

int(*fp)(int, int*);
fp = fun;

int y = 1;
int result = fp(3, &y);
```

### Buffer Overflows

A buffer overflow is a common security vulnerability which occures when a pointer referencing an array is incremented beyond the memory assigned for it. As C does not perform **bound checking** on arrays, it is possible for the program to then overwrite unintended parts of the memory or (maliciously) execute arbitrary code.

If the buffer array was allocated on the stack, it is very possible for the code to overwrite the return address of the calling code, enabling the program to redirect to anywhere in the system. 

[Back to index.](./README.md)
