#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    int* numbers = (int*) calloc(n, sizeof(int));

    // Read the integers from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Calculate the sum
    int sum = 0;                          
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    // Print the sum
    printf("Sum: %d\n", sum);

    // Free the allocated memory
    free(numbers);

    return 0;
}