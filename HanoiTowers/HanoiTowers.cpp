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

    Ring* above;
    Ring* below;

	Tower* tower;
};

struct Tower
{
    int number;

    Tower* prev;
    Tower* next;

    Ring* topRing;
};

int main()
{
    Ring* ring = NULL;
    Tower* tower = NULL;

    int option;
    int ringsNumber;

    //Test(tower, ring);

    ClearConsole(programName);

    cout << "Number of rings: ";
    cin >> ringsNumber;

    ClearConsole(programName);

    SetTowers(tower, 3);
    SetRings(ring, tower, ringsNumber);
    SetTowers(tower, 3);

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

void SetTowers(Tower*& tower, int towerNumber)
{
    Tower* newTower = new Tower();

    newTower->number = towerNumber;

    newTower->prev = NULL;
    newTower->next = tower;

    if (tower != NULL)
        tower->prev = newTower;
    tower = newTower;

    if (towerNumber > 1)
        SetTowers(tower, towerNumber - 1);
}

void ShowTowers(Tower*& tower)
{
    Tower* aux = tower;

    if (aux->topRing != NULL)
    {
        if (aux->prev == NULL)
            cout << "Tower # " << aux->number << "; Top ring: " << aux->topRing->size << "; Prev tower: N/A " << "; Next Tower: " << aux->next->number << endl;
        else if (aux->next == NULL)
            cout << "Tower # " << aux->number << "; Top ring: " << aux->topRing->size << "; Prev tower: " << aux->prev->number << "; Next Tower: N/A" << endl;
        else
            cout << "Tower # " << aux->number << "; Top ring: " << aux->topRing->size << "; Prev tower: " << aux->prev->number << "; Next Tower: " << aux->next->number << endl;
    }
    else
    {
        if (aux->prev == NULL)
            cout << "Tower # " << aux->number << "; Top ring: N/A" << "; Prev tower: N/A " << "; Next Tower: " << aux->next->number << endl;
        else if (aux->next == NULL)
            cout << "Tower # " << aux->number << "; Top ring: N/A" << "; Prev tower: " << aux->prev->number << "; Next Tower: N/A" << endl;
        else
            cout << "Tower # " << aux->number << "; Top ring: N/A" << "; Prev tower: " << aux->prev->number << "; Next Tower: " << aux->next->number << endl;
    }
    aux = aux->next;

    if (aux != NULL)
        ShowTowers(aux);
}

void SetRings(Ring*& ring, Tower*& tower, int ringsNumber)
{
    Ring* newRing = new Ring();

    newRing->size = ringsNumber;
    newRing->tower = tower;

    newRing->above = NULL;
    newRing->below = ring;

    if (ring != NULL)
        ring->above = newRing;
    ring = newRing;

    if (ringsNumber > 1)
        SetRings(ring, tower, ringsNumber - 1);

    tower->topRing = ring;
}

void ShowRings(Ring*& ring)
{
    Ring* aux = ring;

    if (aux->above == NULL)
        cout << "Ring size: " << aux->size << "; Tower # " << aux->tower->number << "; Above: N/A" << "; Below: " << aux->below->size << endl;
    else if (aux->below == NULL)
        cout << "Ring size: " << aux->size << "; Tower # " << aux->tower->number << "; Above: " << aux->above->size << "; Below: N/A" << endl;
    else
        cout << "Ring size: " << aux->size << "; Tower # " << aux->tower->number << "; Above: " << aux->above->size << "; Below: " << aux->below->size << endl;

    aux = aux->below;

    if (aux != NULL)
        ShowRings(aux);
}

//void MoveRings(Ring*& ring)
//{
//    if ((ring != NULL) && (ring->above == NULL))
//    {
//        if ((ring->tower->next != NULL) && (ring->tower->next->topRing->size > ring->size))
//        {
//            ring->tower = ring->tower->next;
//        }
//        ring->tower;
//    }
//
//    MoveRings(ring);
//}

void MoveRings(Ring*& ring)
{
    Ring* aux = ring;

    if ((aux != NULL) && (aux->above == NULL))
    {
        if (aux->tower->next != NULL)
        {
            if (aux->tower->next->topRing != NULL)
            {
                if (aux->tower->next->topRing->size > aux->size)
                {
                    aux->tower = aux->tower->next;
                    aux->below = aux->tower->topRing;
                    aux->tower->topRing = aux;
                }
                else
                    MoveRings(aux);
            }
            else
            {
                aux->tower = aux->tower->next;
                aux->below = aux->tower->topRing;
                aux->tower->topRing = aux;
            }
        }
        else
        {
            if (aux->tower->prev->topRing != NULL)
            {
                if (aux->tower->prev->topRing->size > aux->size)
                {
                    aux->tower = aux->tower->prev;
                    aux->below = aux->tower->topRing;
                    aux->tower->topRing = aux;
                }
                else
                    MoveRings(aux);
            }
        }

        ring = aux;

                MoveRings(ring);
        while (aux != NULL)
        {
            if (aux->tower->number == 1)
            aux = aux->below;
        }
    }
}

void Test(Tower*& tower, Ring*& ring)
{
    ClearConsole(programName);

    cout << "-- TOWER TESTING --" << endl;

    SetTowers(tower, 3);
    ShowTowers(tower);

    cout << "-- END TOWER TESTING --" << endl;

    Pause();
    ClearConsole(programName);

    SetRings(ring, tower, 5);

    cout << "-- RING TESTING --" << endl;

    ShowRings(ring);

    cout << "-- END RING TESTING --" << endl;

    Pause();

    ClearConsole(programName);

    cout << "-- TOWER TESTING --" << endl;

    ShowTowers(tower);

    cout << "-- END TOWER TESTING --" << endl;

    Pause();

    ClearAll(ring, tower);
}

void ClearAll(Ring*& ring, Tower*& tower)
{
    Ring* aux1 = ring;
    Tower* aux2 = tower;

    if (aux1 == NULL && aux2 == NULL)
        return;

    if (aux1 != NULL)
    {
        ring = aux1->below;

        delete aux1;
    }
    if (aux2 != NULL)
    {
        tower = aux2->next;

        delete aux2;
    }

    ClearAll(ring, tower);
}

































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
