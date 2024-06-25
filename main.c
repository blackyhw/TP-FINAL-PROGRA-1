#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "User.h"

int main()
{
    loginMenuBepefy();
    FILE*archi = fopen("Users.bin","rb");

    if(archi){
        User user;
        while(fread(&user,sizeof(User),1,archi)>0){

            printf("Nombre%s:\n",user.username);
            printf("ID:%d\n",user.id);
            printf("State:%d\n",user.state);
        }
    }
    return 0;
}

