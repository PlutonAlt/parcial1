#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int calificaciones[5];
    int suma = 0;
    float media, mediana, moda, rango, varianza, desviacion;

    int opcion;
 	FILE *archivo;
    do {
        // Mostrar el menú
        printf("\n--- Menú ---\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Ver historial\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Ingresar calificaciones
                printf("Ingrese 5 calificaciones entre 0 y 100:\n");
                for (int i = 0; i < 5; i++) {
                    printf("Calificación %d: ", i + 1);
                    scanf("%d", &calificaciones[i]);
                    suma += calificaciones[i];
                }
     
    media = (float)suma / 5;

    int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
    qsort(calificaciones, 5, sizeof(int), comparar);

    mediana = calificaciones[2];

    int contador = 1, modaContador = 1;
    moda = calificaciones[0];
    for (int i = 1; i < 5; i++) {
        if (calificaciones[i] == calificaciones[i - 1]) {
            contador++;
            if (contador > modaContador) {
                modaContador = contador;
                moda = calificaciones[i];
            }
        } else {
            contador = 1;
        }
    }

    rango = calificaciones[4] - calificaciones[0];

    float sumCuadrados = 0;
    for (int i = 0; i < 5; i++) {
        sumCuadrados += pow(calificaciones[i] - media, 2);
    }
    varianza = sumCuadrados / 5;
    desviacion = sqrt(varianza);
    
                break;

            case 2:
                // Ver historial
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para lectura.\n");
                } else {
                    printf("\nHistorial:\n");
                    char caracter;
                    while ((caracter = fgetc(archivo)) != EOF) {
                        printf("%c", caracter);
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

