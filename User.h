#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Song.h"

typedef struct{
  int id;
  char username[20];
  char email[30];
  int phoneNumber;
  char passWord[15];
  int state;
  Song playList[200];

}User;
User* searchUsername(char*username);





#endif // USER_H_INCLUDED
