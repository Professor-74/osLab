#include <stdio.h>

struct process { 
    int at, bt, ct, tat, wt; 
};

void roundRobin(struct process p[], int n, int quantum) {
    int time = 0, completedProcess = 0;
    int rem_bt[n];

    for (int i = 0; i < n; i++) {
        rem_bt[i] = p[i].bt;
    }

    while (completedProcess < n) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    p[i].ct = time;
                    completedProcess++;
                }
            }
        }

        if (done) {
          time++;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
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

    roundRobin(p, n, 2);

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
