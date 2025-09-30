#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    int pid, burst, priority;
    int waiting, turnaround, remaining;
} Process;

void fcfs(Process p[], int n) {
    p[0].waiting = 0;
    for (int i = 1; i < n; i++)
        p[i].waiting = p[i-1].waiting + p[i-1].burst;
    for (int i = 0; i < n; i++)
        p[i].turnaround = p[i].waiting + p[i].burst;
}

void sjf(Process p[], int n) {
    // sort by burst
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (p[j].burst < p[i].burst) {
                Process tmp = p[i]; p[i] = p[j]; p[j] = tmp;
            }
    fcfs(p, n);
}

void priority_sch(Process p[], int n) {
    // sort by priority (smaller = higher)
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (p[j].priority < p[i].priority) {
                Process tmp = p[i]; p[i] = p[j]; p[j] = tmp;
            }
    fcfs(p, n);
}

void round_robin(Process p[], int n, int quantum) {
    int time = 0, remain = n;
    for (int i = 0; i < n; i++) p[i].remaining = p[i].burst;

    while (remain > 0) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].waiting = time - p[i].burst;
                    p[i].turnaround = time;
                    p[i].remaining = 0;
                    remain--;
                }
            }
        }
    }
}

void print_table(Process p[], int n) {
    printf("\nPID\tBurst\tPrio\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].burst, p[i].priority,
               p[i].waiting, p[i].turnaround);
}

int main() {
    Process p[MAX];
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &p[i].burst);
        printf("Enter priority of P%d: ", i+1);
        scanf("%d", &p[i].priority);
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: fcfs(p, n); break;
        case 2: sjf(p, n); break;
        case 3: priority_sch(p, n); break;
        case 4: printf("Enter quantum: "); scanf("%d", &quantum);
                round_robin(p, n, quantum); break;
        default: printf("Invalid choice!\n"); return 0;
    }

    print_table(p, n);
    return 0;
}
