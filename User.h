#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Song.h"

typedef struct{
  int id;
  char username[21];
  char email[31];
  char phoneNumber[16];
  char passWord[21];
  int state;
  Song playList[200];

}User;
int posUser();
User*searchUsername(char*username);
User*searchEmail(char*email);
User*searchPhoneNumber(char*phoneNumber);
int searchIdFree();
User* accVerify(User *user,char*username,char*passWord);
int verifyAt(char*email);
int verifyValidEmail(char*email);
int verifyMail(char mail[]);
int verifyPhone(char phone[]);
void saveUser(User user);
void optionMenuUser();
void subEditMenuUser(User*user);
User* editMenuUser(User*user);
void showUser(int pos);
void updateUser(intposUser);

#endif // USER_H_INCLUDED
