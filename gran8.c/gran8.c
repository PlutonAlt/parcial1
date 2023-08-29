#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcion;
    int suma_dados, resultado;
    srand(time(NULL));  // Inicializar la semilla del generador de números aleatorios
    FILE *archivo;
    int dado1 = rand() % 6 + 1; 
                int dado2 = rand() % 6 + 1;
                suma_dados = dado1 + dado2;

    

    do {
        printf("\n--- Menú ---\n");
        printf("1. Jugar\n");
        printf("2. Ver historial\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
  
                printf("Resultado del lanzamiento: %d + %d = %d\n", dado1, dado2, suma_dados);

                if (suma_dados == 8) {
                    printf("¡Ganaste!\n");
                    resultado = 1;
                } else if (suma_dados == 7) {
                    printf("¡Perdiste!\n");
                    resultado = 0;
                } else {
                    printf("Sigue jugando...\n");
                    resultado = 2;
                }

                // Guardar el resultado en el historial
                archivo = fopen("historial.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escritura.\n");
                } else {
                    fprintf(archivo, "Resultado: %d\n", resultado);
                    fclose(archivo);
                }
                break;

            case 2:
                // Ver historial
                archivo = fopen("historial.txt", "r");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para lectura.\n");
                } else {
                    printf("\nHistorial:\n");
                    char linea[50];
                    while (fgets(linea, sizeof(linea), archivo) != NULL) {
                        printf("%s", linea);
                    }
                    fclose(archivo);
                }
                break;

            case 3:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

