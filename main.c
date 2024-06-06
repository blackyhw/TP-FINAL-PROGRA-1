#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "User.h"
int main()
{
    stUser user;
    stUser*userList = userFileToArray();
    int dimUsers = dimFile("Users.bin",sizeof(stUser));
    int userLoc = searchUsername("OrbMeister",userList,dimUsers);
    user = userList[userLoc];
    printf("%d",userLoc);
    return 0;
}
