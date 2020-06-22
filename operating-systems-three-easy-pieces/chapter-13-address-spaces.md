# Chapter 13 - Address Spaces

Address spaces are used as an abstraction of the physical memory of a machine.

The OS needs to allocate memory for a process in order to store things like the heap, the stack, and the code in memory, as well as other things like static variables. These could be cached when changing between processes, but unlike fast memory assets like registers, saving the whole heap and stack would not be time effective. So, inorder to swap between processes, the OS assigns each process it's own block of memory which is abstracted away.

The reason for this abstraction is for **ease of use** for the processes, and also for **security** so that harmful processes cannot peek or overwrite other elements of the computer memory.

Some interesting linux based commands are `free` which shows the free memory of the system at that moment, and `pmap` which shows the memory map of a given process. The OSX equivalents of these are `vm_stat` and `vmmap`.

[Back to index.](./README.md)
