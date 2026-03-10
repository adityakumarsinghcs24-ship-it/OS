#include<stdio.h>
#include<limits.h>
struct Process {
    int pid, at, bt, ct, tat, wt, remaining_bt;
};
float fcfs(struct Process p[], int n) {
    int time = 0;
    float total_wt = 0, total_tat = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(time < p[i].at)
            time = p[i].at;
        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        time = p[i].ct;
    }
    printf("\n FCFS \n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    printf("Average WT = %.2f\n", total_wt/n);
    printf("Average TAT = %.2f\n", total_tat/n);
    return total_wt/n;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process original[n];
    for(int i = 0; i < n; i++) {
        original[i].pid = i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &original[i].at, &original[i].bt);
    }
    struct Process p1[n], p2[n], p3[n];
    for(int i = 0; i < n; i++) {
        p1[i] = original[i];
        p2[i] = original[i];
        p3[i] = original[i];
    }
    float fcfs_wt = fcfs(p1, n);


    return 0;
}
