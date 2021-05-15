#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "juego.h"


int inicializarAlquileres(eAlquiler alquileres[], int tam){
    int retorno=0;
    if(alquileres!=NULL && tam>0){
        for(int i=0; i<tam;i++){
            alquileres[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}

int buscarLugarAlq(eAlquiler alquileres[], int tam){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if (alquileres[i].isEmpty==1){
            indice=i;
            break;
        }
    }
    return indice;
}

int altaAlquiler(eAlquiler alquileres[], int tam, int *pId, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int todoOk=0;
    int indice=buscarLugarAlq(alquileres, tam);
    eAlquiler nuevoAlquiler;
    if(alquileres != NULL && tam>0 && pId != NULL && categorias != NULL && tamCat>0 && clientes != NULL && tamC>0){
        if(indice==-1){
            printf("No hay lugar disponible.\n");
        }else{
            nuevoAlquiler.codigoAlquiler=*pId;
            printf("    ALTA DE ALQUILERES\n");
            printf ("Codigo de alquiler: %d\n", nuevoAlquiler.codigoAlquiler);
            printf("\n");
            mostrarClientes(clientes, tamC);
            printf("\n");
            printf ("Ingrese codigo cliente: ");
            scanf("%d", &nuevoAlquiler.codigoCliente);
            printf("\n");
            if(buscarCliente(clientes, tamC, nuevoAlquiler.codigoCliente)){
                mostrarJuegos(juegos,  tamJ, categorias, tamCat);
                printf("\n");
                printf ("Ingrese codigo de juego: ");
                scanf("%d", &nuevoAlquiler.codigoJuego);
                printf ("Ingrese fecha (dd/mm/aaaa): ");
                scanf ("%d/%d/%d",&nuevoAlquiler.fecha.dia, &nuevoAlquiler.fecha.mes, &nuevoAlquiler.fecha.anio);
                printf("\n");
                nuevoAlquiler.isEmpty=0;
                alquileres[indice]=nuevoAlquiler;
                todoOk=1;
                (*pId)++;
            }else{
                printf ("El codigo del cliente no existe\n\n");
            }
        }
    }
    return todoOk;
}

int contarAlquileres(eAlquiler alquileres[],int tam){
    int contador=0;
    if(alquileres != NULL && tam>0){
        for(int i=0;i<tam;i++){
            if (alquileres[i].isEmpty==0){
                contador++;
            }
        }
    }
    return contador;
}

int listarAlquileres(eAlquiler alquileres[], int tam){
    int todoOk=0;
    int flag=1;
    printf(" Id   |  Id cliente |  Id juego  |    Fecha\n");
    if(alquileres != NULL && tam>0){
        for(int i=0;i<tam;i++){
            if(!alquileres[i].isEmpty){
                mostrarAlquiler(alquileres[i]);
                flag=0;
            }
        }
        if(flag){
            printf("No hay almuerzos para mostrar\n");
        }
    todoOk=1;
    }
    printf("\n");
    return todoOk;
}

void mostrarAlquiler(eAlquiler alquiler){
    printf(" %d        %d        %d        %02d/%02d/%d\n", alquiler.codigoAlquiler, alquiler.codigoCliente, alquiler.codigoJuego, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
}
