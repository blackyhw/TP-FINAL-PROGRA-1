#include "System.h"
#include "Song.h"
#include "User.h"

void registerUser()
{
    User user;
    int i = 0;
    char username[21];
    char email[31];
    char phoneNumber[16];
    char password[21];
    char option=NULL;
    int nameVerify=0;
    int passVerify=0;
    int mailVerify=0;
    int phoneVerify=0;

    user.id = searchIdFree();
    user.playListSize = -1;
    listSongNull(&user);
    user.isAdmin = 0;


    while(nameVerify == 0 && option!=27)
    {
        system("cls");
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t      ------------------------------\n");
        printf("\t\t\t\t\t      | SISTEMA DE REGISTRO BEPIFY |\n");
        printf("\t\t\t\t\t      ------------------------------\n\n");
        printf("\t\t\t\t\t        Ingresar nombre de usuario\n");
        printf("\t\t\t\t\t          (Maximo 20 caracteres)\n\n");    //verificar medidad del usuario.
        printf("\t\t\t\t\t\t       ");

        mostrarCursor();
        fflush(stdin);
        gets(username);
        ocultarCursor();

        if(!searchUsername(username))
        {
            strcpy(&user.username, username);
            nameVerify=1;
        }
        else
        {
            printf("\n\n");
            printf("\t\t\t\t\t  El nombre de usuario no esta disponible. \n\n");
            printf("\t\t\t\t\t   Desea cancelar la carga? Presione ESC.\n\n");
            printf("\t\t\t\t     Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
            system("cls");
        }
    }

    while(passVerify == 0 && option!=27)
    {
        system("cls");
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t      ------------------------------\n");
        printf("\t\t\t\t\t      | SISTEMA DE REGISTRO BEPIFY |\n");
        printf("\t\t\t\t\t      ------------------------------\n\n");
        printf("\t\t\t\t\t           Ingresar contrasenia\n");
        printf("\t\t\t\t\t      (Longitud de 8 a 15 caracteres)\n\n");
        printf("\t\t\t\t\t\t       ");

        mostrarCursor();
        fflush(stdin);
        gets(password);
        ocultarCursor();

        if(strlen(password)<=15 && strlen(password)>=8)
        {
            strcpy(&user.passWord, password);
            passVerify = 1;
        }
        else
        {
            printf("\n\n");
            printf("\t\t\t\tError. La contrasenia ingresada no posee la longitud expresada.\n\n");
            printf("\t\t\t\t\t  Desea cancelar la carga? Presione ESCAPE.\n\n");
            printf("\t\t\t\t      Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
    }

    while(mailVerify == 0 && option!=27)
    {
        system("cls");
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t      ------------------------------\n");
        printf("\t\t\t\t\t      | SISTEMA DE REGISTRO BEPIFY |\n");
        printf("\t\t\t\t\t      ------------------------------\n\n");
        printf("\t\t\t\t\t       Ingresar correo electronico\n");
        printf("\t\t\t\t\t          (Maximo 30 caracteres)\n\n");
        printf("\t\t\t\t\t\t    ");

        mostrarCursor();
        fflush(stdin);
        scanf("%s",&email);
        ocultarCursor();

        if(verifyValidEmail(email) == 0)
        {
            printf("\n\n");
            printf("\t\t\t\t      El email ya esta en uso, intente uno diferente\n\n");
            printf("\t\t\t\t         Desea cancelar la carga? Presione ESCAPE.\n\n");
            printf("\t\t\t\t     Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
        else
        {
            strcpy(&user.email, email);
            mailVerify=1;
        }

    }

    while(phoneVerify == 0 && option!=27)
    {
        system("cls");
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t      ------------------------------\n");
        printf("\t\t\t\t\t      | SISTEMA DE REGISTRO BEPIFY |\n");
        printf("\t\t\t\t\t      ------------------------------\n\n");
        printf("\t\t\t\t\t       Ingresar numero de telefono.\n\n");
        printf("\t\t\t\t\t\t        ");

        mostrarCursor();
        fflush(stdin);
        gets(phoneNumber);
        ocultarCursor();

        phoneVerify = verifyPhone(phoneNumber);
        if(phoneVerify == 1)
        {
            printf("\n\n");
            printf("\t\t\t\t      Numero de telefono ocupado, por favor eliga otro\n\n");
            printf("\t\t\t\t           Desea cancelar la carga? Presione ESC\n\n");
            printf("\t\t\t\t      Para volver a intentarlo presione cualquier tecla\n");
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
        user.state = 1;
        saveUser(user);
    }
    system("cls");
}

void loginMenuBepefy()
{
    ocultarCursor();

    int option = 0;
    int verify = 1;

    do
    {

        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t        -----------------------\n");
        printf("\t\t\t\t\t        | BIENVENIDO A BEPIFY |\n");
        printf("\t\t\t\t\t        -----------------------\n\n");
        printf("\t\t\t\t\t         Seleccione una opcion\n");
        printf("\t\t\t\t\t         ********************* \n\n");

        printf("\n\t\t\t\t\t            1. Registrarse\n");
        printf("\n\t\t\t\t\t            2.    Login\n");
        printf("\n\t\t\t\t\t            3.    Salir\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option)
        {

        case 49:
            registerUser();
            break;

        case 50:
            subMenuLogin();
            break;

        case 51:

            break;

        default:

            printf("Opcion incorrecta.\n");
            system("pause");
            system("cls");
            break;

        }

    }
    while(option != 51);

    printf("\nFIN DEL PROGRAMA\n");
}

void subMenuLogin()
{
    char infoToLogin [20];
    char password [15];
    User*userP = NULL;
    User user;

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t        ------------------\n");
    printf("\t\t\t\t\t        | INICIAR SESION |\n");
    printf("\t\t\t\t\t        ------------------\n\n");

    printf("\t\t\t       Ingrese su nombre de usuario, email o numero de telefono\n\n");
    printf("\t\t\t\t\t\t     ");

    mostrarCursor();
    fflush(stdin);
    gets(infoToLogin);
    ocultarCursor();

    system("cls");

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t        ------------------\n");
    printf("\t\t\t\t\t        | INICIAR SESION |\n");
    printf("\t\t\t\t\t        ------------------\n\n");

    printf("\t\t\t\t\t      Ingrese su contrasenia\n\n");
    printf("\t\t\t\t\t\t     ");

    mostrarCursor();
    fflush(stdin);
    gets(password);
    ocultarCursor();

    userP = accVerify(userP,infoToLogin,password);
    if(userP)
    {
        user = *userP;
        system("cls");
        menuBepefy(user);
    }
    system("cls");
    printf("Usuario no registrado, Intente nuevamente\n");
    system("pause");
    system("cls");

}

void menuBepefy(User user)
{
   int flag = 0;
    int option = NULL;

    do
    {

        system("cls");

        printf("\n\n\n\n\n");
        printf("\t\t\t\t   ____     _____    ____    _____    _____   __     __    \n");
        printf("\t\t\t\t  | __ )   | ____|  |  _ \\  | ____|  |  ___|  \\ \\   / / \n");
        printf("\t\t\t\t  |  _ \\   |  _|    | |_) | |  _|    | |_      \\ \\_/ /  \n");
        printf("\t\t\t\t  | |_) |  | |___   |  __/  | |___   |  _|      \\   /     \n");
        printf("\t\t\t\t  |____/   |_____|  |_|     |_____|  |_|         |_|       \n");

        printf ("\n\n\n\n");
        printf("\t\t\t\t      _____________________________________________\n");
        printf("\t\t\t\t     |                                             |\n");
        printf("\t\t\t\t     |       ELIGE UNA OPCION PARA CONTINUAR       |\n");
        printf("\t\t\t\t     |_____________________________________________|\n");
        printf("\t\t\t\t     |                                             |\n");
        printf("\t\t\t\t     | 1. Usuario                                  |\n");
        printf("\t\t\t\t     | 2. Biblioteca                               |\n");
        printf("\t\t\t\t     | 3. Salir                                    |\n");
        printf("\t\t\t\t     |_____________________________________________|\n");

        fflush(stdin);
        option = getch();

        switch (option)
        {
        case 49:
            if(user.isAdmin == 1){
                    system("cls");
                menuUserAdm(user);
            }else{
                system("cls");
            flag = menuUser(user);
            }
            break;

        case 50:
            system("cls");
            menuSongs(user);
            break;
        case 51:

            break;
        default:

            printf("\n\n\t\t\t\t\t\t   Opcion incorrecta.\n\n");
            printf("\t\t\t                   ");
            system("pause");

            break;
        }
    }
    while (option != 51 && flag == 0);
}

int menuUser(User user)
{

    int flag = 0;
    int option = 0;

    do
    {

        printf("\nELIGA UNA OPCION.\n");

        printf("\n1. Dar de baja al usuario.\n");
        printf("\n2. Editar usuario.\n");
        printf("\n3. Mostrar datos del usuario.\n");
        printf("\n4. Activar el modo desarollador.\n");
        printf("\n5. Volver al menu principal.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

        case 49:
            flag = delUser(user);
            break;
        case 50:
            subEditMenuUser(user);
            break;

        case 51:
            showUser(user);
            break;

        case 52:
            adminMode(&user);
            break;

        case 53:
            break;
        default:

            printf("Opcion incorrecta.\n");
            system("cls");
            break;
    }

    }while(option != 53 && flag == 0);
    return flag;
}

void menuSongs(User user)
{
    int option = 0;

    do
    {

        printf("\nELIGA UNA OPCION.\n");

        printf("\n1. Mi Playlist\n");
        printf("\n2. Biblioteca\n");
        printf("\n3. Buscar una cancion\n");
        printf("\n4. Volver al menu principal.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option)
        {

        case 49:

            subMenuPlaylist(user);
            break;

        case 50:
            menuLibrary();
            break;

        case 51:
            subSearch(user);
            break;
        case 52:

            break;

        default:

            printf("Opcion incorrecta.\n");
            system("cls");
            break;

        }
    }
    while(option !=52);
}

void menuLibrary()
{

    int option = NULL;

    do
    {

        printf("\nELIJA UNA OPCION.\n\n");

        printf("\n1. Ver la Biblioteca completa.\n");
        printf("\n2. Ver Biblioteca por Orden alfabetico.\n");
        printf("\n3. Ver Biblioteca por Genero.\n");
        printf("\n4. Salir.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option)
        {

        case 49:
            showLibrary();
            break;

        case 50:
            showLibraryAtoZ();
            break;

        case 51:
            showLibraryGenre();
            break;
        case 52:

            break;
        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            system("cls");
            break;

        }

    }while(option != 52);
}

void subSearch(User user)
{
    char response = NULL;
    Song*listSongs = (Song *) malloc(amountSongs()*sizeof(Song));
    archToArr(listSongs);
    char buffer[50];

    printf("Ingrese la cancion que desea buscar: ");
    char*fullWord = getStr(buffer,listSongs,0);
    Song song = getSong(fullWord, listSongs);

    system("cls");
    printf("Desea agregar %s a su playlist?(s/n):",song.name);
    response = getch();
    if (response == 's' || response == 'S')
    {
        if (song.name[0] != '\0')
        {
            updatePlayList(user,song);
            printf("\nLa cancion se agrego correctamente.\n");
            system("pause");

        }
    }
    system("cls");
}

char* getStr(char* nameSong, Song*sList, int i)
{
    char aux = getch();
    gotoxy(i+37, 0);

    if (aux == 13)
    {
        nameSong[i] = '\0';
        return nameSong;
    }
    else if (aux == 8 && i > 0)
    {
        gotoxy(i+37 - 1,0);
        printf(" ");
        gotoxy(i+37 - 1,0);
        nameSong[i - 1] = '\0';
        printSearch(sList,nameSong);
        gotoxy(i+37-1, 0);
        return getStr(nameSong, sList, i - 1);
    }
    nameSong[i] = aux;
    nameSong[i + 1] = '\0';
    printSearch(sList, nameSong);
    gotoxy(i+37+1, 0);

    return getStr(nameSong, sList, i + 1);

}

void printSearch(Song*sList,char*songName)
{
    int i = 0;
    system("cls");
    printf("Ingrese la cancion que desea buscar: ");
    printf("%s",songName);

    while(sList[i].name != '\0' && i<100 && strcmpi(songName,"") != 0)
    {
        if(strstr(sList[i].name,songName)!= NULL)
        {
            printf(" ");
            printf("\n%s\t",sList[i].name);
            printf("%s\t",sList[i].artist);
            printf("%d\t",sList[i].age);
            printf("%s\t",sList[i].genre);
        }
        i++;
    }

}
Song getSong(char*nameSong,Song*listSong)
{
    Song aux;
    int i = 0;
    int found = 0;

    while(!found)
    {
        if(strstr(listSong[i].name, nameSong) != NULL)
        {
            aux = listSong[i];
            found= 1;
        }
        i++;
    }

    return aux;
}

void addSongToPlaylist(User*user,Song song)
{
    if(user->playListSize == -1){
        user->playListSize = 0;
        user->playList[user->playListSize] = song;
    }else if(user->playListSize<199){
        user->playListSize++;
        user->playList[user->playListSize] = song;
    }
}
void subMenuPlaylist(User user)
{
    system("cls");
    int option;

    do{
        showPlaylist(user);
        printf("\nDesea quitar elementos de la playlist?\n");
        printf("1.Quitar de playlist\n");
        printf("2.Volver al menu anterior\n");

        fflush(stdin);
        option = getch();

        switch(option){

        case 49:
            removeToPlaylist(user);
            break;
        case 50:

            break;
        default:
        printf("No existe esa opcion\n");
        system("pause");
        system("cls");

        }
    }while(option != 50);
    system("cls");
}
void menuUserAdm(User user){

    int option = 0;

    do
    {

        printf("\nELIGA UNA OPCION.\n");
        printf("\n1. Mostrar datos de los usuarios.\n");
        printf("\n2. Volver al menu principal.\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

        case 49:
            showUserAdm();
            break;
        case 50:
            break;


        default:

            printf("Opcion incorrecta.\n");
            system("cls");
            break;
    }

    }while(option != 50);
}
void showUserAdm(){
    int id = -1;
    User aux;
    FILE*archi = fopen("Users.bin","rb");
    if(archi){
        while(fread(&aux,sizeof(User),1,archi)>0){
            printf("-------------------------------------\n");
            printf("ID:%d\n",aux.id);
            printf("Nombre de usuario:%s\n",aux.username);
            printf("Contrasenia:%s\n",aux.passWord);
            printf("Email::%s\n",aux.email);
            printf("Numero de telefono:%s\n",aux.phoneNumber);
            printf("Estado del usuario::%s\n",aux.state == 1?"Activo":"Inactivo");
            printf("Tipo de cuenta:%s\n",aux.isAdmin == 1?"Administrador":"Usuario");

        }
    }
    printf("\nDesea editar algun usuario?(s/n)\n");
    char option = getch();

    if(option == 's' || option == 'S'){
        printf("\nIngrese el id del usuario a modificar:");
        scanf("%d",&id);

        menuEditAdm(id);
    }
    system("cls");
}
void adminMode(User *user){
    char aux[10];
    const char *code = "4818139";

    printf("Introduzca el codigo de validacion: ");
    fflush(stdin);
    scanf("%s", aux);

    if (strcmp(aux, code) == 0) {
        user->isAdmin = 1;

        FILE *archi = fopen("Users.bin", "r+b");
        if (archi) {
            fseek(archi, sizeof(User) * (user->id), SEEK_SET);

            fwrite(user, sizeof(User), 1, archi);

            fclose(archi);
            printf("Codigo validado. Ahora eres administrador.\n");
            system("pause");
            system("cls");
        }
    }else {
        printf("Codigo de validacion incorrecto. Acceso denegado.\n");
        system("pause");
        system("cls");
    }
}
int menuEditAdm(int id){
    User aux;
     FILE*archi = fopen("Users.bin","rb");
        if(archi){
        fseek(archi, sizeof(User) *id, SEEK_SET);
        fread(&aux,sizeof(User),1,archi);

        fclose(archi);
    }
    int flag = 0;
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
        printf("5. Dar de baja al usuario\n");
        printf("6. Dar de alta al usuario\n");
        printf("7. Volver al menu anterior\n");

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
                strcpy(aux.username,newUsername);
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
                strcpy(aux.email,newEmail);
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
                strcpy(aux.phoneNumber,newPhone);
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
                strcpy(aux.passWord, newPassWord);
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
                system("cls");
                printf("Usuario  deshabilitado.\n");
                aux.state = 0;
                system("pause");
            break;

        case 54:
            system("cls");
            printf("Usuario habilitado\n");
            aux.state = 1;
            system("pause");
            break;
        case 55:
            flag = 1;
            break;
        default:
            printf("No existe esa opción \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option != 55 && option != 27);
    system("cls");

    FILE*archi1 = fopen("Users.bin","r+b");
        if(archi){
        fseek(archi, sizeof(User) *id, SEEK_SET);
        fwrite(&aux,sizeof(User),1,archi);

        fclose(archi);
    }
}
void menuLoginPrint(){
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t******************************\n");
    printf("\t\t\t\t\t\t**   Sistema de registro    **\n");
    printf("\t\t\t\t\t\t******************************\n");
}
