# Chapter 1 - Language And Performance

Modern day performance is mainly about _how efficiently your data gets into the processor_. The speed order of different locations in memory architecture is as follows: 

Processor Cache (L1 > L2 > L3) ---> Stack Memory ---> Heap Memory

Organizing your code so that data moves directly into the higher level - faster - areas of memory is key to performant code. For example, when iterating over a 2d matrix we should try to iterate sequentially through arrays, as in via rows, rather than across multiple arrays, as in via columns. This is because arrays in go are stored sequentially in memory and can therefore be loaded into cache memory together efficiently. Accessing iteratively the same index from _multiple arrays_ would access from many disperate locations in memory and so memory could not be promoted up the memory heirarchy as efficiently.

Another key technique available in go is using *value semantics* instead of *pointer semantics*. The main difference between these two concepts is that value semantics will create a copy and work on that copy, whereas pointer semantics uses a reference to the same object in memory. From a performance point of view, value semantics greatly increases the chances that the value will only be needed within the context of the calling function. If this is the case, the object only needs to exist on the stack and can therefore be very quickly created and destroyed (technically, the stack will automatically overwrite it, so the clean up is free). Copying to the stack is much faster than retrieving from the heap due to the nature of the architecture.

[Back to index.](./README.md)
