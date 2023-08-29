#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opcion;
    FILE *archivo;
    char nombre[100];
    int aciertos = 0;
    char respuesta[100];

    do {
        printf("\n--- Menú ---\n");
        printf("1. Jugar adivinanzas\n");
        printf("6. Ver historial\n");
        printf("7. Ingresar nombre y guardar aciertos\n");
        printf("8. Eliminar historial\n");
        printf("9. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Elije una adivinanza:\n");
                printf("1. Abierto siempre estoy para todos los niños. Cerrado y solo me quedo los domingos.\n");
                printf("2. Soy pequeña y de cristal, méteme al hoyo y no perderás.\n");
                printf("3. Se la doy a todo el mundo y me quedo con ella, ¿qué es?\n");
                printf("4. Te sirven para escribir, dibujar, señalar y sentir.\n");
                printf("5. Buenas y sonoras cuerdas tengo; cuando me rascan, a la gente entretengo.\n");
                int seleccion;
                printf("Selecciona una adivinanza (1-5): ");
                scanf("%d", &seleccion);
 
                switch (seleccion) {
                    case 1:
                         printf("Adivinanza 1:\n");
                printf("Abierto siempre estoy para todos los niños. Cerrado y solo me quedo los domingos.\n");
                printf("Tu respuesta: ");
                scanf("%s", respuesta);
                if (strcmp(respuesta, "colegio") == 0) {
                    printf("¡Correcto!\n");
                    aciertos++;
                } else {
                    printf("Incorrecto.\n");
                }
                        break;

                    case 2:
                        printf("Adivinanza 2:\n");
                printf("Soy pequeña y de cristal, méteme al hoyo y no perderás. \n");

                printf("Tu respuesta: ");
                scanf("%s", respuesta);
                if (strcmp(respuesta, "cincos") == 0) {
                    printf("¡Correcto!\n");
                    aciertos++;
                } else {
                    printf("Incorrecto.\n");
                }
                        break;

                    case 3:
                         printf("Adivinanza 3:\n");
                printf("Se la doy a todo el mundo y me quedo con ella, ¿qué es? \n");
               
                printf("Tu respuesta: ");
                scanf("%s", respuesta);
                if (strcmp(respuesta, "mano") == 0) {
                    printf("¡Correcto!\n");
                    aciertos++;
                } else {
                    printf("Incorrecto.\n");
                }
                        break;

                    case 4:
                        printf("Adivinanza 4:\n");
                printf("Te sirven para escribir, dibujar, señalar y sentir. \n");
                
                printf("Tu respuesta: ");
                scanf("%s", respuesta);
                if (strcmp(respuesta, "dedos") == 0) {
                    printf("¡Correcto!\n");
                    aciertos++;
                } else {
                    printf("Incorrecto.\n");
                }
                        break;

                    case 5:
                        printf("Adivinanza 5:\n");
                printf("Buenas y sonoras cuerdas tengo; cuando me rascan, a la gente entretengo. \n");
               
                printf("Tu respuesta: ");
                scanf("%s", respuesta);
                if (strcmp(respuesta, "guitarra") == 0) {
                    printf("¡Correcto!\n");
                    aciertos++;
                } else {
                    printf("Incorrecto.\n");
                }
                
                
                archivo = fopen("historial.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escritura.\n");
                } else {
                    fprintf(archivo, "Nombre: %s, Aciertos: %d\n", nombre, aciertos);
                    fclose(archivo);
                 
                }
                
                break;    
                    
		case 6:
                printf("Ingresa tu nombre: ");
                scanf("%s", nombre);
                printf("Aciertos registrados para %s: %d\n", nombre, aciertos);
                printf("Saliendo...\n");
                break;

            case 7:
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
                 default:
                        printf("Opción inválida.\n");
                        break;
                }
                break;

            case 8:
                archivo = fopen("historial.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escritura.\n");
                } else {
                    fclose(archivo);
                    printf("Historial eliminado.\n");
                }
                break;

            

            default:
                printf("Saliendo.\n");
                break;
        }
    } while (opcion != 9);

    return 0;
}
