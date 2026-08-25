#include "fibonacci.h"
#include <math.h>
#include <stdlib.h>

// Pre-computed lookup table for O(1) performance (0 <= n <= 93)
static const uint64_t FIB_LOOKUP[] = {
    0ULL, 1ULL, 1ULL, 2ULL, 3ULL, 5ULL, 8ULL, 13ULL, 21ULL, 34ULL, 55ULL, 89ULL,
    144ULL, 233ULL, 377ULL, 610ULL, 987ULL, 1597ULL, 2584ULL, 4181ULL, 6765ULL,
    10946ULL, 17711ULL, 28657ULL, 46368ULL, 75025ULL, 121393ULL, 196418ULL,
    317811ULL, 514229ULL, 832040ULL, 1346269ULL, 2178309ULL, 3524578ULL,
    5702887ULL, 9227465ULL, 14930352ULL, 24157817ULL, 39088169ULL, 63245986ULL,
    102334155ULL, 165580141ULL, 267914296ULL, 433494437ULL, 701408733ULL,
    1134903170ULL, 1836311903ULL, 2971215073ULL, 4807526976ULL, 7778742049ULL,
    12586269025ULL, 20365011074ULL, 32951280099ULL, 53316291173ULL,
    86267571272ULL, 139583862445ULL, 225851433717ULL, 365435295862ULL,
    591286729579ULL, 956722025441ULL, 1548008755020ULL, 2504730780461ULL,
    4052739535481ULL, 6557470315942ULL, 10610209851423ULL, 17167680167365ULL,
    27777889018788ULL, 44945569186153ULL, 72723458204941ULL, 117669027391094ULL,
    190392485596035ULL, 308061512987129ULL, 498453998583164ULL, 806515511570293ULL,
    1304969510153457ULL, 2111485021723750ULL, 3416454531877207ULL, 5527939553600957ULL,
    8944394085478164ULL, 14472333639079121ULL, 23416727724557285ULL, 37889061363636406ULL,
    61305789088193691ULL, 99194850451830097ULL, 160500639539023788ULL, 259695489990853885ULL,
    420196129529877673ULL, 679891619520731558ULL, 1100087749050609231ULL, 1779979368571340789ULL,
    2880067117621950020ULL, 4660046486193290809ULL, 7540113603815240829ULL, 12200160089908531638ULL
};

// Returns the nth Fibonacci number using O(1) table lookup
uint64_t fib_nth(size_t n) {
    return fib_lookup(n);
}

// Allocates an array containing the first 'count' Fibonacci numbers [F_0 ... F_(count-1)]
uint64_t* fib_sequence(size_t count) {
    if (count == 0) return NULL;

    uint64_t* seq = (uint64_t*)malloc(count * sizeof(uint64_t));
    if (!seq) return NULL;

    for (size_t i = 0; i < count; i++) {
        seq[i] = fib_nth(i);
    }
    return seq;
}

// 1. Static Lookup Table (O(1) Time, O(1) Space)
uint64_t fib_lookup(size_t n) {
    if (n > FIB_MAX_INDEX) return 0; // Overflow guard
    return FIB_LOOKUP[n];
}

// 2. Iterative / Dynamic Programming (O(n) Time, O(1) Space)
uint64_t fib_iterative(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    uint64_t prev2 = 0;
    uint64_t prev1 = 1;
    uint64_t current = 0;

    for (size_t i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// 3. Naive Recursion (O(2^n) Time, O(n) Stack Space)
uint64_t fib_recursive_naive(size_t n) {
    if (n <= 1) return n;
    return fib_recursive_naive(n - 1) + fib_recursive_naive(n - 2);
}

// 4. Memoized Recursion (O(n) Time, O(n) Space)
static uint64_t memo_helper(size_t n, uint64_t* memo) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];

    memo[n] = memo_helper(n - 1, memo) + memo_helper(n - 2, memo);
    return memo[n];
}

uint64_t fib_memoized(size_t n) {
    if (n <= 1) return n;
    uint64_t* memo = (uint64_t*)calloc(n + 1, sizeof(uint64_t));
    if (!memo) return 0;

    uint64_t result = memo_helper(n, memo);
    free(memo);
    return result;
}

// 5. Fast Doubling Method (O(log n) Time, O(log n) Stack Space)
static void fast_doubling_helper(size_t n, uint64_t* a, uint64_t* b) {
    if (n == 0) {
        *a = 0;
        *b = 1;
        return;
    }
    uint64_t c, d;
    fast_doubling_helper(n >> 1, &c, &d);
    uint64_t e = c * ((d << 1) - c);
    uint64_t f = c * c + d * d;

    if (n & 1) {
        *a = f;
        *b = e + f;
    } else {
        *a = e;
        *b = f;
    }
}

uint64_t fib_fast_doubling(size_t n) {
    uint64_t a, b;
    fast_doubling_helper(n, &a, &b);
    return a;
}

// 6. Matrix Exponentiation (O(log n) Time, O(1) Space)
static void multiply_matrix(uint64_t F[2][2], uint64_t M[2][2]) {
    uint64_t x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    uint64_t y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    uint64_t z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    uint64_t w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

static void power_matrix(uint64_t F[2][2], size_t n) {
    if (n <= 1) return;
    uint64_t M[2][2] = {{1, 1}, {1, 0}};

    power_matrix(F, n / 2);
    multiply_matrix(F, F);

    if (n % 2 != 0) {
        multiply_matrix(F, M);
    }
}

uint64_t fib_matrix_exponentiation(size_t n) {
    if (n == 0) return 0;
    uint64_t F[2][2] = {{1, 1}, {1, 0}};
    power_matrix(F, n - 1);
    return F[0][0];
}

// 7. Binet's Closed-Form Formula (O(1) Time, Loss of Precision at High N)
uint64_t fib_binet(size_t n) {
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    return (uint64_t)round(pow(phi, n) / sqrt(5.0));
}
