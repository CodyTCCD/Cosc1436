/*
 * Cody Price
 * Lab 4
 * COSC 1436 Fall 2025
 */

#include <iostream>
#include <iomanip>
#include <string>

/// <summary>Displays program information.</summary>
void DisplayProgramInfo()
{
    std::cout << "Array Statistics Calculator" << std::endl;
    std::cout << "Cody Price" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl << std::endl;
}

/// <summary>Prompts the user to enter values into the array.</summary>
/// <param name="values">Array to store values.</param>
/// <param name="size">Maximum size allowed.</param>
/// <returns>The number of valid values entered.</returns>
int ReadInitialValues(int values[], int size)
{
    int count = 0;

    while (count < size)
    {
        std::cout << "Enter a value: ";

        int input;
        std::cin >> input;

        if (input == 0)
        {
            //Stop entering values
            break;
        } else if (input < 0)
        {
            std::cout << "You must enter a value greater than or equal to 0" << std::endl;
        } else
        {
            values[count] = input;
            count = count + 1;   //no ++ operator
        }
    }

    return count;
}

/// <summary>Displays the main menu and returns the user's selection.</summary>
/// <returns>The menu choice entered by the user.</returns>
char DisplayMenu()
{
    std::cout << std::endl;
    std::cout << "Main Menu" << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << "L)argest" << std::endl;
    std::cout << "S)mallest" << std::endl;
    std::cout << "U)m (sum)" << std::endl;
    std::cout << "M)ean" << std::endl;
    std::cout << "V)iew Values" << std::endl;
    std::cout << "I)nsert Values" << std::endl;
    std::cout << "Q)uit" << std::endl;
    std::cout << "Enter choice: ";

    char choice;
    std::cin >> choice;

    return choice;
}

int main()
{
    const int MaximumValues = 100;

    //Array to store user values
    int values[MaximumValues] = {0};

    //Number of valid values entered
    int valueCount = 0;

    //Display program information
    DisplayProgramInfo();

    //Prompt user for initial values
    valueCount = ReadInitialValues(values, MaximumValues);

    //Menu loop
    bool done = false;
    while (!done)
    {
        char choice = DisplayMenu();

        switch (choice)
        {
            case 'L':
            case 'l':
                std::cout << "You selected largest." << std::endl;
                break;

            case 'S':
            case 's':
                std::cout << "You selected smallest." << std::endl;
                break;

            case 'U':
            case 'u':
                std::cout << "You selected sum." << std::endl;
                break;

            case 'M':
            case 'm':
                std::cout << "You selected mean." << std::endl;
                break;

            case 'V':
            case 'v':
                std::cout << "You selected view values." << std::endl;
                break;

            case 'I':
            case 'i':
                std::cout << "You selected insert values." << std::endl;
                break;

            case 'Q':
            case 'q':
                done = true;
                break;

            default:
                std::cout << "That value is invalid." << std::endl;
                break;
        }
    }

    return 0;
}