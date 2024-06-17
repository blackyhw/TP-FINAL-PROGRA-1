#include "User.h"

User* searchUsername(char*username)
{

    User*user1 = NULL;
    User aux;

    FILE * archi = fopen("Users.bin","rb");

    if(archi)
    {
        printf("El archivo no pudo abrirse correctamente");
        return user1;
    }

    while(user1 == NULL && fread(&aux,sizeof(User),1,archi)>0){

        while(a == NULL && fread(&aux,sizeof(User),1,archi)>0)
        {
            if(strcmp(aux.username,username)== 0)
                user1 = &aux;
        }
    }

    fclose(archi);

    return user1;
}


int accVerify(User *u,char*username,char*passWord)
{
    u = searchUsername(username);
    if(!u)
    {
        printf("El archivo no pudo abrirse correctamente");
    }

    if(strcmp(u->passWord,passWord) == 0)
    {
        return 1;
    }
    return 0;
}

void registerUser()
{
    User user;
    char username[21];
    char email[31];
    char phoneNumber[16];
    char password[16];
    char option=NULL;
    int i=0;
    int nameVerify=0;
    int passVerify=0;
    int mailVerify=0;
    int phoneVerify=0;


    printf(". . . Sistema de registro BEPEFY . . .\n");

    while(nameVerify==0 && option!=27)
    {
        system("cls");
        printf("Ingresar nombre de usuario:\n");
        printf("Maximo 20 caracteres.\n");    //verificar medidad del usuario.
        fflush(stdin);
        gets(username);
        if(!searchUsername(username))
        {
            strcpy(&user.username, username);
            nameVerify=1;
        }
        else
        {
            printf("Nombre de usuario invalido.\n");
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
    }

    while(passVerify==0 && option!=27)
    {
        system("cls");
        printf("Ingresar contrasenia:\n");
        printf("Longitud de 8 a 15 caracteres.\n");
        fflush(stdin);
        gets(password);
        if(strlen(password)<=15 && strlen(password)>=8)
        {
            strcpy(&user.passWord, password);
            passVerify = 1;
        }
        else
        {
            printf("Error. La contrasenia ingresada no posee la longitud expresada.\n");
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
    }

    while(mailVerify==0 && option!=27)
    {
        system("cls");
        printf("Ingresar correo electronico:\n");
        printf("Maximo 30 caracteres.\n");  // verificar la medida del mail.
        fflush(stdin);
        gets(email);
        mailVerify = verifyMail(email);
        if(mailVerify == 0)
        {
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
        else
        {
            strcpy(&user.email, email);
            mailVerify=1;
        }
    }

    while(phoneVerify==0 && option!=27)
    {
        system("cls");
        printf("Ingresar numero de telefono:\n");
        fflush(stdin);
        gets(phoneNumber);
        phoneVerify = verifyPhone(phoneNumber);
        if(phoneVerify == 0)
        {
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
        else
        {
            strcpy(&user.phoneNumber, phoneNumber);
            phoneVerify = 1;
        }
    }

    if(phoneVerify == 1)
    {
        saveUser(user);
    }
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

    FILE*archive = fopen("Users.bin", "ab");

    if(archive)
    {
        fwrite(&user, sizeof(User),1, archive);
    }

    fclose(archive);
}
