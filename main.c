#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void menuBepefy();
void  desactivarMaximizar();
int main()
{

barraCarga(0,76,2);
menuBepefy ();


    return 0;
}
  void menuBepefy(){



    desactivarMaximizar();
    system("mode con: cols=81 lines=23");
    system("color F0");
   dibujarCuadro(2,5,78,11);
    char opcion = 0;
    gotoxy(2,6);
    printf("            ____     _____    ____    _____    _____   __     __                \n");
    gotoxy(2,7);
    printf("           | __ )   | ____|  |  _ \\  | ____|  |  ___|  \\ \\   / /              \n");
    gotoxy(2,8);
    printf("           |  _ \\   |  _|    | |_) | |  _|    | |_      \\ \\_/ /               \n");
    gotoxy(2,9);
    printf("           | |_) |  | |___   |  __/  | |___   |  _|      \\   /                   \n");
    gotoxy(2,10);
    printf("           |____/   |_____|  |_|     |_____|  |_|         |_|                    \n");




   do {


    printf ("\n\n\n\n\n\n");
    printf("                 _____________________________________________\n");
    printf("                |       ELIGE UNA OPCION PARA CONTINUAR       |\n");
    printf("                |_____________________________________________|\n");
    printf("                | 1. Usuario                                  |\n");
    printf("                | 2. Canciones                                |\n");
    printf("                | 3. Biblioteca                               |\n");
    printf("                | 4. Salir                                    |\n");
    printf("                |_____________________________________________|\n");




         system("cls");



         switch (opcion)
         {
             case 1:
                // void menuUser();
                break;

            case 2:
                //void menuSongs();
                break;

            case 3:
                //void menuLibrary();
                break;

            case 4:
                break;

            default:
                printf("Opcion incorrecta.\n");
                Beep(750, 800);
                break;
         }
    }while (opcion != 4);

    printf("FIN DE PROGRAMA");
    Beep(750, 800);

  }
  void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");
}
void desactivarMaximizar()
{
    HWND consoleWindow;
    consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}


void barraCarga(int bordeIzq, int bordeDer, int fila)
{
    int i;

    system("color F0");
    system("mode con: cols=79 lines=6");

    for(i=bordeIzq;i<=bordeDer;i++)
    {
        gotoxy(i,fila); printf("%c", 177);
    }

    for(i=bordeIzq;i<=bordeDer;i++)
    {
        gotoxy(i,fila); printf("%c", 219);
        Sleep(1);
    }

    gotoxy(120,58); printf("                                                ");
    gotoxy(15,60); printf("                                                                                                                                                                                                                                                                              ");
    ocultarCursor();
}

void ocultarCursor()
{
    printf("\e[?25l");
}


