#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "Song.h"

typedef struct{
  int id;
  char name[50];
  char username[30];
  char email[15];
  int phoneNumber;
  char passWord[12];
  int state;
  stSong playList;

}stUser;











#endif // USER_H_INCLUDED
