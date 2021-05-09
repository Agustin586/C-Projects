/*
    Autor: Zuliani,Agustin
    Fecha: 01/05/21
    Programa: Practica 3 Ejercico 6
*/

/*
    Entradas: L1,L2,L3
    Salidas: Tipo de triangulo
    Metologia: a==b AND b==c -> Equilatero
               a<>b AND b<>c AND a<>c -> Escaleno
               a<>b AND b==c -> Isosceles
*/

/*
    Algoritmo: P3_E6
    Variables:
        Enteros: L1,L2,L3
    Inicio:
        Escribir("Ingrese los lados del triangulo")
        Leer(L1,L2,L3)

        Si (L1==L2 AND L1==L3)
            entonces    Escribri("Es equilatero")
            Sino Si ((L1==L2 AND L2<>L3) OR (L2==L3 AND L1<>L3))
                    entonces Escribir("Es isosceles")
                    Sino    Escribir("Es escaleno")
                Fin Si
        Fin Si
    Fin.
*/

#include <stdio.h>
#include <stdint.h>
#include <conio.h>

int main()
{
    int L1,L2,L3;

    printf("Ingrese el valor de los lados del triangulo:\n");
    
    printf("Lado 1:"),scanf("%d",&L1);
    printf("Lado 2:"),scanf("%d",&L2);
    printf("Lado 3:"),scanf("%d",&L3),printf("\n");

    if (L1==L2 && L1==L3)   printf("Es equilatero");
    else 
    {
        if((L1==L2 && L2!=L3) || (L2==L3 && L1!=L3))    printf("Es isosceles");
        else    printf("Es escaleno");
    }


    getch();
    return 0;
}