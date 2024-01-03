# 42_Philosophers
I never thought philosophy would be so deadly! Project to learn the basics of threading a process: create threads and discover mutexes.

### Description
It is classic task about [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).
To do this task, you need know some rules:
- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
- While they are eating, they are not thinking nor sleeping;
- while thinking, they are not eating nor sleeping;
- while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!

### Usage
Program takes the following arguments:
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

- Each philosopher has a number ranging from 1 to number_of_philosophers.
- Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

About the logs of your program:
• Any state change of a philosopher must be formatted as follows:
```
- timestamp_in_ms X has taken a fork
- timestamp_in_ms X is eating
- timestamp_in_ms X is sleeping
- timestamp_in_ms X is thinking
- timestamp_in_ms X died
```
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.

### Specific rules
## Mandatory path:
- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.

### Step 1: Checking input
### Step 2: Creating structures
### Step 3: Initialize and allocate
### Step 4: philo's routine, supervisor and monitor
### Step 5: Clean memory

## CREATE THREADS
We can create a new thread from any thread in the program using the pthread_create function. 
Prototype pthread_create:

```
int pthread_create(pthread_t *restrict thread,
                    const pthread_attr_t *restrict attr,
                    void *(*start_routine)(void *),
                    void *restrict arg);
```

Arguments are:

- thread: A pointer to a variable of type pthread_t to store the id of the thread to be created.
- attr: An argument that allows changing the default attributes of the new thread during its creation. This goes beyond the scope of this project, so we will indicate NULL here.
- start_routine: The function by which the thread begins its execution. This function must have the prototype void 
```
*function_name_of_choice(void *arg);
```
When the thread reaches the end of this function, it will have completed all its tasks.
- arg: The pointer to an argument to be passed to the start_routine function of the thread. To pass multiple parameters to this function, you will need to provide a pointer to a structure here.

When the pthread_create function completes, the thread variable provided to it will contain the id of the created thread. The function returns 0 if the creation was successful or another value if there was an error.

## JOIN THREADS

To retrieve a thread, to block the execution of a thread while waiting for another thread to finish, you can use the pthread_join function:

```
int pthread_join(pthread_t thread, void **retval);
```

Parameters:

- thread: The id of the thread being waited for. The thread specified here must be joinable (i.e., not detached).
- retval: A pointer to a variable that can contain the return value of the thread's routine function (the start_routine function provided during the thread creation). We don't need this value, so we simply specify NULL.

The pthread_join function returns 0 on success or another integer to represent an error code.

It is noteworthy that one can only wait for the end of a specific thread. There is no way to wait for the first thread to finish without dealing with its identifier, as the wait function of a child process does.

In this project, we want to ensure that the main thread of our program waits for each philosopher thread to finish its execution. This way, we can free up memory and safely terminate the program.
