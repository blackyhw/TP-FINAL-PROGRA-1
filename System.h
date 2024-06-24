#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "Song.h"

#include "Behaviour.h"

void registerUser();
void loginMenuBepefy();
void subMenuLogin();
void menuBepefy(User*user);
void menuUser(User*user);
void menuSongs(User*user);
void menuLibrary();
void subSearch();
char* getStr(char* nameSong, Song*sList, int i);
void printSearch(Song*sList,char*songName);
#endif // SYSTEM_H_INCLUDED
