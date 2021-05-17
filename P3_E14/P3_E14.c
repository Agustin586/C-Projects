/*
    Autor: Zuliani,Agustin
    Fecha: 15/05/21
    Programa: Practica 3 Ejercicio 14
*/

/*
    Entrada: 500 Numeros reales
    Salida:  Informacion de orden del conjunto de numeros
    Metodologia:
        - Ingresar datos 500 veces
        - Leer datos
        - Detectar si estan en orden
        - Si el valor nuevo es igual o mayor al anterior sigue en orden
*/

/*
    Algoritmo:
    Variables:
        Entero: ContO,ContB
        Reales: Val, Mayor
    Inicio:
        
        ContO <- 0
        ContB <- 0
        Escribir("Ingrese el primer valor:")
        Leer(Val)
        Mayor <- Val
        ContO <- ContO + 1

        Repetir Mientras (ContB < 499)
            ContB <- ContB +1

            Escribir("Ingrese el valor:",ContO+1)
            Leer(Val)

            Si (Val >= Mayor)

                entonces    ContO <- ContO + 1
                            Mayor <- Val

            Fin Si.

        Fin Repetir Mientras.

        Si (ContO = 500)
            entonces    Escribir("El conjunto esta ordenado")
            Sino        Escribir("El conjunto no esta ordenado")
        Fin Si.

    Fin.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    unsigned int ContO,ContB;
    float Val,Mayor;

    ContO = 0;
    ContB = 0;

    printf("Ingrese el primer valor:");
    scanf(" %f",&Val);
    ContO += 1,ContB += 1;
    Mayor = Val;

    while (ContB < 5)
    {
        ContB += 1;
        printf("\nIngrese el valor %d:",ContB);
        scanf("%f",&Val);

        if (Val >= Mayor)   ContO += 1,Mayor = Val;
    }
    
    if (ContO == 5) printf("\nEl conjunto esta ordenado");
    else            printf("\nEl conjunto no esta odenado");

    getch();
    return 0;
}