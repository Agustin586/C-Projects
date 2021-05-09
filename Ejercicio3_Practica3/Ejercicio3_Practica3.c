/*
    Autor: Agustin Zuliani
    Fecha: 28/04/21
*/

// Incluimos las  librerias necesarias //
#include <stdio.h>

/*
    Ejercicio 3 de la Practica 3

    Algoritmo: ejercicio 3

    Variables:
        enteros: hora,minutos,segundos
        entero: segundos_totales
    Inicio:
        Escribir("Ingrese hora,minutos y segundos:")
        Leer(hora,minuto,segundo)
        segundos_totales = horas * 3600 + minutos * 60 + segundos
        Escribir("Total:",segundos_totales)
    Fin.
*/

// Inicio del programa //
int main()
{
    // Variables //
    int horas,minutos,segundos,segundos_totales;

    // Leemos los valores de entrada //
    printf("Ingrese, HH,MM,SS:");
    scanf("%d %d %d",&horas,&minutos,&segundos);
    segundos_totales = horas * 3600 + minutos * 60 + segundos;

    // Imprimimos el resultado //
    printf("Los segundos totales son: %d",segundos_totales);

    return 0;
}
