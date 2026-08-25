#include <iostream>
#include <vector>
#include <cstdlib>
#include "fibonacci.h"

int main() {
    // 1. Fetch nth number
    std::cout << "F(50) = " << fib_nth(50) << std::endl;

    // 2. Fetch sequence into std::vector
    size_t count = 10;
    uint64_t* raw_seq = fib_sequence(count);

    if (raw_seq != nullptr) {
        std::vector<uint64_t> seq(raw_seq, raw_seq + count);
        std::free(raw_seq); // Free C allocation

        std::cout << "Vector contents: ";
        for (uint64_t val : seq) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
