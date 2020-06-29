# Chapter 3 - Quick Sort

The Quicksort algorithm functions by choosing a pivot value in an array, then partitioning the array into values below or above that value. This is done recursively until the array is sorted.

Quicksort has a logarithmic average big O complexity in the average case.

The worst case complexity is quadratic, and would occur if the pivot value is always the lowest or highest value. In this case the partitions would have 1 and n-1 items and the array would need to be partitioned n times in order to be sorted. In practice, this might occur when sorting nearly sorted arrays. We can guard against this by using **randomization** shuffling the array before sorting.

As Quicksort works by swapping elements of an array, it is an **in-place** algorithm. There is some extra memory usage on the stack as the we recurse through the partitions, but this extra space is logarithmic.

As the swaps made by the algorithm as not next to each other and elements can make 'long jumps', quicksort is **not stable**.

### Some improvements could be:

Use insertion sort for small partition subarrays (<10 elements) to save the cost of recursing.

Find the median of 3 random items and use as the pivot value to try to get more even partitions.


[Back to index.](./README.md)
