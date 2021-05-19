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
#include "informes.h"
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
    hardcodearClientes(clientes, TAMC, 10, &pIdCliente);
    hardcodearAlquileres(alquileres, TAMA, 10, &pIdAlq);
    char salir;

    eCategoria categorias[TAMCAT] ={
        {10,"Mesa"},
        {11,"Azar"},
        {12,"Estrategia"},
        {13,"Salon"},
        {14,"Magia"},
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
                int codigoBaja=bajaCliente(clientes, TAMC);
                if(codigoBaja!=-1){
                    bajaAlquileresCliente(alquileres, TAMA, codigoBaja);
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
                listarAlquileres(alquileres,TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAMCAT);
            }else{
                printf("No hay alquileres para mostrar\n\n");
            }
            break;
        case 7:
            if(contarAlquileres(alquileres,TAMA)>0){
                switch(submenuInformes()){
                    case 1:
                        mostrarJuegosCategoria(juegos,TAMJ,categorias, TAMCAT);
                        break;
                    case 2:
                        categoriaPreferidaClientes(alquileres, TAMA, juegos, TAMJ, categorias, TAMCAT);
                        break;
                    case 3:
                        juegoPreferidoClientes(alquileres, TAMA, juegos, TAMJ);
                        break;
                    case 4:
                        juegoPreferidoMujeres(alquileres, TAMA, clientes, TAMC, juegos, TAMJ);
                        break;
                    case 5:
                        categoriaPreferidaHombres(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAMCAT);
                        break;
                    case 6:
                        mostrarJuegosCliente(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAMCAT);
                        break;
                    case 7:
                        break;
                    case 8:
                        menuOpciones();
                        break;
                }
            }else{
                printf("No hay datos para informar\n\n");
            }
            break;
        case 8:
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
