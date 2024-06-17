#include "User.h"

User* searchUsername(char*username){

    User*user1 = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(!archi)
    {
        printf("El archivo no pudo abrirse correctamente");
        return user1;
    }

    while(user1 == NULL && fread(&aux,sizeof(User),1,archi)>0){
            if(strcmp(aux.username,username)== 0)
                user1 = &aux;
        }

        fclose(archi);

    return user1;
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

