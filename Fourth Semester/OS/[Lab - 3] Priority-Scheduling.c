#include <stdio.h>

// Function to swap two integer values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // Initialize arrays for arrival time, burst time, priority, turnaround time, and waiting time
    int at[10], bt[10], pr[10], i, n, t = 0, count = 0, att[10], btt[10], prr[10], process[10], j = 0, count1 = 0, tat[10], wt[10];
    // Initialize variables for average turnaround time and average waiting time
    float avgtat = 0, avgwt = 0;

    // Prompt user for number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Prompt user for arrival time, burst time, and priority for each process
    printf("Enter the arrival time, burst time, and priority of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // Set the start time to the arrival time of the first process
    t = at[0];

    // Print the table header
    printf("Process\t Arrival_Time\tBurst_Time\tPriority\tTurn_Around_Time\tWaiting_Time\n");

    // While not all processes have been scheduled
    while (count1 < n)
    {
        count = 0;
        // For each process
        for (i = 0; i < n; i++)
        {
            // If the process has arrived and has not finished
            if (at[i] <= t && bt[i] != 0)
            {
                // Add the process to the list of ready processes
                att[count] = at[i];
                btt[count] = bt[i];
                prr[count] = pr[i];
                process[count] = i + 1;
                count++;
            }
        }

        // Sort the ready processes by priority
        for (i = 0; i < count - 1; i++)
        {
            for (j = i + 1; j < count; j++)
            {
                // If the current process has a lower priority than the next process
                if (prr[i] > prr[j])
                {
                    // Swap the burst times, arrival times, priorities, and process IDs
                    swap(&btt[i], &btt[j]);
                    swap(&att[i], &att[j]);
                    swap(&prr[i], &prr[j]);
                    swap(&process[i], &process[j]);
                }
            }
        }

        // Update the current time by adding the burst time of the first process in the ready queue
        t = t + btt[0];

        // Calculate the turnaround time and waiting time for the process
        tat[process[0] - 1] = t - att[0];
        wt[process[0] - 1] = tat[process[0] - 1] - btt[0];

        // Mark the process as finished
        bt[process[0] - 1] = 0;

        // Update the count of scheduled processes
        count1++;

        // Update the total turnaround time and waiting time
        avgtat = avgtat + tat[process[0] - 1];
        avgwt = avgwt + wt[process[0] - 1];

        // Print the process details
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", process[0], att[0], btt[0], prr[0], tat[process[0] - 1], wt[process[0] - 1]);
    }

    // Calculate and print the average turnaround time and waiting time
    avgtat = avgtat / n;
    avgwt = avgwt / n;
    printf("Average turn around time = %.2f\n", avgtat);
    printf("Average waiting time = %.2f\n", avgwt);

    return 0;
}
