/*
 * Cody Price
 * Lab 5
 * COSC 1436 Fall 2025
 */

#include <iostream>
#include <string>
#include <cctype>

/// <summary>Represents a single stop on the trip.</summary>
struct Stop
{
    int x;  // X coordinate (-100 to 100)
    int y;  // Y coordinate (-100 to 100)
};

/// <summary>Displays program information.</summary>
void DisplayProgramInfo()
{
    std::cout << "Trip Planner" << std::endl;
    std::cout << "Cody Price" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl << std::endl;
}

/// <summary>Displays an error message.</summary>
void DisplayError(std::string const &message)
{
    std::cout << "ERROR: " << message << std::endl;
}

/// <summary>Prompts the user for confirmation (Y/N).</summary>
bool Confirm(std::string const &message)
{
    std::string input;

    std::cout << message << " (Y/N): ";
    std::cin >> input;

    while (true)
    {
        if (!input.empty())
        {
            char answer = static_cast<char>(toupper(input[0]));
            if (answer == 'Y') return true;
            if (answer == 'N') return false;
        }

        DisplayError("You must enter Y or N.");
        std::cout << message << " (Y/N): ";
        std::cin >> input;
    }
}

/// <summary>Displays the main menu and returns choice.</summary>
char GetMenuChoice()
{
    std::cout << "Main Menu" << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "A)dd Stop" << std::endl;
    std::cout << "V)iew Trip" << std::endl;
    std::cout << "R)emove Stop" << std::endl;
    std::cout << "C)lear Trip" << std::endl;
    std::cout << "Q)uit" << std::endl;
    std::cout << "Enter choice: ";

    std::string input;
    std::cin >> input;

    if (input.empty())
        return ' ';

    return static_cast<char>(toupper(input[0]));
}

/// <summary>Prompts the user for a valid stop and returns a pointer.</summary>
Stop* ReadStopCoordinates()
{
    int x = 0, y = 0;

    do
    {
        std::cout << "Enter X (-100 to 100): ";
        std::cin >> x;

        if (x < -100 || x > 100)
            DisplayError("X must be between -100 and 100.");
    } while (x < -100 || x > 100);

    do
    {
        std::cout << "Enter Y (-100 to 100): ";
        std::cin >> y;

        if (y < -100 || y > 100)
            DisplayError("Y must be between -100 and 100.");
    } while (y < -100 || y > 100);

    Stop* newStop = new Stop;
    newStop->x = x;
    newStop->y = y;

    return newStop;
}

/// <summary>Adds a stop to the trip list.</summary>
bool AddStopToTrip(Stop* trip[], int size, Stop* stop)
{
    for (int i = 0; i < size; ++i)
    {
        if (trip[i] == nullptr)
        {
            trip[i] = stop;
            return true;
        }
    }

    return false; // no space
}

/// <summary>Handles the Add Stop menu option.</summary>
void HandleAddStop(Stop* trip[], int size)
{
    Stop* newStop = ReadStopCoordinates();

    if (!AddStopToTrip(trip, size, newStop))
    {
        DisplayError("Trip is full. Stop cannot be added.");
        delete newStop;
    } else
    {
        std::cout << "Stop added successfully." << std::endl;
    }
}

/// <summary>Shows all stops in order.</summary>
void HandleViewTrip(Stop* trip[], int size)
{
    int count = 0;

    std::cout << "Stop   Location" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (int i = 0; i < size; ++i)
    {
        if (trip[i] == nullptr)
            break;

        count++;

        std::cout << count << "      ("
            << trip[i]->x << ", "
            << trip[i]->y << ")"
            << std::endl;
    }

    std::cout << "-------------------------" << std::endl;
    std::cout << "Total stops: " << count << std::endl;
}

/// <summary>Removes a stop from the trip (not implemented yet).</summary>
void HandleRemoveStop(Stop* trip[], int size)
{
    std::cout << "Remove Stop is not implemented yet." << std::endl;
}

/// <summary>Removes all stops from memory and clears the list.</summary>
void ClearTrip(Stop* trip[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (trip[i] != nullptr)
        {
            delete trip[i];
            trip[i] = nullptr;
        }
    }
}

/// <summary>Handles the Clear Trip menu option.</summary>
void HandleClearTrip(Stop* trip[], int size)
{
    if (Confirm("Are you sure you want to clear the trip?"))
    {
        ClearTrip(trip, size);
        std::cout << "Trip cleared." << std::endl;
    } else
    {
        std::cout << "Trip was not cleared." << std::endl;
    }
}

int main()
{
    DisplayProgramInfo();

    const int MaximumStops = 100;
    Stop* trip[MaximumStops] = {nullptr};

    bool done = false;

    while (!done)
    {
        char choice = GetMenuChoice();

        switch (choice)
        {
            case 'A': HandleAddStop(trip, MaximumStops); break;
            case 'V': HandleViewTrip(trip, MaximumStops); break;
            case 'R': HandleRemoveStop(trip, MaximumStops); break;
            case 'C': HandleClearTrip(trip, MaximumStops); break;

            case 'Q':
                if (Confirm("Are you sure you want to quit?"))
                    done = true;
                break;

            default:
                DisplayError("That value is invalid.");
                break;
        }

        std::cout << std::endl;
    }

    // Clean up any remaining stops before exiting
    ClearTrip(trip, MaximumStops);

    return 0;
}
