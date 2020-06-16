# Chapter 3.8 - Array Allocation And Access

CS:APP 3.8 - Array allocation and Access

When an array is declared in C, the data type is used to compute the step-size between accessors. For example;

```
	int A[12] 
```

Array A is of type ``int`` which require 4 bytes - so the accessor step size is 4. Element ``i`` can be referenced for an array starting at ``xA`` using the formulae ```xA + (I * 4)```.

Example:

```
# %rdx => short array P
# %rdc => integer index i

# %rax => return register for pointers
# %ax  => return register for short types

	p[1]		# => 	movw 2(%rdx), %ax
	p + 3 + i	# =>	leaq 6(%rdx, %rcx, 2), %rax
	p[i*6-5]	# =>	movw -10(%rdx, %rcx, 12), %rax 
```

The same principle applies for multidimensional arrays. The compiler will deduce the offset as follows: 
```
# X     = the starting pointer of the array
# L     = the size of the data type
# C     = the number of columns, the depth of the array
# i, j  = indicies

X + L * (C * i + j)
```


For fixed-size arrays, the compiler is able to do some clever optimizations by extracting the root pointer of the array and performing pointer arithmetic directly on the root pointer. 
For example:

```
void fix_set_diag(fix_matrix A, int val) {
	long i;
	for (i =0; i < N; i++) {
		A[i][i] = val;
	}
}
```

Could be optimized to

```
void fix_set_diag_opt(fix_matrix A, int val) {
    int *Aroot = &A[0][0];
    long i;
    long end = N*(N+1);
    do {
        Aroot[i] = val;
        i += N+1; 
    } while (i != end)
}
```

As the size is fixed, the compiler is able to make some assumptions about the step size from ```N``` and convert iterations into simpler expressions.
















[Back to index.](./README.md)
