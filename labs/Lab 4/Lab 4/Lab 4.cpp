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

/// <summary>Prompts the user to enter initial values.</summary>
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
            break;
        else if (input < 0)
            std::cout << "You must enter a value greater than or equal to 0" << std::endl;
        else
        {
            values[count] = input;
            count = count + 1;
        }
    }

    return count;
}

/// <summary>Displays the main menu.</summary>
/// <returns>User’s menu choice.</returns>
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

/// <summary>Gets the largest value.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Number of valid values.</param>
/// <returns>The largest value.</returns>
int GetLargestValue(int values[], int count)
{
    if (count <= 0)
        return 0;

    int largest = values[0];
    int index = 1;

    while (index < count)
    {
        if (values[index] > largest)
            largest = values[index];

        index = index + 1;
    }

    return largest;
}

/// <summary>Gets the smallest value.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Number of valid values.</param>
/// <returns>The smallest value.</returns>
int GetSmallestValue(int values[], int count)
{
    if (count <= 0)
        return 0;

    int smallest = values[0];
    int index = 1;

    while (index < count)
    {
        if (values[index] < smallest)
            smallest = values[index];

        index = index + 1;
    }

    return smallest;
}

/// <summary>Gets the sum of the values.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Number of valid values.</param>
/// <returns>The sum of the values.</returns>
int GetSum(int values[], int count)
{
    int sum = 0;
    int index = 0;

    while (index < count)
    {
        sum = sum + values[index];
        index = index + 1;
    }

    return sum;
}

/// <summary>Gets the mean value.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Number of valid values.</param>
/// <returns>The mean as a double.</returns>
double GetMean(int values[], int count)
{
    if (count <= 0)
        return 0.0;

    int sum = GetSum(values, count);
    double mean = static_cast<double>(sum) / count;
    return mean;
}

/// <summary>Displays the values.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Number of valid values.</param>
void DisplayValues(int values[], int count)
{
    if (count <= 0)
    {
        std::cout << "No values have been entered." << std::endl;
        return;
    }

    int index = 0;

    while (index < count)
    {
        std::cout << std::setw(6) << values[index];

        if ((index + 1) % 10 == 0)
            std::cout << std::endl;

        index = index + 1;
    }

    std::cout << std::endl;
}

/// <summary>Inserts additional values.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Reference to number of valid values.</param>
/// <param name="size">Maximum size allowed.</param>
void InsertValues(int values[], int& count, int size)
{
    while (count < size)
    {
        std::cout << "Enter a value: ";

        int input;
        std::cin >> input;

        if (input == 0)
            break;
        else if (input < 0)
            std::cout << "You must enter a value greater than or equal to 0" << std::endl;
        else
        {
            values[count] = input;
            count = count + 1;
        }
    }

    if (count >= size)
        std::cout << "Array is full, cannot insert more values." << std::endl;
}

int main()
{
    const int MaximumValues = 100;
    int values[MaximumValues] = {0};
    int valueCount = 0;

    DisplayProgramInfo();

    valueCount = ReadInitialValues(values, MaximumValues);

    bool done = false;

    while (!done)
    {
        char choice = DisplayMenu();

        switch (choice)
        {
            case 'L':
            case 'l':
                if (valueCount <= 0)
                    std::cout << "No values have been entered." << std::endl;
                else
                    std::cout << "Largest = " << GetLargestValue(values, valueCount) << std::endl;
                break;

            case 'S':
            case 's':
                if (valueCount <= 0)
                    std::cout << "No values have been entered." << std::endl;
                else
                    std::cout << "Smallest = " << GetSmallestValue(values, valueCount) << std::endl;
                break;

            case 'U':
            case 'u':
                if (valueCount <= 0)
                    std::cout << "No values have been entered." << std::endl;
                else
                    std::cout << "Sum = " << GetSum(values, valueCount) << std::endl;
                break;

            case 'M':
            case 'm':
                if (valueCount <= 0)
                    std::cout << "No values have been entered." << std::endl;
                else
                {
                    std::cout << std::fixed << std::setprecision(4);
                    std::cout << "Mean = " << GetMean(values, valueCount) << std::endl;
                }
                break;

            case 'V':
            case 'v':
                DisplayValues(values, valueCount);
                break;

            case 'I':
            case 'i':
                InsertValues(values, valueCount, MaximumValues);
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
