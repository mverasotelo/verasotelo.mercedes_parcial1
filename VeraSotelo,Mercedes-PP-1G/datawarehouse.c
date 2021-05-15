#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

int hardcodearJuegos(eJuego juegos[],int tamJ, int cant){
    int total=0;
    if(juegos!=NULL && tamJ>0 && cant>=0 && cant<=tamJ){
        for(int i=0; i<cant;i++){
            strcpy(juegos[i].descripcion,descripcionJuego[i]);
            juegos[i].codigo=codigos[i];
            juegos[i].idCategoria=idCategoriaJuego[i];
            juegos[i].importe=importes[i];
            total++;
        }
    }
    return total;
}
