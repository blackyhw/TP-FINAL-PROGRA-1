#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

typedef struct{
 int id;
 char name[50];
 int age;
 char genre[10];
 char artist[3][50];
 int state;

}stSong;


#endif // SONG_H_INCLUDED
