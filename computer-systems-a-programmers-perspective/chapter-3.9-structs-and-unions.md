# Chapter 3.9 - Structs And Unions

**Structs** in C are mainly the same as in arrays, that is that the pointer to the struct points to the first field of the struct and sequential fields are referenced by offsets depending on the size of the previous fields.

```
struct myType {
	char c
	int i
} 
```

Would appear in memory as a contiguous block:


``[  2  ][  - 4 -  ]``

In C we can also declare **unions** which assign the multiple fields of the union to the same area in memory. This can be dangerous as we bypass the type safety provided by C. This can also be used to cast between different types.


[Back to index.](./README.md)
