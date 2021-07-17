/*
    Autor: Zuliani,Agustin
    Fecha: 18/06/21
    Programa: Practica 5 Ejercicio 3
*/

/*
    Algoritmo: principal
    Entrada:
        - Valor (entero)
    Salida:
        - Factorial (entero)
    Metodolgia:
        - Ingreso del valor
        - Llamada a la funcion
        - Imprime el resultado
    Funcion: Entrada: entero val Salida: fact (real)
        - Calcula el factorial
        - Devuelve el valor del resultado
*/

/*
    Funcion FACTORIAL (entero val):entero
        Variables:
            Entero: i,fact
        Inicio:
            fact <- 1
            Repetir Para i <- 2,val
                fact <- fact * i
            fin para
            Devolver (fact)
    Fin funcion FACTORIAL

    Algoritmo: P5_E3
    Variables:
        Entero: val
    Inicio:
        Escribir("Ingrese el valor:")
        Leer(val)
        Escribir("El factorial de ",val,"es:",FACTORIAL(val))
    Fin.
*/

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

int32_t FACTORIAL (int val)
{
    int32_t fact=1;
    for (int i=1;i<=val;i++)    fact = fact * i;
    return fact;   
}

int main()
{
    int val;

    printf("Ingrese el valor:\n");
    scanf("%d",&val);

    while (val < 0)
    {
        printf("Ingrese un valor mayor o igual a 0:\n");
        scanf("%d",&val);
    }

    printf("%d es:%d",val,FACTORIAL(val));

    getch();
    return 0;
}