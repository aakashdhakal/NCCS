#include <stdio.h>

int main()
{
    int track[10], n, i, init, endt, res = 0;
    printf("Enter number of tracks to be visited: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter track to be visited in order %d: ", i + 1);
        scanf("%d", &track[i]);
    }
    printf("Enter initial track: ");
    scanf("%d", &init);
    printf("Enter the track limit: ");
    scanf("%d", &endt);
    for (i = 0; i < n; i++)
    {
        if (init > track[i])
        {
            res += (init - track[i]);
            init = track[i];
        }
        else
        {
            res += (track[i] - init);
            init = track[i];
        }
    }
    printf("The total disk movements is %d tracks", res);
    return 0;
}
