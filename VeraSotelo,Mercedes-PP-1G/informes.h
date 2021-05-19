#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "alquileres.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"

int mostrarJuegosCategoria(eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


int categoriaPreferidaClientes(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


int juegoPreferidoClientes(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ);


int juegoPreferidoMujeres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ);


int categoriaPreferidaHombres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


int mostrarJuegosCliente(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);

#endif // INFORMES_H_INCLUDED
