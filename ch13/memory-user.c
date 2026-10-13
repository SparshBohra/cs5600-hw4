#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// ch13: use some memory and keep touching it
// arg1 = megabytes, optional arg2 = seconds (0 = forever)

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: %s <mb> [seconds]\n", argv[0]);
        return 1;
    }

    int mb = atoi(argv[1]);
    int secs = 0;
    if (argc >= 3) {
        secs = atoi(argv[2]);
    }

    if (mb <= 0) {
        printf("mb must be > 0\n");
        return 1;
    }

    size_t nbytes = (size_t)mb * 1024 * 1024;
    char *block = malloc(nbytes);
    if (block == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    printf("pid %d using %d MB\n", getpid(), mb);
    fflush(stdout);

    // touch every page so it really gets mapped
    size_t i;
    for (i = 0; i < nbytes; i += 4096) {
        block[i] = 1;
    }

    int t = 0;
    while (1) {
        for (i = 0; i < nbytes; i += 4096) {
            block[i] = (char)(block[i] + 1);
        }

        if (secs > 0) {
            t++;
            if (t >= secs) {
                break;
            }
        }

        sleep(1);
    }

    free(block);
    return 0;
}
