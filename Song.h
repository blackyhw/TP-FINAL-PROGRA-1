#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{

 int id;
 char name[50];
 int age;
 char genre[14];
 char artist[50];
}Song;

int archToArr(Song*librarySongs);
int amountSongs();
void showLibrary();
int searchSongAtoZ(Song listSong[], int numberOfSong, int pos);
void orderArrayAtoZ(Song listSong[], int numberOfSongs);
void showLibraryAtoZ();
int searchSongGenre(Song listSong[], int numberOfSong, int pos);
void orderArrayGenre(Song listSong[], int numberOfSongs);
void showLibraryGenre();
#endif // SONG_H_INCLUDED
