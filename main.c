#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "User.h"
int main()
{
    ///Version sin Puntero

    /*User a;
    a = searchUsername("manflet");

    *if(a.username != NULL){
        printf("%s",a.username);
    }
    */

    ///Version con Puntero
    User *a;
    a = searchUsername2("manfle");
    if(a->username){
        printf("%s",a->username);
    }else{
        printf("Usuario no existe");
    }

    return 0;
}
