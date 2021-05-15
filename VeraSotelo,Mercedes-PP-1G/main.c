#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMC 20
#define TAMA 20
#define TAMJ 10
#define TAMCAT 5
#include "cliente.h"
#include "inputs.h"
#include "fecha.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"
#include "alquileres.h"
#include "datawarehouse.h"

int main()
{
    int pIdCliente=1000;
    int pIdAlq=2000;
    eCliente clientes[TAMC];
    eAlquiler alquileres[TAMA];
    eJuego juegos[TAMJ];
    inicializarClientes(clientes, TAMC);
    inicializarAlquileres(alquileres,TAMA);
    hardcodearJuegos(juegos, TAMJ, TAMJ);
    char salir;

    eCategoria categorias[TAMCAT] ={
        {10,"mesa"},
        {11,"azar"},
        {12,"estrategia"},
        {13,"salon"},
        {14,"magia"},
    };

    //menu de opciones
    do{
        switch(menuOpciones()){
        case 1:
            if(altaCliente(clientes, TAMC, &pIdCliente)){
                printf("Alta exitosa!\n\n");
            }else{
                printf("No se ha podido realizar el alta\n\n");
            }
            break;
        case 2:
            if(contarClientes(clientes,TAMC)==0){
                printf("No hay clientes para modificar\n\n");
            }else{
                if(modificarCliente(clientes,TAMC)){
                    printf("Modificacion exitosa!\n\n");
                }
            }
            break;
        case 3:
            if(contarClientes(clientes,TAMC)==0){
                printf("No hay clientes para dar de baja\n\n");
            }else{
                if(bajaCliente(clientes, TAMC)){
                    printf("Baja exitosa!\n\n");
                }else{
                    printf("No se ha podido realizar la baja\n\n");
                }
            }
            break;
        case 4:
            mostrarClientes(clientes, TAMC);
            break;
        case 5:
            if(contarClientes(clientes,TAMC)==0){
                printf("Primero debe ingresar al menos un cliente\n\n");
            }else{
                if(altaAlquiler(alquileres, TAMA,&pIdAlq, clientes, TAMC, juegos, TAMJ, categorias, TAMCAT)){
                    printf("Alta exitosa!\n\n");
                }
            }
            break;
        case 6:
            if(contarAlquileres(alquileres,TAMA)>0){
               listarAlquileres(alquileres,TAMA);
            }else{
                printf("No hay alquileres para mostrar\n\n");
            }
            break;
        case 7:
            printf("Está seguro de que desea salir?\n");
            fflush(stdin);
            salir=getchar();
            printf("\n");
            if(salir=='s'){
                printf("Programa finalizado\n\n");
            }
            break;
        }
    }while(salir!='s');

    return 0;
}
