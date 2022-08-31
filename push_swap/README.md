# Push\_swap
#### Ordering ints in the most stackable way.

<img src="https://github.com/IcaroJam/Cursus42/blob/master/push_swap/images/Result.png?raw=true" alt="Results image" width="150"/>  
[Note: This implementation gets _really_ close to the perfect 125, but it doesn't quite get there, so 115 it is. I'm sure some tinkering could be done to bring the movements down to the required minimum for the perfect score, but I can't be bothered with that at the moment.]


This project is based in ordering a given list of ints, with a limited instruction set and only two stacks. Is important when considering everything going on here to take into account we want to minimize the _number of instructions_ and nothing else. Runtime, memory usage and computing power used aren't taken into account.  
This leaves us in a peculiar situation, since we can take as much time as we like in between movements. Meaning we could potentially evaluate _every_ possible case after each movement to take the best next step. This would surely, however, result in timeouts (and great headaches). So let's not do that.

### The algorithm
After pondering a bunch of ways to sort out numbers, I opted for [the quicksort algorithm](https://en.wikipedia.org/wiki/Quicksort), which seemed pretty intuitive and a bit challenging.  
A far simpler approach, used by many in my campus, is [radix sort](https://en.wikipedia.org/wiki/Radix_sort). I wanted to try something different though (and better too lol).

Anyways, what does quicksort do? [This video](https://www.youtube.com/watch?v=e_l77X9P1H4) is a pretty visual way of explaining it. It is all about pivoting to partially sort the stack.

### Coding the algorithm
The logic behind this is pretty much the same as [SamLynnEvans' implementation](https://github.com/SamLynnEvans/Push_swap), since I used it as a guide when trying to figure out how to translate the algorithm into code.

I used a version of the algorithm that takes the median of the stack as a pivot. This means we first have to sort the whole stack to look for the number located in it's middle once it is sorted. In my case, a simple (and inefficient) bubblesort does the job. Remember when I said only the number of moves matters? Yup.  
Now, many versions of this project are based around linked lists of various types. This didn't seem right to me for some reason, so my implementation makes use of arrays.

---
#### The stacks
![Header image](https://github.com/IcaroJam/Cursus42/blob/master/push_swap/images/Header.png?raw=true)  
Quicksort requires to keep track of the pivots, using them to make partitions in the stack. To do this I simply create a stack struct that holds the size (to make the initial malloc of the array), the "top" which is always i+1, where i is the index of the number at the top of the stack, and the array. As to keep track of the pivots, the array isn't of ints, but of a struct holding the number itself and a flag that marks the number as a pivot.  
Note that my implementation considers the int at the index 0 of a stack to be the item _at the bottom_ of the stack.  
Also note that the moving operations must take into account whether the numbers being moved are flaged and act accordingly.  
This implementation allows for easy manipulation of the elements of the stacks without having to manage memory, pointers, or even delete the numbers after moving them around. The top flag marks where the last number we are interested in is, whatever comes after it isn't important, so you can just overwrite stuff without having to take care of deleting anything.

---

The process goes as follows:
- Check the input. If valid, store in the a-stack as it comes. (It is important to have the order in which you are storing the numbers very clear).
- Make a sorted copy of the stack, use it to find the median, then destroy the copy.
- Iterate the a-stack. Everything smaller than the pivot goes to the b-stack. Same thing for the pivot itself. When done, mark a partition at the top of b-stack.
- Repeat until 5 or less numbers are left.
- Sort the remaining numbers in a-stack with the method of your choice and mark a partition in a-stack. Partitions in this stack mark that it is sorted up until that point.

We now have a sorted a-stack with few numbers and a pseudo-sorted b-stack with clear partitions. The process from this point on is repetitive and similar to the one before:

- Create a sorted copy of the upmost partition of b-stack, get it's median and destroy the copy.
- Push the numbers bigger than the pivot and the pivot itself to a-stack. Note that, after reaching the end of the partition, it is _essential_ that we bring the elements that weren't pushed back to the top of b-stack.
- If five or less elements were pushed, we can easily sort them, then mark a partition in a-stack.
- If more than five elements were pushed, we iterate through a-stack yet again, _only_ up until it's last partition, pushing to b the same way we did before.
These steps are repeated until the whole thing is sorted.

For more detailed information on _how_ all of this can be put down into code, checkout the source files of the repository. They aren't my cleanest code and some parts can be a bit confusing, but I think it makes perfect sense if you understand the logic behind it.  
As always, if you find anything you think could be improved or have any questions, you can message me via slack, send a mail, shoot an arrow with a note attached at my door... the usual.

Signing out, ~Ari.
