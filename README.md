# Programming Assignment 2: Search Trees
In this Programming Assignment, you will be assessing your understanding of Binary Search Trees and K-D Trees.

## Part 0: Setup

Work through the [SETUP.md](SETUP.md) document to configure your development environment.

## Part 1: Tree Balance (20 points)
The time complexity of algorithms on many tree structures depends significantly upon the "balance" of the tree. Trees can be *perfectly balanced*, *perfectly unbalanced*, or somewhere in between.

### Task 1a: Create ``1a.txt`` (5 points)
Imagine we have created a Binary Search Tree by inserting the following sequence of integers into an empty Binary Search Tree (in this exact order):

```
10, 20
```

Create a file called ``1a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when added after the above sequence of integers, will result in a **perfectly *un*balanced** tree.

### Task 1b: Create ``1b.txt`` (5 points)
Imagine we have created a Binary Search Tree by inserting the following sequence of integers into an empty Binary Search Tree (in this exact order):

```
10, 20
```

Create a file called ``1b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as  [``README.md``](README.md)) containing a single integer that, when added after the above sequence of integers, will result in a **perfectly balanced** tree.

### Task 1c: Create ``1c.txt`` (5 points)
Create a file called ``1c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as  [``README.md``](README.md)) containing a comma-separated list of 7 integers that, when added to an empty Binary Search Tree, will result in a **perfectly *un*balanced** tree.

### Task 1d: Create ``1d.txt`` (5 points)
Create a file called ``1d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as  [``README.md``](README.md)) containing a comma-separated list of 7 integers that, when added to an empty Binary Search Tree, will result in a **perfectly balanced** tree.

