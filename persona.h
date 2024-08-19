#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "carton.h"

#define LARGO_NOMBRE 30

struct _Persona;

typedef struct _Persona * Persona;

/// @brief Crea una persona en base a los parametros proporcioandos
/// @param dni El DNI
/// @param nombre El nombre
/// @return una Persona
Persona crearPersona(int dni, char nombre[LARGO_NOMBRE]);

/// @brief Crea una Persona por teclado
/// @return una Persona
Persona crearPersonaPorTeclado();

/// @brief Muestra por consola los datos de la Persona
/// @param p la Persona a mostrar
void mostrarPersona(Persona p);

/// @brief Obtiene el nombre de la persona
/// @param p La persona
/// @return El nombre
char * getPersonaNombre(Persona p);

/// @brief Obtiene el carton de la persona
/// @param p La persona
/// @return El Carton
Carton getCartonPersona(Persona p);

/// @brief Obtiene el DNI de la persona
/// @param p La persona
/// @return El DNI
int getDniPersona(Persona p);

/// @brief Enlaza el Carton a la Persona
/// @param p La Persona
/// @param c El Carton
/// @return La Persona con el Carton agregado
Persona agregarCarton(Persona p, Carton c);

/// @brief Libera espacio de memoria de la Persona
/// @param p La persona
void destruirPersona(Persona p);

/// @brief Valida el DNI y el Nombre de la Persona
/// @param dni El DNI
/// @param nombre El nombre
void validarDatosEntradaCreacionPersona(int dni, char nombre[LARGO_NOMBRE]);

#endif // PERSONA_H_INCLUDED
