#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int menuOpciones(){
    int opcion;
    printf("     GESTION DE JUEGOS\n");
    printf("1) Alta Cliente\n");
    printf("2) Modificar Cliente\n");
    printf("3) Baja Cliente\n");
    printf("4) Listar Clientes\n");
    printf("5) Alta alquiler\n");
    printf("6) Listar alquileres\n");
    printf("7) Salir\n\n");
    opcion=getOption(1,7);
    return opcion;
}

int submenuModificar(){
    int opcion;
    printf("Que dato desea modificar?\n1. Nombre\n2. Apellido\n3. Sexo\n\n");
	opcion=getOption(1,3);
    return opcion;
}

int getOption(int min, int max){
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<min||opcion>max){
        printf("Opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}

int getString(char *string, int maxLen){
    int retorno=0;
    char aux[100];
    if(string!=NULL && maxLen>0 && maxLen<99){
        fflush(stdin);
        fgets(aux,100,stdin);
        while(strlen(aux)>maxLen){
            printf("El maximo numero de caracteres permitidos es %d. Reingrese dato: ",maxLen);
            fflush(stdin);
            fgets(aux,100,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(string, aux);
        retorno=1;
    }
    return retorno;
}

int getSexo(char* sexo){
    int retorno=0;
    printf ("Ingrese sexo (m/f): ");
    if(sexo!=NULL){
        scanf ("%c", sexo);
        while(*sexo!='f'&&*sexo!='m'){
            printf ("Error. Ingrese m/f: ");
            fflush(stdin);
            scanf ("%c", sexo);
        }
        retorno=1;
    }
    return retorno;
}
