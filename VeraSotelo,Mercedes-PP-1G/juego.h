#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "categoria.h"

typedef struct {
    int codigo;
    char descripcion [20];
    float importe;
    int idCategoria;
}eJuego;


int mostrarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamCat);

void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat);

#endif // JUEGO_H_INCLUDED
