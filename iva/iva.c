#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;
    float valor;
    FILE *archivo;

    do {
        // Mostrar el menú
        printf("\n--- Menú ---\n");
        printf("1. Calcular IVA\n");
        printf("2. Ver historial\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un valor: ");
                scanf("%f", &valor);

                float iva = valor * 0.12;
                float valor_sin_iva = valor - iva;

                printf("Valor: %.2f\n", valor);
                printf("IVA (12%%): %.2f\n", iva);
                printf("Valor sin IVA: %.2f\n", valor_sin_iva);

                // Guardar el resultado en el historial
                archivo = fopen("historial.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escritura.\n");
                } else {
                    fprintf(archivo, "Valor: %.2f, IVA: %.2f, Valor sin IVA: %.2f\n", valor, iva, valor_sin_iva);
                    fclose(archivo);
                }
                break;

            case 2:
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

