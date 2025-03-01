#Process Scheduling Simulation
Overview

This program emulates the process scheduling mechanism in an operating system using structs in C. It takes a list of processes as input, simulating their execution based on priority scheduling. The program outputs an interleaved trace of the processes and the dispatcher.

Features

Priority Scheduling: The process with the highest priority (lowest priority value) is selected first. If multiple processes have the same priority, the first one is chosen.

Struct-Based Design: The program utilizes a Process struct to store and manage process details.

Dispatcher Simulation: A dedicated dispatcher process runs periodically and cannot be preempted.

Dynamic Priority Adjustment: After a process completes its execution cycle, the priority of all remaining processes increases by 1.

Specifications

Process Struct: Each process is represented by the following attributes:

pid (Process ID): A unique random number between 1000 - 4000.

processName: A string (char array) with a maximum length of 30.

priority: An integer (0 - Highest priority, 10 - Lowest priority).

runTime: The total execution time required for completion.

elapsedTime (or remainingTime): Tracks the progress of the process.

Dispatcher:

Runs for 4 clock cycles.

Has a fixed pid of 6787 and a priority of 0.

Cannot be preempted.

Process Execution:

Each process runs for 5 clock cycles before switching.

Upon completion or context switch, all remaining processes have their priority increased by 1.

Input Format

The program accepts process details from the command line, entered one at a time in the format:

PROCESSNAME PRIORITY RUNTIME

The process list continues until the user enters 'Q' to quit.

Example Input

Enter the process details: CHROME 2 10
Enter the process details: XORG 0 20
Enter the process details: QMGRT 10 8
Enter the process details: GVFASD 3 1
Enter the process details: SSH 9 3
Enter the process details: Q

Implementation Details

Each process input is stored as a struct object.

All processes are managed in an array of structs or another suitable data structure.

The dispatcher and process execution logic are structured into separate functions.

Header files and comments are included for clarity.
