#include <stdio.h>
#include <string.h>

int main()
{
    int page[3] = {-1, -1, -1}, count = 0, i, hit = 0, check;
    int input[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    printf("String\tFrame 1\tFrame 2\tFrame 3\tresult\n");
    for (i = 0; i < 12; i++)
    {
        check = 0;
        if (page[0] == input[i] || page[1] == input[i] || page[2] == input[i])
        {
            hit++;
            check = 1;
        }
        else
        {
            page[count] = input[i];
            count = (count + 1) % 3;
        }
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%s\n", input[i], page[0], page[1], page[2], check ? "Hit" : "Miss");
    }
    printf("The total number of hits is %d", hit);
    return 0;
}
