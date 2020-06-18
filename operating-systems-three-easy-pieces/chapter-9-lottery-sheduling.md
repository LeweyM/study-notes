# Chapter 9 - Lottery Sheduling

There are numerous ways of implementing a CPU sheduling policy, many of which are implemented across various systems. 

### Lottery 

Lottery scheduling involves assigning **tickets** to processes and randomly running tasks by choosing from the available tickets. This relies on a fast random number generator but has some nice advantages.

Systems using lottery based scheduling can use **ticket transfer** to assign more processing power to child processes, or **ticket inflation** to increase the chance of processing when opperating with trusted processes.

The implementation is straight-forward as we simply check if the ticket is within the range of the task1.ticket_count, if not then task2.ticket_count etc. This can be improved by keeping the ticket counts in a sorted data structure.

Lottery systems can also maintain the concept of a **stride** which is inversely proportional to the ticket count and is used to calculate the total runtime of the process. This can keep the CPU profile fairer.

[Back to index.](./README.md)

