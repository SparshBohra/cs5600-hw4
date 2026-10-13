#include <stdio.h>
#include <stdlib.h>

// ch14 q8: tiny growable int list using realloc

typedef struct {
    int *items;
    int len;
    int cap;
} IntVec;

void vec_init(IntVec *v) {
    v->items = NULL;
    v->len = 0;
    v->cap = 0;
}

int vec_push(IntVec *v, int x) {
    if (v->len >= v->cap) {
        int new_cap = (v->cap == 0) ? 2 : v->cap * 2;
        int *p = realloc(v->items, new_cap * sizeof(int));
        if (p == NULL) {
            return -1;
        }
        v->items = p;
        v->cap = new_cap;
    }
    v->items[v->len] = x;
    v->len++;
    return 0;
}

void vec_free(IntVec *v) {
    free(v->items);
    v->items = NULL;
    v->len = 0;
    v->cap = 0;
}

int main(void) {
    IntVec v;
    int i;

    vec_init(&v);
    for (i = 0; i < 20; i++) {
        if (vec_push(&v, i * 10) != 0) {
            printf("push failed\n");
            vec_free(&v);
            return 1;
        }
    }

    for (i = 0; i < v.len; i++) {
        printf("%d ", v.items[i]);
    }
    printf("\nlen=%d cap=%d\n", v.len, v.cap);

    vec_free(&v);
    return 0;
}
