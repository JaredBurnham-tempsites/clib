#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Max index supported by 64-bit unsigned integers before overflow (F_93)
#define FIB_MAX_INDEX 93

// Standard API: Lookup Table / Iterative
uint64_t fib_nth(size_t n);
uint64_t* fib_sequence(size_t n);

// Known Algorithm Variants
uint64_t fib_iterative(size_t n);
uint64_t fib_recursive_naive(size_t n);
uint64_t fib_memoized(size_t n);
uint64_t fib_fast_doubling(size_t n);
uint64_t fib_matrix_exponentiation(size_t n);
uint64_t fib_binet(size_t n);
uint64_t fib_lookup(size_t n);

#ifdef __cplusplus
}
#endif

#endif // FIBONACCI_H
