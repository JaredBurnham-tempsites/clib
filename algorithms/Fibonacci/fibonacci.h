#ifndef FIBONACCI_H
#ifndef FIBONACCI_H
#define FIBONACCI_H

#ifdef __cplusplus
extern "C" {
#endif

// Allocates and returns an array of the first 'a' Fibonacci numbers.
// Caller is responsible for freeing the allocated memory.
int* fibonacciNumbers(int a);

// Recursively calculates Fibonacci value
int recursivefib(int a, int b, int f);

// Example functions that print sequences directly
void fibloopexample(int i);
void fibrecursionexample(int prev1, int prev2);

// Returns the nth Fibonacci number (0-indexed)
int findnth(int n);

#ifdef __cplusplus
}
#endif

#endif // FIBONACCI_H
