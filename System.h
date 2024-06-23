#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "User.h"

void registerUser();
void loginMenuBepefy();
void subMenuLogin();
<<<<<<< HEAD
void menuBepefy();
void menuUser();
void menuSongs();
void showPlaylist(User);
=======
void menuBepefy(User*user);
void menuUser(User*user);
void menuSongs(User user);
>>>>>>> 2a3dbdc87ac1c5eb3086343dde961ce42964fc55

#endif // SYSTEM_H_INCLUDED
