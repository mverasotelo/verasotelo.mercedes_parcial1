#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "juego.h"
#include "categoria.h"

static int codigos[10]={501,500,502,503,501,501,502,503,500,504};

static int idCategoriaJuego[10]={11,11,13,14,12,13,11,14,12,13};

static float importes[10]={1000,200,1500,1300,1250,1500,1250,1002,1250,1006};

static char descripcionJuego[10][10]={
    "TEG",
    "Monopoly",
    "UNO",
    "Trust",
    "Ludo",
    "Ajedrez",
    "Cartas",
    "Damas",
    "Generala",
    "Magia",
};

//prototipos funciones


int hardcodearJuegos(eJuego juegos[],int tamJ, int cant);

#endif // DATAWAREHOUSE_H_INCLUDED
