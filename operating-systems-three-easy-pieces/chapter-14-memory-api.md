# Chapter 14 - Memory Api

Memory can be allocated on the **stack** and on the **heap**. Memory allocated on the stack is allocated implicitly and it is cleaned up automatically by the environment when the stack frame closes. 

Memory allocated on the heap must be declared explicitly by system calls to the OS. The C stdlib contains library calls which handle these controls, mainly via ''malloc'' and ''free'' function calls. ''malloc'' recieves as an argument the size of the space in the heap to be allocated and returns a pointer to the starting point of this block of memory. ''free'' will clear this space in memory and allow it to be reassigned by the OS.

## Some common mistakes

Explicitly assigning memory can lead to various errors.

### Memory Leaks

By not freeing assigned memory on the heap, we can produce memory leaks in our programs. Tools like **valgrid** are useful for assessing how much memory was allocated before and after the program has run. As the OS will clear the virtual memory space of a program when it terminates, this is more of an issue for long running processes such as servers.

### Buffer Overflows

Assigning memory for an array but writing beyond that array can lead to silent but deadly errors. If the array was declared on the stack, the process could overwrite the stack data such as the return address of the calling function. This presents a source of errors and a common security flaw.


[Back to index.](./README.md)
