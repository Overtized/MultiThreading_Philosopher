# *This project has been created as part of the 42 curriculum by mchanlia*

# **Program Name** : ['MultiThreading_Philosopher']

### **Short Description** : 
> This project introduces the fundamentals of multithreading, process synchronization, and concurrency in C by solving the classic Dining Philosophers problem using POSIX threads and mutexes.  

### **Table of Content**:

|  ---  |                Section                 |         ---         |
| :---: | :------------------------------------: | :-----------------: |
|  1.   |      [Description](#description)       | :large_blue_circle: |
|  1.1  |     [Program Name](#program-name)     |   :yellow_circle:   |
|  1.2  |  [Project Summary](#project-summary-)  |   :yellow_circle:   |
|  1.3  | [Project Features](#project-features-) |   :yellow_circle:   |
|  2.   |     [Instructions](#instructions)      | :large_blue_circle: |
|  2.1  |     [Installation](#installation-)     |   :yellow_circle:   |
|  2.2  |            [Usage](#usage-)            |   :yellow_circle:   |
|  3.   |        [Resources](#resources)         | :large_blue_circle: |
  

# Description

## **Program Name**:
### MultiThreading_Philosopher

Introduction :

Philosophers is a project that dives into the complex world of concurrent programming. It is built around Edsger Dijkstra's famous "Dining Philosophers Problem," formulated in 1965 to illustrate synchronization issues and techniques for resolving them in concurrent algorithm design.

In a multithreaded environment, multiple sequences of instructions (threads) execute simultaneously within the same process, sharing the same memory space. This shared memory is a double-edged sword: it allows for fast communication between threads but introduces the risk of data races and deadlocks if two threads try to modify the same resource at the exact same time. To prevent this, we use mutexes (Mutual Exclusions) as locks to protect shared data.

You will interact with fundamental concurrent programming concepts such as:

- POSIX Threads (pthread)
- Mutexes
- Data Races
- Readlocks
- Context  
  
Apart from mastering the pthread library, a massive part of this project involves optimizing time complexity. The program requires extreme precision using gettimeofday and custom usleep implementations to ensure philosophers don't inadvertently die due to CPU scheduling delays or inefficient looping.

- The aim of the project is to go over:

[How to build a stable multithreaded application natively in C:]
- Thread creation, joining, and detachment using the POSIX thread library.
- Protecting shared memory resources (like forks and output logs) using mutexes.
- Designing algorithms to prevent deadlocks (where everyone is waiting on a lock and the program freezes) and starvation.
- Precise time management and microsecond-level delay calculations.

This project emphasizes the understanding of:
- Parallel execution and the underlying architecture of multi-core processors.
- Identifying, debugging, and preventing race conditions in complex memory environments.

### **Project Summary** :
The program simulates a round table where $N$ philosophers sit, with $N$ forks placed between them. Each philosopher is a separate thread, and each fork is protected by a mutex lock. A philosopher must acquire two forks (the one on their left and right) to eat. The simulation meticulously logs every state change (taking a fork, eating, sleeping, thinking, or dying) with strict chronological timestamps. The goal is to design an algorithm that allows them to survive as long as possible without starving or deadlocking the simulation.  


### **Project Features** :

- Full multithreaded architecture where every philosopher operates independently.
- Mutex-based resource management to handle shared forks safely.
- Microsecond-precision timestamping and custom delay handling.
- Anti-deadlock logic (e.g., odd/even staggering or strict order of lock acquisition).
- Complete prevention of data races, verifiable via valgrind --tool=helgrind or -fsanitize=thread.
  

# Instructions

### **Installation** :
> ```  
> git clone <repo_url>  
> cd MultiThreading_Philosopher/philo  
> make  
> ```

### **Usage** :
> ```  
> Launch the simulation with the following arguments:
> ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
> Example 1: 5 philosophers who shouldn't die (perfect loop)
> ./philo 5 800 200 200
> Example 2: 4 philosophers, where they will inevitably die due to tight constraints
> ./philo 4 310 200 100
> Example 3: Stop the simulation after each has eaten 7 times
> ./philo 5 800 200 200 7
>```
# Resources

#### Docs

[Website : The dining philosopher problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)  
[Website : Pthread](https://www.geeksforgeeks.org/c/thread-functions-in-c-c/)  
[Website : Mutexes](https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/)  
[Website : Mutexes vs Semaphore](https://www.geeksforgeeks.org/operating-systems/mutex-vs-semaphore/)  
