/*
    Autor: Zuliani, Agustin
    Fecha: 16/05/21
    Programa: Determinar cuantas cifras tiene un numero entero ingresado
*/

/*
    Entrada: Valor
    Salida:  Cantidad de cifras
    Metodologia: 
            - Leer el valor ingresado
            - 123 / 10 -> 12,3 / 10 -> 1,23 / 10 -> 0,123 -> Vamos diviendo el numero hasta que sea < 1
            - Si el numero > = 1 => suma en 1 el contador de cifras
            - Imprime la cantidad de cifras que tiene el entero
*/

/*
    Algoritmo:
    Variables:
        Entero: Valor, Cont_Cifras
        Real: Aux
    Inicio:

        Escribir("Ingrese el valor entero:")
        Leer(Valor)
        Si (Valor < 0)  Valor <- abs(Valor)
        Aux <- Valor

        Repetir Mientras (Aux >= 1)

            Si (Aux >= 1)
                entonces    Cont_Cifras <- Cont_Cifras + 1
            Fin Si
            
            Aux <- Aux / 10.0

        Fin Mientras

        Si (Aux == 0)
            entonces    Escribir("Cifras: 1")
            Sino        Escribir("Cifras:",Cont_Cifras)
        Fin Si

    Fin.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int Valor, Cont_Cifras=0;
    float Aux;

    printf("Ingrese el valor entero:");
    scanf("%d",&Valor);

    if (Valor < 0)  Valor = abs (Valor);
    Aux = Valor;

    while (Aux >= 1)
    {
        if (Aux >= 1)   Cont_Cifras += 1;
        Aux = Aux / 10.0;           
    }
    
    if (Aux == 0)   printf("Cifras: 1");
    else            printf("Cifras: %d",Cont_Cifras);

    getch();
    return 0;
}