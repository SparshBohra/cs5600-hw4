#include <stdio.h>

// ch14 q1: deref a null pointer on purpose

int main(void) {
    int *p = NULL;
    printf("%d\n", *p);
    return 0;
}
