#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "fecha.h"
#include "juego.h"
#include "cliente.h"

typedef struct {
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;

}eAlquiler;


/** \brief Inicializa alquileres a isEmpty=1
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño
 * \return int devuelve 0 si hay error 1 si esta todoOk
 *
 */
int inicializarAlquileres(eAlquiler alquileres[], int tam);

/** \brief busca lugar libre para alquiler
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño
 * \return int devuelve indice libre
 *
 */
int buscarLugarAlq(eAlquiler alquileres[], int tam);

/** \brief
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \param pId int*
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int altaAlquiler(eAlquiler alquileres[], int tam, int *pId, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);

/** \brief
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño
 * \return int
 *
 */
int listarAlquileres(eAlquiler alquileres[], int tam);

/** \brief muestra un alquiler
 *
 * \param alquiler eAlquiler
 * \return void
 *
 */
void mostrarAlquiler(eAlquiler alquiler);

/** \brief cuenta los alquileres activos
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño

 * \return int devuelve numero de alquileres activos
 *
 */
int contarAlquileres(eAlquiler alquileres[],int tam);


#endif // ALQUILERES_H_INCLUDED
