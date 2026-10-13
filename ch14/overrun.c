#include <stdio.h>
#include <stdlib.h>

// ch14 q5: data[100] on a size-100 array

int main(void) {
    int *data = malloc(100 * sizeof(int));
    if (data == NULL) {
        return 1;
    }
    data[100] = 0;
    printf("wrote past end\n");
    free(data);
    return 0;
}
