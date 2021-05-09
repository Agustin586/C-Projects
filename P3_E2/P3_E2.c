/*
    Autor: Zuliani,Agustin
    Fecha: 01/05/21
    Programa: Practica 3 Ejercicio 2
*/

/*
    Datos:  A,B,aux
    Salidas: B,A
    Metodologia: aux <- A,A <- B, B <- aux 
*/

/*
    Algoritmo: P3_E2
    Variables: 
        Enteros: A,B,aux
    Inicio:
        Escribir("Ingrese el valor A y B, respectivamente")
        Leer(A,B)
        aux <- A
        A <- B
        B <- aux
        Escribir("Valor de A:",A)
        Escribir("Valor de B:",B)
    Fin.
*/

#include <stdio.h>
#include <stdint.h>
#include <conio.h>

// int main()
// {
//     int A,B,aux=0;

//     printf("Ingrese el valor de A:");
//     scanf("%d",&A);
//     printf("Ingrese el valor de B:");
//     scanf("%d",&B);

//     aux = A;
//     A = B;
//     B = aux;
    
//     printf("Valor de A: %d",A);
//     printf("\nValor de B: %d",B);

//     getch();
//     return 0;
// }

int main()
{
    char A,B,aux;

    printf("Ingrese A:\n");
    scanf("%c",&A);
    printf("Ingrese B:\n");
    scanf(" %c",&B);    // Importante el espacio antes del %c, debido a que sino el scanf lee el enter(\n) ingresado despues
                        // de escribir el caracter A
        
    aux = A;
    A = B;
    B = aux;

    printf("\n");
    printf("A:%c \n",A);
    printf("B:%c",B);
    
    getch();
    return 0;
}