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

#### **Push swap algorithm**

1. Order the numbers of stack a in an array.
2. Divide the array in chunks from index n to n + x.
3. In stack b, group together the numbers from stack a that belong to the same chunk. Stack a is left empty.
4. In stack a, order the numbers from stack b.

The algoritm to sort the stack will follow these rules:

a -> | A | B | C | // | Z |

b -> | A | B | C | // | Z |

**PUSH**
- A(b) will only push to a when A(b) > B(b).
- If priority is in stack b (see PRIORITY), A(b) will only push to a when A(b) < A(a).


**SWAP**

In stack b, A will swap with B if A < B && A > C .  
EX: b | 3 | 5 | 1 | //	->  | 5 | 3 | 1 | //

In stack a, A will swap with B if A > B .                     
EX: a | 5 | 3 | //	->  | 3 | 5 | //
	
	
**ROTATE**

In stack b, A will rotate if A < B && A < C .                 
EX: b | 1 | 5 | 3 | //	->  | 5 | 3 | // | 1

In stack a, A will rotate if B + n > C + n .                  
EX: a | 3 | 5 | 1 | //	->  | 5 | 1 | // | 3


**REVERSE ROTATE**

In stack b, Z will reverse rotate if Z > A && Z in chunk(A)   
EX: b | 3 | 1 | // | 5	->  | 5 | 3 | 1 | //

In stack a, Z will reverse rotate if Z > A && Z < B           
EX: a | 1 | 5 | // | 3	->  | 3 | 1 | 5 | //


**PRIORITY**
- After every push, we will check which stack is more untidy, this one will get the PRIORITY flag.
- The other stack will only perform swap, rotate or reverse rotate instructions if the priority stack needs to,
  executing for this a double instruction (ss, rr, rrr).


---

### To do

- Determine what must be the proportion between the size of the chunk and the number of numbers to sort.
