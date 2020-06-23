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

### Allignment

Due to some opimization techniques at the hardware level, some systems place restrictions on the addresses for primitive types, specifying that they must be at an address which is a multiple of 8.

This means that the following memory outlay would not be permitted:

```
struct S {
	int i;
	char c;
	int j;
}
```

```
0        4  5       9  
[   i   ][c][   j   ] 
```

This is because ``j`` cannot be referenced at index 5 as it is not a multiple of 8. Instead, the compiler would allocate free space and increase the overall size of the struct.

```
0       4  5    8       12
[   i  ][c][///][   j  ] 
```

This also applies to arrays of structs, where structs which are not multiples of 8 are padded so that they can be referenced correctly.

One technique of packing structs so as to maximally use space is to **place the fields in descending order**.


[Back to index.](./README.md)
