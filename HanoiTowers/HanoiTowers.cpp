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

struct Ring
{
	int size;
	int tower;

    Ring* below;
};

int main()
{
    Ring* ring = NULL;

    int option;
    int ringsNumber;

    ClearConsole(programName);

    cout << "Number of rings: ";

    cin >> ringsNumber;

    ClearConsole(programName);
    SetRings(ring, ringsNumber);
    ShowRings(ring);

    Pause();
    ClearConsole(programName);

    MoveRings(ring);
    ShowRings(ring);

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

void SetRings(Ring*& ring, int ringsNumber)
{
    Ring* newRing = new Ring();

    newRing->size = ringsNumber;
    newRing->tower = 2;

    newRing->below = ring;

    ring = newRing;

    if (ringsNumber > 1)
        SetRings(ring, ringsNumber - 1);
}

void ShowRings(Ring*& ring)
{
    Ring* aux = ring;

    cout << "Ring size: " << aux->size << "; Tower # " << aux->tower << endl;
    aux = aux->below;

    if (aux != NULL)
        ShowRings(aux);
}

void MoveRings(Ring*& ring)
{
    Ring* aux = ring;

    if (aux != NULL)
    {

        ring->tower;
    }

    MoveRings(aux);
}

//Ring Pop(StackNode*& stack)
//{
//    StackNode* aux = stack;
//    Ring ring;
//
//    if (aux != NULL)
//    {
//        ring = aux->ring;
//        stack = aux->next;
//
//        delete aux;
//    }
//    return ring;
//}




































//struct StackNode
//{
//    Ring ring;
//    StackNode* next = NULL;
//};
//
//StackNode* CreateStackNode(Ring ring)
//{
//    StackNode* newNode = new StackNode;
//
//    newNode->ring = ring;
//    newNode->next = NULL;
//
//    return newNode;
//}
//
//// se agrega un StackNode
//void Push(StackNode*& stack, Ring ring)
//{
//    StackNode* newNode = CreateStackNode(ring);
//
//    newNode->next = stack;
//
//    stack = newNode;
//}
//
//// se elimina un StackNode
//Ring Pop(StackNode*& stack)
//{
//    StackNode* aux = stack;
//    Ring ring;
//
//    if (aux != NULL)
//    {
//        ring = aux->ring;
//        stack = aux->next;
//
//        delete aux;
//    }
//    return ring;
//}
//
//// vaciar el stack
//bool IsStackEmpty(StackNode*& stack)
//{
//    bool answer = false;
//
//    if (stack == NULL) answer = true;
//    return answer;
//}
