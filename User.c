#include "User.h"
int posUser(int idUser)
{
    int pos = -1;
    int i = 0;
    User aux;

    FILE*archi = fopen("Users.bin","rb");

    if(archi)
    {
        while(pos == -1 && fread(&aux,sizeof(User),1,archi) > 0)
        {
            if(aux.id == idUser)
            {
                pos = i;
            }
            i++;
        }
        fclose(archi);
    }

    return pos;
}
User* searchUsername(char*username)
{

    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi)
    {
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0)
        {
            if(strcmpi(aux.username,username)== 0)
            {
                user = &aux;
            }
        }


    }

    fclose(archi);

    return user;
}

User* accVerify(User*user,char*infoToLogin,char*passWord)
{

    user = searchUsername(infoToLogin);
    if(!user)
    {
        user = searchEmail(infoToLogin);
        if(!user)
        {
            user = searchPhoneNumber(infoToLogin);
            if(!user)
            {
                return user;
            }

        }
    }

    if(strcmp(user->passWord,passWord) == 0)
    {
        return user;
    }
}

User*searchEmail(char*email)
{
    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi)
    {
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0)
        {
            if(strcmp(aux.email,email) == 0)
            {
                user = &aux;
            }
        }

    }
    fclose(archi);

    return user;
}

User*searchPhoneNumber(char*phoneNumber)
{
    User*user = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi)
    {
        while(user == NULL && fread(&aux,sizeof(User),1,archi)>0)
        {
            if(strcmp(aux.phoneNumber,phoneNumber) == 0)
            {
                user = &aux;
            }
        }

    }
    fclose(archi);

    return user;
}


int searchIdFree()
{
    User aux;
    int id = 0;
    long pos;
    long sizeUser;
    long sizeArch;
    long users;
    FILE*archi = fopen("Users.bin","rb");

    if(archi)
    {
        fseek(archi, 0, SEEK_END);
        sizeUser =  sizeof(User);
        sizeArch = ftell(archi);
        users = sizeArch/sizeUser;
        pos = (users - 1) * sizeUser;

        fseek(archi,pos,SEEK_SET);

        fread(&aux,sizeof(User),1,archi);
        fclose(archi);

        return aux.id+1;
    }
    printf("El archivo no se abrio correctamente.");
    return -1;
}

int verifyValidEmail(char*email)
{
    int i = 0;
    int flag = 0;
    char*validDomains[] = {"hotmail.com","gmail.com","outlook.com","yahoo.com"};
    int numDomains = sizeof(validDomains) / sizeof(validDomains[0]);

    char *at = strchr(email, '@');
    if (at == NULL)
    {
        return flag;
    }

    char *domainPart = at + 1;

    while(i<numDomains && flag == 0)
    {
        if (strcmpi(domainPart, validDomains[i]) == 0)
        {
            flag = 1;
        }

        i++;
    }
    return flag;
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

void showUser(int pos)
{
    User aux;
    FILE*archi = fopen("Users.bin","rb");

    if(archi){
        fseek(archi,sizeof(User)*pos,SEEK_SET);

        fread(&aux,sizeof(User),1,archi);
        system("cls");
        printf(".................................................................\n");
        printf("Nombre de usuario:%s.\n", aux.username);
        printf(".................................................................\n");
        printf("Mail::%s.\n", aux.email);
        printf(".................................................................\n");
        printf("Numero de Telefono:%s.\n", aux.phoneNumber);
        printf(".................................................................\n");
        system("pause");
        system("cls");

    fclose(archi);
    }
}

void subEditMenuUser(User*user)
{

    int pos = posUser(user->id);
    updateUser(pos);
}

User* editMenuUser(User*user)
{
    char newUsername[21];
    char newEmail[31];
    char newPhone[16];
    char newPassWord[21];

    int option;
    do
    {
        system("cls");
        printf("Cual campo queres modificar?\n");
        printf("1. Nombre de Usuario\n");
        printf("2. Email \n");
        printf("3. Numero de Telefono\n");
        printf("4. Contrasenia\n");
        printf("5. Volver al menu anterior\n");

        fflush(stdin);
        option = getch();

        switch(option)
        {

        case 49:
            system("cls");
            printf("Ingrese el nuevo nombre de usuario:\n");
            fflush(stdin);
            scanf("%s",&newUsername);
            system("cls");
            if(!searchUsername(newUsername))
            {
                strcpy(user->username,newUsername);
                printf("Se modifico correctamente.\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("El nombre de usuario no esta disponible\n");
                printf("Por favor eliga otro o pulse ESC para cancelar\n");
                fflush(stdin);
                option = getch();
                system("cls");
            }

            break;

        case 50:
            system("cls");
            printf("Ingrese el nuevo Email:\n");
            scanf("%s",&newEmail);
            if(verifyValidEmail(newEmail)== 0)
            {
                system("cls");
                printf("\nEse mail ya esta en uso");
            }
            else
            {
                system("cls");
                strcpy(user->email,newEmail);
                printf("Se modifico correctamente\n");
            }
            break;

        case 51:
            system("cls");
            printf("Ingrese el nuevo numero de telefono:\n");
            fflush(stdin);
            scanf("%s",&newPhone);
            if(verifyPhone(newPhone)==1)
            {
                system("cls");
                printf("El numero de telefono se encuentra ocupado.\n");
            }
            else
            {
                system("cls");
                strcpy(user->phoneNumber,newPhone);
                printf("Se modifico correctamente\n");
                system("pause");
            }
            break;

        case 52:
            system("cls");
            printf("Ingrese una nueva contrasenia:\n");
            printf("Longitud de 8 a 15 caracteres.\n");
            fflush(stdin);
            scanf("%s",&newPassWord);
            if(strlen(newPassWord)<=15 && strlen(newPassWord)>=8)
            {
                system("cls");
                strcpy(&user->passWord, newPassWord);
                printf("Se modifico correctamente");
            }
            else
            {
                system("cls");
                printf("Error. La contrasenia ingresada no posee la longitud expresada.\n");
                printf("Desea cancelar la carga? Presione ESCAPE.\n");
                printf("Para volver a intentarlo presione cualquier tecla.\n");
                fflush(stdin);
                option = getch();
            }

        default:
            printf("No existe esa opción \n");
            system("cls");
            break;
        }

    }while(option != '5' && option != 27);

    return user;

}
void updateUser(int posUser)
{
    User aux;
    User*user;
    FILE*archi = fopen("Users.bin","r+b");
    if(archi)
    {
        fseek(archi, sizeof(User) * posUser, SEEK_SET);
        fread(&aux,sizeof(User),1,archi);


            user = editMenuUser(&aux);


            fseek(archi, -sizeof(User), SEEK_CUR);


            fwrite(user, sizeof(User), 1, archi);


        fclose(archi);
    }
}
