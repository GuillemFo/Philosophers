# Philosophers — I Never Thought Philosophy Would Be So Deadly

## 🎯 Project Overview

**Philosophers** is a concurrency project that introduces the concepts of **threads, mutexes, and synchronization** through the classic **Dining Philosophers Problem**.

The goal of the project is to simulate philosophers sitting around a table while sharing limited resources (forks). Each philosopher alternates between **thinking**, **eating**, and **sleeping**, while the program must prevent **race conditions**, **deadlocks**, and **starvation**.

Through this project, you gain practical experience with:

* **multithreading**
* **mutex synchronization**
* **resource sharing**
* **concurrency control**

---

## 🍝 The Dining Philosophers Problem

### Scenario

* Several philosophers sit around a **round table**
* A bowl of **spaghetti** is placed in the center
* There is **one fork between each pair of philosophers**
* Philosophers alternate between:

  * **thinking**
  * **eating**
  * **sleeping**

To **eat**, a philosopher must pick up **two forks**:

* the fork on their **left**
* the fork on their **right**

If a philosopher does not eat within a certain time limit, they **die of starvation**, and the simulation stops.

---

## 🧠 Philosopher States

| State        | Description                                          |
| ------------ | ---------------------------------------------------- |
| **Eating**   | The philosopher holds two forks and eats             |
| **Sleeping** | The philosopher rests after eating                   |
| **Thinking** | The philosopher waits before attempting to eat again |

---

## ⚙️ Program Specifications

### Arguments

| Argument                  | Description                                                       |
| ------------------------- | ----------------------------------------------------------------- |
| `number_of_philosophers`  | Number of philosophers and forks                                  |
| `time_to_die`             | Time (ms) before a philosopher dies without eating                |
| `time_to_eat`             | Time (ms) spent eating                                            |
| `time_to_sleep`           | Time (ms) spent sleeping                                          |
| `[must_eat]` *(optional)* | Simulation stops when all philosophers have eaten this many times |

---

### Logging Format

The program must print the following events:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Where:

* `timestamp_in_ms` → time since the start of the simulation
* `X` → philosopher ID

Messages must **not overlap or mix between threads**.

---

## 🔧 Mandatory Part

### Technical Requirements

| Component             | Specification       |
| --------------------- | ------------------- |
| **Program Name**      | `philo`             |
| **Directory**         | `philo/`            |
| **Language**          | C                   |
| **Concurrency Model** | Threads (`pthread`) |
| **Synchronization**   | Mutexes             |
| **Global Variables**  | Forbidden           |

---

### Implementation Details

* Each **philosopher is implemented as a thread**
* Each **fork is protected by a mutex**
* Philosophers must **lock forks before eating**
* Forks must be **released after eating**
* The program must avoid:

  * **data races**
  * **deadlocks**
  * **starvation**

A monitoring mechanism must detect if a philosopher dies and stop the simulation.

Death detection must occur **within 10 ms** of the actual time of death.

---

## 🔧 Allowed Functions

Thread management:

* `pthread_create`
* `pthread_join`
* `pthread_detach`

Mutex operations:

* `pthread_mutex_init`
* `pthread_mutex_destroy`
* `pthread_mutex_lock`
* `pthread_mutex_unlock`

Utilities:

* `gettimeofday`
* `usleep`
* `printf`
* `malloc`
* `free`

---

## 🎯 Learning Objectives

This project focuses on fundamental concepts in **concurrent programming**:

* **Thread creation and management**
* **Mutex-based synchronization**
* **Deadlock prevention**
* **Race condition avoidance**
* **Precise time management**
* **Resource allocation strategies**

---

## ⚠️ Critical Constraints

* **No global variables**
* **No data races**
* **No memory leaks**
* **Output messages must not overlap**
* **Strict compliance with the 42 Norm**
* **Death must be detected within 10 ms**

---

## 📚 Additional Notes

This project is part of the **42 School curriculum** and aims to introduce students to real-world problems in **multithreaded programming and synchronization**.
