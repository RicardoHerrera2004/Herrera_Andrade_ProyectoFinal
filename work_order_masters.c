#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

FILE *archivo;

struct costos
{
    char nombre[40];
    int cedula;
    int total;
} usuario[];




int main () {

    srand(time(NULL)); // Sembrar la función rand()

    int boton1, antivirus, limpieza, software, disco_duro, resultado;

    do
    {
        printf("Ingrese 1 para hacer un diagnostico\n");
        printf("Ingrese 2 para cotizar el mantenimiento de su computador\n");
        printf("Ingrese 3 para imprimir la factura\n");
        printf("Ingrese 4 para imprimir todas las facturas guardadas\n");
        printf("Ingrese 5 para salir\n");
        scanf("%d", &boton1);
        getchar(); // Limpiar el búfer del teclado

        switch (boton1)
        {
        case 1:
            printf("Bienvenido al diagnosticador de su pc\n");

            break;

        case 2:
            printf("Bienvenido a la calculadora del precio del mantenimiento\n");
            resultado = sumar(antivirus, limpieza, software, disco_duro);
            printf("La cotizacion en total tiene un costo de: %d\n", resultado);
            break;

        case 3:
            printf("Factura\n");
            factura(resultado, antivirus, limpieza, software, disco_duro);
            break;

        case 4:
            printf("Imprimir factura\n");
            imprimir_factura();
            break;

        case 5:
            printf("Gracias por usar el programa\n");
            break;

        default:
            printf("Numero invalido, ingrese de nuevo\n");
            break;
        }
    } while (boton1 != 5);


    return 0;
}
