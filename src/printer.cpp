#include "printer.h"
#include <iostream>

void printer::printNumbers(int num1, int num2) {
    std::cout << "First number: " << num1 << std::endl;
    std::cout << "Second number: " << num2 << std::endl;

}

void printer::printResult(int result) {
    std::cout << "Final result: " << result << std::endl;
}