## Part 2: Implementing a Binary Search Tree (35 points)
Much of the beginning of this course is centered around [Binary Search Trees (BSTs)](https://en.wikipedia.org/wiki/Binary_search_tree). As such, it is important for us to be able to implement the basic functionality of a BST.

### Task: Edit [``BST.cpp``](BST.cpp) (``BST`` functions)
In this repository, there is a file called [``BST.cpp``](BST.cpp) that contains the initial steps towards implementing a BST. Function headers (with usage details) are included in [``BST.h``](BST.h), and you need to fill in the constructor, destructor, and all functions of the ``BST`` class. Note that, at this point in the PA, we do not expect you to fill in the ``BST::Node::successor()`` function: that will be in a later part of this PA.

We have provided a tester program, [``BSTTest``](BSTTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -O0 -g -std=c++11 -o BSTTest BSTTest.cpp BST.cpp
```

Here's an example of how it should look like when it's compiled and run from the command line:

```
$ g++ -Wall -pedantic -O0 -g -std=c++11 -o BSTTest BSTTest.cpp BST.cpp
$ ./BSTTest
Success
```

If it prints anything *other* than ``Success``, that means it has bugs. We expect you to be able to debug your code however you feel is best (e.g. print statements, ``gdb``, etc.).

### Task: Create a Makefile
As you may have noticed, this PA's starter code did not come with a Makefile.
Create your own a Makefile with a build target called `BSTTest` which produces the `BSTTest` executable.
Feel free to look at the Makefile of the previous PA.

> ### 🛠 Know Your Tools - GNU Make
>
> The command [`make`](https://www.gnu.org/software/make/) is part of [GNU](https://www.gnu.org/home.en.html) just like [GCC](https://gcc.gnu.org/) is part of GNU.
>
> Make is what is called a "build tool" it helps you build your program from source files. Note that a build tool is not a compiler; build tools make use of compilers.
>
> The advantage of using a build tool such as `make` is to improve the user-friendliness of the compilation process. For example, in the compile examples above we've made direct calls to `g++` from the terminal. This works just fine, however we need to remember to pass in all the correct options as well as all the required source files to build the executable. Making developers on our projects remember all this is not exactly user friendly.
> With `make` we can write a Makefile which contains all of these details about how to compile our program. The developer can now just call `make` or `make <target>` to compile the program.
>
> What is the difference between running `make` and `make <target>`? And what even is a `<target>`?
>
> A "build target" or "target" is something that can be compiled, such as an executable or an [object file](https://en.wikipedia.org/wiki/Object_file). The "target" is the output file of your compilation.
>
> A ["rule"](https://www.gnu.org/software/make/manual/html_node/Rules.html) tells `make` how to execute a series of commands in order to build a target. Rules may depend on targets with their own rules, which `make` will then automatically execute first.
>
> The rule syntax in a Makefile is:
> ```Makefile
> targetName: targets and files that this target depends on
>     commands to be run to build the target file
> ```
>
> Why is it useful to have a rule for each build target? For example, our project might be large and have many different build targets.
> In such a project, we might want to avoid having to compile our entire project if we are just interested in compiling one of the executables.
> If we have a separate rule in our Makefile for the executable that we want to compile, then we can let make execute just that one rule.
>
> Make also allows us to create ["phony targets"](https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html). These are defined by rules in our Makefile which do not actually produce a target file with the target name. Instead they are just the name of a recipy to be executed.
> This is useful because we might want to create some utility rules which do not produce new files. A common example of such a phony target is `clean` which generally just removes all previously built target files.
>
> If you do not specify which target you want `make` to build, then `make` will run the top-most rule in your Makefile. It might therefore make sense to create a phony target called `default` at the top of your Makefile. Let this `default` target "depend" on the targets of the rules you want to run when the developer runs `make` without specifying a target name.
>
> When writing our rules, we may find that many rules use the exact same `g++` options. To avoid duplication, we can define variables at the top of the Makefile.
> For example, in a C++ project's Makefile the convention is to define your compiler command under the variable `CXX` and your compiler flags under the variable `CXXFLAGS`.

### Checking for Memory Leaks
Remember that you will be dynamically creating ``Node`` objects, so beware of memory leaks! You can use ``valgrind`` to check for memory leaks. For example, you can run it as follows:

```bash
valgrind --tool=memcheck --leak-check=yes ./BSTTest
```

If it gives you a report like the following, you do not have memory leaks and are good to go (the important part is ``All heap blocks were freed -- no leaks are possible``):

```
==2129== Memcheck, a memory error detector
==2129== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2129== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2129== Command: ./BSTTest
==2129==
==2129== error calling PR_SET_PTRACER, vgdb might block
==2129==
==2129== HEAP SUMMARY:
==2129==     in use at exit: 0 bytes in 0 blocks
==2129==   total heap usage: 316 allocs, 316 frees, 83,936 bytes allocated
==2129==
==2129== All heap blocks were freed -- no leaks are possible
==2129==
==2129== For counts of detected and suppressed errors, rerun with: -v
==2129== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

If you *do* have memory leaks, the report will look something like the following:

```
==2178== Memcheck, a memory error detector
==2178== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2178== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2178== Command: ./BSTTest
==2178==
==2178== error calling PR_SET_PTRACER, vgdb might block
==2178==
==2178== HEAP SUMMARY:
==2178==     in use at exit: 3,200 bytes in 100 blocks
==2178==   total heap usage: 312 allocs, 212 frees, 83,816 bytes allocated
==2178==
==2178== 3,200 (32 direct, 3,168 indirect) bytes in 1 blocks are definitely lost in loss record 3 of 3
==2178==    at 0x4C3017F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==2178==    by 0x1095A1: BST::insert(int) (in /mnt/c/Users/niema/Desktop/PA2-Solution/BSTTest)
==2178==    by 0x108F54: main (in /mnt/c/Users/niema/Desktop/PA2-Solution/BSTTest)
==2178==
==2178== LEAK SUMMARY:
==2178==    definitely lost: 32 bytes in 1 blocks
==2178==    indirectly lost: 3,168 bytes in 99 blocks
==2178==      possibly lost: 0 bytes in 0 blocks
==2178==    still reachable: 0 bytes in 0 blocks
==2178==         suppressed: 0 bytes in 0 blocks
==2178==
==2178== For counts of detected and suppressed errors, rerun with: -v
==2178== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Part 3: BST Successor (25 points)
One can iterate over the elements of a BST in ascending order by starting at the left-most node in the BST (which is the smallest element) and one-by-one finding each node's [successor](https://www.youtube.com/watch?v=XX_2nHNICO4&list=PLM_KIlU0WoXmkV4QB1Dg8PtJaHTdWHwRS).

### Task: Edit [``BST.cpp``](BST.cpp) (``BST::Node::successor()``)
Now that you have implemented the member functions of the ``BST`` class, it's time to implement ``BST::Node::successor()``, which will find the successor of the current node.

We have provided a tester program, [``SuccessorTest``](SuccessorTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -O0 -g -std=c++11 -o SuccessorTest SuccessorTest.cpp BST.cpp
```

Here's an example of how it should look like when it's compiled and run from the command line:

```
$ g++ -Wall -pedantic -O0 -g -std=c++11 -o SuccessorTest SuccessorTest.cpp BST.cpp
$ ./SuccessorTest
Success
```

If it prints anything *other* than ``Success``, that means it has bugs. We expect you to be able to debug your code however you feel is best (e.g. print statements, ``gdb``, etc.).

### Task: Extend your Makefile
Extend your Makefile with a build target called `SuccessorTest` which produces the `SuccessorTest` executable.

## Part 4: K-D Trees (15 points)
The [K-Dimensional (or K-D) Tree](https://en.wikipedia.org/wiki/K-d_tree) is an extension of a BST for multi-dimensional data. Essentially, all tree algorithms of a K-D Tree are the same as those for a BST, except in a K-D tree, you alternate between dimensions for each level. For example, in a K-D Tree storing 3-dimensional points, we would only compare the root's *x*-coordinate with our query's *x*-coordinate; on the next level, we would only compare *y*-coordinates; on the next level, we would only compare *z*-coordinates; on the next level, we would only compare *x*-coordinates; etc.

For the tasks below you may assume that we always alternate between dimensions from left to right (i.e. first *x*, then *y*, then *z*; just like in the example above).


### Task 4a: Create ``4a.txt`` (5 points)
Imagine we have created a K-D Tree by inserting the following sequence of integer 2D points into an empty K-D Tree (in this exact order):

```
(7,2), (5,4), (9,6), (4,7), (2,3), (8,7)
```

Create a file called ``4a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a 2D integer point in the format ``(x,y)`` that, when added after the above sequence of points, will result in a **perfectly balanced** tree.

### Task 4b: Create ``4b.txt`` (5 points)
Imagine we have created a K-D Tree by inserting the following sequence of integer 3D points into an empty K-D Tree (in this exact order):

```
(21,42,63), (10,100,1000), (3,6,9)
```

Create a file called ``4b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a 3D integer point in the format ``(x,y,z)`` that, when added after the above sequence of points, will result in a **perfectly *un*balanced** tree.

### Task 4c: Create ``4c.txt`` (5 points)
Imagine we have created a K-D Tree by inserting the following sequence of integer 4D points into an empty K-D Tree (in this exact order):

```
(10,30,50,70), (20,40,60,80), (15,30,45,60), (100,10,1,0)
```

Create a file called ``4c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a 4D integer point in the format ``(x1,x2,x3,x4)`` that, when added after the above sequence of points, will result in a **perfectly *un*balanced** tree.

## Academic Integrity
This Programming Assignment (PA) must be completed 100% independently! You may only discuss the PA with the Tutors, TAs, and Instructors. You are free to use resources from the internet, but you are not allowed to blatantly copy-and-paste code. If you ever find yourself highlighting a code snippet, copying, and pasting into your PA, you are likely violating the Academic Integrity Policy. If you have any concerns or doubts regarding what you are about to do, *please* be sure to post on Piazza first to ask us if it is okay.

## Grading (100 points total)
* **Part 1: Tree Balance**
  * 5 points for a correct ``1a.txt`` (0 points for incorrect)
  * 5 points for a correct ``1b.txt`` (0 points for incorrect)
  * 5 points for a correct ``1c.txt`` (0 points for incorrect)
  * 5 points for a correct ``1d.txt`` (0 points for incorrect)
* **Part 2: Implementing a Binary Search Tree**
  * 30 points for a correct solution with no memory leaks (20 points for correct with memory leaks, 0 points for incorrect)
  * 5 points for a correct Makefile
* **Part 3: BST Successor**
  * 20 points for a correct solution (0 points for incorrect)
  * 5 points for a correct Makefile
* **Part 4: KD-Tree**
  * 5 points for a correct ``4a.txt`` (0 points for incorrect)
  * 5 points for a correct ``4b.txt`` (0 points for incorrect)
  * 5 points for a correct ``4c.txt`` (0 points for incorrect)
* **Know Your Tools**
  * up to 5 points for the Know Your Tools assignment on gradescope

## Submission
* Run `./create_submission_zip.sh` in your project root.
* Submit `submission.zip` to the programming assignment auto grader on [Gradescope](https://www.gradescope.com/)
* Submit the Know Your Tools assignment on [Gradescope](https://www.gradescope.com/)
* Late submissions **will not be accepted**, check [Gradescope](https://www.gradescope.com/) for the deadlines.
