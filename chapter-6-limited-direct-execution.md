# Chapter 3 - CPU - Limited Direct Execution


Can run programs in **user mode** and **kernel mode** - only kernel mode has access to **system calls.** 

System calls are made under the hood by **trap** instructions stored in specific locatiosn on the the stack or in registers. These are abstracted away by the C standard library.

The system calls which carry out processes in kernel mode are specified at boot time and are stored in a trap table. They are then called by passing a system call number rather than accessing the location directly.

X86 systems store the data (registers, program counter, etc.) necessary to `return-from-trap` - return back to the user mode process - on a **kernel stack.**

Sometimes it is necessary for the OS to retake control of the CPU, this could be to perform a context switch or to read I/O opperations. As a user process could be intentionally or accidentally unresponsive and never voluntarily give back control (such as in an infinte loop), the OS uses **timer interrupts** to intermittedly take back control.

When changing between processes, process relevant data must be stored and later reset. This low level process is a **context switch.**
