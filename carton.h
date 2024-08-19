#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

#include <stdbool.h>

#define CANTIDAD_NUMEROS_CARTON 8
#define LARGO_DIRECCION_AGENCIA 20

struct _Carton;

typedef struct _Carton * Carton;

/// @brief Crea un Carton con numeros aleatorios
/// @param direccionAgencia La direccion de la agencia
/// @return un Carton con los datos proporcionados
Carton crearCarton(char direccionAgencia[LARGO_DIRECCION_AGENCIA]);


/// @brief Crea un Carton con todos los datos por teclado
/// @return un Carton con los datos proporcionados
Carton crearCartonPorTeclado();

/// @brief Crea un carton vacio, util para inicializar dentro de un arreglo
/// @return un Carton vacio
Carton inicializarCarton();


/// @brief Crea un carton (aleatorio, o por teclado) segun opcion
/// @return el Carton creado
Carton crearCartonSegunOpcion();


/// @brief Obtiene el valor de la direccion de agencia
/// @param c El carton a obtener la direccion de agencia
/// @return La direccion de agencia
char * getCartonDireccionAgencia(Carton c);

/// @brief Obtiene el vector de numeros
/// @param c El carton a obtener el vector
/// @return El vector con los numeros
int * getNumerosCarton(Carton c);

/// @brief Muestra un Carton por consola
/// @param c el Carton
void mostrarCarton(Carton c);

/// @brief Libera espacio en memoria del Carton
/// @param c el Carton a destruir
void destruirCarton(Carton c);

/// @brief Completa el vector con numeros generados aleatoriamente entre el 0-99
/// @param numeros El vector a rellenar
void completarVectorConNumerosAleatorios(int numeros[CANTIDAD_NUMEROS_CARTON], int largoVector);

/// @brief Verifica si existe un numero dentro del vector
/// @param numero El numero a verificar
/// @param numeros El vector
/// @return true Si el numero ya esta en el vector
bool existeNumeroEnVector(int numero, int numeros[CANTIDAD_NUMEROS_CARTON]);

/// @brief Completa el vector leyendo desde teclado
/// @param numeros El vector a rellenar
void completarVectorDesdeTeclado(int numeros[CANTIDAD_NUMEROS_CARTON], int largoVector);

/// @brief Completa el vector con todos los valores en -1
/// @param numeros El vector a rellenar
void inicializarVector(int numeros[CANTIDAD_NUMEROS_CARTON]);

/// @brief Lee desde teclado un numero
/// @param i La posicion, utilizado para decir 'posicion x'
/// @return El numero leido por teclado
int obtenerNumeroDesdeTeclado(int i);

/// @brief Valida si la direccion de agencia es correctas
/// @param direccionAgencia La direccion a validar
void validarDireccionAgencia(char direccionAgencia[LARGO_DIRECCION_AGENCIA]);

/// @brief Ordena el vector de numeros mediante el algoritmo de BubbleSort
/// @param numeros El vector a ordenar
void ordenarVectorBubbleSort(int numeros[], int largoVector);

#endif // CARTON_H_INCLUDED
