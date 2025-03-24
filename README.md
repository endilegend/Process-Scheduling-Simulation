# 🖥️ Process Scheduling Simulation in C

This project simulates **priority-based process scheduling** in an operating system using C. It utilizes `structs` to represent processes and simulates the execution timeline with a dispatcher and dynamic priority updates.

---

## 📌 Features

- **Priority Scheduling:**  
  Processes with the highest priority (lowest priority number) are selected first. Ties are broken by input order.

- **Struct-Based Design:**  
  Each process is stored as a `struct` with details such as PID, name, priority, and runtime.

- **Dispatcher Simulation:**  
  A special non-preemptive dispatcher process runs for 4 clock cycles between each process execution.

- **Dynamic Priority Adjustment:**  
  After every process execution (or completion), the priority of all remaining processes increases by 1.

---

## 🔧 Specifications

### 🧱 Process Struct

Each process is represented using the following structure:

```c
typedef struct {
    int pid;               // Unique Process ID (1000–4000)
    char processName[30];  // Process Name
    int priority;          // 0 (highest) to 10 (lowest)
    int runTime;           // Total time required
    int elapsedTime;       // Time already executed
} Process;
```

### ⚙️ Dispatcher Process

- **Fixed PID:** `6787`  
- **Priority:** Always `0`  
- **Behavior:** Runs for `4` clock cycles and **cannot be preempted**

---

## 🕹️ Process Execution Logic

- Each process runs for **5 clock cycles** per turn.
- After each time slice (or if the process finishes), the dispatcher runs for 4 cycles.
- On each context switch or process completion:
  - All remaining processes have their **priority increased by 1** (up to max value of 10).
- The scheduler picks the **next process with the highest priority** (lowest value).

---

## 🧑‍💻 Input Format

The program accepts user input in the format:

```
PROCESSNAME PRIORITY RUNTIME
```

- Example:
  ```
  Enter the process details: CHROME 2 10
  Enter the process details: XORG 0 20
  Enter the process details: QMGRT 10 8
  Enter the process details: GVFASD 3 1
  Enter the process details: SSH 9 3
  Enter the process details: Q
  ```

- Input continues until the user enters `Q` to quit.

---

## 📂 Implementation Details

- Processes are stored using an array of `Process` structs (or another suitable data structure).
- The simulation includes:
  - Function for adding and validating processes.
  - A dispatcher function to simulate its 4-clock-cycle behavior.
  - Scheduler and execution loop for selecting, running, and updating processes.
- Code includes clear **comments** and **header files** for readability and modularity.

---

## 🚀 Compilation & Running

To compile the program:

```bash
gcc -o scheduler scheduler.c
```

To run the program:

```bash
./scheduler
```

---

## ✅ Example Output (Simplified)

```
Running process: XORG [PID: 1034, Priority: 0]
... (5 clock cycles)
Dispatcher running [PID: 6787]
... (4 clock cycles)
Running process: CHROME [PID: 2456, Priority: 3]
...
```

---

## 📄 License

This project is open-source and free to use under the MIT License.

---

## ✍️ Author

Developed with ❤️ in C by Endi Troqe
