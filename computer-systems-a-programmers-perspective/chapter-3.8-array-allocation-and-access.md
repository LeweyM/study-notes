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

[Back to index.](./README.md)
