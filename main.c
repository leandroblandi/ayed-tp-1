#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "persona.h"
#include "carton.h"
#include "sorteo.h"

int main()
{
    srand(time(NULL));
    jugarSorteo();
    return 0;
}

void jugarSorteo() {
    mostrarMenu();

    printf("\n1. Creacion del jugador");
    Persona persona = crearPersonaPorTeclado();

    printf("\n2. Carton de juego");
    Carton carton = crearCartonSegunOpcion();
    agregarCarton(persona, carton);

    sleep(2);
    printf("\nNumeros del carton generados:\n");
    mostrarCarton(carton);

    printf("\n3. Jugar");
    Sorteo sorteo = crearSorteo(persona);

    printf("\n\nPreparando Sorteo...");
    sleep(2);

    printf("\nRandomizando numeros...\n");
    sleep(2);

    printf("\nNumeros de Sorteo generados:\n");
    mostrarSorteo(sorteo);
    verificarSiEsGanador(sorteo, persona);

    cantidadDeIntentosHastaAcierto(sorteo, persona);

    printf("\nGenerando comprobante de sorteo...");
    sleep(1);
    persistirSorteo(sorteo, persona);
}

void mostrarMenu() {
    printf("\n=== Bienvenido a Quiniela Plus ===\n");
    printf("\n8 aciertos = $11M !!!");
    printf("\n7 aciertos = $20K !!");
    printf("\n6 aciertos = $500 !");
    printf("\n6 aciertos = $50\n");
}

