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

int sumar(int x, int y, int z, int a)
{
    int resultado = x + y + z + a;
    return resultado;
}




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

            // Cotizacion del antivirus
            int r_a = rand() % 2 + 1;
            printf("%d\n", r_a);
            if (r_a == 1){
                printf("Su computadora necesita un nuevo antivirus\n");
                antivirus = 30;
            }
            else if (r_a == 2){
                printf("Su computadora no necesita un nuevo antivirus\n");
                antivirus = 0;
            }

            // Cotizacion de la limpieza interna de la computadora
            int r_l = rand() % 5 + 1;
            printf("%d\n", r_l);
            if (r_l == 1){
                printf("Su computadora necesita una limpieza interna completa\n");
                limpieza = 125;
            }
            else if (r_l == 2){
                printf("Su computadora necesita una limpieza interna avanzada\n");
                limpieza = 100;
            }
            else if (r_l == 3){
                printf("Su computadora necesita una limpieza interna estandar\n");
                limpieza = 75;
            }
            else if (r_l == 4){
                printf("Su computadora necesita una limpieza interna basica\n");
                limpieza = 50;
            }
            else if (r_l == 5){
                printf("Su computadora no necesita ninguna limpieza interna\n");
                limpieza = 0;
            }

            // Cotizacion de la instalacion y actualizacion de un nuevo sistema operativo
            int r_s = rand() % 3 + 1;
            printf("%d\n", r_s);
            if (r_s == 1){
                printf("Su computadora necesita instalar un nuevo sistema operativo\n");
                software = 30;
            }
            else if (r_a == 2){
                printf("Su computadora necesita actualizar su sistema operativo\n");
                software = 25;
            }
            else if (r_s == 3){
                printf("Su computadora no necesita ninguna software\n");
                software = 0;
            }

            // Cotizacion de un reinicio del disco duro
            int r_d = rand() % 2 + 1;
            printf("%d\n", r_d);
            if (r_d == 1){
                printf("Su computadora necesita un reinicio del disco duro\n");
                disco_duro = 60;
            }
            else if (r_d == 2){
                printf("Su computadora no necesita un reinicio del disco duro\n");
                disco_duro = 0;
            }

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
