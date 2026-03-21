#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    try {
        std::cout << "--- Subject Test ---" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Exception Test ---" << std::endl;
        Span spError(2);
        spError.addNumber(1);
        std::cout << spError.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- 15000 Elements & Iterator Range Test ---" << std::endl;
        Span spRange(15000);
        std::vector<int> randomNumbers;
        std::srand(std::time(NULL));
        
        for (int i = 0; i < 15000; ++i) {
            randomNumbers.push_back(std::rand());
        }
        
        spRange.addNumber(randomNumbers.begin(), randomNumbers.end());
        
        std::cout << "Shortest span: " << spRange.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spRange.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}