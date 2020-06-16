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

## Homework Answers

HW
1. Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers. 
```	SJF:	
		response time: 200
		turnaround time: 400
	FIFO:	
		response time: 200
		turnaround time: 400
```
2. Now do the same but with jobs of different lengths: 100, 200, and 300. 
```	SJF:	
		response time: 133
		turnaround time: 333
	FIFO:	
		response time: 133
		turnaround time: 333
```
3. Now do the same, but also with the RR scheduler and a time-slice of 1. 
```	RR:	
		response time: 1
		turnaround time: 465
```
4. For what types of workloads does SJF deliver the same turnaround times as FIFO?
```
Jobs increasing in length.
```
5. For what types of workloads and quantum lengths does SJF deliver the same response times as RR? 
```
If the quantum length is the same as the longest job
```
6. What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend? 
```
The response time ignores the longest job. The response times accumulate until n-1 and then the average is the result of summing the accumulations and dividing by n.
```
7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?
```
quantum lengths map directly to response times.
q(((n * (n + 1)) / 2 ) / n) 
```


[Back to index.](README.md)
