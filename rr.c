#include <stdio.h>

struct process {
    int at, bt, ct, tat, wt;
};

// For Gantt Chart
struct gantt {
    int pid;
    int start;
    int end;
};

void roundRobin(struct process p[], int n, int quantum) {
    int time = 0, completedProcess = 0;
    int rem_bt[n];
    struct gantt gc[100];  // assuming max 100 time slices
    int gc_index = 0;

    for (int i = 0; i < n; i++) {
        rem_bt[i] = p[i].bt;
    }

    while (completedProcess < n) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && p[i].at <= time) {
                done = 0;

                gc[gc_index].pid = i;
                gc[gc_index].start = time;

                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    p[i].ct = time;
                    completedProcess++;
                }

                gc[gc_index].end = time;
                gc_index++;
            }
        }

        // If no process was ready, move time forward
        if (done) {
            time++;
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Display Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gc_index; i++) {
        printf("| P%d ", gc[i].pid);
    }
    printf("|\n");

    // Print time scale
    printf("0");
    for (int i = 0; i < gc_index; i++) {
        printf("   %d", gc[i].end);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes:\t");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter the AT and BT of process p%d:\t", i);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    int quantum;
    printf("\nEnter Time Quantum:\t");
    scanf("%d", &quantum);

    roundRobin(p, n, quantum);

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}

