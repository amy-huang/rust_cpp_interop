// SpaceshipOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <compare>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#include <tuple>
#include <utility>
#include <windows.h>
#include <iostream>
#include <string>
#include "printlibfunctions.h"

// Example class that uses the spaceship operator
class Person {
    class Hobby {
    public:
        std::string name;

        Hobby() {}

        Hobby(std::string n) : name(std::move(n)) {}

    };

public:
    std::string name;
    int age;
    Hobby hobby;

    Person(std::string n, int a) : name(std::move(n)), age(a) {}

};

typedef void (*PrintPhraseFunc)(const unsigned char*, size_t);

int main() {
    Person A("Ames", 27);
    Person B("Mike", 30);

    std::strong_ordering ordering = 4 <=> 9;
    bool is_greater = ordering == std::strong_ordering::greater;
    std::cout << std::boolalpha << is_greater << std::endl;  // Uses the default spaceship operator

    // Load the DLL at runtime
    HMODULE hLib = LoadLibrary(L"mylib.dll");
    if (hLib == NULL) {
        std::cerr << "Failed to load mylib.dll" << std::endl;
        return 1;
    }

    // Get the function address
    PrintPhraseFunc printPhrase = (PrintPhraseFunc)GetProcAddress(hLib, "printPhrase");
    if (printPhrase == NULL) {
        std::cerr << "Failed to find printPhrase function" << std::endl;
        FreeLibrary(hLib);
        return 1;
    }

    // Use the function
    std::string message = "Hello from C++!";
    printPhrase(reinterpret_cast<const unsigned char*>(message.c_str()),
        message.length());

    FreeLibrary(hLib);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
