#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int kk, i, j, run = 10;
    float x, iat, st, awt, pcu, wt = 0, it = 0;
    float mean = 10.0, sd = 1.5, mue = 9.5, sigma = 1.0;
    float sb = 0.0, se = 0.0, cit = 0, cat = 0, cwt = 0;
    printf("\n  IAT         CAT       SB         ST         SE         CWT       CIT");

    for (j = 1; j <= run; ++j)
    {
        float sum = 0;
        for (i = 1; i <= 12; ++i)
        {
            x = rand() / 32768.0;
            sum = sum + x;
        }
        iat = mean + sd * (sum - 6.0);
        cat = cat + iat;
        if (cat <= se)
        {
            sb = se;
            wt = se - cat;
            cwt = cwt + wt;
        }
        else
        {
            sb = cat;
            it = sb - se;
            cit = cit + it;
        }
        sum = 0;
        for (i = 1; i <= 12; ++i)
        {
            x = rand() / 32768.0;
            sum = sum + x;
        }
        st = mue + sigma * (sum - 6.0);
        se = sb + st;
        printf("\n %5.2f     %6.2f     %6.2f     %6.2f     %6.2f     %6.2f     %6.2f", iat, cat, sb, st, se, cwt, cit);
    }
    awt = cwt / run;
    pcu = ((cat - cit) * 100.0) / cat;
    printf("\n\nAverage waiting time =  %6.2f", awt);
    printf("\nPercentage capacity untilization =  %6.2f\n", pcu);
}
