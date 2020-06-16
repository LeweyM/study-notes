
http://pages.cs.wisc.edu/~remzi/OSTEP/

# Chapter 1: Processes

Processes are an abstraction for programs running in a system.

Processes are said to be in a certain state - this could be running, ready or blocked and are used by the OS to schedule effective use of common resources such as the CPU or a network link. This swapping in and out of processes in different states is known as **context switching**.

Processes expose a public API for the OS or other programs to do some general purpose actions affecting the process - these include things like `create` to create a new process or `kill` to stop the process from running. A **process list** is a data structure maintaining all of the processes in the system.

[Back to index.](README.md)