# CPU Scheduler Simulator

A simple C program that simulates common CPU scheduling algorithms used in operating systems.  
This project demonstrates how different scheduling strategies affect process waiting time and turnaround time.

## Features
- **First-Come, First-Served (FCFS)**
- **Shortest Job First (SJF)**
- **Priority Scheduling**
- **Round Robin (RR)** with configurable time quantum

## How It Works
The program:
1. Accepts the number of processes.
2. Takes input for each process:
   - Burst time  
   - Priority  
3. Prompts the user to choose a scheduling algorithm.
4. Displays a results table with:
   - Process ID  
   - Burst Time  
   - Priority  
   - Waiting Time  
   - Turnaround Time  

## Example Usage

```bash
$ gcc procman.c -o procman
$ ./procman
Enter number of processes: 3
Enter burst time of P1: 5
Enter priority of P1: 2
Enter burst time of P2: 3
Enter priority of P2: 1
Enter burst time of P3: 8
Enter priority of P3: 3

Choose Scheduling Algorithm:
1. FCFS
2. SJF
3. Priority
4. Round Robin
2
