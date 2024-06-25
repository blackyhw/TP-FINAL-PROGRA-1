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
void menuBepefy(User user);
int menuUser(User user);
void menuSongs(User user);
void subSearch(User user);
char* getStr(char* nameSong, Song*sList, int i);
void printSearch(Song*sList,char*songName);
Song getSong(char*nameSong,Song*listSong);
void addSongToPlaylist(User user,Song song);
void subMenuPlaylist(User user);
#endif // SYSTEM_H_INCLUDED
