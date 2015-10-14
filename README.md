# CPS305A2

CPS305 Assignment 2

No extensions will be given.  No late assignments are accepted.

This file may be copied only by a current CPS305 student, and only to 
her/his personal space for use in this course. It may never be placed in 
any public domain, nor in any place accessible by anyone other than the 
single CPS305 student who copied it.

Consult A2addendum.txt for changes to these requirements, as modifications
and clarifications may be made at any time and are part of this assignment.

Assignment is done in groups of 1, 2 or 3 people.
There is no marking penalty for working in a group.
A group member's grade is zero if any group member forgets to include this person's name at submit time. 

------------------------------------------------------------------------

Topics: 
------
  recursion, ADTs 

Platform:
--------
  The CS moons

Files:
------
  pathfinder.c     (you write)
  vector.c         (you write)
  vector.h         (you write)
  path.c           (you write)
  path.h           (you write)
  A2cert.txt       (copy it from A1cert.txt. Edit it correctly)
  A2member.txt     (copy it and edit correctly--will vary by member)


Submit Files:
------------
  Designate ONE PERSON in your group to be the submit-person
  Note carefully what each person submits:

  A2member.txt  EACH and EVERY group member submits own (including submit person)
 
  A2cert.txt    ONLY SUBMIT PERSON submits this
 
  pathfinder.c  ONLY SUBMIT PERSON submits this
  
  vector.c      ONLY SUBMIT PERSON submits this
 
  vector.h      ONLY SUBMIT PERSON submits this 
 
  path.c        ONLY SUBMIT PERSON submits this
 
  path.h        ONLY SUBMIT PERSON submits this



Summary:
--------

Given: Vector, V, in which N non-negative integers are stored (in positions 0, 1, 2, ... (N-1)), where the integer in position (N-1) is 0.

Task:  Find a path through V starting at position 0, and ending at 
       position (N-1), in accordance with the Rule below. If multiple
       such paths exist, print them all; if no such path exists, print 
       appropriate message.
       
Rule:  From position i, the next position in the path must be either i+x, 
       or i-x, where x is the non-negative integer stored in position i.
       There is no path possible from position i to position i+x if
       either of these 2 conditions hold:
<<<<<<< HEAD
      
       position i+x is beyond the end of V.
=======
       
       position i+x is beyond the start of V.
>>>>>>> 6b8d9663d8dd828e758ccf8002f375b7fc9b52dd
       
       position i+x is already on the path.
       
       There is no path possible from position i to position i-x if either of these 2 conditions hold:
       
       position i-x is beyond the start of V.
       
       position i-x is already on the path.

Example:
       Suppose V contained the following:
       
       Position: 0 1 2 3 4 5 6 7 8 9 10 11
       
       Integer:  2 8 3 2 7 2 2 3 2 1 3  0
       
Then one path is:
        0 2 5 7 4 11
       
i.e., you could get from position 0 to position 11 of V by following the path of positions: 0 2 5 7 4 11
      
Note that other paths also exist, such as:
       
       0 2 5 3 1 9 8 10 7 4 11


ADTs
----
  Vectors:
  --------
  Create appropriate Vector ADT, to hold Vectors as given above. 
  Use the following definition:
  
     typedef struct {
        int *item;
        int size;
     } Vector;
     
  Note "item" is an integer array of "size" elements, allocated 
  using Dynamic Memory Allocation.
  
  Implement at least the following operation:
  
     void VectorRead(Vector *V ) ; 
     
  which reads a Vector from stdin. Assume input is on two lines.
  First line contains size, second line contains Vector items. 
  
  e.g., for the example above, input is:
 
      12
      2 8 3 2 7 2 2 3 2 1 3  0

  Paths:
  ------
  Create appropriate Path ADT, to hold a path through a Vector (a 
  sequence of positions. )
  
  Path is similar to Vector (integer array and size); however, 
  at least one additional field is necessary because the current 
  length of the sequence usually differs from its maximum array
  size. 
  
  e.g., the first Path above (0 2 5 7 4 11) might have 
  maximum size=12 items, but would occupy only the first 6 
  positions of the array.
  
  Implement at least the following operations:
  
    void PathInit(Path *P, int size); //using DMA
    int PathAddEntry(Path *P, int entry );
    int PathRemoveEntry(Path *P );
    void PathPrint(Path P);

  Implement your ADTs in files Vector.[ch] and Path.[ch]


