# Philosophers - I never thought philosophy would be so deadly

## 🎯 Project Overview

**Philosophers** is a project that introduces you to threading, mutexes, and synchronization problems through the classic **Dining Philosophers Problem**. You'll learn how to manage concurrent processes and prevent race conditions and deadlocks.

> **Summary:** In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

## 🍝 The Dining Philosophers Problem

### Scenario
- One or more philosophers sit at a round table with a large bowl of spaghetti
- There are as many forks as philosophers
- Philosophers alternate between **eating**, **thinking**, and **sleeping**
- To eat, a philosopher needs **both right and left forks**
- The simulation stops when a philosopher dies of starvation

### Philosopher States
- **Eating**: Holding two forks, not thinking or sleeping
- **Thinking**: Not eating or sleeping  
- **Sleeping**: Not eating or thinking

## ⚙️ Program Specifications

### Arguments
| Argument | Description |
|----------|-------------|
| `number_of_philosophers` | Number of philosophers and forks |
| `time_to_die` (ms) | Time until philosopher dies if not eating |
| `time_to_eat` (ms) | Time taken to eat (holding two forks) |
| `time_to_sleep` (ms) | Time spent sleeping |
| `[must_eat]` (optional) | If specified, simulation stops when all philosophers eat this many times |

### Logging Format
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping` 
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

## 🔧 Mandatory Part

### Technical Requirements
| Component | Specification |
|-----------|---------------|
| **Program Name** | `philo` |
| **Directory** | `philo/` |
| **Language** | C |
| **Synchronization** | Threads + Mutexes |
| **Global Variables** | **Forbidden** |

### Implementation Details
- **Each philosopher is a thread**
- **One fork between each pair** of philosophers
- **Mutex protection** for each fork
- **No data races** allowed
- **Death detection** within 10ms of actual death

### Allowed Functions
- `pthread_create`, `pthread_detach`, `pthread_join`
- `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- `gettimeofday`, `usleep`, `printf`, `malloc`, `free`



## 🎯 Learning Objectives

- **Thread Management**: Creation, detachment, joining
- **Mutex Synchronization**: Locking, unlocking, deadlock prevention  
- **Process Management**: Forking, signaling, waiting
- **Semaphore Usage**: Binary and counting semaphores
- **Time Management**: Precise timing and sleeping
- **Race Condition Prevention**: Data protection strategies
- **Resource Allocation**: Fork management and scheduling

## ⚠️ Critical Constraints

- **No global variables** allowed
- **No data races** tolerated
- **No memory leaks** permitted
- **Strict norm compliance** required
- **Death messages** within 10ms accuracy
- **No message mixing** in output


