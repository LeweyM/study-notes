# Chapter 7 - Scheduling

In order make the most of the cpu time and to give the appearance of executing each process or **job** faster, the CPU has to schedule the jobs appropriately.

A metric for scheduler efficiency is **turn-around time** which is the time between a job arriving and completing.

Stack based FIFO running of jobs could be inefficient if quick tasks get stuck behind long tasks. This is known as the **cargo effect.**

If we knew the running time ahead of time, we could run tasks in **Shortest Job First - SJF** order. This would still run into cargo effect problems if quick jobs arrive after long jobs.

**Shortest Time to Completion First** ordering is more optimal as it takes into account currently running jobs.

 Another metric is **Reponse Time** which is the time between a task arriving and it first being scheduled. The above policies are ineffective for thismetric as jobs generally wait until the completion of other tasks before being started.

The **Round Robin** policy jumps between all queued jobs by some set amount, stretching out the time to completion but minimizing the overall response time. 

There is a sunk time in context-switching which could be non-trivial as data between processes must be switched out in multiple locations (registers, stack, CPU caches, etc.) This can be amortized by adjusting the RR interval. 

> This represents a general idea of scheduling - there is an implicit trade-off between turn-around and response time, between ***speed*** and ***fairness***.

Optimizing CPU usage also means making use of process I/O time, in which the CPU is not being used. This time can be **overlapped** with other processes inorder to use the CPU dead-time.


[Back to index.](./README.md)
