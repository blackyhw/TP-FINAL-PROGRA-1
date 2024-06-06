#include "User.h"

stUser*userFileToArray(){
    stUser * aux = NULL;
    FILE*arch = fopen("Users.bin","rb");

    if(!arch){
         printf("Error en el archivo");
         return aux;
    }

    stUser*users;

    int dim = sizeof(arch)/sizeof(stUser);

    users  = (stUser*)malloc(sizeof(arch));

    fclose(arch);
    return users;
}
int dimFile(char*nameFile,int size1){
    FILE*arch = fopen(nameFile,"rb");
    int cant = 0;

    if(arch){
        fseek(arch,0,SEEK_END);
        cant = ftell(arch)/size1;
        fclose(arch);
    }
    return cant;
}


int searchUsername(char*username,stUser*list,int dim){

    int pos = -1;
    int i = 0;

    while(i<dim && pos == -1){
        if(strcmp(list[i].username,username) == 0){
        pos = i;
        }
        i++;
    }
    return pos;

}
