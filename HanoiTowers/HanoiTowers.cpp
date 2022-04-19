// IDS344 - 2022-01 - Grupo 1 - Hanoi Towers
//
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323
// Daniel Báez - 1073597

#include <iostream>
#include "HanoiTowers.h"
#include "GenericFunctions.h"

using namespace std;

const string programName = "Hanoi Towers";

int Play(int ring, int tower1, int tower2, int tower3)
{
    static int mov = 0;
    if (ring == 0)
        return mov;
    mov++;
    Play(ring - 1, tower1, tower3, tower2);
    cout << "Disc #" << ring << " from tower " << tower1 << " to tower " << tower3 << endl;
    Play(ring - 1, tower2, tower1, tower3);
}

int main()
{
    int option;
    int ringsNumber;

    ClearConsole(programName);

    cout << "Number of rings: ";
    cin >> ringsNumber;

    ClearConsole(programName);
    cout << "Movements: " << Play(ringsNumber, 1, 2, 3);

    Pause();
    ClearConsole(programName);

    cout << "Select an option: (1 - 2)" << endl;
    cout << "1- Set rings" << endl;
    cout << "2- Exit" << endl;

    cin >> option;

    switch (option)
    {
        case 1:
            main();
            break;
        case 2:
            ExitProgram();
            break;
        default:
            cout << "Select a valid option (1 - 2)";
            break;
    }
}
