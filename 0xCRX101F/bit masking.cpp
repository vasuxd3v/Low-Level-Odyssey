#include <iostream>
#include <cstring>
#include <cstdint>

// ─────────────────────────────────────────
// PART 3: BIT MASKING
// ─────────────────────────────────────────
// Bit masking = using bitwise AND/OR/XOR/NOT to read or write
// specific bits inside a number.
// Used everywhere: file permissions, flags, protocol headers, RE.

void check_bit_masking() {
    std::cout << "\n=== PART 3: BIT MASKING ===\n";

    uint8_t flags = 0b10110101; // 8 flags packed into one byte
    std::cout << "flags byte = 0b10110101 = 0x"
              << std::hex << (int)flags << "\n\n";

    // CHECK a specific bit (is bit 2 set?)
    // Mask = 0b00000100 — only bit 2 is 1
    uint8_t mask = (1 << 2); // shift 1 left by 2 positions
    bool bit2_set = (flags & mask) != 0;
    std::cout << "Is bit 2 set?  " << (bit2_set ? "YES" : "NO") << "\n";

    // SET a bit (turn bit 1 ON, regardless of current state)
    uint8_t set_result = flags | (1 << 1);
    std::cout << "After setting bit 1:   0b";
    for (int i = 7; i >= 0; i--)
        std::cout << ((set_result >> i) & 1);
    std::cout << "\n";

    // CLEAR a bit (turn bit 4 OFF)
    uint8_t clear_result = flags & ~(1 << 4);
    std::cout << "After clearing bit 4:  0b";
    for (int i = 7; i >= 0; i--)
        std::cout << ((clear_result >> i) & 1);
    std::cout << "\n";

    // TOGGLE a bit (flip bit 7)
    uint8_t toggle_result = flags ^ (1 << 7);
    std::cout << "After toggling bit 7:  0b";
    for (int i = 7; i >= 0; i--)
        std::cout << ((toggle_result >> i) & 1);
    std::cout << "\n";

    // EXTRACT a value from specific bits
    // Imagine bits 4-6 store a 3-bit number. Extract it.
    uint8_t extracted = (flags >> 4) & 0b00000111;
    std::cout << "\nBits 4-6 extracted as a number: "
              << std::dec << (int)extracted << "\n";
}

int main() {

    check_bit_masking();
    return 0;
}