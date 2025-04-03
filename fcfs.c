//FCFS

#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt;
};

void fcfs(struct Process p[], int n) {
    int time = 0;
    
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at; // CPU remains idle if no process has arrived
        }
        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        time = p[i].ct;
    }
}

void printProcesses(struct Process p[], int n) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d AT BT: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    // Sorting processes by Arrival Time (FCFS rule)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    fcfs(p, n);
    printProcesses(p, n);

    return 0;
}
