#include "System.h"
#include "Song.h"
#include "User.h"

void loginMenuBepefy(){

    int option = 0;
    int verify = 1;

    do{

        printf("\nELIGA UNA OPCION.\n");

        printf("\n1. Registrarse\n");
        printf("\n2. Login\n");
        printf("\n3. Salir\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

            case 49:

                ///register();
                break;

            case 50:

                /// verify = accVerify(stUser);

                if(verify == 0){

                    printf("No se encontro el usuario en el sistema.\n");
                }
                else if(verify == 1){

                    menuBepefy();
                }

                break;

            case 51:

                break;

            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }

    }while(option != 51);

    printf("\nFIN DEL PROGRAMA\n");
}

void menuBepefy(){


    int option=NULL;

    system("mode con: cols=81 lines=23");
    system("color F0");


//    gotoxy(2,6);
    printf("            ____     _____    ____    _____    _____   __     __                \n");
//    gotoxy(2,7);
    printf("           | __ )   | ____|  |  _ \\  | ____|  |  ___|  \\ \\   / /              \n");
//    gotoxy(2,8);
    printf("           |  _ \\   |  _|    | |_) | |  _|    | |_      \\ \\_/ /               \n");
//    gotoxy(2,9);
    printf("           | |_) |  | |___   |  __/  | |___   |  _|      \\   /                   \n");
//    gotoxy(2,10);
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

        fflush(stdin);
        option = getch();
        system("cls");



         switch (option)
         {
             case 49:
                menuUser();
                break;

            case 50:
                //void menuSongs();
                break;

            case 51:
                //void menuLibrary();
                break;

            case 52:
                break;

            default:
                printf("Opcion incorrecta.\n");
                Beep(750, 800);
                system("cls");
                break;
         }
    }while (option != 52);

    printf("FIN DE PROGRAMA");
    Beep(750, 800);

  }

void menuUser(){

    int flag = 0;
    int option = 0;

    while(1){

        printf("\nELIGA UNA OPCION.\n");

        printf("\n1. Dar de baja al usuario.\n");
        printf("\n2. Editar usuario.\n");
        printf("\n3. Mostrar datos del usuario.\n");
        printf("\n4. Volver al menu principal.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

            case 49:

                ///flag = delUser(stUser);
                break;

            case 50:

                ///menuEditUser();
                break;

            case 51:

                ///showUser(stUser);
                break;

            case 52:

                menuBepefy();
                break;

            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }
    }
}
