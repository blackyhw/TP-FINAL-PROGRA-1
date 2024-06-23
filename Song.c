#include "Song.h"


<<<<<<< HEAD
void menuPlaylist(User*User)
{
    int option;

    do
    {
        printf("\nSELECCIONE UNA OPCION.\n");

        printf("\n1. Ver mi playlist.\n");
        printf("\n2. Editar mi playlist.\n");
        printf("\n3. Volver al menu anterior.\n\n");
        fflush(stdin);
        option = getch();
        system("cls");

        switch(option)
        {

        case 49:
            voidShowPlaylist(user);
            break;

        case 50:
            editPlaylist(user);
            break;

        default:
            printf("Opcion invalida, por favor seleccione una opcion existente.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 51);

}
=======
>>>>>>> 0bfcbb21f40c191f38e4b5bac4c025eac5fa38e0
