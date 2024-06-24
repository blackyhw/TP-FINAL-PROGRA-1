#include "Behaviour.h"


void gotoxy(int posX,int posY){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = posX;
    dwPos.Y = posY;
    SetConsoleCursorPosition(hcon,dwPos);
}
