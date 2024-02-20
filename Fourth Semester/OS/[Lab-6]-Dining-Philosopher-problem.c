#include <stdio.h>

int wait(int a)
{
    if (a != 0)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n, chopstick[10], count = 0, i, check[10], phil[10];
    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        chopstick[i] = 1;
        check[i] = 0;
        phil[i] = 0;
    }

    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (check[i] == 1)
            {
                printf("Philosopher %d has finished eating \n", i + 1);
                check[i] = 0;
                phil[i] = 1;
                chopstick[i]++;
                chopstick[(i + 1) % n]++;
                count++;
            }
            if (phil[i] == 0)
            {

                if (wait(chopstick[i]) && wait(chopstick[(i + 1) % n]))
                {
                    chopstick[i]--;
                    chopstick[(i + 1) % n]--;
                    printf("Philosopher %d is eating\n", i + 1);
                    check[i] = 1;
                }
                else
                {
                    printf("Philosopher %d is waiting\n", i + 1);
                }
            }
        }
    }
    return 0;
}
