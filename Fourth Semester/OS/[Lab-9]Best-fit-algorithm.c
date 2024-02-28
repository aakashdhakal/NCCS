#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i, j, k, n1, n2, count;
    int block[10], process[10], diff[10], mem[10];

    printf("Enter the number of memory blocks: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter memory block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the memory required by process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    printf("Process\tProcess Size\tMemory Block\n");
    for (i = 0; i < n2; i++) {
        count = 0;
        for (j = 0; j < n1; j++) {
            if (process[i] <= block[j]) {
                diff[count] = block[j] - process[i];
                mem[count] = j;
                count++;
            }
        }

        if (count == 0) {
            printf("%d\t\t%d\t\tNot allocated\n", i + 1, process[i]);
        } else if (count == 1) {
            block[mem[0]] -= process[i];
            printf("%d\t\t%d\t\t%d\n", i + 1, process[i], mem[0] + 1);
        } else {
            // Sort diffs and corresponding memory block indices in ascending order
            for (j = 0; j < count - 1; j++) {
                for (k = j + 1; k < count; k++) {
                    if (diff[j] > diff[k]) {
                        swap(&diff[j], &diff[k]);
                        swap(&mem[j], &mem[k]);
                    }
                }
            }
            block[mem[0]] -= process[i];
            printf("%d\t\t%d\t\t%d\n", i + 1, process[i], mem[0] + 1);
        }
    }

    return 0;
}
