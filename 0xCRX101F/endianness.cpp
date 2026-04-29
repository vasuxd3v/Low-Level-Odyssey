#include <iostream>
#include <cstdint>
#include <cstring>


// PART 1: ENDIANNESS

// A multi-byte number is stored in memory.
// Little-endian (x86/x64): least significant byte stored FIRST.
// Big-endian: most significant byte stored FIRST.
// Your Mac/PC is little-endian. This proves it.

void check_endianness(){

    std::cout << "ENDIANNESS" << std::endl;

    uint32_t value = 0x01020304;

    uint8_t* byte = reinterpret_cast<uint8_t*>(&value);

    std::cout << "The number 0x01020304 sits in memory as:\n";
    for(int i = 0; i < 4; i++){
        std::cout << "Address [" << i << "] = 0x"
            << std::hex << (int)byte[i] << std::endl;
    }

    if(byte[0] == 0x04){
        std::cout << "Result : LITTLE-ENDIAN" << std::endl;
    } else {
        std::cout << "Result : BIG-ENDIAN" << std::endl;
    }
}


int main() {
    check_endianness();
    return 0;
}