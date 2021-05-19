#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

//funciones menu de opciones y validacion datos

/** \brief menu de opciones
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int menuOpciones();

/** \brief submenu de datos a modificar
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuModificar();


/** \brief submenu de informes
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuInformes();


/** \brief pide y valida una opcion
 *
 * \param min int opcion minima
 * \param max int opcion maxima
 *
 */
int getOption(int min, int max);

/** \brief pide y valida extension de un string
 *
 * \param string char* string
 * \param maxLen int extension maxima
 * \return int devuelve 0 si esta todo OK y -1 si hay algun error
 *
 */
int getString(char string[], int maxLen);


/** \brief pide el sexo, lo valida y lo guarda en la direccion de memoria indicada
 *
 * \param telefono char* puntero al sexo
 * \return int devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int getSexo(char* sexo);


#endif // INPUTS_H_INCLUDED
