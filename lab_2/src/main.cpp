// Создать класс Hex для работы с беззнаковыми целыми шестнадцатеричными числами

#include <iostream>
#include "../include/Hex.h"


Hex::Hex() : hexArray(nullptr), size(0) {}

Hex::Hex(const std::string& hexString) : hexArray(nullptr), size(0)
{
    size_t length = hexString.length();
    allocateMemory(length);

    for (size_t i = 0; i < length; ++i) {
        hexArray[i] = hexCharToDigit(hexString[length - i - 1]);
    }
}

Hex::Hex(const std::initializer_list<unsigned char>& hexDigits) : hexArray(nullptr), size(0)
{
    size_t length = hexDigits.size();
    allocateMemory(length);

    size_t i = 0;
    for (auto digit : hexDigits) {
        hexArray[i++] = digit;
    }
}

Hex::Hex(const Hex& other) : hexArray(nullptr), size(0)
{
    size = other.size;
    allocateMemory(size);

    for (size_t i = 0; i < size; ++i) {
        hexArray[i] = other.hexArray[i];
    }
}

Hex::Hex(Hex&& other) noexcept : hexArray(nullptr), size(0)
{
    hexArray = other.hexArray;
    size = other.size;

    other.hexArray = nullptr;
    other.size = 0;
}

Hex::~Hex() noexcept
{
    deallocateMemory();
}

Hex& Hex::operator=(const Hex& other)
{
    if (this != &other) {
        deallocateMemory();

        size = other.size;
        allocateMemory(size);

        for (size_t i = 0; i < size; ++i) {
            hexArray[i] = other.hexArray[i];
        }
    }
    return *this;
}

Hex& Hex::operator+=(const Hex& other)
{
    size_t maxSize = std::max(size, other.size);
    allocateMemory(maxSize + 1);

    unsigned char carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char sum = carry;
        if (i < size) sum += hexArray[i];
        if (i < other.size) sum += other.hexArray[i];
        hexArray[i] = sum % 16;
        carry = sum / 16;
    }

    if (carry > 0) {
        hexArray[maxSize] = carry;
        ++size;
    }

    return *this;
}

Hex& Hex::operator-=(const Hex& other)
{
    if (*this < other) {
        throw std::invalid_argument("Cannot subtract larger Hex from smaller Hex");
    }

    unsigned char borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        unsigned char difference = borrow;
        if (i < other.size) difference += other.hexArray[i];
        if (hexArray[i] < difference) {
            hexArray[i] = 16 + hexArray[i] - difference;
            borrow = 1;
        } else {
            hexArray[i] = hexArray[i] - difference;
            borrow = 0;
        }
    }

    while (size > 1 && hexArray[size - 1] == 0) {
        --size;
    }

    return *this;
}

bool Hex::operator==(const Hex& other) const
{
    if (size != other.size) return false;

    for (size_t i = 0; i < size; ++i) {
        if (hexArray[i] != other.hexArray[i]) return false;
    }

    return true;
}

bool Hex::operator!=(const Hex& other) const
{
    return !(*this == other);
}

bool Hex::operator<(const Hex& other) const
{
    return false;
}

bool Hex::operator>(const Hex& other) const
{
    return false;
}

bool Hex::operator<=(const Hex& other) const
{
    return false;
}

bool Hex::operator>=(const Hex& other) const
{
    return false;
}

std::string Hex::toString() const
{
    std::string hexString;
    for (size_t i = 0; i < size; ++i) {
        hexString = digitToHexChar(hexArray[i]) + hexString;
    }
    return hexString;
}

unsigned char Hex::hexCharToDigit(char hexChar) const
{
    if (hexChar >= '0' && hexChar <= '9') {
        return hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        return hexChar - 'A' + 10;
    } else if (hexChar >= 'a' && hexChar <= 'f') {
        return hexChar - 'a' + 10;
    } else {
        throw std::invalid_argument("Invalid hex character");
    }
}

char Hex::digitToHexChar(unsigned char digit) const
{
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    } else if (digit >= 10 && digit <= 15) {
        return 'A' + (digit - 10);
    } else {
        throw std::invalid_argument("Invalid hex digit");
    }
}

void Hex::allocateMemory(size_t newSize)
{
    hexArray = new unsigned char[newSize];
    size = newSize;
}

void Hex::deallocateMemory()
{
    delete[] hexArray;
    hexArray = nullptr;
    size = 0;
}
