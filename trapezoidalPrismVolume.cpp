// Copyright (c) 2025 Luke Di Bert All rights reserved.
//
// Created by: Luke Di Bert
// Date: May 21, 2025

// adds iostream library
#include <iostream>

// adds string library
#include <array>

// adds rounding
#include <iomanip>

// adds strings
#include <string>

// function to calculate area
float areaCalc(std::array<float, 4> array) {
    float area = 0.5 * (array[0] + array[1]) * array[2];
    return area;
}

// main function calculating volume
int main() {
    while (true) {
        // variables to store data for transfer
        std::string base1;
        std::string base2;
        std::string height;
        std::string length;

        std::cout <<
        "Welcome to Luke's volume of a trapezoidal prism calculator!"
        << std::endl;

        // array for shape dimensions
        std::array<float, 4> dimension;

        // user input for dimensions
        std::cout << "Enter base 1 of the trapezoidal prism (cm): ";
        std::cin >> base1;
        std::cout << "Enter base 2 of the trapezoidal prism (cm): ";
        std::cin >> base2;
        std::cout << "Enter height of the trapezoidal prism (cm): ";
        std::cin >> height;
        std::cout << "Enter length of the trapezoidal prism (cm): ";
        std::cin >> length;

        try {
            // transfers data from variables into array
            dimension[0] = std::stof(base1);
            dimension[1] = std::stof(base2);
            dimension[2] = std::stof(height);
            dimension[3] = std::stof(length);

            // compound boolean expression if statement
            if (
                dimension[0] <= 0 ||
                dimension[1] <= 0 ||
                dimension[2] <= 0 ||
                dimension[3] <= 0) {
                std::cout << "Dimensions cannot be zero!" << std::endl;
                break;
            }

            // areaCalc call with dimension array in parameter
            float baseArea = areaCalc(dimension);

            // volume calculation using returned value
            float volume = baseArea * dimension[3];

            // volume displayed rounded to two decimal places
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "The volume is: " << (volume) << "cm^3" << std::endl;
        } catch (const std::invalid_argument&) {
            std::cout <<
            "Oops you entered invalid input, use numbers only!"
            << std::endl;
            break;
        }
        // asks the user if they want to quit
        std::string userQuit;
        std::cout << "Would you like to play again? yes(0), no(1): ";
        std::cin >> userQuit;
        try {
            // converts user input into usable value
            int userQuitInt = std::stoi(userQuit);

            // quits program if user put 1
            if (userQuitInt == 1) {
                std::cout << "Have a good day" << std::endl;
                break;
            }
        } catch (const std::invalid_argument&) {
            std::cout << userQuit <<
            " is invalid input! please use an integer"
            << std::endl;
            break;
        }
    }
}
