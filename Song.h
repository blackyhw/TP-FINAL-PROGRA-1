#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

typedef struct{
 int id;
 char name[50];
 int age;
 char genre[10];
 char artist[50];

}Song;

void menuPlaylist(User*user);

#endif // SONG_H_INCLUDED
