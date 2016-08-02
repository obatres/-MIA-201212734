#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char nombre [250];
    char direccion [100];
    int telefono;
}contacto;

void menu (char* nombreArchivo);
contacto crearContacto();
void guardarContacto(Contacto contacto, char* nombreArchivo);
void mostrarAgenda(char* nombreArchivo);

int main()
{
    char nombreArchivo[50]="agenda.bin";

    menu (nombreArchivo);

}

void menu(char* nombreArchivo){
int opcion;

do{
    system("cls");
    printf("");

}
}



/*{
    printf("Hello world!\n");
    return 0;
}*/
