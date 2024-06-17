#include "User.h"

User* searchUsername(char*username){

    User*a = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(!archi)
    {
        printf("El archivo no pudo abrirse correctamente");
    }

    while(a == NULL && fread(&aux,sizeof(User),1,archi)>0){
            if(strcmp(aux.username,username)== 0)
                a = &aux;
        }

        fclose(archi);

    return a;
}


int accVerify(User *u,char*username,char*passWord){
    u = searchUsername(username);
    if(!u){
            printf("El archivo no pudo abrirse correctamente");
    }

    if(strcmp(u->passWord,passWord) == 0){
            return 1;
    }
    return 0;
}

