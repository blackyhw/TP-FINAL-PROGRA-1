#include "User.h"

User* searchUsername(char*username)
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
