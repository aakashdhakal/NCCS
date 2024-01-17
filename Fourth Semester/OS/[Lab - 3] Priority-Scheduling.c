#include <stdio.h>

int main() {
    int at[10], bt[10], pr[10], i, n, t = 0, count = 0, att[10], btt[10], prr[10], process[10], j = 0, count1, tat[10], wt[10];
    float avgtat = 0, avgwt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time, burst time, and priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }
    printf("Process\t Arrival_Time\tBurst_Time\tPriority\tTurn_Around_Time\tWaiting_Time\n");
    for (int k = 0; k < n; k++) {
        count1 = count;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && bt[i] != 0) {
                att[count] = at[i];
                btt[count] = bt[i];
                prr[count] = pr[i];
                process[count] = i + 1;
                count++;
            }
        }
        for (i = k; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                int temp;
                if (prr[i] > prr[j]) {
                    temp = prr[i];
                    prr[i] = prr[j];
                    prr[j] = temp;

                    temp = btt[i];
                    btt[i] = btt[j];
                    btt[j] = temp;

                    temp = att[i];
                    att[i] = att[j];
                    att[j] = temp;

                    temp = process[i];
                    process[i] = process[j];
                    process[j] = temp;
                }
            }
        }
        t = t + btt[k];
        tat[k] = t - att[k];
        wt[k] = tat[k] - btt[k];
        bt[process[k] - 1] = 0;
        avgtat = avgtat + tat[k];
        avgwt = avgwt + wt[k];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", process[k], att[k], btt[k], prr[k], tat[k], wt[k]);
    }
    avgtat = avgtat / n;
    avgwt = avgwt / n;
    printf("Average turn around time = %.2f\n", avgtat);
    printf("Average waiting time = %.2f\n", avgwt);
    return 0;
}
