#include <iostream>
using namespace std;

struct Tower;
struct Tower* CreateTower(std::string data);

void Push(Tower*& tower, string data);
std::string Pop(Tower*& tower);
bool IsTowerEmpty(Tower*& tower);
//void DebugMemory(Tower* tower);
