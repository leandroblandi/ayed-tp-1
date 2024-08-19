#ifndef SORTEO_H_INCLUDED
#define SORTEO_H_INCLUDED

#include "persona.h"

#define CANTIDAD_NUMEROS_SORTEO 20

struct _Sorteo;

typedef struct _Sorteo * Sorteo;

/// @brief Crea un sorteo generando los numeros aleatoriamente
/// @return el Sorteo creado
Sorteo crearSorteo();


/// @brief Reliza el paso a paso para jugar
void jugarSorteo();

/// @brief Muestra por consola el sorteo
/// @param sorteo
void mostrarSorteo(Sorteo sorteo);

/// @brief Verifica si el jugador gano
/// @param sorteo
/// @param persona
void verificarSiEsGanador(Sorteo sorteo, Persona persona);

/// @brief Muestra el menu principal del Sorteo
void mostrarMenu();

/// @brief Libera espacio en memoria del struct Sorteo
/// @param sorteo
void destruirSorteo(Sorteo sorteo);


/// @brief Obtiene la cantidad de aciertos
/// @param sorteo
/// @param persona
/// @return La cantidad de aciertos sobre los numeros que salieron del Sorteo
int obtenerCantidadAciertos(Sorteo sorteo, Persona persona);

/// @brief Obtiene la cantidad de aciertos
/// @param sorteo
/// @param persona
void cantidadDeIntentosHastaAcierto(Sorteo sorteo, Persona persona);

/// @brief Guarda en un .txt el resultado del sorteo
/// @param sorteo
/// @param persona
void persistirSorteo(Sorteo sorteo, Persona jugador);

#endif // SORTEO_H_INCLUDED
