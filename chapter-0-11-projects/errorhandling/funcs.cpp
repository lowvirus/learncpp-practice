#include <iostream>
#include "funcheads.h"
#include <cstdlib>
#include <limits>
#include <cmath>

//Function to flush buffer within the cin
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    if(!std::cin)
    {
        if (std::cin.eof()) //If the stream was closed
        {
            std::exit(0);
        }

        //Handling the failure
        std::cin.clear(); //Make cin work again, normal
        ignoreLine();  //Flushes the cin buffer
        return true;
    }
    return false;
}

//Function to get the user input
double userInput()
{
    while(true)
    {
        std::cout << "Enter an integer: ";
        double x{};
        std::cin >> x;
        if(clearFailedExtraction())
        {
            std::cout << "Sorry, INVALID character entered , try entering the input again :(\n";
            continue;
        }
        ignoreLine();
        return x;
    }
}

//function to get the operator
char getOperator()
{
    while(true)
    {
        std::cout << "Enter an operator ('+', '/','*','-','^','r'): ";
        char ch{};
        std::cin >> ch;
        ignoreLine();
        if(!clearFailedExtraction())
        {
            switch (ch)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case 'r':
                return ch; // Return the entered char to the caller
            default: // Otherwise tell the user what went wrong
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
        }
    
    }
}

void printResult(double num1, char ch, double num2)
{
    switch(ch)
    {
    case '+':
        std::cout << "result: " << num1 + num2 << '\n';
        break;
    case '-':
        std::cout << "result: " << num1 - num2 << '\n';
        break;
    case '/':
        std::cout << "result: " << num1 / num2 << '\n';
        break;
    case '*':
        std::cout << "result: " << num1 + num2 << '\n';
        break;
    case '^':
        std::cout << "result: " << pow(num1,num2) << '\n';
        break;
    case 'r':
        std::cout << "Square root of "<< num1 << " : " << sqrt(num1) << " and " << num2 << " is "<< sqrt(num2) << '\n';
        break;
    default:
        std::cout << "You have entered an unauthorised character, exiting....";
        break;
    }
}