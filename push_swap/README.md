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
In my case, I used a version of the algorithm that uses the median of the stack as a pivot. This means we first have to sort the whole stack to look for the number located in it's middle once it is sorted. In my case, a simple (and inefficient) bubblesort does the job.  

