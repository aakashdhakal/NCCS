#include <stdio.h>

int predict(int page[], int pg[], int pn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < 3; i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (page[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main()
{
    int page[3] = {-1, -1, -1}, hit = 0, i, j;
    int input[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    int pn = sizeof(input) / sizeof(input[0]);
    printf("String\tFrame 1\tFrame 2\tFrame 3\tresult\n");
    for (i = 0; i < pn; i++)
    {
        int check = 0;
        for (j = 0; j < 3; j++)
        {
            if (page[j] == input[i])
            {
                hit++;
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            int j = predict(page, input, pn, i + 1);
            page[j] = input[i];
        }
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%s\n", input[i], page[0], page[1], page[2], check ? "Hit" : "Miss");
    }
    printf("The total number of hits is %d", hit);
    return 0;
}
