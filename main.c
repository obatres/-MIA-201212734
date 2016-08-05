
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct{
        char nombre[20];
        char direccion[30];
        int telefono;
    }Contacto;


    char cadenainicial[250];
    void menu (char* nombreArchivo);
    Contacto crearContacto();
    void guardarContacto(Contacto contacto, char* nombreArchivo);
    void mostrarAgenda(char* nombreArchivo);
    void pausar();
    void comandoMskdisk(char cadena[]);
    void token(char cad[]);
    int main(){


        char nombreArchivo[12]= "agenda.bin";
        menu (nombreArchivo);
        return 0;
    }

    void menu(char* nombreArchivo){
        int opcion;

        while (opcion!=4){
            printf("\n");
            printf("1. Crear contacto\n");
            printf("2. Consultar agenda\n");
            printf("3. Comando\n");
            printf("4. Salir\n\n");
            printf("Ingresar una opcion: ");
            scanf(" %d", &opcion);


               // system("cls");
                switch(opcion){
                    case 1:
                        guardarContacto(crearContacto(), nombreArchivo);
                        break;
                    case 2:
                        mostrarAgenda(nombreArchivo);
                        break;
                    case 3:
                        printf("ingrese comando: \n");
                        char  ingreso[250];
                        scanf("%s",&ingreso);
                        //comandoMskdisk(ingreso);
                        token(ingreso);
                        break;
                    case 4:
                        printf("Fin del programa\n");
                        pausar();
                        break;
                }


        }
    }

    Contacto crearContacto(){
        Contacto contacto;

        printf("Nombre: ");
        scanf(" %[^\n]", contacto.nombre);
        printf("Direccion: ");
        scanf(" %[^\n]", contacto.direccion);
        printf("Telefono: ");
        scanf(" %d", &contacto.telefono);

        return contacto;
    }

    void guardarContacto(Contacto contacto, char* nombreArchivo){
        FILE* file= fopen(nombreArchivo, "ab");

        if (file==NULL){
            printf("Error al intentar acceder al archivo\n");
            pausar();
        }
        else{
            fwrite(&contacto, sizeof(Contacto), 1, file);
            printf("\nContacto guardado!\n");
            pausar();
            fclose(file);
        }
    }

    void mostrarAgenda(char* nombreArchivo){
        FILE* file= fopen(nombreArchivo, "rb");

        if (file==NULL){
            printf("Error al intentar acceder al archivo\n");
            pausar();
        }
        else{
            Contacto contacto;
            printf("%-20s %-30s %-10s\n\n", "Nombre", "Direccion", "Telefono");
            while (fread(&contacto, sizeof(Contacto), 1, file)){
                printf("%-20s %-30s %-10d\n", contacto.nombre, contacto.direccion,
                        contacto.telefono);
            }
            fclose(file);
            printf("\n\n");
            pausar();
        }
    }

    void pausar(){


        printf("Presione ENTER para continuar");

        while (getchar() != '\n');
        getchar();

        printf("");
    }

    void comandoMskdisk(char cadena[]){
           char  str[250];
           strcpy(str,cadena);
           //Mkdisk –Size::3000 +unit::K –path::"/home/user/" –name::"Disco1.dsk";
            char piece1[20] = ""
                ,piece2[20] = ""
                ,piece3[20] = ""
                ,piece4[20] = ""
                ,piece5[20] = "";
            char * p;

            p = strtok (str," "); // call the strtok with str as 1st arg for the 1st time.
            strcpy(piece1,p); // save the token.
            p = strtok (NULL," "); // subsequent call should have NULL as 1st arg.
            strcpy(piece2,p); // save the token.
            p = strtok (NULL," "); // subsequent call should have NULL as 1st arg.
            strcpy(piece3,p);
            p = strtok (NULL," "); // subsequent call should have NULL as 1st arg.
            strcpy(piece4,p);
            p = strtok (NULL," "); // subsequent call should have NULL as 1st arg.
            strcpy(piece5,p);



            printf("%s \n%s \n%s \n%s \n%s",piece1,piece2,piece3,piece4,piece5); // prints Stackoverflow :: Serverfault
           // printf("%s \n ",p);
    }

    void token (char cad[]){
        //char  cad[] = "Este es un enunciado con 7 tokens";
        //char cadena[25];
        strcpy(cadenainicial, cad);
        char *ptrToken;

        printf("Los tokens son:" );

        ptrToken = strtok(cadenainicial," ");
            if ( ptrToken != NULL ) {
                printf( "%s\n", ptrToken );

                ptrToken = strtok(NULL, " " );
                ptrToken = "\0";

            }
    }



