#include "User.h"

User* searchUsername(char*username){

    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi){
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0){
                if(strcmpi(aux.username,username)== 0){
                user = &aux;
                }
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
            if(strcmp(aux.email,email) == 0){
                user = &aux;
            }
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
            if(strcmp(aux.phoneNumber,phoneNumber) == 0){
                user = &aux;
            }
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

    FILE*archive = fopen("Users.bin", "ab");

    if(archive)
    {
        fwrite(&user, sizeof(User),1, archive);
    }

    fclose(archive);
}

void showUser(User user)
{
    printf("--------Nombre de usuario: %s.\n", user.username);
    printf("--------------------Email: %s.\n", user.email);
    printf("-------Numero de telefono: %s.\n", user.phoneNumber);
}

void editMenuUser(User user)
{
    int option = 0;

    do
    {
        editMenu();
        option = getch();
        system("cls");

        switch(option)
        {
        case 49:
            printf("Edicion de nombre de usuario:\n");
            editUsername(user);
            printf("Los cambios han sido realizados.\n");
            system("pause");
            system("cls");
            break;

        case 50:
            printf("Edicion de contrasenia:\n");
            editPassword(user);
            printf("Los cambios han sido realizados.\n");
            system("pause");
            system("cls");
            break;

        case 51:
            printf("Edicion de correo electronico:\n");
            editEmail(user);
            printf("Los cambios han sido realizados.\n");
            system("pause");
            system("cls");
            break;

        case 52:
            printf("Edicion de numero de telefono:\n");
            editPhoneNumber(user);
            printf("Los cambios han sido realizados.\n");
            system("pause");
            system("cls");
            break;

        case 53:

            break;

        default:
                printf("Opcion incorrecta.\n");
                system("pause");
                system("cls");
            break;
        }
    }while(option!=53)
}

void editMenu()
{
    printf("---------Editar datos del usuario---------\n");
    printf("\nSeleccione una opcion:\n");
    printf("1. Editar nombre de usuario.\n");
    printf("2. Editar contrasenia.\n");
    printf("3. Editar correo electronico.\n");
    printf("4. Editar numero de telefono.\n");
    printf("5. Salir del menu de edicion.\n");
}
