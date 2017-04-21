#include <iostream>
#include "graphics.h"

void printPhase1()
{
    std::cout << R"(
        _____________
        |/          |
        |
        |
        |
        |
        |
        |
    ---------
    )" << std::endl;
}

void printPhase2()
{
    std::cout << R"(
        _____________
        |/          |
        |           O
        |
        |
        |
        |
        |
    ---------
    )" << std::endl;
}

void printPhase3()
{
    std::cout << R"(
        _____________
        |/          |
        |           O
        |           |
        |
        |
        |
        |
    ---------
    )" << std::endl;
}

void printPhase4()
{
    std::cout << R"(
        _____________
        |/          |
        |           O
        |          /|
        |
        |
        |
        |
    ---------
    )" << std::endl;
}

void printPhase5()
{
    std::cout << R"(
        _____________
        |/          |
        |           O
        |          /|\
        |
        |
        |
        |
    ---------
    )" << std::endl;
}

void printPhase6()
{
    std::cout << R"(
        _____________
        |/          |
        |           O
        |          /|\
        |          /
        |
        |
        |
    ---------
    )" << std::endl;
}

void printPhase7()
{
    std::cout << R"(
        _____________
        |/          |
        |           O
        |          /|\
        |          / \
        |
        |
        |
    ---------
    )" << std::endl;
}

void (* printPhases[])() = {&printPhase1, &printPhase2, &printPhase3, &printPhase4,
                            &printPhase5, &printPhase6, &printPhase7};
