#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool es_primo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int opcion;
    int numero;
    FILE *archivo;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Verificar número primo\n");
        printf("2. Ver historial\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Verificar número primo
                printf("Ingrese un número: ");
                scanf("%d", &numero);

                if (es_primo(numero)) {
                    printf("%d es un número primo.\n", numero);
                } else {
                    printf("%d es un número compuesto.\n", numero);
                }

                // Guardar el resultado en el historial
                archivo = fopen("historial.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escritura.\n");
                } else {
                    fprintf(archivo, "Número: %d, Es primo: %s\n", numero, es_primo(numero) ? "Sí" : "No");
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
                    char linea[100];
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

