//not completed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void firstFit(int blockSize[], int blockLength, int processSize[], int processLength, int allocation[]) {
    // Initialize allocations to -1 (unallocated)
    for (int i = 0; i < blockLength; i++) {
        allocation[i] = -1;
    }

    // Allocate processes to memory blocks using First Fit
    for (int i = 0; i < processLength; i++) {
        for (int j = 0; j < blockLength; j++) {
            if (processSize[i] <= blockSize[j] && allocation[j] == -1) {
                // Process fits in block, allocate it
                allocation[i] = j;
                blockSize[j] -= processSize[i];  // Update remaining block size
                break;  // Process allocated, move to next process
            }
        }
    }
}

int main() {
    // Sample memory block sizes and process sizes
    int blockSize[] = {200, 400, 600, 500, 300};
    int processSize[] = {356, 210, 468, 419};
    int blockLength = sizeof(blockSize) / sizeof(blockSize[0]);
    int processLength = sizeof(processSize) / sizeof(processSize[0]);

    // Array to store process allocations
    int allocation[processLength];

    // Simulate First Fit
    firstFit(blockSize, blockLength, processSize, processLength, allocation);

    // Print allocation results
    for (int i = 0; i < processLength; i++) {
        if (allocation[i] != -1) {
            printf("Process %d allocated to block %d (size %d)\n", i + 1, allocation[i] + 1, processSize[i]);
        } else {
            printf("Process %d could not be allocated (size %d)\n", i + 1, processSize[i]);
        }
    }

    return 0;
}
