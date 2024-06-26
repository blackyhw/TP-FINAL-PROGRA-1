#include "Song.h"
#define ELEMENTS_PER_PAGE 10
void archToArr(Song*librarySongs){
    int i = 0;
    FILE*archi = fopen("Songs.bin","rb");

    if(archi){

        while(fread(&librarySongs[i],sizeof(Song),1,archi)>0){
            i++;
        }
        fclose(archi);
    }
}

int amountSongs(){
    int size = 0;
    FILE*archi = fopen("Songs.bin","rb");

    if(archi){
        fseek(archi,0,SEEK_END);
        size = ftell(archi);
        fclose(archi);
    }

    return size;
}

void showLibrary(){
    char option = NULL;
    int j = 1;
    int max = amountSongs()/sizeof(Song);
    Song listSong[500];
    archToArr(listSong);

    for(int i= 0;i<max;i++){
        printf("----------------------------------------\n");
        printf("|Nombre de la cancion: %s\n",listSong[i].name);
        printf("|Artista: %s\n",listSong[i].artist);
        printf("|Anio: %d\n",listSong[i].age);
        printf("|Genero: %s\n",listSong[i].genre);

        if((i+1) % ELEMENTS_PER_PAGE == 0){
            gotoxy(53,52);
            printf("<-----Pagina %d----->",j);
            option = getch();

            if(option == 13){
                system("cls");
                j++;

            }else if(option == 8){
                system("cls");
                j--;
                i-=20;
                printf("%d",i);
                if (i < 0) i = 0;
            }
        }
        printf("");

    }

}


