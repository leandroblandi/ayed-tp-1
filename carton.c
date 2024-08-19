#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "carton.h"

#define MAXIMO_VALOR_NUMERO 99

struct _Carton {
    int numeros[CANTIDAD_NUMEROS_CARTON];
    char direccionAgencia[LARGO_DIRECCION_AGENCIA];
};

Carton crearCarton(char direccionAgencia[LARGO_DIRECCION_AGENCIA]) {
    validarDireccionAgencia(direccionAgencia);
    Carton c = (Carton) malloc(sizeof(struct _Carton));
    strcpy(c->direccionAgencia, direccionAgencia);
    completarVectorConNumerosAleatorios(c->numeros, CANTIDAD_NUMEROS_CARTON);
    return c;
}

Carton crearCartonPorTeclado() {
    Carton c = (Carton) malloc(sizeof(struct _Carton));
    printf("\nNombre de agencia > ");
    fflush(stdin);
    fgets(c->direccionAgencia, LARGO_DIRECCION_AGENCIA, stdin);
    c->direccionAgencia[strcspn(c->direccionAgencia, "\n")] = '\0';

    validarDireccionAgencia(c->direccionAgencia);
    completarVectorDesdeTeclado(c->numeros, CANTIDAD_NUMEROS_CARTON);

    return c;
}

Carton inicializarCarton() {
    Carton c = (Carton) malloc(sizeof(struct _Carton));
    strcpy(c->direccionAgencia, "");

    for (int i = 0; i < CANTIDAD_NUMEROS_CARTON; i++) {
        c->numeros[i] = -1;
    }
    return c;
}

Carton crearCartonSegunOpcion() {
    char opcion;

    printf("\nElija como quiere generar los numeros\n");
    printf("\na. Aleatoriamente");
    printf("\nb. Manualmente\n");

    do {
        printf("\n(a/b) > ");
        fflush(stdin);
        scanf(" %c", &opcion);
    } while (opcion != 'a' && opcion != 'b');

    if (opcion == 'a') {
        return crearCarton("Quiniela Plus");
    }

    printf("\nRandomizando numeros...\n");
    return crearCartonPorTeclado();
}

char * getCartonDireccionAgencia(Carton c) {
    return c->direccionAgencia;
}

int * getNumerosCarton(Carton c) {
    return c->numeros;
}

void mostrarCarton(Carton c) {
    if (c == NULL || c->direccionAgencia == NULL) {
        return;
    }

    printf("\nCarton(numeros=");

    for (int i = 0; i < CANTIDAD_NUMEROS_CARTON; i++) {

        if (i == CANTIDAD_NUMEROS_CARTON - 1) {
            printf("%d", c->numeros[i]);
        } else {
            printf("%d ", c->numeros[i]);
        }
    }

    printf(", agencia=%s)\n", c->direccionAgencia);
}

void destruirCarton(Carton c) {
    free(c);
}

void completarVectorConNumerosAleatorios(int numeros[CANTIDAD_NUMEROS_CARTON], int largoVector) {
    int numero;

    for (int i = 0; i < largoVector; i++) {
        numero = rand() % MAXIMO_VALOR_NUMERO + 1;

        while (existeNumeroEnVector(numero, numeros)) {
            numero = rand() % MAXIMO_VALOR_NUMERO + 1;
        }
        numeros[i] = numero;
    }
    ordenarVectorBubbleSort(numeros, largoVector);
}

bool existeNumeroEnVector(int numero, int numeros[CANTIDAD_NUMEROS_CARTON]) {

    for (int i = 0; i < CANTIDAD_NUMEROS_CARTON; i++) {
        if(numeros[i] == numero) {
            return true;
        }
    }

    return false;
}

void completarVectorDesdeTeclado(int numeros[CANTIDAD_NUMEROS_CARTON], int largoVector) {
    inicializarVector(numeros);
    int numero;

    for (int i = 0; i < CANTIDAD_NUMEROS_CARTON; i++) {
        numero = obtenerNumeroDesdeTeclado(i);

        while(numero < 0 || numero > 99 || existeNumeroEnVector(numero, numeros) == true) {
            printf("\n[ERR] Motivo/s:\n\t-El numero ingresado no se encuentra en el rango valido (0-99)\n\t-Ya se encuentra en el vector (ingresado=%d)", numero);
            numero = obtenerNumeroDesdeTeclado(i);
        }

        numeros[i] = numero;
    }
    ordenarVectorBubbleSort(numeros, largoVector);
}

void inicializarVector(int numeros[CANTIDAD_NUMEROS_CARTON]) {
    for (int i = 0; i < CANTIDAD_NUMEROS_CARTON; i++) {
        numeros[i] = -1;
    }
}


int obtenerNumeroDesdeTeclado(int i) {
    int numero;
    printf("\nIngrese valor para el numero %d del carton:", i + 1);
    scanf("%d", &numero);
    return numero;
}

void validarDireccionAgencia(char direccionAgencia[LARGO_DIRECCION_AGENCIA]) {
    if (direccionAgencia == NULL || strlen(direccionAgencia) == 0) {
        fprintf(stderr, "[ERR] El nombre de la agencia es invalido");
        exit(-1);
    }
}

void ordenarVectorBubbleSort(int numeros[], int largoVector) {
    for (int i = 0; i < largoVector; i++) {
        for(int k = 0; k < largoVector - 1; k++) {
            if(numeros[k] > numeros[k + 1]) {
                int aux = numeros[k + 1];
                numeros[k + 1] = numeros[k];
                numeros[k] = aux;
            }
        }
    }
}
