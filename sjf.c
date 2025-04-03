//sjf

#include <stdio.h>
#include <limits.h>

struct Process {
    int id, at, bt, ct, tat, wt, completed;
};

void calculateTimes(struct Process p[], int n) {
	
    int time = 0, completedProcesses = 0;

    while (completedProcesses < n) {
        int min_bt = INT_MAX, index = -1;

       
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0 && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                index = i;
            }
        }

        if (index == -1) {
            
            time++;
        } else {
            
            time += p[index].bt;
            p[index].ct = time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].completed = 1; 
            completedProcesses++;
        }
    }
}

void display(struct Process p[], int n) {
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d (AT BT): ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].completed = 0;  
    }

    calculateTimes(p, n);
    display(p, n);

    return 0;
}
