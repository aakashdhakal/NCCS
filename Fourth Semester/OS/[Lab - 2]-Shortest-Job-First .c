#include <stdio.h>

void sjf(int n, int bt[], int p[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0, pos, temp;

    // Sort burst time in ascending order using selection sort
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
            {
                pos = j;
            }
        }
        // Swap bt[pos] and bt[i]
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap p[pos] and p[i]
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Calculate waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        total_wt += wt[i];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
    }

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n];
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    sjf(n, bt, p);

    return 0;
}
