# 42 Philosophers
#### A project to learn about thread syncronization using mutexes (and process syncronization using semaphores in the bonus)

My approach to projects can be a bit chaotic sometimes, so let's start by taking a look at the header file shall we?
The header used in the mandatory part is the same one the shared functions use in the bonus part, that's why it is stored in the main directory. Just for clarification.

![Header image here]()

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
