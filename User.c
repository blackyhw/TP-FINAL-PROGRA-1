#include "User.h"

User searchUsername(char*username){

    User aux, user;
    int flag = 0;

    FILE * archi = fopen("Users.bin","rb");

    if(archi != NULL)
    {

        while(flag == 0 && fread(&aux,sizeof(User),1,archi)> 0)
        {
            if(strcmp(aux.username,username)==0)
            {
                user = aux;
                flag = 1;
            }
        }
        fclose(archi);
    }
        return user;
}

User* searchUsername2(char*username)
{

    User*a = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi)
    {
        while(a == NULL && fread(&aux,sizeof(User),1,archi)>0)
        {
            if(strcmp(aux.username,username)==0)
                a = &aux;
        }

        fclose(archi);
    }

    return a;
}
