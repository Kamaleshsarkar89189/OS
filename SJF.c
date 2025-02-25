#include <stdio.h>

void sortProcesses(int bt[], int p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n, bt[20], wt[20], tat[20], p[20];
    float wtavg, tatavg;

    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d: ", i);
        if (scanf("%d", &bt[i]) != 1 || bt[i] < 0) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    sortProcesses(bt, p, n);

    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = tat[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", wtavg / n);
    printf("Average Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
