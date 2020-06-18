# Chapter 8 - Multi Level Feedback Queue

Scheduling the CPUs processing time across processes is done without information about how long the process will last or whether it will involve frequent I/O connections during it's execution. **MLFQ** is a heuristic method to optimize process execution based on it's recent history.

Processes are ordered into different queues according to their percieved priority.

### Rules:

- if priority A > priority B  - B is not executed.
- if priority A == priority B - jobs are executed in round robin.
- Jobs start at the highest priority.
- After a given time of a job processing, it moves down in priority. This is regardless of frequently giving up the CPU for I/O tasks.
- After a given time, all jobs jump back to top priority.


[Back to index.](./README.md)
