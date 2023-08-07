#include <stdio.h>

#define TSIZE 10

void linear_probe(int *arr, int key) {
    int i, h;
    h = key % TSIZE;
    if (arr[h] == -1) {
        arr[h] = key;
    } else {
        i = 1;
        while (arr[h] != -1) {
            h = (h + i) % TSIZE;
        }
        arr[h] = key;
    }
}

void quadratic_probe(int *arr, int key) {
    int i, h;
    h = key % TSIZE;
    if (arr[h] == -1) {
        arr[h] = key;
    } else {
        i = 1;
        while (arr[h] != -1) {
            h = (h + i * i) % TSIZE;
        }
        arr[h] = key;
    }
}

void double_hashing(int *arr, int key) {
    int i, h, h1, h2;
    h1 = key % TSIZE;
    h2 = 7 - (key % 7); 
    h = h1;
    if (arr[h] == -1) {
        arr[h] = key;
    } else {
        i = 1;
        while (arr[h] != -1) {
            h = (h1 + i * h2) % TSIZE;
        }
        arr[h] = key;
    }
}

void clearTable(int *htable){
	int i;
	 for (i = 0; i < TSIZE; i++) {
        htable[i] = -1;
    }
}

int main() {
    int htable[TSIZE];
    int i;
    for (i = 0; i < TSIZE; i++) {
        htable[i] = -1;
    }
    int arr[TSIZE] = {97, 7, 72, 13, 23, 44, 19, 12};
clearTable(htable);
    printf("Using linear probing\n");

    for (i = 0; i < TSIZE; i++) {
        linear_probe(htable, arr[i]);
        printf("htable[%d] = %d\n", i, htable[i]);
    }

   clearTable(htable);

    printf("\nUsing quadratic probing\n");

    for (i = 0; i < TSIZE; i++) {
        quadratic_probe(htable, arr[i]);
        printf("htable[%d] = %d\n", i, htable[i]);
    }

	clearTable(htable);

    printf("\nUsing double hashing\n");

    for (i = 0; i < TSIZE; i++) {
        double_hashing(htable, arr[i]);
        printf("htable[%d] = %d\n", i, htable[i]);
    }

    return 0;
}
