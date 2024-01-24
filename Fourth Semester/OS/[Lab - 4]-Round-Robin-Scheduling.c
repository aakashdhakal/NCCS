#include <stdio.h>

void main()
{
    // Declare variables
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    // Prompt user to enter the total number of processes
    printf("Enter the total no of process: ");
    scanf("%d", &NOP);
    y = NOP;

    // Prompt user to enter the arrival and burst time for each process
    printf("\nEnter the Arrival and Burst time of each process\n");
    for (i = 0; i < NOP; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        temp[i] = bt[i];
    }

    // Prompt user to enter the time quantum for the process
    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");

    // Implement the Round Robin scheduling algorithm
    for (sum = 0, i = 0; y != 0;)
    {
        // If the remaining burst time of the current process is less than or equal to the time quantum
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        // If the remaining burst time of the current process is greater than the time quantum
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        // If the current process has finished execution
        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\nP[%d] \t\t %d\t\t\t %d\t\t %d", i + 1, bt[i], sum - at[i],
                   sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }

        // If all processes have been checked, reset the index to start again from the first process
        if (i == NOP - 1)
            i = 0;
        // If the next process has arrived, move to the next process
        else if (at[i + 1] <= sum)
            i++;
        // If the next process has not arrived, reset the index to start again from the first process
        else
            i = 0;
    }

    // Calculate the average waiting time and turnaround time
    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;

    // Display the average waiting time and turnaround time
    printf("\n\nAverage Turnaround Time: %f", avg_wt);
    printf("\nAverage Waiting Time: %f\n", avg_tat);
}
