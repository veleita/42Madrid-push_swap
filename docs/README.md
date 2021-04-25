PUSH SWAP
=========

General
-------

### Allowed functions

- write
- read
- malloc
- free
- exit


### Push swap instructions

- sa / swap a  -  swap the first 2 elements at the top of stack a. Do nothing if there is one or no elements.
- sb / swap b  -  swap the first 2 elements at the top of stack b. Do nothing if there is one or no elements.
- ss  -  sa and sb at the same time.
- pa / push a  -  take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
- pb / push b  -  take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
- ra / rotate a  -  shift up all elements of stack a by 1. The first element becomes the last.
- rb / rotate a  -  shift up all elements of stack b by 1. The first element becomes the last.  
- rr  -  ra and rb at the same time.  
- rra / reverse rotate a  - shift up all elements of stack a by 1. The first element becomes the last.
- rrb / reverse rotate b  - shift up all elements of stack b by 1. The first element becomes the last. 
- rrr  -  rra and rrb at the same time. 

---

Code
----

### Arguments cooker --FUNCTION--

Receives the arguments passed to the checker or push swap programs.
Checks that
- There are arguments. (else, display nothing)
- The arguments are numbers in the range of an int (-2,147,483,648 to 21,147,483,647). (else, display an error)
- There are no duplicates. (else, display an error)



### Checker --PROGRAM--

Works with two stacks, a and b. a must be filled with integers passed as arguments. b must be empty.

Reads from stdin until it receives EOF.
	If it reads any of the push swap instructions followed by a ‘\n’, perform it and keep reading.
	Else, display an error.

After reading and performing the instructions, if the stack a is ordered and b is empty, display OK. Else, display KO.



### Push swap --PROGRAM--


Works with two stacks, a and b. a must be filled with integers passed as arguments. b must be empty.
It must generate a series of instructions so the numbers in stack a, leaving the stack b empty.

#### **Push swap new algorithm**

1. Order the numbers of stack a in an array.
2. Divide the array in chunks from index n to n + x.
3. Group together the numbers from stack a that belong to the same chunk.
   The smallest half of the chunks remain in stack b, and the biggest half in stack a.
4. Order the numbers in stack a from smallest to biggest a, and from biggest to smallest in stack b.

The algoritm to sort the stack will follow these rules:

a -> | a | // | A | // |

b -> | B | // | b | // |

(B < a)

**PUSH**
- Once the chunks are divided, b will only push to a when both stacks are ordered.

**STACK A**
1. Identify the two biggest unsequenced numbers and put them together.
   The bigger one in this pair be *A*, the smaller be *a*.
2. **ra** or **rra** until *a* is in the head of the stack.
3. **ra sa** or **rra sa** until *a* is located right before *A*.

**STACK B**
1. Identify the two smallest unsequenced numbers and put them together.
   The smaller one in this pair be *b*, the bigger be *B*.
2. **rb** or **rrb** until *B* is in the head of the stack.
3. **rb sb** or **rrb sb** until *B* is located right before *b*.

**BOTH**
1. After each of the loops described above, calculate which stack is more untidy.
2. The tidier stack will only perform double instructions (ss, rr, rrr).
   Therefore, it will wait for the other stack to perform the same instruction.

---

### To do

- Optimize chunks algorithm. DONE - NOT TESTED
- Search two bigger/smaller unsequenced pair of numbers.
- Implement priority system.
