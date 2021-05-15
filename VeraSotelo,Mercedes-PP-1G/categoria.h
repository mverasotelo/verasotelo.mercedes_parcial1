#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct {
    int id;
    char descripcion [20];
}eCategoria;


int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamCat, char descripcion[20]);

#endif // CATEGORIA_H_INCLUDED
