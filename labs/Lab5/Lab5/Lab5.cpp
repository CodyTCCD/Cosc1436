/*
 * Cody Price
 * Lab 5
 * COSC 1436 Fall 2025
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

/// <summary>Represents a single stop on the trip.</summary>
struct Stop
{
    int x;
    int y;
};

/// <summary>Displays program information.</summary>
void DisplayProgramInfo()
{
    std::cout << "Trip Planner" << std::endl;
    std::cout << "Cody Price" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl << std::endl;
}

/// <summary>Displays an error message.</summary>
void DisplayError(std::string const& message)
{
    std::cout << "ERROR: " << message << std::endl;
}

/// <summary>Prompts for confirmation.</summary>
bool Confirm(std::string const& message)
{
    std::string input;

    std::cout << message << " (Y/N): ";
    std::cin >> input;

    while (true)
    {
        if (!input.empty())
        {
            char c = static_cast<char>(toupper(input[0]));
            if (c == 'Y') return true;
            if (c == 'N') return false;
        }

        DisplayError("You must enter Y or N.");
        std::cout << message << " (Y/N): ";
        std::cin >> input;
    }
}

/// <summary>Displays the menu and returns the choice.</summary>
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

/// <summary>Prompts for a valid stop coordinate.</summary>
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

    Stop* s = new Stop;
    s->x = x;
    s->y = y;

    return s;
}

/// <summary>Adds a stop to the trip.</summary>
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
    return false;
}

/// <summary>Handles adding a stop.</summary>
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

/// <summary>Finds the stop pointer based on stop number (1-based).</summary>
Stop* GetStopByNumber(Stop* trip[], int size, int number)
{
    if (number < 1)
        return nullptr;

    int index = number - 1;

    if (index >= size || trip[index] == nullptr)
        return nullptr;

    return trip[index];
}

/// <summary>Removes a stop and shifts remaining stops up.</summary>
void RemoveStop(Stop* trip[], int size, int number)
{
    int index = number - 1;

    if (index < 0 || index >= size || trip[index] == nullptr)
        return;

    delete trip[index];
    trip[index] = nullptr;

    // shift remaining stops up
    int newIndex = index;

    for (int i = index + 1; i < size; ++i)
    {
        trip[newIndex] = trip[i];
        trip[i] = nullptr;
        newIndex++;

        if (trip[newIndex - 1] == nullptr)
            break;
    }
}

/// <summary>Handles removing a stop.</summary>
void HandleRemoveStop(Stop* trip[], int size)
{
    int number = 0;

    std::cout << "Enter stop number to remove: ";
    std::cin >> number;

    if (number < 1)
    {
        DisplayError("Stop number must be 1 or higher.");
        return;
    }

    Stop* s = GetStopByNumber(trip, size, number);

    if (s == nullptr)
    {
        DisplayError("Stop not found.");
        return;
    }

    RemoveStop(trip, size, number);
    std::cout << "Stop removed." << std::endl;
}

/// <summary>Deletes all stops and clears array.</summary>
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

/// <summary>Handles clearing the trip.</summary>
void HandleClearTrip(Stop* trip[], int size)
{
    if (Confirm("Are you sure you want to clear the trip?"))
    {
        ClearTrip(trip, size);
        std::cout << "Trip cleared." << std::endl;
    } else
    {
        std::cout << "Trip not cleared." << std::endl;
    }
}

/// <summary>Prompts the user for travel speed.</summary>
int GetTravelSpeed()
{
    int speed = 0;

    do
    {
        std::cout << "Enter your travel speed (1 - 60 mph): ";
        std::cin >> speed;

        if (speed < 1 || speed > 60)
            DisplayError("Speed must be between 1 and 60.");
    } while (speed < 1 || speed > 60);

    return speed;
}

/// <summary>Calculates the distance between two points.</summary>
double CalculateDistance(Stop* a, Stop* b)
{
    double dx = static_cast<double>(b->x - a->x);
    double dy = static_cast<double>(b->y - a->y);

    return std::sqrt(dx * dx + dy * dy);
}

/// <summary>Handles viewing the trip with distances and times.</summary>
void HandleViewTrip(Stop* trip[], int size, int speed)
{
    int count = 0;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Stop   Location       Distance (miles)   Time (minutes)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    double totalDistance = 0.0;
    int totalMinutes = 0;

    Stop origin = {0, 0}; // first point

    Stop* prev = &origin;

    for (int i = 0; i < size; ++i)
    {
        if (trip[i] == nullptr)
            break;

        count++;

        double distance = CalculateDistance(prev, trip[i]);
        totalDistance += distance;

        double hours = distance / speed;
        double minutes = hours * 60.0;

        int roundedMinutes = static_cast<int>(std::ceil(minutes));
        totalMinutes += roundedMinutes;

        std::cout << count << "      ("
            << trip[i]->x << ", " << trip[i]->y << ")"
            << "        " << distance
            << "              " << roundedMinutes
            << std::endl;

        prev = trip[i];
    }

    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << count << " stops   ";
    std::cout << totalDistance << " miles   ";
    std::cout << totalMinutes << " minutes" << std::endl;
}

int main()
{
    DisplayProgramInfo();

    const int MaximumStops = 100;
    Stop* trip[MaximumStops] = {nullptr};

    int speed = GetTravelSpeed();

    bool done = false;

    while (!done)
    {
        char choice = GetMenuChoice();

        switch (choice)
        {
            case 'A': HandleAddStop(trip, MaximumStops); break;
            case 'V': HandleViewTrip(trip, MaximumStops, speed); break;
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

    ClearTrip(trip, MaximumStops);
    return 0;
}
