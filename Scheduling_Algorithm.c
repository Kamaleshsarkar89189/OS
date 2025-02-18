#include <stdio.h>

int main() 
{ 
    int bt[20], wt[20], tat[20], i, n; 
    float wtavg, tatavg; 

    printf("Enter the number of processes: "); 
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for(i = 0; i < n; i++) 
    { 
        printf("Enter Burst Time for Process %d: ", i); 
        if (scanf("%d", &bt[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    } 

    wt[0] = wtavg = 0; 
    tat[0] = tatavg = bt[0]; 

    for(i = 1; i < n; i++) 
    { 
        wt[i] = wt[i-1] + bt[i-1]; 
        tat[i] = tat[i-1] + bt[i]; 
        wtavg += wt[i]; 
        tatavg += tat[i]; 
    } 

    printf("\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n"); 
    for(i = 0; i < n; i++) 
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]); 

    printf("Average Waiting Time: %f\n", wtavg/n); 
    printf("Average Turnaround Time: %f\n", tatavg/n); 

    return 0;
}