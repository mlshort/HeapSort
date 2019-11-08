# Heap Sort Project

Directory Structure
====================

```<language>
  Heap Sort (Solution File)
     |
     +-- Bin (binaries)
     |
     +-- Data (input data file)
     |
     +-- HeapSortProject (Source code) (Project file)
     |
     +-- Obj (compile time intermediaries objects)
```

 Heap Sort Project Overview
===============================================================================

  Assignment: CMPS 5243 Algorithm Analysis

  Write a program to implement a heapsort. For convenience, you may assume that 
  the input has no more than 100 numbers.  Print out the original input data, 
  the array after build_heap has been accomplished, and then print out the array 
  together with the value of heap_size after each 10 elements have been removed 
  from the heap.  Print out the final array.

 Implementation
===============================================================================

  While there are plenty of 'heap-sort' implementations available online, 
  the attached source code was developed based on the text's version 
  (Introduction to Algorithms, 3rd Ed) algorithm as closely as possible.

  Accordingly, the following methods were developed and performed the necessary
  operations as outlined in "chapter 6 - Heapsort":

  - MaxHeapify    : corresponds to MAX-HEAPIFY(A,i) (6.2) 
  - BuildMaxHeap  : corresponds to BUILD-MAX_HEAP(A) (6.3)
  - HeapSort      : corresponds to HEAPSORT(A) (6.4)

 Enhancement(s)
===============================================================================

  Additionally, the program also keeps a running total of all of the in-place data 
  item copying involved through the 'heap-sort' algorithm implementation, for further 
  analysis.

  The amount of 'in-place' data item copying involved in the actual algorithm 
  implementation is an important factor in considering an algorithm's impact on 
  scalability, multi-threaded performance, and system-level data cache awareness.

  The Heap Sort algorithm, in general, is noted for not being very cache performance friendly.

 References
===============================================================================

  * "In-Place Heap Construction with Optimized Comparisons, Moves, and Cache Misses"
    - https://pdfs.semanticscholar.org/9cc6/36d7998d58b3937ba0098e971710ff039612.pdf#page=1

  * Heapsort (via wikipedia)
    - https://en.wikipedia.org/wiki/Heapsort

  * Heaps and Heap Sort - MIT OpenCourseWare
    - https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec04.pdf
