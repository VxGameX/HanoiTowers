// IDS344-01 - 2022-01 - Grupo #1 - Linked List
//
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323
// Daniel Báez - 1073597

#include <iostream>
#include <string>

using namespace std;

// Checks if string is a number

/// <summary>
/// Checks if string is a number
/// </summary>
/// <param name="value">The string to check</param>
/// <returns>True if the value is a number, false if not</returns>
bool IsNumber(string value)
{
    for (int i = 0; i < value.length(); i++)
        if (isdigit(value[i]) == false)
            return false;

    return true;
}

/// <summary>
/// Closes the program
/// </summary>
void ExitProgram()
{
    exit(EXIT_SUCCESS);
}

/// <summary>
/// Clears the console
/// </summary>
/// <param name="textToShow">Text to show at the top of the console</param>
void ClearConsole(string textToShow)
{
    system("cls");
    cout << "-- " << textToShow << " --\n\n";
}

/// <summary>
/// Waits for a user to press some button
/// </summary>
void Pause()
{
    cout << "\n";
    system("pause");
}
