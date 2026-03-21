#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::cout << "--- TEST 1: std::vector ---" << std::endl;
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    try {
        std::cout << "Searching for 20 in vector..." << std::endl;
        std::vector<int>::iterator it1 = easyfind(myVector, 20);
        std::cout << "Found! Value is: " << *it1 << std::endl;

        std::cout << "Searching for 99 in vector..." << std::endl;
        easyfind(myVector, 99);
        std::cout << "This line should not be displayed." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: std::list ---" << std::endl;
    std::list<int> myList;
    myList.push_back(42);
    myList.push_back(84);
    myList.push_back(21);

    try {
        std::cout << "Searching for 84 in list..." << std::endl;
        std::list<int>::iterator it2 = easyfind(myList, 84);
        std::cout << "Found! Value is: " << *it2 << std::endl;

        std::cout << "Searching for 100 in list..." << std::endl;
        easyfind(myList, 100);
        std::cout << "This line should not be displayed." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}