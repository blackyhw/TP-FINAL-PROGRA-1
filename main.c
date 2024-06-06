#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "User.h"
int main()
{
    User a;
    a = searchUsername("manflet");

    if(a.username != NULL){
        printf("%s",a.username);
    }
    else{
        printf("El usuario no se encuentra");
    }
    return 0;
}
