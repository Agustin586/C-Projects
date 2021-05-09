/*
    Autor: Zuliani,Agustin
    Fecha: 03/05/21
    Programa: Pratica 3 ejercicio 8
*/

/*
    Algoritmo: Practica 3 ejercicio 8

    Variable: 
        Flotante: Prom
        Arreglo: Nums[80]
        Entero: i

    Inicio:

        Repetir Para i <- 0,80,1
            Escribir("Ingrese el valor :",i)
            Leer(Nums[i])
            Prom = Prom + Nums[i]
        Fin Para

        Proms = Proms / 80.0
        Escribir("El promedio es:",Prom)

    Fin.
*/

#include <conio.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
    float Prom;
    int Nums[5];
    int i=0;

    for(i=0;i<5;i++)
    {
        printf("Ingrese el valor %d:\n",i);
        scanf(" %d",&Nums[i]);
        Prom = Prom + Nums[i];    
    }
    
    Prom = Prom / 5.0;
    printf("El promedio es: %f",Prom);

    getch();
    return 0;
}