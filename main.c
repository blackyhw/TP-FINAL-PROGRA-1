#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "User.h"

int main()
{
    //loginMenuBepefy();
    User aux;
    FILE*archi=fopen("Users.bin","rb");
    if(archi){
        while(fread(&aux,sizeof(User),1,archi)){
            printf("ID:%d",aux.id);
            printf("Nombre:%s",aux.username);

        }

    }
    return 0;
}

