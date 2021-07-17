/*
    Autor: Zuliani,Agustin
    Fecha: 18/06/21
    Programa: Practica 5 Ejercicio 5
*/

/*
    Algoritmo: principal
    Entrada:
        - Ingreso de dos numero m y n (enteros y mayores a 0)
    Salida:
        - Numero combinatorio: m! / n! * (m-n)!
    Metodologia:
        - Ingreso de m y n y validacion
        - Llamada de la funcion COMBITARIO
        - Imprimir e resultado
    Funcion: COMBINATORIO Entrada: entero m, entero n Salida: real result
        - Calculo de m! --> Llamada a la funcion factorial
        - Calculo de n! --> Llamada a la funcion factorial
        - Calculo de (m-n)! --> Llamada a la funcion factorial
        - Operacion combinatoria
        - Devolucion
*/

/*
    Funcion COMBINATORIO (entero m, entero n):real
        Variables:
            Entero: 
        Inicio:
            Devolver((FACTORIAL(m)*1.0)/(FACTORIAL(n)*1.0) * FACTORIAL(m-n))
    Fin funcion COMBINATORIO

    Algoritmo: P5_E5
    Variables:
        Entero: m,n
    Inicio:
        Escribir("Ingrese el m y n:")
        Leer(m,n)
        Escribir("El resultado es:",COMBINATORIO(m,n))
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

float COMBINATORIO (int m, int n)
{
    return ((FACTORIAL(m)*1.0)/((FACTORIAL(n)*1.0) * (FACTORIAL(m-n)*1.0)));
}

int main()
{
    int m,n;
    
    printf("Ingrese m y n:\n");
    scanf("%d %d",&m,&n);

    while (m < 0 || n < 0 || m < n)
    {
        printf("Ingrese de nuevo:\n");
        scanf("%d %d",&m,&n);
    }
    
    printf("El resultado es:%.2f",COMBINATORIO(m,n));

    getch();
    return 0;
}