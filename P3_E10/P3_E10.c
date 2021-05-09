/*
    Algoritmo:

    Variables:
        Entero: SumPares,SumImpares,i,Val

    Inicio:
        
        SumPares   <- 0
        SumImpares <- 0

        Repetir Para i <- 1,100,1

            Escribir("Ingrese el valor :",i)
            Leer(Val)
            Si (mod(Val,2) == 0)
                entonces    SumPares <- SumaPares + Val
                Sino        SumImpares <- SumaImpares + Val
            Fin Si    

        Escribir("Suma de valores pares:",SumaPares)
        Escribir("Suma de valores impares:",SumaImpares)

        Fin Para
*/

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

int main()
{
    int Sum_Pares,Sum_Impares,Val;

    Sum_Pares = 0;
    Sum_Impares = 0;

    for(int i=0;i<10;i++)
    {
        printf("Ingrese el valor %d:",i);
        scanf("%d",&Val);
        if(Val%2 == 0)  Sum_Pares = Sum_Pares + Val;
        else    Sum_Impares = Sum_Impares + Val;
    }

    printf("\nSuma de valores pares: %d",Sum_Pares);
    printf("\nSuma de valores impares: %d",Sum_Impares);

    getch();
    return 0;
}