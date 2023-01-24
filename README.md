# Cursus42
#### My approaches to the projects of 42's Common Core.

This repository contains:
- All of my code for the different projects from 42. Of which I'm currently trying to write documentation so people ~and I myself~ can understand what I've done and why I've done it as I have. Currently documented (with astounding verbose):
  - Push_swap.
  - Philosophers.
- A Makefile template that I personally find pretty **_a e s t h e t i c_**.

Brief description of my implementations:
- [libft](https://github.com/IcaroJam/Cursus42/tree/master/libft): The essential cursus library, with a focus on safety and some extra functions that do stuff like return the absolute value, return the power of an int, return whether a string will overflow an int if passed to atoi and free a pointer and point it to NULL.
- [get_next_line](https://github.com/IcaroJam/Cursus42/tree/master/get_next_line): Memory safe and code clean. Very modular, with variables with weird names :)
- [printf](https://github.com/IcaroJam/Cursus42/tree/master/printf): Memory safe implementation with the bonuses that buffers the output because I seem to like pain. Unorganized and confusing as hell, but working marvelously.
- [buffLessPrintf](https://github.com/IcaroJam/Cursus42/tree/master/buffLessPrintf%20%5BDead%20till%20further%20notice%5D): An unfinished version that wouldn't have buffered the output. I began this out of sheer frustration, but since the other version turned out nicely I'll probably never finish this.
- [so_long](https://github.com/IcaroJam/Cursus42/tree/master/so_long): [100% Denominación de Origen](https://en.wikipedia.org/wiki/Denominaci%C3%B3n_de_origen) project using the old and leaky mlxlib, with a desert theme and all bonuses. ~~It mostly works fine but does some weird stuff if lots of enemies overlap.~~ Works perfectly. My sweet child :_)
- [pipex](https://github.com/IcaroJam/Cursus42/tree/master/pipex): Perfecly working, memory safe and bonusful. Won't work without an enviroment variable though.
- [push_swap](https://github.com/IcaroJam/Cursus42/tree/master/push_swap): Memory safe implementation of a modified median-focused quicksort using arrays that sorts in groups of five. It got really really close to being 5-point worthy, but it ultimately wasn't.
- [philosophers](https://github.com/IcaroJam/Cursus42/tree/master/philo): Reasonably clean implementation with a prettier bonus part than mandatory part. The precision it has in both bonus and mandatory is remarkable, being able to work to the milisecond in the campus' macs.
- [minishell](https://github.com/IcaroJam/Cursus42/tree/master/minishell): Mi personal (s)hell, done together with [phijano](https://github.com/phijano). I was in charge of coding the builtins and the parser. The executor and signal handling are courtesy of my partner. There are a couple of things that could be improved, like flag-handling and ctl-D in blocking processes, but overall I think it turned out pretty nice.  
DISCLAIMER: The PATH is currently hardcoded for the commands that aren't builtin. We should probably look into that and fix it...
