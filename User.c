#include "User.h"

User* searchUsername(char*username){

    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi){
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0){
                if(strcmpi(aux.username,username)== 0)
                user = &aux;
        }


    }

        fclose(archi);

    return user;
}
User*searchEmail(char*email){
    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi){
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0){
            if(strcmp(aux.email,email) == 0)
                user = &aux;
        }

    }
        fclose(archi);

    return user;
}
User*searchPhoneNumber(char*phoneNumber){
    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi){
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0){
            if(strcmp(aux.phoneNumber,phoneNumber) == 0)
                user = &aux;
        }

    }
        fclose(archi);

    return user;
}
int accVerify(User *user,char*infoToLogin,char*passWord){
    int flag = 0;

    user = searchUsername(infoToLogin);
    if(!user){
            user = searchEmail(infoToLogin);
                if(!user){
                    user = searchPhoneNumber(infoToLogin);
                        if(!user){
                            return flag;
                        }

                }
    }

    if(strcmp(user->passWord,passWord) == 0){
            return 1;
    }
    return 0;
}
int searchIdFree(){
    User aux;
    int id = 0;
    long pos;
    long sizeUser;
    long sizeArch;
    long users;
   FILE*archi = fopen("Users.bin","rb");

   if(archi){
        fseek(archi, 0, SEEK_END);
        sizeUser =  sizeof(User);
        sizeArch = ftell(archi);
        users = sizeArch/sizeUser;
        pos = (users - 1) * sizeUser;

        fseek(archi,pos,SEEK_SET);

        fread(&aux,sizeof(User),1,archi);
   }
   fclose(archi);

   return aux.id+1;
}
int verifyValidEmail(char*email){
    int i = 0;
    int flag = 0;
    char*validDomains[] = {"hotmail.com","gmail.com","outlook.com","yahoo.com"};
    int numDomains = sizeof(validDomains) / sizeof(validDomains[0]);

    char *at = strchr(email, '@');
    if (at == NULL) {
        return flag;
    }

     char *domainPart = at + 1;

     while(i<numDomains && flag == 0){
        if (strcmpi(domainPart, validDomains[i]) == 0) {
            flag = 1;
        }

        i++;
     }
    return flag;
}

int verifyMail(char mail[]){
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
    int flag = 0;
    int i = 0;

        FILE*archive = fopen("Users.bin", "rb");

        if(archive)
        {
            while(flag == 0 && fread(&aux, sizeof(User), 1, archive)>0)
            {
                if(strcmp(aux.phoneNumber,phone) == 0)
                {
                    flag = 1;
                }
            }
        }

        fclose(archive);

        i++;


    return flag;
}

void saveUser(User user)
{

    FILE*archive = fopen("Users.bin", "ab");

    if(archive)
    {
        fwrite(&user, sizeof(User),1, archive);
    }

    fclose(archive);
}
