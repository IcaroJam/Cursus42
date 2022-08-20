# 42 Philosophers
#### A project to learn about thread syncronization using mutexes (and process syncronization using semaphores in the bonus)

[Note: Files in the root directory are shared between the mandatory and bonus parts. The bonus and mandatory directories each have their main file and source file with the essential runtime functions.]

My approach to projects can be a bit chaotic sometimes, so let's start by taking a look at the header file shall we?  
The header used in the mandatory part is the same one the shared functions use in the bonus part, that's why it is stored in the main directory. Just for clarification.  
Prepare yourself. This may be, as we say here, _mucho texto._

![Header image here](https://github.com/IcaroJam/Cursus42/blob/master/philo/images/Header.png?raw=true)

The program counts with a main data structure, which holds everything the program needs to run tightly packed in a single pointer ready to be passed down to the functions.
The struct can be stripped down to:
- nop (no. of philos), ttd (time to die), tte (time to eat), tts (time to sleep) and notepme (no. of times each philo must eat): Input values that dictate the values to be handled by the program.
- starttime: The time at which the program "started" (we'll get to that later). It'll be used as a reference for timestamps during runtime.
- philodeath: A flag pointing out if any of the threads died.
- notepmeflag: A flag pointing out how may philos ate enough times.
- phls: A pointer to an array of structures with data related to the different threads.
- forks: A pointer to an array of mutex locks.
- mstrthrd: The "Master Thread" that will continuously iterate through the philosophers checking their status.
- log: A mutex lock for the consolelog function, so that multiple threads can't write to the standard output at the same time.

We also have the data structure used for each philosopher, composed of the following:
- ticketback: A pointer to the main struct. This is convenient for the main function of the threads, as it must receive a single void pointer, so passing the corresponding philosopher's struct to each thread ensures an easy way for the thread to have all data while also knowing which philosopher it represents.
- philo: The thread data type.
- id: The id of the philosopher.
- leftfork: The index in the fork array that the fork left to this philo has.
- rightfork: As above but for the fork to the right.
- lstmealtime: Timestamp of the last time this philosopher started eating.
- timeseaten: Amount of times this philosopher has eaten.

Moving on to what the program _actually_ does.
### Input handling
First things first, we must check if the input values are valid. That's where _input.c_ comes in. The inputhandler function first checks whether main received 5 or 6 arguments and error exits otherwise. Note that when the program ends due to an error, the error message is printed using printf, so it is printed onto the stdout instead of stderr, which isn't the right thing to do. _Don't do that_. I did it out of lazyness.  
After checking the number of arguments, the program iterates through the characters, first checking for non-digit chars (none of the args should be a negative number), then for arguments that would overflow an int.  
If neither of those terrible, terrible things happened, inputhandler stores the arguments as ints in the main struct.  
My implementation considers that a number of philosophers lower than 2 is an error since a single philo can't eat due to having a single fork. This however may be considered bad practice by some hardcore evaluators. I personally think is a better solution since it prevents a program destined to fail from ever running, but that's just me.  
After all of this, the death flag is initialized to 0 and the start time of the program is saved. This is done now for precission purposes, but it really isn't a big deal.
### Mutex initialization
Alright so now we've got all values ready and stored. Time to start doing some real computing. On with the forks!  
A single mutex with the purpose of locking the consolelog function is created first, then the utensilgenesis function is called. This function allocates space for _nop_ forks and creates them.  
A simple loop is in charge of creating the mutexes that fill the fork array. If a mutex init fails, the mutexes created up to this point are destroyed and the fork array freed.  
If everything goes according to plan, we are now ready to create the threads.
### Thread creation
The philinit function first allocates memory for the philosopher struct array, then iterates the array initializing the variables to some default values and finally, creates the corresponding thread.  
Note than when a thread is created, a function that will act as the thread's main is passed to it. The thread will immediatelly begin doing it's thing, so one may want to implement some starting syncronization so all threads begin at the same time. That isn't the case here though, at least normally. A huge amount of philosophers may result in some delays.    
When all threads have been successfully created, the master thread is created.
If philinit fails at any point, the worldender function is called, which frees all memory and destroys all mutexes, and the program error exits.  
On a successful philinit, main gets blocked waiting for the master thread to end.  
We are now running the real deal.
### Thread functions
The philosophers all execute the sofic\_routine function (that should really be called sophic\_routine as it is in the bonus but oh well), which starts out by upgrading the void pointer it receives to the struct of the current philosopher, then store the pointer to the general struct and then initialize the indexes of the forks it will use. As stated in the image above, the index of the fork to the right of a philosopher is the same as the philosopher's id. The last philosopher will have the first fork (index 0) to it's right.
To avoid deadlocks (picture a situation where all the philosophers grab the fork to their left. None able to eat since all forks are taken, they all perish a starving death... tragic innit? We don't want that), philosophers with an uneven id wait _a minimum_ of 250 microseconds.  
_A minimum?_ that's weird. Let's go on a bit of a tangent:

---

### The phisleep function
The only sleep function allowed in this project is usleep which, as it turns out, was deprecated because it is quite bad. If you use it as it comes, your program won't take long to introduce a very noticeable offset in the timestamps.  
That is why we came up with a better alternative here at JamLabs. Conveniently packed into the clockstuff.c source file.  
Phisleep simply uses a loop using usleep with a small value, checking if the difference between the current timestamp and the one saved at the beginning of the function is greater than the amount of time the thread should sleep and returning if so.

---

Back in sofic\_routine, we enter _the_ loop. A long as all philosophers are alive, each philosopher will lock their forks if they are free or wait for them to be free if they aren't. When a philosopher has taken both forks, it will store the timestamp in lstmealtime and sleep for tte. After that it will unlock both forks and start sleeping. After sleeping it will start thinking and begin again. At pretty much everty step of the process the philosopher checks if someone has died as a security measure so that the threads don't keep doing stuff if someone has died. This way of preventing this is very redundant, but I couldn't come up with a better alternative. Do hit me up on slack or write me an email if you think of a better way. Maybe even fork the project or open a pull request ^^.  
Whenever a philosopher logs what it is doing, it does so using the consolelog function, which uses it's own mutex and only prints if no philosopher has died.  
Again, a bit redundant but it is what it is.

While the philosopher threads are doing their thing, the master thread is running on the everwatcher function, iteratively looping through the philo array checking, for each philosopher, if enough time has passed that the philosopher must die, or if the philosopher has eaten enough times.  
After each iteration, if the notepme argument was passed to main and the notepmeflag equals nop (meaning all philosophers ate at least notepme times), the death flag is set to true and a message is printed.  
The same happens when a philosopher dies, which results in the master thread waiting for all other threads to end and then ending itself.
This results in the termination of the program.

All of this works because threads of the same process run in parallel and all share the same memory space. This allows for all philosophers to read and change variables in the main structure (so that a single death flag can be used for all threads since the program must end on the death of any philosopher), but also carries the risk of a thread changing a variable in between reads of said variable on a different thread. Thats where mutexes come in and that's what the project is all about.

But what if the philosophers weren't threads of the same process, but different processes..?
## Bonus part
That is exactly what is going on in the bonus part. Instead of threads, the philosophers are processes. Instead of mutexes, we use semaphores. And the forks are all ready for the take in the middle of the table rather than restricted to the inbetween of two philosophers.
The implications of this differences can be seen if we take a closer look at the bonus header file:
![Header image here](https://github.com/IcaroJam/Cursus42/blob/master/philo/images/Bonusheader.png?raw=true)
The main struct has the same input flags, but lacks a death flag; instead of mutex types, we have semaphore types; and there is no master thread.
The philosopher struct now has a process id (pid) type instead of a thread type. There is no left and right forks, since all forks rest in the middle of the table and each philosopher now has it's own death flag.

While threads share memory space, processes don't. When a process is forked, the child process creates a copy of all the variables of it's parent process in a different place in memory. The copy and the original are both isolated from each other, so when either the parent or child process change a variable's value they do so of the value in _their_ memory space, so the variable of the other process isn't changed at all.  
This leaves the processes in mutual isolation, but see, thats where semaphores come in.
### A bit on semaphores
As opposed to mutexes, named semaphores are a system thing instead of a process thing (talking in technical terms if we must), so they aren't store in any of the memory spaces of the processes. What this means to us here, is that _all_ processes can use the same semaphore, which comes in the handiest.  
Another thing to note is that, while mutexes are strictly binary locks (either allowing or blocking entrance to a piece of code), semaphores are given a number that represents how many times a piece of code can be accessed. This can result in a semaphore being used as a binary operator or as a kind of security guard that only allows X people in.  
In-project, this means a single semaphore can represent how many forks are currently free to be taken, so that if a philosopher is holding one but needs another and there aren't any avavailable, it must wait until another philo drops their's.
### The bonus main
The handling of the input is exactly the same as in the mandatory part.  
Since there is no need for a fork array, the philinit function if called directly. This instance of the function begins by unlinking the semaphores names, destroying them as to create them anew in case they existed due to another process or a previous instance of the philo\_bonus. It then creates the two semaphores we'll be using: a binary one for the console and a counting one of count nop to act as the forks.  
It then allocates space for the philosophers and initializes their variables to a default. After that, the start time of the program is stored and a loop forks the child processes. If the forking fails at some point, the parent process ends, leaving zombie child processes behind. Again: _don't do that_.  
On a successful philinit, the parent process enters a loop in which it waits for _any_ of it's child processes to end, then checks their exit status and either kills all other child processes (if the exit status means the philosopher has died) or returns to the loop to wait for the next one (if the philosopher has eaten enough times).
### The processes
As soon as the parent process is forked, a child process is created. The thing is, as stated before, this child process creates a copy of all variables in the parent process in a different memory space, the return of the fork function, however, is stored _after_ cloning the variables. Now fork returns the process id of the child to the parent process _and 0_ to the child. This allows us to write code that checks with process is running it and doing stuff based on that.  
In practice this means that as soon as a child is created, it is sent to the sophicroutine function, while the parent stays on the forking loop.
### Sophicroutine
The philosophers can't check if they are still breathing while they sleep now can they? In the mandatory part we had a master thread that looped through the philo array checking that, but there is no master thread in the bonus, so each process has _it's very own_ overseer thread to do the checking.  
Creating said thread is the first thing the child processes do.  
After that, they enter an infinite loop that takes the philosophers through their routine. This loop is very similar to the one in the mandatory part, with the exception of using semaphores instead of mutexes and without the redundant ifs that check if a mate has died.
### Overseer
The thread upgrades the void pointer to the current philosopher, then stores the pinter to the main struct and then enters a loop that, as long as the current philosopher is alive, checks whether it hasn't eaten for too long or it has eaten enough times. The difference here is that in the mandatory part the threads could eat more than notepme times. In the bonus as soon as a philo has eaten that amount, the process exits.  
The only thing to note here is that, on death, the solog function (same as the consolelog but for the bonus) is blocked, since the semaphore isn't posted if the death flag is true. This results in no message being printed after the death message. On notepme exit, on the other hand, the semaphore isn't blocked despite the death flag becoming true, since no message is printed after setting it, and the flags aren't shared among processes. On notepme exit, how ever, both forks are posted before exiting so that a process doesn't block them forever when it ends. This works because the tte is much much longer than the time it takes for the thread to post the semaphores. A huge amount of processes could result in the thread posting the forks _after_ they've been posted by the process, leaving surplus forks and ruining the project. But that kind of overload handling isn't something I consider important for a project of this scope.

---

As you can see, the bonus requires less code and comes out cleaner. Forking processes, however, takes longer than creating threads, and so, many times an initial delay can be noticed in the first timestamp, that comes out as 1ms instead of 0ms. I don't think this is a code issue, nor has it ever translated to incorrect functioning, at least on my watch.

Anyways, both the mandatory and bonus parts showed great precission during evaluation, being able to work to the millisecond without diying.  
I hope you found this half-a-novel of a README useful. You can contact me if you find any issues in the code or come up with a better way of doing something. I'm also open to discussing anything really, don't be afraid to hit me up!

Regards, ~Ari.
