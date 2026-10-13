#include <stdio.h>
#include <stdlib.h>

// ch14 q6: free then print an element

int main(void) {
    int *data = malloc(100 * sizeof(int));
    if (data == NULL) {
        return 1;
    }
    data[0] = 7;
    free(data);
    printf("after free: %d\n", data[0]);
    return 0;
}
