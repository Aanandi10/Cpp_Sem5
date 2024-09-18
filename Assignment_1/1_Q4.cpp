#include <iostream>

void printBinary(int number) {
    const int bits = sizeof(int) * 8; 
    std::cout << number << " in binary: ";

    for (int i = bits - 1; i >= 0; --i) {
        int bit = (number >> i) & 1; 
        std::cout << bit;
    }
    std::cout << std::endl;
}

void verifyTwosComplement(int number) 
{
    
    int twosComplement = (~(-number)) + 1;
    std::cout << "Two's complement verification:" << std::endl;
    std::cout << "Original negative number: " << number << std::endl;
    std::cout << "Computed Two's complement: " << twosComplement << std::endl;
    std::cout << "Are they equal? " << (number == twosComplement ? "Yes" : "No") << std::endl;
}

int main() {
    int positiveNum = 25;
    int negativeNum = -25;

    std::cout << "Positive number:" << std::endl;
    printBinary(positiveNum);

    std::cout << "Negative number:" << std::endl;
    printBinary(negativeNum);

    std::cout << "Two's Complement Verification:" << std::endl;
    verifyTwosComplement(negativeNum);

    return 0;
}

	
