# 🖥️ Operating System Lab — C Programming Assignments

<div align="center">

![OS Lab](https://img.shields.io/badge/Course-Operating%20Systems-blue?style=for-the-badge&logo=linux&logoColor=white)
![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Linux%20%2F%20Unix-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*A complete collection of Operating System concepts implemented in C and C++*

</div>

---

## 📚 Table of Contents

| # | Topic | Concepts Covered |
|---|-------|-----------------|
| [Q1](#-question-1--fork--parent--child-process) | Fork — Parent & Child Process | `fork()`, PID, PPID |
| [Q2](#-question-2--parent--child-number-printing) | Parent & Child Number Printing | `fork()`, execution order |
| [Q3](#-question-3--two-child-processes) | Two Child Processes | Process tree, multiple `fork()` |
| [Q4](#-question-4--fcfs-scheduling) | FCFS Scheduling | Waiting Time, Turnaround Time |
| [Q5](#-question-5--sjf-non-preemptive) | SJF Non-Preemptive | Gantt Chart, WT, TAT |
| [Q6](#-question-6--sjf-preemptive-srtf) | SJF Preemptive (SRTF) | Completion, WT, TAT |
| [Q7](#-question-7--round-robin-scheduling) | Round Robin Scheduling | Time Quantum, Gantt Chart |
| [Q8](#-question-8--priority-scheduling) | Priority Scheduling | Preemptive / Non-Preemptive |
| [Q9](#-question-9--bankers-algorithm) | Banker's Algorithm | Deadlock Avoidance, Safe Sequence |
| [Q10](#-question-10--deadlock-detection) | Deadlock Detection | Allocation & Request Matrix |
| [Q11](#-question-11--fifo-page-replacement) | FIFO Page Replacement | Page Faults, Page Hits |
| [Q12](#-question-12--lru-page-replacement) | LRU Page Replacement | Frame Status, Page Faults |

---

## 🔧 Prerequisites & Setup

### Requirements
- **OS:** Linux / Unix (Ubuntu recommended)
- **Compiler:** GCC (GNU Compiler Collection)
- **Shell:** Bash

### Install GCC (if not installed)
```bash
sudo apt update
sudo apt install gcc
```

### Compile & Run Any Program
```bash
gcc filename.c -o output_name
./output_name
```

---

## 📂 Project Structure

```
OS-Lab/
│
├── Process/
│   ├── q1_fork_parent_child.c
│   ├── q2_parent_child_numbers.c
│   └── q3_two_child_processes.c
│
├── CPU-Scheduling/
│   ├── q4_fcfs.c
│   ├── q5_sjf_nonpreemptive.c
│   ├── q6_srtf_preemptive.c
│   ├── q7_round_robin.c
│   └── q8_priority_scheduling.c
│
├── Deadlock/
│   ├── q9_bankers_algorithm.c
│   └── q10_deadlock_detection.c
│
├── Memory-Management/
│   ├── q11_fifo_page_replacement.c
│   └── q12_lru_page_replacement.c
│
└── README.md
```

---

## 🔵 PROCESS MANAGEMENT

---

### 🔹 Question 1 — Fork: Parent & Child Process

**📌 Objective:** Create a child process using `fork()` and display PIDs.

**📤 Output:**
- Parent PID
- Child PID
- Parent Process ID (PPID) of the child

**▶️ Run:**
```bash
gcc 01.c.c -o q1
./q1
```

**💡 Key Concepts:** `fork()`, `getpid()`, `getppid()`

---

### 🔹 Question 2 — Parent & Child Number Printing

**📌 Objective:** Parent prints `1–5`, child prints `6–10`. Observe the execution order.

**📤 Output:**
- Parent: numbers 1 to 5
- Child: numbers 6 to 10
- Execution order may vary (non-deterministic)

**▶️ Run:**
```bash
gcc 02.c.c -o q2
./q2
```

**💡 Key Concepts:** `fork()`, process scheduling, concurrent execution

---

### 🔹 Question 3 — Two Child Processes

**📌 Objective:** Create two child processes from a single parent and display the process tree.

**📤 Output:**
```
Parent PID: XXXX
  ├── Child 1 PID: XXXX
  └── Child 2 PID: XXXX
```

**▶️ Run:**
```bash
gcc 03.c -o q3
./q3
```

**💡 Key Concepts:** Multiple `fork()` calls, process hierarchy

---

## 🟠 CPU SCHEDULING

---

### 🔹 Question 4 — FCFS Scheduling

**📌 Objective:** Implement **First Come First Serve** CPU Scheduling.

**📤 Calculates:**
- ✅ Waiting Time (WT)
- ✅ Turnaround Time (TAT)
- ✅ Average Waiting Time
- ✅ Average Turnaround Time

**▶️ Run:**
```bash
gcc 04_WithAT.cpp -o q4
./q4
```

**💡 Key Concepts:** Non-preemptive scheduling, arrival order processing

---

### 🔹 Question 5 — SJF Non-Preemptive

**📌 Objective:** Implement **Shortest Job First** (Non-Preemptive) scheduling.

**📤 Displays:**
- ✅ Gantt Chart
- ✅ Waiting Time
- ✅ Turnaround Time

**▶️ Run:**
```bash
gcc 05.cpp -o q5
./q5
```

**💡 Key Concepts:** Burst time sorting, starvation possibility

---

### 🔹 Question 6 — SJF Preemptive (SRTF)

**📌 Objective:** Implement **Shortest Remaining Time First** scheduling.

**📤 Calculates:**
- ✅ Completion Time
- ✅ Waiting Time
- ✅ Turnaround Time

**▶️ Run:**
```bash
gcc 06.cpp -o q6
./q6
```

**💡 Key Concepts:** Preemption, remaining burst time comparison

---

### 🔹 Question 7 — Round Robin Scheduling

**📌 Objective:** Implement **Round Robin** scheduling with a user-defined time quantum.

**📤 Displays:**
- ✅ Gantt Chart
- ✅ Waiting Time
- ✅ Turnaround Time

**▶️ Run:**
```bash
gcc 07.cpp -o q7
./q7
```

**💡 Key Concepts:** Time quantum, circular queue, preemption

---

### 🔹 Question 8 — Priority Scheduling

**📌 Objective:** Implement **Priority Scheduling** (Non-Preemptive or Preemptive).

**📤 Calculates:**
- ✅ Completion Time
- ✅ Waiting Time
- ✅ Turnaround Time

**▶️ Run:**
```bash
gcc 08.cpp -o q8
./q8
```

**💡 Key Concepts:** Priority assignment, starvation, aging technique

---

## 🔴 DEADLOCK

---

### 🔹 Question 9 — Banker's Algorithm

**📌 Objective:** Implement the **Banker's Algorithm** for deadlock avoidance.

**📥 Input:**
- Allocation Matrix
- Maximum Matrix
- Available Resources

**📤 Output:**
- ✅ Safe / Unsafe state detection
- ✅ Safe Sequence (if exists)

**▶️ Run:**
```bash
gcc 09_Dead_Lock_Avoidence.cpp -o q9
./q9
```

**💡 Key Concepts:** Need matrix = Maximum − Allocation, resource-request algorithm

---

### 🔹 Question 10 — Deadlock Detection

**📌 Objective:** Detect **deadlock** in a system.

**📥 Input:**
- Allocation Matrix
- Request Matrix
- Available Resources

**📤 Output:**
- ✅ Deadlock detected / not detected
- ✅ Deadlocked processes (if any)

**▶️ Run:**
```bash
gcc q10_deadlock_detection.cpp -o q10
./q10
```

**💡 Key Concepts:** Resource allocation graph, cycle detection

---

## 🟣 MEMORY MANAGEMENT

---

### 🔹 Question 11 — FIFO Page Replacement

**📌 Objective:** Implement **First-In First-Out** page replacement algorithm.

**📥 Input:**
- Page reference string
- Number of frames

**📤 Output:**
- ✅ Frame state after each page
- ✅ Total Page Faults
- ✅ Total Page Hits

**▶️ Run:**
```bash
gcc 11.cpp -o q11
./q11
```

**💡 Key Concepts:** Queue-based replacement, Belady's anomaly

---

### 🔹 Question 12 — LRU Page Replacement

**📌 Objective:** Implement **Least Recently Used** page replacement algorithm.

**📤 Displays:**
- ✅ Frame status after each page reference
- ✅ Total Page Faults

**▶️ Run:**
```bash
gcc 12.cpp -o q12
./q12
```

**💡 Key Concepts:** Recency tracking, stack/counter-based implementation

---

## 📊 Algorithm Summary Table

| Algorithm | Type | Preemptive | Starvation | Overhead |
|-----------|------|-----------|-----------|----------|
| FCFS | Scheduling | ❌ | ❌ | Low |
| SJF | Scheduling | ❌ | ✅ | Medium |
| SRTF | Scheduling | ✅ | ✅ | High |
| Round Robin | Scheduling | ✅ | ❌ | Medium |
| Priority | Scheduling | Both | ✅ | Medium |
| Banker's | Deadlock Avoidance | — | — | High |
| FIFO | Page Replacement | — | — | Low |
| LRU | Page Replacement | — | — | Medium |

---

## 👨‍💻 Author

<div align="center">

**Your Name : Nuralam Shikder**
*Dept : Computer Science & Engineering*

[![GitHub](https://img.shields.io/badge/GitHub-Follow-181717?style=for-the-badge&logo=github)](https://github.com/nur127)

</div>

---

## 📄 License

This project is for **educational purposes** only as part of the Operating Systems Lab coursework.

---

<div align="center">

⭐ *If this helped you, give the repo a star!* ⭐

</div>
