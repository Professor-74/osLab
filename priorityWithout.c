#include <stdio.h>

struct process {
    int at, bt, priority, ct, tat, wt, completed;
};

void priority(struct process p[], int n) {
    int time = 0, completedProcess = 0;

    // Sorting based on arrival time
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {  
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

   
    for (int i = 0; i < n; i++) {
        p[i].completed = 0;
    }

    
    while (completedProcess < n) {
        int min_priority = 9999;
        int selected = -1;

        
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0) {
                if (p[i].priority < min_priority) {
                    min_priority = p[i].priority;
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            time++;  
        } else {
            time = time + p[selected].bt;
            p[selected].ct = time;
            p[selected].tat = p[selected].ct - p[selected].at;
            p[selected].wt = p[selected].tat - p[selected].bt;
            p[selected].completed = 1;
            completedProcess++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];


    for (int i = 0; i < n; i++) {
        printf("Process %d (AT BT Priority): ", i);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].priority);
    }

    priority(p, n);

   
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
