#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

class Hex {
    public:
        Hex();
        Hex(const std::string& hexString);
        Hex(const std::initializer_list<unsigned char>& hexDigits);
        Hex(const Hex& other);
        Hex(Hex&& other) noexcept;
        ~Hex() noexcept;

        Hex& operator=(const Hex& other);
        Hex& operator+=(const Hex& other);
        Hex& operator-=(const Hex& other);

        bool operator==(const Hex& other) const;
        bool operator!=(const Hex& other) const;
        bool operator<(const Hex& other) const;
        bool operator>(const Hex& other) const;
        bool operator<=(const Hex& other) const;
        bool operator>=(const Hex& other) const;

        std::string toString() const;

    private:
        unsigned char* hexArray;
        size_t size;

        unsigned char hexCharToDigit(char hexChar) const;
        char digitToHexChar(unsigned char digit) const;
        void allocateMemory(size_t newSize);
        void deallocateMemory();
};