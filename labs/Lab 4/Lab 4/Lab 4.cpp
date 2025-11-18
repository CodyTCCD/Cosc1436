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

    //Menu and additional features come later
    return 0;
}