#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"
#include "carton.h"

struct _Persona {
    int dni;
    char nombre[LARGO_NOMBRE];
    Carton carton;
};

Persona crearPersona(int dni, char nombre[LARGO_NOMBRE]) {
    validarDatosEntradaCreacionPersona(dni, nombre);
    Persona p = (Persona) malloc(sizeof(struct _Persona));

    p->dni = dni;
    p->carton = inicializarCarton();

    strcpy(p->nombre, nombre);
    return p;
}

Persona crearPersonaPorTeclado() {
    Persona p = (Persona) malloc(sizeof(struct _Persona));
    printf("\nDNI > ");
    scanf("%d", &(p->dni));

    printf("Nombre > ");
    fflush(stdin);
    fgets(p->nombre, LARGO_NOMBRE, stdin);

    p->nombre[strcspn(p->nombre, "\n")] = '\0';
    p->carton = inicializarCarton();

    validarDatosEntradaCreacionPersona(p->dni, p->nombre);
    return p;
}

void mostrarPersona(Persona p) {

    if (p->dni == -1) {
        return;
    }

    printf("\nPersona(dni=%d, nombre=%s)", p->dni, p->nombre);

    if (strlen(getCartonDireccionAgencia(p->carton)) > 0) {
        printf("\nOtros structs asociados:");
        mostrarCarton(p->carton);
    }
}

char * getPersonaNombre(Persona p) {
    return p->nombre;
}

Carton getCartonPersona(Persona p) {
    return p->carton;
}

int getDniPersona(Persona p) {
    return p->dni;
}

Persona agregarCarton(Persona p, Carton c) {
    p->carton = c;
    return p;
}

void destruirPersona(Persona p) {
    free(p);
}

void validarDatosEntradaCreacionPersona(int dni, char nombre[LARGO_NOMBRE]) {
    if (dni <= 0 || nombre == NULL || strlen(nombre) == 0) {
        fprintf(stderr, "[ERR] El DNI/Nombre son invalidos");
        exit(-1);
    }
}
