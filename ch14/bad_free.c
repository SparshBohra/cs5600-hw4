#include <stdio.h>
#include <stdlib.h>

// ch14 q7: free pointer that is not the start of the block

int main(void) {
    int *data = malloc(100 * sizeof(int));
    if (data == NULL) {
        return 1;
    }
    free(data + 10);
    printf("should not get here\n");
    return 0;
}
