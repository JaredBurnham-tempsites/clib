# libfibonacci

A high-performance C/C++ library for computing Fibonacci numbers and sequences.

![Language](https://img.shields.io/badge/Language-C99%20%7C%20C%2B%2B11-blue)
![Precision](https://img.shields.io/badge/Precision-64--Bit%20%28uint64__t%29-green)
![Lookup Speed](https://img.shields.io/badge/Lookup%20Time-O%281%29-brightgreen)

---

## Overview

`libfibonacci` is a fast, lightweight, zero-dependency C library designed for calculating $n$-th Fibonacci numbers and generating complete sequences. It features full cross-compatibility with C and C++ projects, robust 64-bit unsigned integer handling (up to $F_{93}$ without overflow), and optimized $\mathcal{O}(1)$ lookup performance alongside 7 distinct mathematical algorithm implementations.

---

## Key Features

- **C & C++ Interoperability:** Uses standard `extern "C"` guards to ensure seamless linkage across both C and C++ compilers.
- **$\mathcal{O}(1)$ Lookup Table:** Employs a pre-computed static array for instant values without runtime arithmetic.
- **64-Bit Integer Support:** Uses `uint64_t` to calculate up to $F_{93}$ ($12,200,160,419,912,013,638$) before integer overflow.
- **Algorithm Suite:** Includes 7 implementations (Fast Doubling, Matrix Exponentiation, Iterative DP, Binet's Formula, etc.).
- **Dynamic Sequence Generation:** Heap-allocates arrays containing complete Fibonacci sequences up to count $N$.

---

## Project Layout

```text
libfibonacci/
├── include/
│   └── fibonacci.h      # Public API header (extern "C")
├── src/
│   └── fibonacci.c      # Lookup table & algorithm implementations
├── examples/
│   ├── main.c           # C project integration example
│   └── main.cpp         # C++ project integration example
└── README.md            # Library documentation
