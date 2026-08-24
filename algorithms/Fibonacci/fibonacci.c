#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int recursivefib(int a, int b, int f) {
    int fib1;
    int fib2;
    static int c = 0;
    c++;
    fib2 = a + b;
    fib1 = b;
    if (f - 2 > c) {
        return recursivefib(fib1, fib2, f);
    } else {
        printf("%d", fib2);
        return fib2;
    }
}

int* fibonacciNumbers(int a) {
    if (a <= 0) return NULL;

    int* fn = (int*)malloc(a * sizeof(int));
    if (fn == NULL) return NULL;

    for (int i = 0; i < a; i++) {
        if (i == 0) {
            fn[i] = 0;
        } else if (i == 1) {
            fn[i] = 1;
        } else {
            fn[i] = fn[i - 1] + fn[i - 2];
        }
    }
    for (int j = 0; j < a - 1; j++) {
        printf("%d, ", fn[j]);
    }
    return fn;
}

void fibloopexample(int i) {
    int prev2 = 0;
    int prev1 = 1;
    int newfibo;
    printf("%d\n%d\n", prev2, prev1);
    for (int j = 0; j <= i; j++) {
        newfibo = prev1 + prev2;
        printf("%d\n", newfibo);
        prev2 = prev1;
        prev1 = newfibo;
    }
}

void fibrecursionexample(int prev1, int prev2) {
    int newfibo;
    static int count = 0;

    if (count <= 30) {
        newfibo = prev1 + prev2;
        printf("%d\n", newfibo);
        prev2 = prev1;
        prev1 = newfibo;
        count += 1;
        fibrecursionexample(prev1, prev2);
    } else {
        return;
    }
}

int findnth(int n) {
    if (n <= 1) {
        return n;
    } else {
        return findnth(n - 1) + findnth(n - 2);
    }
}
