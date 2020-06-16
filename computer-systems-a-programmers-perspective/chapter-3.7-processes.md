# Chapter 3.7 - Processes

Procedure calls are handled at the machine level on the stack. The stack is maintained by a registry pointing to the call point of the procedure ``%rsp`` **Registry Stack Pointer**. When a procedure is called, the pointer is updated to where the function was called from.

Arguments passed to procedures normally occupy the 6 argument registries, however sometimes more memory is required for handling pointers, structs, or more than 6 arguments. In these cases, memory can be allocated in the stack frame by extending the stack pointer and assigning memory relative to the new pointer position, and then resetting the stack pointer to its appropriate position at the end of the procedure call.

This example stores a variable on the stack frame and passes a pointer to a second procedure.(The address is accessed using the ``leaq`` - **Load Effective Address** command)

```
void myFunc() {
  long x = 5;
  foo(&x);
  return;
}
```
```
subq $8 %rsp        # move the stack pointer down 8 bytes
movq $5 (%rsp)      # assign 5 to free space in stack frame
leaq (%rsp ) %rdi   # assign pointer to first argument register
call foo            # call foo function
addq $8 %rsp        # reset the stack pointer
ret                 # return
```
Some registers by convention are **callee-saved**, which means that procedures must preserve the values of these registers by saving their values and resetting them before the procedure is returned. This convention means that these registers can be used safely by procedures without subsequent procedure calls overwriting the values further down the stack.

[Back to index.](./README.md)
