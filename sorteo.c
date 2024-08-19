#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorteo.h"
#include "carton.h"
#include "persona.h"

struct _Sorteo {
    int numeros[CANTIDAD_NUMEROS_SORTEO];
};

Sorteo crearSorteo() {
  Sorteo sorteo = (Sorteo) malloc(sizeof(struct _Sorteo));
  completarVectorConNumerosAleatorios(sorteo->numeros, CANTIDAD_NUMEROS_SORTEO);
  return sorteo;
}

void verificarSiEsGanador(Sorteo sorteo, Persona persona) {
  int aciertos = obtenerCantidadAciertos(sorteo, persona);
  char mensaje[25] = "";

  switch (aciertos) {
      case 8:
          strcpy(mensaje, "Has ganado $11M de pesos");
          break;
      case 7:
          strcpy(mensaje, "Has ganado $20K pesos");
          break;
      case 6:
          strcpy(mensaje, "Has ganado $500 pesos");
          break;
      case 5:
          strcpy(mensaje, "Has ganado $50 pesos");
          break;
      default:
          printf("\n:( Lo sentimos, no has ganado esta vez, solo contaste con %d aciertos, intentalo nuevamente.\n", aciertos);
          return;
  }
  printf("\n[ACIERTOS: %d] %s", aciertos, mensaje);
}

void mostrarSorteo(Sorteo sorteo) {
  printf("\nSorteo(numeros=");

  for (int i = 0; i < CANTIDAD_NUMEROS_SORTEO; i++) {

    if (i == CANTIDAD_NUMEROS_SORTEO - 1) {
      printf("%d", sorteo->numeros[i]);

    } else {
      printf("%d ", sorteo->numeros[i]);
    }

  }
  printf(")\n");
}

void destruirSorteo(Sorteo sorteo) {
  free(sorteo);
}

int obtenerCantidadAciertos(Sorteo sorteo, Persona p) {
  int aciertos = 0;

  for (int i = 0; i < CANTIDAD_NUMEROS_CARTON; i++) {
    for (int k = 0; k < CANTIDAD_NUMEROS_SORTEO; k++) {
      if(getNumerosCarton(getCartonPersona(p))[i] == sorteo->numeros[k]) {
        aciertos++;
      }
    }
  }
  return aciertos;
}

void cantidadDeIntentosHastaAcierto(Sorteo sorteo, Persona persona) {
  int aciertos = 0;
  int intentos = 0;

  do {
    completarVectorConNumerosAleatorios(sorteo->numeros, CANTIDAD_NUMEROS_SORTEO);
    aciertos = obtenerCantidadAciertos(sorteo, persona);
    intentos++;
  } while(aciertos != 8);

  printf("\nSe intento %d veces hasta obtener el resultado", intentos);
  mostrarSorteo(sorteo);
}

void persistirSorteo(Sorteo sorteo, Persona jugador) {
    FILE * archivoSorteo = fopen("comprobante_sorteo.txt", "w");

    if (archivoSorteo == NULL) {
        printf("\n[ERR] Hubo un problema al crear/sobreescribir el archivo");
    }

    fprintf(archivoSorteo, "=== SORTEO ===\n");
    fprintf(archivoSorteo, "\nNumeros del sorteo (en total 22):\n");

    for (int i = 0; i < CANTIDAD_NUMEROS_SORTEO; i++) {
        // Si es la ultima iteracion, quitamos la coma final ','
        if (i == CANTIDAD_NUMEROS_SORTEO - 1) {
            fprintf(archivoSorteo, "%d", sorteo->numeros[i]);
        } else {
            fprintf(archivoSorteo, "%d, ", sorteo->numeros[i]);
        }
    }

    fprintf(archivoSorteo, "\nDatos del jugador:\n");
    fprintf(archivoSorteo, "\nNombre: %s", getPersonaNombre(jugador));
    fprintf(archivoSorteo, "\nDNI: %d\n", getDniPersona(jugador));
    fprintf(archivoSorteo, "\nDatos del carton del jugador\n");

    for (int j = 0; j < CANTIDAD_NUMEROS_CARTON; j++) {
        // Si es la ultima iteracion, quitamos la coma final ','
        if (j == CANTIDAD_NUMEROS_CARTON - 1) {
            fprintf(archivoSorteo, "%d", getNumerosCarton(getCartonPersona(jugador))[j]);
        } else {
            fprintf(archivoSorteo, "%d, ", getNumerosCarton(getCartonPersona(jugador))[j]);
        }
    }

    printf("\nComprobante 'comprobante_sorteo.txt' generado exitosamente\n");
    fclose(archivoSorteo);
}
