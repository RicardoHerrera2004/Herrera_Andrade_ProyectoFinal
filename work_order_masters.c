#include <stdio.h>  // Incluye la biblioteca estándar de entrada y salida
#include <string.h> // Incluye la biblioteca de manipulación de cadenas
#include <stdlib.h> // Incluye la biblioteca estándar
#include <time.h>   // Incluye la biblioteca de tiempo

FILE *archivo; // Declara un puntero a un archivo

struct costos // Definimos una estructura llamada costos
{
    char nombre[40]; // Campo para el nombre del usuario
    int cedula;      // campo para el numero de cedula
    int total;       // compo para los costos totales
} usuario[];         // Declara un array de estructura costos llamado usuario

int sumar(int x, int y, int z, int a) // Función para sumar cuatro números
{
    int resultado = x + y + z + a; // Suma los cuatro números
    return resultado;              // Devuelve el resultado
}

void factura(int resultado, int antivirus, int limpieza, int software, int disco_duro) // Función para generar una factura
{
    char direccion[] = "Facturas.txt"; // Define la dirección del archivo de facturas
    archivo = fopen(direccion, "a");   // Abre el archivo en modo de añadir
    if (archivo == NULL)
    {                                                // Si no se pudo abrir el archivo
        printf("Error al ingresar en el archivo\n"); // Imprime un mensaje de error
    }
    static int contador = 1; // Dlecara un contados estatico

    printf("\n");
    printf("Ingrese su cedula: ");
    scanf("%d", &usuario[contador].cedula); // lee la cedula del usuario
    getchar();                              // Para consumir el '\n' dejado por scanf, osea limpia el bufer

    printf("Ingrse su nombre y apellido: ");
    fgets(usuario[contador].nombre, 40, stdin);                            // lee el nombre del usuario
    usuario[contador].nombre[strcspn(usuario[contador].nombre, "\n")] = 0; // Para eliminar el '\n' al final

    usuario[contador].total = resultado; // Asigna el resultado al total del usuario

    time_t t = time(NULL);         // Obtiene el tiempo actual
    struct tm tm = *localtime(&t); // Convierte el tiempo a una estructura tm
    fprintf(archivo, "\n");
    fprintf(archivo, "--------------------------------- \n");
    fprintf(archivo, "-------Detalle de facturas------- \n");
    fprintf(archivo, "--Usuario %d--\n", contador);
    fprintf(archivo, "Fecha: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    fprintf(archivo, "Cedula: %d\n", usuario[contador].cedula);
    fprintf(archivo, "Nombre: %s\n", usuario[contador].nombre);
    fprintf(archivo, "Precio total: %d\n", usuario[contador].total);
    fprintf(archivo, "DETALLE DEL DIAGNOSTICO\n");
    fprintf(archivo, "Antivirus: $%d\n", antivirus);
    fprintf(archivo, "Limpieza: $%d\n", limpieza);
    fprintf(archivo, "Software: $%d\n", software);
    fprintf(archivo, "Disco duro: $%d\n", disco_duro);

    fclose(archivo); // Cierra el archivo
    contador++;      // Incrementa el contador
}

void imprimir_factura() // Función para imprimir una factura
{
    char direccion[] = "Facturas.txt"; // Define la dirección del archivo de facturas
    archivo = fopen(direccion, "r");   // Abre el archivo en modo de lectura
    if (archivo == NULL)
    { // Si no se pudo abrir el archivo
        printf("Error al ingresar en el archivo\n");
    }
    else
    {
        char ch;
        while ((ch = fgetc(archivo)) != EOF) // Si no se pudo abrir el archivo
            putchar(ch);                     // Imprime cada carácter del archivo
        fclose(archivo);                     // Cierra el archivo
    }
}

int main() // Funcion principal del programa
{
    srand(time(NULL)); // Sembrar la función rand() con el tiempo actual para obtener números aleatorios diferentes en cada ejecución

    int boton1, antivirus, limpieza, software, disco_duro, resultado;

    do // inicio del bucle do-while
    {
        printf("\n");
        printf("\n");
        printf("-----------Bienvenido al sistema de ordenes de venta----------\n");
        printf("\t--------Selecciona la opcion que deseas--------\n");
        printf("Ingrese-1-para hacer un diagnostico\n");
        printf("Ingrese-2-para cotizar el mantenimiento de su computador\n");
        printf("Ingrese-3-para imprimir la factura\n");
        printf("Ingrese-4-para imprimir todas las facturas guardadas\n");
        printf("Ingrese-5-para salir\n");
        scanf("%d", &boton1); // Lee la opcion del usuario
        getchar();            // Limpiar el búfer del teclado

        switch (boton1)
        {
        case 1: // Caso 1: Diagnóstico
            printf("\n");
            printf("------------------------------------------------------------\n");
            printf("------------Bienvenido al diagnosticador de su pc-----------\n");

            // Cotizacion del antivirus
            int r_a = rand() % 2 + 1; // Generar un número aleatorio entre 1 y 2
            printf("%d\n", r_a);      // Imprimir el número aleatorio
            if (r_a == 1)
            { // Si el número aleatorio es 1
                printf("Su computadora necesita un nuevo antivirus\n");
                antivirus = 30; // Asignar valor a la variable antivirus
            }
            else if (r_a == 2)
            { // Si el número aleatorio es 2
                printf("Su computadora no necesita un nuevo antivirus\n");
                antivirus = 0; // Asignar valor a la variable antivirus
            }
            // Cotizacion de la limpieza interna de la computadora
            int r_l = rand() % 5 + 1; // Generar un número aleatorio entre 1 y 5
            printf("%d\n", r_l);
            if (r_l == 1)
            {
                printf("Su computadora necesita una limpieza interna completa\n");
                limpieza = 125;
            }
            else if (r_l == 2)
            {
                printf("Su computadora necesita una limpieza interna avanzada\n");
                limpieza = 100;
            }
            else if (r_l == 3)
            {
                printf("Su computadora necesita una limpieza interna estandar\n");
                limpieza = 75;
            }
            else if (r_l == 4)
            {
                printf("Su computadora necesita una limpieza interna basica\n");
                limpieza = 50;
            }
            else if (r_l == 5)
            {
                printf("Su computadora no necesita ninguna limpieza interna\n");
                limpieza = 0;
            }
            // Cotizacion de la instalacion y actualizacion de un nuevo sistema operativo
            int r_s = rand() % 3 + 1;
            printf("%d\n", r_s);
            if (r_s == 1)
            {
                printf("Su computadora necesita instalar un nuevo sistema operativo\n");
                software = 30;
            }
            else if (r_a == 2)
            {
                printf("Su computadora necesita actualizar su sistema operativo\n");
                software = 25;
            }
            else if (r_s == 3)
            {
                printf("Su computadora no necesita ninguna software\n");
                software = 0;
            }

            // Cotizacion de un reinicio del disco duro
            int r_d = rand() % 2 + 1;
            printf("%d\n", r_d);
            if (r_d == 1)
            {
                printf("Su computadora necesita un reinicio del disco duro\n");
                disco_duro = 60;
            }
            else if (r_d == 2)
            {
                printf("Su computadora no necesita un reinicio del disco duro\n");
                disco_duro = 0;
            }
            break;

        case 2: // Caso 2: Cotización
            printf("\n");
            printf("------Bienvenido a la calculadora del precio del mantenimiento-----\n");
            resultado = sumar(antivirus, limpieza, software, disco_duro); // Imprimir mensaje de bienvenida a la cotización
            printf("\tLa cotizacion en total tiene un costo de: $%d\n", resultado);
            break;

        case 3: // Caso 3: factura
            printf("\n");
            printf("---Bienvenido al sistema de facturacion---\n");
            printf("Ingrese los datos para la factura\n");
            factura(resultado, antivirus, limpieza, software, disco_duro); // Imprimir mensaje de bienvenida a la cotización
            break;

        case 4: // Caso 4: Impresion de factura
            printf("\n");
            printf("Imprimiendo facturas.....\n");
            imprimir_factura();
            break;

        case 5: // Caso 5: Salida
            printf("Gracias por usar el programa :) saliendo......\n");
            break;

        default:
            printf("Numero invalido, ingrese de nuevo\n");
            break;
        }
    } while (boton1 != 5); // para finalizar el programa

    return 0;
}