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

/// <summary>Displays all stops in the trip.</summary>
void HandleViewTrip(Stop* trip[], int size)
{
    int count = 0;

    std::cout << "Stop   Location" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (int i = 0; i < size; ++i)
    {
        if (trip[i] == nullptr)
            break;   // no more stops

        count++;

        std::cout << count << "      ("
            << trip[i]->x << ", " << trip[i]->y
            << ")" << std::endl;
    }

    std::cout << "-------------------------" << std::endl;
    std::cout << "Total stops: " << count << std::endl;
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

/// <summary>Prompts the user for valid stop coordinates.</summary>
/// <returns>A pointer to a new Stop with validated X/Y values.</returns>
Stop* ReadStopCoordinates()
{
    int x = 0, y = 0;

    // X coordinate
    do
    {
        std::cout << "Enter X (-100 to 100): ";
        std::cin >> x;

        if (x < -100 || x > 100)
            DisplayError("X must be between -100 and 100.");

    } while (x < -100 || x > 100);

    // Y coordinate
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

/// <summary>Adds a stop to the trip array.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="size">Size of the array.</param>
/// <param name="stop">Stop pointer to add.</param>
/// <returns>True if added successfully; false if trip is full.</returns>
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

    return false; // trip full
}

/// <summary>Handles the Add Stop menu option.</summary>
void HandleAddStop(Stop* trip[], int size)
{
    Stop* newStop = ReadStopCoordinates();

    if (!AddStopToTrip(trip, size, newStop))
    {
        DisplayError("Trip is full. Stop cannot be added.");
        delete newStop;  // clean up memory
    } else
    {
        std::cout << "Stop added successfully." << std::endl;
    }
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

