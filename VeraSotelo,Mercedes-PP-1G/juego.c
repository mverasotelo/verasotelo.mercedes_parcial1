#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"

int mostrarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamCat){
    int todoOk=0;
    printf(" JUEGOS\n");
    if(juegos!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            mostrarJuego(juegos[i], categorias, tamCat);
        }
        todoOk=1;
    }
    printf("\n");
    return todoOk;
}

void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat){
    char descripcion[20];
    cargarDescripcionCategoria(juego.idCategoria, categorias, tamCat, descripcion);
    printf("%02d- %s- %s- $%.2f\n",juego.codigo, juego.descripcion, descripcion, juego.importe);
}