Pathfinder
----------
Write a program named pathfinder.c as follows.
Pathfinder reads a Vector from stdin. 
Pathfinder prints every path from position 0 to position 
(size-1) of the given vector, or, if no path exists, prints 
appropriate message

Recursive Algorithm
-------------------
Your solution MUST use a recursive function to identify the paths. 

You must implement the recursive function, as follows, where the
... means you may have additional parameters:
 
      int AllPathsRec(int position, Vector *V, Path *Solution, ... ) 

AllPathsRec takes the initial part of a solution Path, and
a potential next solution position in the Vector. It explores
paths with the given position appended to the given solution
path so far.

AllPathsRec may be called by a wrapper function, which initializes
an initial, empty, solution, etc. The wrapper function would
likely call AllPathsRec with position=0 and an empty Solution.


Approach:
--------
It will be helpful if you do NOT try to write the complete
AllPathsRec at once, but, instead, start off with a simple
prototype, get it working, and then incrementally add functionality
to the prototype until you arrive at the completed assignment.
For example:

1. Start off with a prototype AllPathsRec that simply returns 0
   if NO solution path exists, and returns 1 if ANY solution path
   exists. This prototype does not keep track of the solution 
   path. This prototype simply returns 1 the first time it
   encounters position (size-1) in its explorations.
   This prototype has only 2 parameters: position and V.

2. Modify AllPathsRec to keep track of the solution path found
   in part 1 above. Add parameter Solution, and store this
   solution path in it. AllPathsRec returns similarly to
   prototype 1 above, except its caller will find a solution
   path in the Solution parameter. Add additional parameters 
   to AllPathsRec as necessary.

3. Modify AllPathsRec to continue exploring after the a solution
   path is found. You may choose to have AllPathsRec actually 
   print solution paths to stdout as it finds them; thus, when 
   AllPathsRec returns to the wrapper, the Solution parameter 
   may contain only the last last solution path encountered, 
   if any. The trick is to force the recursion to keep going
   even after if finds a solution. It returns only when every
   path has been explored (following the Rule).


Robustness and Assumptions:
--------------------------
 -Assume user provides correct input on stdin 
 
 -Assume memory is always available (malloc calloc, etc)  
 
 -File A2addendum.txt will be updated periodically with additional assignment
  assumptions and QA. Everything in A2addendum.txt must also be considered 
  part of this assignment.

Grading:
--------
 On a CS moon only, we will compile and run your program.

 -The assignment mark IS ZERO for:
   -incorrectly named files (includes case!!)
   -A2cert.txt missing or incorrectly filled-in
   -A2member.txt missing or incorrectly filled-in for any group member
   -code does not compile 
   -code compiles, but is not a good attempt at solving the problem
    (too simplistic, etc.)

 If not zero, then the mark includes, but is not limited to, the 
 following. Note that if the submission is incomplete, then the
 Style/Documentation/Modularity mark is also reduced accordingly.

 -Style and Documentation (15%)
    -simple, clear, readable code
    -function header comments
    -internal documentation only of complicated parts
    -indentation, formatting, use of whitespace (indent with either tabs
     or spaces, but not both mixed). Your code should look properly 
     formatted when displayed with moon "cat" command.
    -meaningful, consistent function and variable names

-Modularity  (10%)
       Good use of helper functions.  If a task is repeated, use a helper 
       function, NOT (nearly) duplicate code.  If a function is too long, 
       consider dividing it into sub-functions, even if they are called 
       only once. Too long is about 30LOC. Divide even short chunks of
       code into functions to increase readability of your code.

 -Functionality (75%)
    -correctness (when following assignment instructions)
     Your program may produce required results, but will be worth nothing
     unless it does so by following assignment instructions/requirements.
      correctness is measured ONLY by the grader's own tests. 


Example Run:
------------
Here is an example of running pathfinder.c (compiled into a.out). 
Note that "dwoit> " is simply my prompt.

    dwoit> cat goodInput
    12
    2 8 3 2 7 2 2 3 2 1 3 0
    dwoit> a.out <goodInput
    0 2 5 7 4 11 
    0 2 5 3 1 9 10 7 4 11 
    0 2 5 3 1 9 8 10 7 4 11 
    0 2 5 3 1 9 8 6 4 11 
    dwoit> cat noSolutionInput
    10
    3 1 1 1 3 4 2 5 3 0
    dwoit> a.out <noSolutionInput
    No Solution
    dwoit> 
