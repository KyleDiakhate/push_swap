*This project has been created as part of the 42 curriculum by micampos and ltomas-d.*
# Push Swap

## Description

The objective when making the project push_swap was learning how different algorithms can sort sets of elements faster or slower depending on the disorder of those elements and how many elements there are.
Many factors can influence how approriate an algorithm is for sorting a set the fastest way possible and this project helped see that effect in a more visual way and with the added constraint of having to work with 
two stacks and limited ordering operations.

## Instructions

### Makefile
Command | Description
-|-
`make`, `make all` | builds program
`make clean` |  removes object files
`make fclean` | removes object files and static library
`make re` | runs `fclean` then `all`

Flags | Description
-|-
`--adaptive` | the default flag even if no flag is used, picks an algorithm complexity based on disorder
`--simple` | forces the use of the simple algorithm
`--medium` | forces the use of the medium complexity algorithm
`--complex` | forces the use of the complex complexity algorithm
`--bench` | can be used before the above mentioned flags, gives several stats to the user about the program

### Use in a Project
1. Clone the repository into your project root.
2. Run `make`to build.
3. Run `./pushswap [flag] [the set of intergers]`.

## Resources
### References

* `man` pages
* Peer discussions

### AI Usage Disclosure

A.I. was used in this project to:
* Clear up some details about the implementation of certain functions and debugging some edge cases.
* Make sure this README was properly made.

## Algorithm Breakdown

### Bubble Sort

A straight forward algorithm easy to understand. Every element is compared to each other. In the context of stacks on stack a, we compare the top 2 elements, if the top is smaller than the one below it's pushed
to stack b.
if the top is bigger than the one below we swap a and then push the smaller number of the two to stack b.
With all the numbers on stack b, we use the same logic but in reverse, the bigger number of the pair is pushed to stack a and the smaller keeps being compared in stack b.
After these two cycles, stack a's disorder metric is checked, if a is not ordered, the cycle reapeats until a is sorted.
This algo is very efficient when the set of intergers is almost ordered but very inefficient when not.

### Chunk Sort

This algo groups the set into chunks by only moving to b values below a certain treshold int this case (sqrt of size of stack - 1). after all the numbers below this treshold have been aggregated in b the treshold is
incremented by [sqrt of size of stack -1] again until all numbers are in stack b. The algorithm then pushes elements to stack a based on how big they are (largest to smallest) by calculting their position on stack b and the
number of operations needed to reach them and push them. This would take a lot of operations if the first step was skipped but since the stack is partially chunk sorted, it becomes faster then bubble sort for more disordered sets.


### Radix sort

A more complex algorithm that utilizes bit shifting to agreggate numbers with same the LSB after shifting occurs.
Every bit of the same significance is sorted based on its logical value.
if the LSB is 0, the number is pushed to b, if 1 the number is rotated back to the end of stack a so that another element can be avaluated.
At the end of this first cycle, all the elements with a bit in position 0 are aggregated in b and the ones with a 1 are in a.
They are all pushed from b to a and the cycle repeats but this time the bit to be compared it the one in position 1.
The algorithm terminates when the MSB of the biggest element is reached and the final aggregation occurs.
This algorithm although slow for small sets of intergers and a low level of disorder, shines when used to sort big sets with big degrees of disorder due to the fact that elements are not compared to each other
to determine superiority.

### Contributions
*ltomas-d* - did the operations and parsing.

*micampos* - did the algorithms.