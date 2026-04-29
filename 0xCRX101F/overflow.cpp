#include <iostream>
#include <cstdint>
#include <cstring>

// ─────────────────────────────────────────
// PART 2: INTEGER OVERFLOW
// ─────────────────────────────────────────
// When a number exceeds its maximum value, it wraps around.
// This is not a crash — it silently produces a wrong value.
// This is one of the most common security bugs in C/C++.

void check_overflow() {
    std::cout << "\n=== PART 2: INTEGER OVERFLOW ===\n";

    // uint8_t holds values 0 to 255
    uint8_t a = 255;
    std::cout << "uint8_t a = 255\n";
    std::cout << "a + 1 = " << (int)(a + 1) << "  (promoted to int, no overflow)\n";

    // Force the overflow to stay in uint8_t
    uint8_t b = a + 1; // 255 + 1 wraps to 0
    std::cout << "uint8_t b = a + 1 = " << (int)b << "  (overflow! wraps to 0)\n";

    // int32_t holds values -2,147,483,648 to 2,147,483,647
    int32_t max_int = 2147483647; // INT32_MAX
    std::cout << "\nint32_t max = " << max_int << "\n";
    int32_t overflowed = max_int + 1; // undefined behaviour in C++ for signed
    std::cout << "max + 1 = " << overflowed << "  (wraps to most negative number)\n";

    // Unsigned overflow is defined and wraps predictably
    uint32_t umax = 4294967295U; // UINT32_MAX
    uint32_t uwrapped = umax + 1;
    std::cout << "\nuint32_t max = " << std::dec << umax << "\n";
    std::cout << "umax + 1 = " << uwrapped << "  (wraps cleanly to 0)\n";
}

int main(){
    check_overflow();

    return 0;
}