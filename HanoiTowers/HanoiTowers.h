// IDS344 - 2022-01 - Grupo 1 - Hanoi Towers
// 
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323
// Daniel Báez - 1073597

struct Tower;
struct Ring;

void Test(Tower*&, Ring*&);
void ClearAll(Ring*&, Tower*&);

void SetTowers(Tower*&, int);
void ShowTowers(Tower*&);

void SetRings(Ring*&, Tower*&, int);
void ShowRings(Ring*&);
void MoveRings(Ring*&);
