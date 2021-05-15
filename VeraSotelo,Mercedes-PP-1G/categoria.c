#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"

int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamCat, char descripcion[20]){
    int todoOk=0;
    for(int i=0; i<tamCat;i++){
        if(categorias[i].id==idCategoria){
            strcpy(descripcion,categorias[i].descripcion);
            break;
        }
    }
    return todoOk;
}
