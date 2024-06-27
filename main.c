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
    Song canciones[100];
    int i = 0;
    FILE*archi = fopen("Songs.bin","rb");
    if(archi){

        while(fread(canciones[i],sizeof(Song),1,archi)>0){
            i++;
        }
        fclose(archi);
    }

    for(i=0;)
    return 0;
}

