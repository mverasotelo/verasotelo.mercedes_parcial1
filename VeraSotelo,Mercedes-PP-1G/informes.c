#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

int mostrarJuegosCategoria(eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int todoOk=0;
    int idCategoria;
    int flag=1;
    mostrarCategorias(categorias, tamCat);
    printf("\n");
    printf("Ingrese ID de la categoria a listar: ");
    scanf("%d", &idCategoria);
    printf("\n");

    if(categorias!=NULL && tamCat>0 && juegos!=NULL && tamJ>0){
        for(int i=0; i<tamCat;i++){
            if(idCategoria==categorias[i].id){
                printf("                        Juegos de %s\n", categorias[i].descripcion);
                printf(" CODIGO         DESCRIPCION             CATEGORIA            IMPORTE\n");
                for(int j=0;j<tamJ;j++){
                    if(juegos[j].idCategoria==categorias[i].id){
                        mostrarJuego(juegos[j], categorias, tamCat);
                        flag=0;
                    }
                }
            }
        }
        if(flag){
            printf("              No hay juegos de esta categoria\n");
        }
    todoOk=1;
    printf("\n\n");
    }
    return todoOk;
}

int juegoPreferidoClientes(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ){
    int todoOk=0;
    int contJuegos[tamJ];
    for(int i=0;i<tamJ;i++){
        contJuegos[i]=0;
    }
    int juegoPreferido=0;
    char juego[10];
    if(alquileres!=NULL && tam>0 && juegos!=NULL && tamJ>0){
            for(int j=0;j<tamJ;j++){
                for(int k=0; k<tam; k++){
                    if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                        contJuegos[j]++;
                    }
                }
                printf("Juego %s: %d\n", juegos[j].descripcion, contJuegos[j]);
            }
        //comparo los contadores de categorias para ver cual es el mayor
        for(int l=0;l<tamJ;l++){
            if(juegoPreferido<contJuegos[l]){
                juegoPreferido=contJuegos[l];
                strcpy(juego,juegos[l].descripcion);
            }
        }
        //imprimo la categoria favorita si hay empate de categorias, informo todas
        printf("\n");
        printf("Juego/s favorito/s de los clientes: ");
            for(int m=0;m<tamJ;m++){
                if(juegoPreferido==contJuegos[m]){
                    printf("%s ", juegos[m].descripcion);
            }
        }
        todoOk=1;
        printf("\n\n");
        }
    return todoOk;
}


int categoriaPreferidaClientes(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int todoOk=0;
    int contCateg[tamCat];
    for(int i=0;i<tamCat;i++){
        contCateg[i]=0;
    }
    int categPreferida=0;
    char categoria[10];
    if(alquileres!=NULL && tam>0 && categorias!=NULL && tamCat>0 && juegos!=NULL && tamJ>0){
        for(int i=0; i<tamCat;i++){
            for(int j=0;j<tamJ;j++){
                if(juegos[j].idCategoria==categorias[i].id){
                    for(int k=0; k<tam; k++){
                        if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                            contCateg[i]++;
                        }
                    }
                }
            }
            printf("Categoria %s: %d\n", categorias[i].descripcion, contCateg[i]);
        }
        //comparo los contadores de categorias para ver cual es el mayor
        for(int l=0;l<tamCat;l++){
            if(categPreferida<contCateg[l]){
                categPreferida=contCateg[l];
                strcpy(categoria,categorias[l].descripcion);
            }
        }
        //imprimo la categoria favorita si hay empate de categorias, informo todas
        printf("\n");
        printf("Categoria favorita de los clientes: ");
            for(int m=0;m<tamCat;m++){
                if(categPreferida==contCateg[m]){
                    printf("%s ", categorias[m].descripcion);
            }
        }
        todoOk=1;
        printf("\n\n");
        }
    return todoOk;
}

