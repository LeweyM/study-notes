# Chapter 2 - Process API

Inorder to control processes from outside of their executing scope, processes expose a **process API.**

One of the ways a process can create new process is with the ``fork()`` command. This creates a new **child process** which is exactly the same as the **parent process**. Executing different flows must be handled by branches within the code.

```
int main() {
	int rc = fork()
	if (ir < 0) {
		printf("fork failed")
		exit(1)
	} else if (ir == 0) {
		printf("I'm a child process")
	} else {
		printf("I'm the parent process")
	}
}
```


When a new branch process is launced, it is given an new identifying **PID** number.

Another way we can execute other processes is with the ``exec()`` command, which substitutes code from another process in the calling process. This does not change the PID.

The command ``wait()`` can also be used so that a parent process can wait untill the child process has terminated.

processes also have a notion of **user**. Users only have permission to control the processes they have created. Only a **superuser** can control other processes.

[Back to index.](README.md)
