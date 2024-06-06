#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Song.h"

typedef struct{
  int id;
  char*username;
  char*email;
  int phoneNumber;
  char*passWord;
  int state;
  stSong playList[200];

}stUser;
stUser*userFileToArray();
int dimFile(char*nameFile,int size1);
int searchUsername(char*username,stUser*list,int dim);






#endif // USER_H_INCLUDED
