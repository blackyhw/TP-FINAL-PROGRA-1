#include "Song.h"
#define ELEMENTS_PER_PAGE 10
int archToArr(Song*librarySongs){
    int i = 0;
    FILE*archi = fopen("Songs.bin","rb");

    if(archi){

        while(fread(&librarySongs[i],sizeof(Song),1,archi)>0){
            i++;
        }
        fclose(archi);
    }

    return i;
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

int searchSongAtoZ(Song listSong[], int numberOfSong, int pos){

    Song aux;

    int i = pos + 1;
    aux = listSong[pos];

    while(i < numberOfSong){

        if(strcmpi(aux.name, listSong[i].name) > 0){

            aux = listSong[i];
            pos = i;
        }

        i++;
    }

    return pos;
}

void orderArrayAtoZ(Song listSong[], int numberOfSongs){

    int i = 0;
    int pos = 0;
    Song aux;

    while(i < numberOfSongs){

        pos = searchSongAtoZ(listSong, numberOfSongs, i);

        aux = listSong[i];
        listSong[i] = listSong[pos];
        listSong[pos] = aux;

        i++;
    }
}

void showLibraryAtoZ(){
    char option = NULL;
    int j = 1;
    int max = amountSongs()/sizeof(Song);

    Song listSongAtoZ[500];
    int validos = 500;
    int numberOfSongs = archToArr(listSongAtoZ);

    orderArrayAtoZ(listSongAtoZ, numberOfSongs);

    for(int i= 0;i<max;i++){
        printf("----------------------------------------\n");
        printf("|Nombre de la cancion: %s\n",listSongAtoZ[i].name);
        printf("|Artista: %s\n",listSongAtoZ[i].artist);
        printf("|Anio: %d\n",listSongAtoZ[i].age);
        printf("|Genero: %s\n",listSongAtoZ[i].genre);

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
    }
}

int searchSongGenre(Song listSong[], int numberOfSong, int pos){

    Song aux;

    int i = pos + 1;
    aux = listSong[pos];

    while(i < numberOfSong){

        if(strcmpi(aux.genre, listSong[i].genre) > 0){

            aux = listSong[i];
            pos = i;
        }

        i++;
    }

    return pos;
}

void orderArrayGenre(Song listSong[], int numberOfSongs){

    int i = 0;
    int pos = 0;
    Song aux;

    while(i < numberOfSongs){

        pos = searchSongGenre(listSong, numberOfSongs, i);

        aux = listSong[i];
        listSong[i] = listSong[pos];
        listSong[pos] = aux;

        i++;
    }
}

void showLibraryGenre(){
    char option = NULL;
    int j = 1;
    int max = amountSongs()/sizeof(Song);

    Song listSongGenre[500];
    int numberOfSongs = archToArr(listSongGenre);

    orderArrayGenre(listSongGenre, numberOfSongs);

    for(int i= 0;i<max;i++){
        printf("----------------------------------------\n");
        printf("|Nombre de la cancion: %s\n",listSongGenre[i].name);
        printf("|Artista: %s\n",listSongGenre[i].artist);
        printf("|Anio: %d\n",listSongGenre[i].age);
        printf("|Genero: %s\n",listSongGenre[i].genre);

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
    }
}
