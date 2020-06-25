# Chapter 14 - Memory Api

Memory can be allocated on the **stack** and on the **heap**. Memory allocated on the stack is allocated implicitly and it is cleaned up automatically by the environment when the stack frame closes. 

Memory allocated on the heap must be declared explicitly by system calls to the OS. The C stdlib contains library calls which handle these controls, mainly via ''malloc'' and ''free'' function calls. ''malloc'' recieves as an argument the size of the space in the heap to be allocated and returns a pointer to the starting point of this block of memory. ''free'' will clear this space in memory and allow it to be reassigned by the OS.

## Some common mistakes

Explicitly assigning memory can lead to various errors.

### Memory Leaks




[Back to index.](./README.md)
