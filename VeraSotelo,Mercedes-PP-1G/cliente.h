#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "inputs.h"

typedef struct {
    int codigo;
    char nombre [51];
    char apellido [51];
    char sexo;
    char telefono[21];
    int isEmpty;

}eCliente;

//funciones

/** \brief Inicializa el campo "isEmpty" de todos los valores de la lista de clientes en 1 (libre)
 *
 * \param clientes[] eCliente - Lista total de clientes
 * \param tam int - Tamaño de la lista de clientes
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int inicializarClientes(eCliente clientes[], int tam);

/** \brief Busca si hay lugar libre en la lista de clientes
 *
 * \param clientes[] eCliente - Lista total de clientes
 * \param tam int - Tamaño de la lista de clientes
 * \return int - Devuelve el primer indice libre en la lista, sino hay lugar devuelve -1
 *
 */
int buscarLugar(eCliente clientes[], int tam);

/** \brief Indica si un cliente esta activo
 *
 * \param cliente eCliente - cliente a evaluar
 * \return int - Devuelve 1 si esta activo y 0 si esta inactivo
 *
 */
int clienteActivo(eCliente cliente);


int contarClientes(eCliente clientes[],int tam);


/** \brief Alta de un nuevo cliente
 *
 * \param clientes[] eCliente lista de clientes donde guardar el nuevo cliente
 * \param tam int tamaño de la lista de clientes
 * \param pId int* legajo a asignar
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int altaCliente(eCliente clientes[], int tam, int *pId);


int ordenarClientes(eCliente clientes[], int tam);


int mostrarClientes(eCliente clientes[], int tam);


void mostrarCliente(eCliente cliente);


int buscarCliente(eCliente clientes[], int tam, int codigo);


int modificarCliente(eCliente clientes[], int tam);


int modificarDato(eCliente clientes[], int tam, int legajo, int datoModif);


int bajaCliente(eCliente clientes[], int tam);


#endif // CLIENTE_H_INCLUDED
