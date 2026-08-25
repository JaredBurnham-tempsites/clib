#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(void) {
    // 1. Fetch nth number
    size_t n = 10;
    uint64_t val = fib_nth(n);
    printf("F(%zu) = %lu\n", n, val);

    // 2. Fetch full sequence
    size_t count = 15;
    uint64_t* seq = fib_sequence(count);

    if (seq != NULL) {
        printf("Sequence [0..%zu]: ", count - 1);
        for (size_t i = 0; i < count; i++) {
            printf("%lu ", seq[i]);
        }
        printf("\n");

        // Remember to free dynamically allocated array
        free(seq);
    }

    return 0;
}
