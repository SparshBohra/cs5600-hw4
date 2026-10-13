#include <stdio.h>
#include <stdlib.h>

// ch14 q4: allocate and forget to free

int main(void) {
    int *nums = malloc(100 * sizeof(int));
    if (nums == NULL) {
        return 1;
    }
    nums[0] = 42;
    printf("stored %d\n", nums[0]);
    // forgot free(nums)
    return 0;
}
