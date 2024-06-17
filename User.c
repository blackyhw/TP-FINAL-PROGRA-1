#include "User.h"

User* searchUsername(char*username){

    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(!archi)
    {
        printf("El archivo no pudo abrirse correctamente");
    }

    while(user == NULL && fread(&aux,sizeof(User),1,archi)>0){
            if(strcmp(aux.username,username)== 0)
                user = &aux;
        }

        fclose(archi);

    return user;
}


int accVerify(User *user,char*username,char*passWord){
    int flag = 0;
    user = searchUsername(username);
    if(!user){

        return flag;
    }

    if(strcmp(user->passWord,passWord) == 0){
            return 1;
    }
    return 0;
}

int verifyMail(char mail[])
{
    User aux;
    int flag=1;
    int i=0;


    while(i<1)
    {
        FILE*archive = fopen("Users.bin", "rb");

        if(archive)
        {
            while(fread(&aux, sizeof(User), 1, archive)>0)
            {
                if(mail == aux.email)
                {
                    printf("Error. El correo electronico ya se encuentra ocupado.\n");
                    flag = 0;
                }
            }
        }

        fclose(archive);

        i++;
    }

    return flag;
}

int verifyPhone(char phone[])
{
    User aux;
    int flag=1;
    int i=0;


    while(i<1)
    {
        FILE*archive = fopen("Users.bin", "rb");

        if(archive)
        {
            while(fread(&aux, sizeof(User), 1, archive)>0)
            {
                if(phone == aux.phoneNumber)
                {
                    printf("Error. El numero de telefono ya se encuentra registrado.\n");
                    flag = 0;
                }
            }
        }

        fclose(archive);

        i++;
    }

    return flag;
}

void saveUser(User user)
{

    FILE*archive = fopen("Users.bin", "wb");

    if(archive)
    {
        fwrite(&user, sizeof(User),1, archive);
    }

    fclose(archive);
}
