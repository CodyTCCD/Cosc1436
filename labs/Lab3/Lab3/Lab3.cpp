/*
* Cody Price
* Lab 3
* COSC 1436 Fall 2025
*/

#include <iostream>
#include <iomanip>
#include <string>

/// <summary>Displays program information.</summary>
void DisplayProgramInfo()
{
    std::cout << "Falling Distance Calculator" << std::endl;
    std::cout << "Cody Price" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl << std::endl;
}

/// <summary>Prompts the user for the falling time (1-60 seconds).</summary>
/// <returns>The time in seconds.</returns>
int ReadFallingTime()
{
    int time = 0;

    //Prompt user for time and validate range
    do
    {
        std::cout << "Please enter the number of seconds (1 - 60): ";
        std::cin >> time;

        if (time < 1 || time > 60)
        {
            std::cout << "That value is invalid." << std::endl;
        }
    } while (time < 1 || time > 60);

    return time;
}

/// <summary>Calculates the falling distance for a given time in seconds.</summary>
/// <param name="time">The time in seconds.</param>
/// <returns>The distance in meters.</returns>
double CalculateFallingDistance(int time)
{
    const double gravity = 9.8;
    double distance = 0.5 * gravity * (time * time);
    return distance;
}

/// <summary>Converts meters to feet.</summary>
/// <param name="meters">The distance in meters.</param>
/// <returns>The distance in feet.</returns>
double ConvertMetersToFeet(double meters)
{
    double feet = meters * 3.281;
    return feet;
}

/// <summary>Prompts the user to select units (meters or feet).</summary>
/// <returns>'m' for meters or 'f' for feet.</returns>
char GetUnitSelection()
{
    std::string input;
    char unit = 'm';

    //Prompt user for unit choice and validate input
    do
    {
        std::cout << "Do you want the results in meters or feet? (m/f): ";
        std::cin >> input;

        if (input.length() > 0)
        {
            unit = tolower(input[0]);
        }

        if (unit != 'm' && unit != 'f')
        {
            std::cout << "That value is invalid." << std::endl;
        }

    } while (unit != 'm' && unit != 'f');

    return unit;
}

/// <summary>Displays a formatted table of falling distances.</summary>
void DisplayResults(int time, char unit)
{
    //Arrays for seconds, distances, and converted distances
    int seconds[60];
    double distances[60];
    double convertedDistances[60];

    //Display header
    std::cout << std::endl;
    std::cout << "Seconds      Distance" << std::endl;
    std::cout << "=====================" << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    //Loop through each second and calculate distances
    for (int index = 0; index < time; index = index + 1)
    {
        seconds[index] = index + 1;
        distances[index] = CalculateFallingDistance(seconds[index]);

        if (unit == 'f')
        {
            convertedDistances[index] = ConvertMetersToFeet(distances[index]);
        } else
        {
            convertedDistances[index] = distances[index];
        }

        //Display each row
        std::cout << std::setw(4) << seconds[index]
            << std::setw(14) << convertedDistances[index];

        if (unit == 'm')
        {
            std::cout << " m";
        } else
        {
            std::cout << " ft";
        }

        std::cout << std::endl;
    }
}

int main()
{
    //Variables
    int time = 0;
    char unit = 'm';

    //Story 1 - Display program information
    DisplayProgramInfo();

    //Story 2 - Get falling time from user
    time = ReadFallingTime();

    //Story 5 - Ask user for desired units
    unit = GetUnitSelection();

    //Story 3 & 4 - Calculate and display distances
    DisplayResults(time, unit);

    return 0;
}
