/*
    Autor: Zuliani,Agustin
    Fecha: 01/05/21
    Programa: Practica 3 Ejercicio 1
*/

/*
    Entrada de datos: Num1,Num2,Num3,Num4,Num5
    Salida: Promedio
    Metolodia: x = (Num1+Num2+Num3+Num4+Num5) / 5.0
*/

/*
    Algoritmo: P3_E1
    Variables:
        Relaes: Num1,Num2,Num3,Num4,Num5,Prom
    Inicio:
        Escribir("Ingrese el valor de los numeros")
        Leer(Num1,Num2,Num3,Num4,Num5)
        Promedio <- (Num1+Num2+Num3+Num4+Num5) / 5.0
        Escribir("El promedio es:",Prom)
    Fin.
*/

#include <stdio.h>
#include <stdint.h>
#include <conio.h>

int main()
{
    float Num1,Num2,Num3,Num4,Num5,Prom;

    printf("Ingrese el valor de los 5 numeros:\n");
    scanf("%f %f %f %f %f",&Num1,&Num2,&Num3,&Num4,&Num5);
    Prom = (Num1+Num2+Num3+Num4+Num5) / 5.0;

    printf("El promedio es: %f",Prom);

    getch();
    return 0;
}
