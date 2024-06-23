#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "User.h"

void registerUser();
void loginMenuBepefy();
void subMenuLogin();
void menuBepefy(User*user);
void menuUser(User*user);
void menuSongs(User user);

#endif // SYSTEM_H_INCLUDED