int juegoPreferidoMujeres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ){
    int todoOk=0;
    int contJuegos[tamJ];
    for(int i=0;i<tamJ;i++){
        contJuegos[i]=0;
    }
    int juegoPreferido=0;
    char juego[10];
    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0){
        for(int j=0;j<tamJ;j++){
            for(int k=0; k<tam; k++){
                if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                    for(int l=0;l<tamC;l++){
                            if(alquileres[k].codigoCliente==clientes[l].codigo&&clientes[l].sexo=='f'){
                                contJuegos[j]++;
                            }
                        }
                    }
                }
                printf("Juego %s: %d\n", juegos[j].descripcion, contJuegos[j]);
            }
        //comparo los contadores de categorias para ver cual es el mayor
        for(int l=0;l<tamJ;l++){
            if(juegoPreferido<contJuegos[l]){
                juegoPreferido=contJuegos[l];
                strcpy(juego,juegos[l].descripcion);
            }
        }
        //imprimo la categoria favorita si hay empate de categorias, informo todas
        printf("\n");
        printf("Juego/s favorito/s de las mujeres: ");
            for(int m=0;m<tamJ;m++){
                if(juegoPreferido==contJuegos[m]){
                    printf("%s ", juegos[m].descripcion);
            }
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}

int categoriaPreferidaHombres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int todoOk=0;
    int contCateg[tamCat];
    for(int i=0;i<tamCat;i++){
        contCateg[i]=0;
    }
    int categPreferida = 0;
    char categoria[10];
    if(alquileres!=NULL && tam>0 && categorias!=NULL && tamCat>0 && juegos!=NULL && tamJ>0 && clientes!=NULL && tamC>0 ){
        for(int i=0; i<tamCat;i++){
            for(int j=0;j<tamJ;j++){
                if(juegos[j].idCategoria==categorias[i].id){
                    for(int k=0; k<tam; k++){
                        if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                            for(int l=0;l<tamC;l++){
                                if(alquileres[k].codigoCliente==clientes[l].codigo&&clientes[l].sexo=='m'){
                                    contCateg[i]++;
                                }
                            }
                        }
                    }
                }
            }
            printf("Categoria %s: %d\n", categorias[i].descripcion, contCateg[i]);
        }
        //comparo los contadores de categorias para ver cual es el mayor
        for(int l=0;l<tamCat;l++){
            if(categPreferida<contCateg[l]){
                categPreferida=contCateg[l];
                strcpy(categoria,categorias[l].descripcion);
            }
        }
        //imprimo la categoria favorita si hay empate de categorias, informo todas
        printf("\n");
        printf("Categoria favorita de los hombres: ");
            for(int m=0;m<tamCat;m++){
                if(categPreferida==contCateg[m]){
                    printf("%s ", categorias[m].descripcion);
            }
        }
        todoOk=1;
        printf("\n\n");
        }
    return todoOk;
}

int mostrarJuegosCliente(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat ){
    int todoOk=0;
    int idCliente;
    int flag=1;
    eCliente cliente;
    int indiceCliente;

    mostrarClientes(clientes, tamC);
    printf("\n");
    printf("Ingrese ID del cliente: ");
    scanf("%d", &idCliente);
    indiceCliente=buscarCliente(clientes, tamC, idCliente);
    if(indiceCliente!=-1){
        cliente=clientes[indiceCliente];
    }else{
        printf("Codigo de cliente inexistente.\n");
    }
    printf("\n");

    if(clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0&& alquileres!=NULL && tam>0 && categorias!=NULL && tamCat>0){
        printf("                        Juegos alquilados por %s %s\n", cliente.nombre, cliente.apellido);
        printf(" CODIGO       CLIENTE             JUEGO            CATEGORIA            FECHA\n");
        for(int j=0;j<tam;j++){
            if(alquileres[j].codigoCliente==idCliente){
                mostrarAlquiler(alquileres[j],clientes, tamC, juegos, tamJ, categorias, tamCat);
                flag=0;
            }
        }
        if(flag){
            printf("              El cliente no ha alquilado ningun juego\n");
        }
    todoOk=1;
    printf("\n\n");
    }
    return todoOk;
}
