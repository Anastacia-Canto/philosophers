# philosophers

<img src="https://img.shields.io/badge/Architecture-Multithreading-2ceee6"> <img src="https://img.shields.io/badge/Data race-Mutexes-2ceee6">

This is a project to learn how to deal with parallelism, multithreads, sharing data, executing a unique code 
in synchronicity without interference between each other. 

The context is like the [Dining Philosopher Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem):

- One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
- There are also as many forks as philosophers on the table.
- Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right 
and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, 
they start thinking again. The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don't speak with each other.
- Philosophers don't know if another philosopher is about to die. 
- No need to say that philosophers should avoid dying!

Usage:

After make, the program needs the following parameters:

- number of philosophers
- time to die: If a philosopher didn't start eating time_to_die milliseconds since the beginning of their last meal 
or the beginning of the simulation, they die.
- time to eat: The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- time to sleep
- number of times each philosophers must eat (optional argument): If all philosophers have eaten at least this number times, 
the simulation stops. If not specified, the simulation stops when a philosopher dies.

```

./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] <number_of_times_each_philosopher_must_eat>

```
 
 
Some useful links to learn about threads:
- [Unix Threads in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [Linux Tutorial: POSIX Threads](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
