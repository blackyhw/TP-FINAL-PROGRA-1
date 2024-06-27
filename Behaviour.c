#include "Behaviour.h"


void gotoxy(int posX,int posY){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = posX;
    dwPos.Y = posY;
    SetConsoleCursorPosition(hcon,dwPos);
}

void setConsoleBufferSize(int width, int height) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error al obtener el handle de la consola.\n");
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    if (!GetConsoleScreenBufferInfo(hOut, &bufferInfo)) {
        fprintf(stderr, "Error al obtener la información del buffer de la consola.\n");
        return;
    }

    COORD newSize;
    newSize.X = bufferInfo.dwSize.X; // Mantenemos el ancho actual
    newSize.Y = height;

    if (!SetConsoleScreenBufferSize(hOut, newSize)) {
        fprintf(stderr, "Error al establecer el tamaño del buffer de la consola.\n");
        return;
    }
}
void desactivarMaximizar()
{
    HWND consoleWindow;
    consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void ocultarCursor()
{
    printf("\e[?25l");
}
void mostrarCursor()
{
    printf("\e[?25h");
}
