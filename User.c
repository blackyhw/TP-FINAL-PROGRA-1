#include "User.h"
int posUser(int idUser)
{
    int pos = -1;
    int flag = 0;
    FILE* archi = fopen("Users.bin", "rb");

    if (archi) {
        User aux;
        int i = 0;
        while (flag == 0 && fread(&aux, sizeof(User), 1, archi)>0) {
            if (aux.id == idUser) {
                pos = i;
                flag = 1;
            }
            i++;
        }
        fclose(archi);
    } else {
        perror("Error opening file"); // Manejo de error si no se pudo abrir el archivo
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
    if(user->state == 0){
        printf("Este usuario esta dado de baja.\n");
        printf("Por favor comuniquese con un Administrador para recuperar su cuenta\n");
        system("pause");
        system("cls");
        return NULL;
    }
    if(strcmp(user->passWord,passWord) == 0)
    {
        return user;
    }
    printf("Contraseña Incorrecta.");
    system("pause");
    return NULL;
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
   long pos = -1;
   long users = 0;

    FILE *archi = fopen("Users.bin", "rb");
    if (archi) {
        users = amountUser(archi);
        fclose(archi);
    } else {
        archi = fopen("Users.bin", "wb");
    }
    pos = users;

    return pos;
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

    FILE*archi = fopen("Users.bin", "ab");
    printf("%s",user.username);
    if(archive)
    {
        fwrite(&user, sizeof(User),1, archi);
    }

    fclose(archive);
}

void showUser(User user)
{
    User aux;
    FILE*archi = fopen("Users.bin","rb");

    if(archi)
    {
        fseek(archi,sizeof(User)*user.id,SEEK_SET);

        fread(&aux,sizeof(User),1,archi);
        system("cls");
        printf(".................................................................\n");
        printf("Nombre de usuario:%s.\n", aux.username);
        printf(".................................................................\n");
        printf("Mail::%s.\n", aux.email);
        printf(".................................................................\n");
        printf("Numero de Telefono:%s.\n", aux.phoneNumber);
        printf(".................................................................\n");
        printf("Cantidad en la playlist:%d.\n",aux.playListSize+1);
        printf(".................................................................\n");
        printf("Estado del Usuario:%d\n",aux.state);
        system("pause");
        system("cls");
        fclose(archi);
    }
}

void subEditMenuUser(User user)
{

    updateUser( user);
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
        case 53:

            break;

        default:
            printf("No existe esa opción \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option != 53 && option != 27);
    system("cls");
    return user;

}
void updateUser(User user)
{
    User aux;
    User*user1;
    FILE*archi = fopen("Users.bin","r+b");
    if(archi)
    {
        fseek(archi, sizeof(User) * user.id, SEEK_SET);
        fread(&aux,sizeof(User),1,archi);


        user1 = editMenuUser(&aux);


        fseek(archi, -sizeof(User), SEEK_CUR);


        fwrite(user1, sizeof(User), 1, archi);


        fclose(archi);
    }
}
void updatePlayList(User user,Song song)
{
    FILE* archi = fopen("Users.bin", "r+b");
    User aux;
    if (archi)
    {
        fseek(archi, sizeof(User) * user.id, SEEK_SET);
        fread(&aux,sizeof(User),1,archi);

        addSongToPlaylist(&aux,song);

        fseek(archi, -sizeof(User), SEEK_CUR);
        fwrite(&aux, sizeof(User), 1, archi);

        fclose(archi);
    }
}
void showPlaylist(User user){

FILE* archi = fopen("Users.bin", "rb");
    if (archi) {

    fseek(archi, sizeof(User) * user.id, SEEK_SET);

    User aux;
    fread(&aux, sizeof(User), 1, archi);
    fclose(archi);

    if (aux.playListSize != -1) {
        printf("----------------------------------------\n");
        for (int i = 0; i <= aux.playListSize; i++) {
            if (aux.playList[i].id != -1) {
                printf("Nombre de la cancion: %s\n", aux.playList[i].name);
                printf("Genero: %s\n", aux.playList[i].genre);
                printf("Anio: %d\n", aux.playList[i].age);
                printf("Artista: %s\n", aux.playList[i].artist);
                printf("----------------------------------------\n");
            }
        }
    } else {
        printf("----------------------------------------\n");
        printf("La playlist esta vacia.\n");
    }
    }
}
void removeToPlaylist(User user){
    char nameSong[30];
    printf("Ingrese el nombre de la cancion que desea remover:");
    gets(nameSong);

    removeSongArch(user,nameSong);


}

void removeSongArch(User user, char *nameSong) {
    User aux;
    FILE *archi = fopen("Users.bin", "r+b");
    int found = 0;

    if (archi) {
        fseek(archi, sizeof(User) * user.id, SEEK_SET);
        fread(&aux, sizeof(User), 1, archi);

        for (int i = 0; i <= aux.playListSize; i++) {
            if (strstr(aux.playList[i].name, nameSong) != NULL) {
                found = 1;
                printf("Eliminando cancion: %s\n", aux.playList[i].name);

                for (int j = i; j < aux.playListSize - 1; j++) {
                    aux.playList[j] = aux.playList[j + 1];
                }
                aux.playListSize--;
                i--;
            }
        }
        if (found == 1) {
            fseek(archi, -sizeof(User), SEEK_CUR);
            fwrite(&aux, sizeof(User), 1, archi);
            printf("\nCancion '%s' eliminada de la playlist.\n", nameSong);
        } else {
            printf("La cancion ingresada no se encontro en la playlist.\n");
        }
        fclose(archi);
    }
    system("pause");
    system("cls");
}

int delUser(User user){
    system("cls");
    char option = NULL;
    printf("Esta seguro? una vez que se le de baja, tendra que comunicarse con un administrador para recuperar su cuenta.");
    printf("\nPresione S/N:");
    option = getch();
    int flag = 0;

    if(option == 's' || option == 'S'){

        User aux;

        FILE*archi = fopen("Users.bin","r+b");

        if(archi){

            fseek(archi,sizeof(User)*user.id ,SEEK_SET);
            fread(&aux,sizeof(User),1,archi);
            aux.state = 0;

            fseek(archi, -sizeof(User), SEEK_CUR);
            fwrite(&aux, sizeof(User), 1, archi);

            flag = 1;
            fclose(archi);
    }
        system("cls");
        printf("Usuario eliminado con exito\n");
        system("pause");
        return flag;
    }
    system("cls");
    return flag;
}

int amountUser(FILE*archi){

    fseek(archi, 0, SEEK_END);
    int sizeUser = sizeof(User);
    long sizeArch = ftell(archi);
    return sizeArch / sizeUser;
}
void listSongNull(User*user){
    Song aux;
    songNull(&aux);
    for(int i = 0;i<200;i++){
        user->playList[i] =aux;
    }

}
void songNull(Song*song){
    song->age = -1;
    strcpy(song->artist,"");
    strcpy(song->genre,"");
    song->id = -1;
    strcpy(song->name,"");
}
