// Guessing Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

int rng(int min, int max)
{
    int rn;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    rn = distr(gen);
    return rn;
}

int main()
{
    std::cout << "Welcome to my number guessing game. Please input the minimum number:\n";
    int min;
    std::cin >> min;
    std::cout << "Please input the maximum number:\n";
    int max;
    std::cin >> max;
    int number = rng(min, max);
    std::cout << "Guess the number I am thinking of:\n";
    int guess;
    while (true)
    {
        std::cin >> guess;
        if (guess > max)
        {
            std::cout << "Way too high! Maximum number is " << max << ". Guess again:\n";
            continue;
        }
        if (guess < min)
        {
            std::cout << "Way too low! Minimum number is " << min << ". Guess again:\n";
            continue;
        }
        if (guess > number)
        {
            std::cout << "Too high, guess again:\n";
            continue;
        }
        if (guess < number)
        {
            std::cout << "Too low, guess again:\n";
            continue;
        }
        if (guess == number)
        {
            std::cout << "Congratulations! You guessed my number!";
        }
        break;
    }
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
