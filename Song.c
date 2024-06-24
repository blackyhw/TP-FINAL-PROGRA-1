#include "Song.h"
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
    }

    return size;
}

void showLibrary(){
    Song aux;
    FILE*archi = fopen("Songs.bin","rb");

    if(archi){
        while(fread(&aux,sizeof(Song),1,archi)>0){
            printf("----------------------------------------\n");
            printf("Nombre de la cancion: %s\n",aux.name);
            printf("Genero: %s\n",aux.genre);
            printf("Anio: %d\n",aux.age);
            printf("Artista %s\n",aux.artist);
        }
    }
}
