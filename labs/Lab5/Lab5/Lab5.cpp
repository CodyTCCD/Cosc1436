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
/// <param name="message">Message to display.</param>
void DisplayError(std::string const &message)
{
    std::cout << "ERROR: " << message << std::endl;
}

/// <summary>Prompts the user for confirmation.</summary>
/// <param name="message">Message to display.</param>
/// <returns>True if the user confirms, otherwise false.</returns>
bool Confirm(std::string const &message)
{
    std::string input;

    std::cout << message << " (Y/N): ";
    std::cin >> input;

    while (true)
    {
        if (!input.empty())
        {
            char answer = static_cast<char>(std::toupper(input[0]));

            if (answer == 'Y')
                return true;

            if (answer == 'N')
                return false;
        }

        DisplayError("You must enter Y or N.");

        std::cout << message << " (Y/N): ";
        std::cin >> input;
    }
}

/// <summary>Displays the main menu and returns the user's choice.</summary>
/// <returns>The menu option selected by the user.</returns>
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

    char choice = static_cast<char>(std::toupper(input[0]));
    return choice;
}

/// <summary>Handles the "add stop" menu option (not yet implemented).</summary>
void HandleAddStop(Stop *trip[], int size)
{
    std::cout << "Add Stop is not implemented yet." << std::endl;
    // Future stories will add the real logic here.
}

/// <summary>Handles the "view trip" menu option (not yet implemented).</summary>
void HandleViewTrip(Stop *trip[], int size)
{
    std::cout << "View Trip is not implemented yet." << std::endl;
    // Future stories will add the real logic here.
}

/// <summary>Handles the "remove stop" menu option (not yet implemented).</summary>
void HandleRemoveStop(Stop *trip[], int size)
{
    std::cout << "Remove Stop is not implemented yet." << std::endl;
    // Future stories will add the real logic here.
}

/// <summary>Handles the "clear trip" menu option (not yet implemented).</summary>
void HandleClearTrip(Stop *trip[], int size)
{
    std::cout << "Clear Trip is not implemented yet." << std::endl;
    // Future stories will add the real logic here.
}

int main()
{
    // Story 1 – program info
    DisplayProgramInfo();

    // Story 3 – create trip array using pointers
    const int MaximumStops = 100;
    Stop *trip[MaximumStops] = {nullptr};

    bool done = false;

    // Story 2 – main menu loop with quit confirmation
    while (!done)
    {
        char choice = GetMenuChoice();

        switch (choice)
        {
            case 'A':
                HandleAddStop(trip, MaximumStops);
                break;

            case 'V':
                HandleViewTrip(trip, MaximumStops);
                break;

            case 'R':
                HandleRemoveStop(trip, MaximumStops);
                break;

            case 'C':
                HandleClearTrip(trip, MaximumStops);
                break;

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

    // Later, when stops are dynamically allocated, this is where
    // they will be cleaned up before the program ends.

    return 0;
}

