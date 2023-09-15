## Pipex
The aim of this project is to replicate [Unix's pipes](https://en.wikipedia.org/wiki/Pipeline_(Unix)) as a way to learn about processes and execution and get a better understanding of file descriptors.

### Mandatory part
This one is as simple as it gets. The goal is creating a program that when launched like this:
```bash
./pipex infile cmd1 cmd2 outfile
```
Works exactly like this does:
```bash
< infile cmd1 | cmd2 > outfile
```

There's some things to take into account here:
- The program must be able to execute the same commands the shell does, so the PATH environment variable must be used to try and find the binaries of the passed commands.
- The permissions of both files and commands passed must be checked and handled properly.
- Each command must be executed by a forked child process of the pipex program, so the `pipe` syscall must be used to ensure communication between processes.

### Bonus part
This one is a bit more convoluted. The mandatory part aims to replicate a _single_ pipe. Bit limited right?  
The bonus is much closer to a fully fledged pipeline. So the program, when launched like this:
```bash
./pipex infile cmd1 cmd2 ... cmdN outfile
```
Works exacly like this does:
```bash
< infile cmd1 | cmd2 | ... | cmdN > outfile
```

But that ain't all folks! The bonus comes with two more redirections. Forget about puny input files, you can now create the input on the fly with the `<<` redirection, say hello to [heredocs](https://en.wikipedia.org/wiki/Here_document)! Also, what's that? Tired of having your output files truncated? Well tire no more for the `>>` redirection is here. This bad boy can append so many characters to the end of the provided outfile it should be illegal. But it isn't, it is very legal.
