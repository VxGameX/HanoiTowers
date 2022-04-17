// IDS344 - 2022-01 - Grupo 1 - Hanoi Towers
// 
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323
// Daniel Báez - 1073597

#include <iostream>

#include "GenericFunctions.h"
//#include "TowerManager.h"
#include "TowerStruct.h"

using namespace std;

const string programName = "Tower Manager";

Tower* tower = NULL; //definir el Tower globalmente para tener acceso desde cada función
bool runTowerManager;

void StartTowerManager()
{
    runTowerManager = true;
    
    ClearConsole(programName);

    cout << "- NOTE:\n";
    cout << "This program uses string data type to store given values.\n";
    cout << "This program follows general towers general rules.\n\n";

    Pause();
    ClearConsole(programName);

    cout << "Welcome!\n\n";

    while (runTowerManager)
    {
        DisplayTowerMenu();
    }
}

/// <summary>
/// Displays program menu
/// </summary>
void DisplayTowerMenu()
{
    string menuOptionString;
    int menuOption;

    cout << "Select an option. (1 - 4)\n";
    cout << "1. Add\n";
    cout << "2. Remove\n";
    cout << "3. Display all\n";
    cout << "4. Exit\n\n";
    cout << ">> ";

    cin >> menuOptionString;

    menuOption = IsNumber(menuOptionString) ? stoi(menuOptionString) : 0;

    switch (menuOption)
    {
        case 1:
            AddToTower();
            break;
        case 2:
            RemoveFromTower();
            break;
        case 3:
            DisplayTower();
            break;
        case 4:
            runTowerManager = false;
            break;
        default:
            cout << "Please, enter a valid option. (1 - 4)\n";
            Pause();
            break;
    }

    ClearConsole(programName);
}

/// <summary>
/// Adds a value to tower
/// </summary>
void AddToTower()
{
    string value;

    ClearConsole(programName);

    cout << "Enter the value: ";
    cin >> value;

    Push(tower, value);    
}

/// <summary>
/// Removes tower's top value
/// </summary>
void RemoveFromTower()
{
    ClearConsole(programName);

    IsTowerEmpty(tower) ? cout << "Tower is currently empty.\n" : cout << Pop(tower) << " removed.\n";
    Pause();
}

/// <summary>
/// Shows all the tower's values
/// </summary>
void DisplayTower()
{
    ClearConsole(programName);

    if (IsTowerEmpty(tower)) cout << "Tower is currently empty.\n";
    else
    {
        cout << "- TOP -\n";

        while (!IsTowerEmpty(tower)) cout << Pop(tower) << "\n";

        cout << "- BOTTOM -\n";
    }

    Pause();
}
