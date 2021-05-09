/*
    Autor: Zuliani,Agustin
    Fecha: 06/05/21
    Programa: Practica 3 Ejercicio 9
*/

/*
    Algoritmo: P3_E9

    Variables:
        Entero: i,Pot
        Reales: Raiz

    Inicio:

        Repetir Para i <- 2,50,1
            
            Pot <- i ** 2
            Escribir("Potencia de : ",i,Pot)
            Raiz <- sqrt(i)
            Escribir("Raiz cuadrada de : ",i,Raiz)

        Fin Para

    Fin.
*/

#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <math.h>

int main()
{
    unsigned int Pot=0;
    float Raiz=0;

    for(int i=2;i<=50;i++)
    {
        Pot = pow(i,2);
        printf("\nPotencia de %d: %d",i,Pot);
        Raiz = sqrt(i);
        printf("\tRaiz cuadrada de %d: %f\n",i,Raiz);
    }

    getch();
    return 0;
}