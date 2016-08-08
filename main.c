
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>
    #include <time.h>
    #define OK       0
    #define NO_INPUT 1
    #define TOO_LONG 2

    typedef struct{
        char nombre[20];
        char direccion[30];
        int telefono;
    }Contacto;

    struct split{
        char * texto;
        struct split * next;
    };

    struct split *head = NULL;


    char cadenainicial[250];
    void menu (char* nombreArchivo);
    Contacto crearContacto();
    void guardarContacto(Contacto contacto, char* nombreArchivo);
    void mostrarAgenda(char* nombreArchivo);
    void pausar();
    void comandoMskdisk(char* cadena);
    void token(char *cad);
    void evaluarComando();


    void limpiarLista(){
    head = NULL;
    }

    void separar (char *entrada){
        char str[250];
        strcpy(str,&entrada);
        printf(str);
        char piece1[20] = ""
            ,piece2[20] = "";

        char * p;

        p = strtok (str," "); // call the strtok with str as 1st arg for the 1st time.
        if (p != NULL) // check if we got a token.
        {
            strcpy(piece1,p); // save the token.
            p = strtok (NULL, " "); // subsequent call should have NULL as 1st arg.
            if (p != NULL) // check if we got a token.
            strcpy(piece2,p); // save the token.
        }
        //printf("%s :: %s\n",piece1,piece2); // prints Stackoverflow :: Serverfault
          printf("%s",piece2);
          getchar();
    }

    void imprimir(char *cadena){
        char recibe[250];
        strcpy(recibe,&cadena);
        for (int i =0;i<=10;i++){
            printf(recibe);
        }

    }

    int getLine (char *prmpt, char *buff, size_t sz) {
        int ch, extra;
        size_t len;



        if (prmpt != NULL) {
            printf ("%s", prmpt);
            fflush (stdout);
        }

        if (fgets (buff, sz, stdin) == NULL)
            return NO_INPUT;



        len = strlen (buff);
            if (buff[len-1] != '\n') {


            extra = 0;
            while ((ch = getchar()) != '\n') {
            if (ch == EOF) break;
                extra = 1;
            }



            return (extra == 1) ? TOO_LONG : OK;
            }

            buff[len-1] = '\0';
            return OK;
}

    int main(){

        int rc;
        char buff[1024];

        rc = getLine("instruccion: ",buff,sizeof(buff));

        if (rc == NO_INPUT){
        printf("\nNO IMPUT\n");
        return 1;
        }

        if (rc == TOO_LONG) {
        printf ("Too long [%s]\n", buff);
        return 1;
        }

        //char * cadena1;
        //scanf("%s",&cadena1);
        //imprimir(cadena1);
        //separar(cadena1);
        //char * entrada;
        //printf("ingrese cadea:\n");
        //scanf("%s",entrada);
        //token(entrada);
        //char nombreArchivo[12]= "agenda.bin";
        //menu (nombreArchivo);
        //limpiarLista();
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
                        char * ingreso;
                        scanf("%s",&ingreso);
                        evaluarComando();
                        comandoMskdisk(ingreso);
                        //token(ingreso);
                        break;
                    case 4:
                        printf("Fin del programa\n");
                        pausar();
                        break;
                }


        }
    }

    void evaluarComando(){
         struct split *ptr = head;
          while(ptr!=NULL){
            if(ptr->next == NULL){
                if(strcmp(ptr->texto,"/")==0){

                    main();
                }
            }
            ptr = ptr->next;
        }
        ptr = head;
        if((strcmp(ptr->texto,"mkdisk"))==0){
            //crear_disco(ptr->next);
            printf("crea disco");
            limpiarLista();

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

    void comandoMskdisk(char* cadena){
           char  str[]="uno dos tres cuatro cinco";
           printf(cadena);
           //strcpy(str,cadena);
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

    void token (char *cad){
        //char  cad[] = "Este es un enunciado con 7 tokens";
        char cadena[]="Hola como te va";
        //strcpy(cadena, cad);
        char *ptrToken;

        printf("Los tokens son:" );

        ptrToken = strtok(cadena," ");
            if ( ptrToken != NULL ) {
                printf( "%s\n", ptrToken );
                ptrToken = strtok(NULL, " " );
                ptrToken = "\0";

            }
    }





