# Chapter 13 - Homework Null

### 1. First, write a simple program called null.c that creates a pointer to an integer, sets it to NULL, and then tries to dereference it. Compile this into an executable called null. What happens when you run this program?

A: Segmentation Fault.

### 2. Next, compile this program with symbol information included (with the -g flag). Doing so let’s put more information into the executable, enabling the debugger to access more useful information about variable names and the like. Run the program under the debugger by typing gdb null and then, once gdb is running, typing run. What does gdb show you?

**Using lldb instead as integrated in mac**

Provides print out of assembly instructions.
This shows the following error 
``` 
EXC_BAD_ACCESS (code=1, address=0x0) 
```

### 3. Finally, use the valgrind tool on this program. We’ll use the memcheck tool that is a part of valgrind to analyze what happens. Run this by typing in the following: valgrind --leak-check=yes null. What happens when you run this? Can you interpret the output from the tool? 

Null dereference error is referenced: 

```
Address 0x0 is not stack'd, malloc'd or (recently) free'd
```

And no leak seems to be found:

```
==99160== LEAK SUMMARY:
==99160==    definitely lost: 0 bytes in 0 blocks
==99160==    indirectly lost: 0 bytes in 0 blocks
==99160==      possibly lost: 0 bytes in 0 blocks
==99160==    still reachable: 0 bytes in 0 blocks
==99160==         suppressed: 14,109 bytes in 159 blocks
```

### 4. Write a simple program that allocates memory using malloc() but forgets to free it before exiting. What happens when this program runs? Can you use gdb to find any problems with it? How about valgrind (again with the --leak-check=yes flag)?

The debugging software shows no problems but ``valgrind`` demonstrates 400 bytes are leaking - 100 * 4 bytes per int.

```
==99530== LEAK SUMMARY:
==99530==    definitely lost: 400 bytes in 1 blocks
==99530==    indirectly lost: 0 bytes in 0 blocks
==99530==      possibly lost: 0 bytes in 0 blocks
==99530==    still reachable: 0 bytes in 0 blocks
==99530==         suppressed: 14,109 bytes in 159 blocks
```

### 5. Write a program that creates an array of integers called data of size 100 using malloc; then, set data[100] to zero. What happens when you run this program? What happens when you run this program using valgrind? Is the program correct?

Valgrid seems to produce the same memory leak errors with an additional error...
```
==248== Invalid write of size 4
==248==    at 0x100000F7A: main (leak.c:5)
==248==  Address 0x10080f750 is 0 bytes after a block of size 400 alloc'd
==248==    at 0x100111995: malloc (in /usr/local/Cellar/valgrind/HEAD-3ab1ae5/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==248==    by 0x100000F6F: main (leak.c:4)
```

This is due to writing past the allocated memory of the array, a buffer overflow error. This does not show up in the debugger nor produces an error when executing. It **fails silently**.

### 6. Create a program that allocates an array of integers (as above), frees them, and then tries to print the value of one of the elements of the array. Does the program run? What happens when you use valgrind on it?

Executing the program prints a seemingly random number...

```
➜  null git:(master) ✗ ./leak
-536870912%                                                                              ➜  null git:(master) ✗ ./leak
-1073741824%                                                                             ➜  null git:(master) ✗ ./leak
1342177280%                                                                              ➜  null git:(master) ✗ ./leak
0%                                                                                       ➜  null git:(master) ✗ ./leak
0%                                                                                       ➜  null git:(master) ✗ ./leak
-2147483648%                                                                             ➜  null git:(master) ✗ ./leak
-805306368%
```

Valgrind shows an invalid read operation and no memory leak, as we would expect:

```
==816== Invalid read of size 4
==816==    at 0x100000F54: main (leak.c:7)
==816==  Address 0x10080f5c4 is 4 bytes inside a block of size 400 free'd
```

```
==816== LEAK SUMMARY:
==816==    definitely lost: 0 bytes in 0 blocks
==816==    indirectly lost: 0 bytes in 0 blocks
==816==      possibly lost: 0 bytes in 0 blocks
==816==    still reachable: 0 bytes in 0 blocks
==816==         suppressed: 18,205 bytes in 160 blocks
```

### 7. Now pass a funny value to free (e.g., a pointer in the middle of the array you allocated above). What happens? Do you need tools to find this type of problem?i

These errors are produced at run-time and give ``pointer being freed was not allocated`` as an error.

Valgrind produces `` ==1031== Invalid free() / delete / delete[] / realloc()`` errors as well as reports the memory leak from the failed free operation.

> **BELOW WOULD BE A GOOD REVIEW EXERCISE**

### 8. Try out some of the other interfaces to memory allocation. For example, create a simple vector-like data structure and related routines that use realloc() to manage the vector. Use an array to store the vectors elements; when a user adds an entry to the vector, use realloc() to allocate more space for it. How well does such a vector perform? How does it compare to a linked list? Use valgrind to help you find bugs.

### 9. Spend more time and read about using gdb and valgrind. Knowing your tools is critical; spend the time and learn how to become an expert debugger in the UNIX and C environment.
