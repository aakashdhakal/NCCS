#include <stdio.h>

#define TSIZE 10

void linear_probe(int *arr, int key)
{
    int i = 1, h;
    h = key % TSIZE;
    if (arr[h] == -1)
    {
        arr[h] = key;
    }
    else
    {
        while (arr[h] != -1)
        {
            h = (h + i) % TSIZE;
            i++;
        }
        arr[h] = key;
    }
}

void quadratic_probe(int *arr, int key)
{
    int i = 1, h;
    h = key % TSIZE;
    if (arr[h] == -1)
    {
        arr[h] = key;
    }
    else
    {
        while (arr[h] != -1)
        {
            h = (h + i * i) % TSIZE;
            i++;
        }
        arr[h] = key;
    }
}

void double_hash(int *arr, int key)
{
    int j = 1, h, hk;
    h = key % TSIZE;

    if (arr[h] == -1)
    {
        arr[h] = key;
    }
    else
    {
        hk = 7 - (key % 7); // Modified this line
        while (arr[h] != -1 && j < TSIZE)
        {
            h = (h + j * hk) % TSIZE;
            j++;
        }
        arr[h] = key;
    }
}

void resetTable(int *arr)
{
    int i;
    for (i = 0; i < TSIZE; i++)
    {
        arr[i] = -1;
    }
}

int main()
{
    int htable[TSIZE];
    int i;
    int arr[TSIZE] = {97, 79, 77, 13, 23, 33, 11, 15};

    printf("\nUsing quadratic probing\n");
    resetTable(htable);
    for (i = 0; i < TSIZE; i++)
    {
        quadratic_probe(htable, arr[i]);
        printf("htable[%d] = %d\n", i, htable[i]);
    }

    printf("\nUsing linear probing\n");
    resetTable(htable);
    for (i = 0; i < TSIZE; i++)
    {
        linear_probe(htable, arr[i]);
        printf("htable[%d] = %d\n", i, htable[i]);
    }

    printf("\nUsing double hashing\n");
    resetTable(htable);
    for (i = 0; i < TSIZE; i++)
    {
        double_hash(htable, arr[i]);
        printf("htable[%d] = %d\n", i, htable[i]);
    }
    return 0;
}
