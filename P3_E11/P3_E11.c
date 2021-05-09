/*
    Autor: Zuliani,Agustin
    Fecha: 06/05/21
    Programa: Practica 3 Ejercicio 11
*/

/*
    Algoritmo: P3_E11

    Variables: 
        Entero: i,Val,ConjCeros,CantPost,SumaPost,Mayor,Menor
    
    Inicio: 

        Repetir Para i <- 1,350,1

            Escribir("Ingrese el valor :",i+1)
            Leer(Val)
            Si (Val == 0)
                entonces    ConjCeros = ConjCeros + 1
                Sino Si (Val > 0)
                        entonces    CantPost <- CantPost + 1
                                    SumaPost <- SumaPost + Val
            Fin Si
            Si (Val > Mayor)    
                entonces    Mayor <- Val
                Sino Si (Val < Menor)
                        entonces    Menor <- Val
            Fin Si

        Fin Para

        Escribir("Cantidad de ceros: ",ConjCeros)
        Escribir("Promedio de los positivos: ",SumaPost/CantPost)
        Escribir("El valor mayor: ",Mayor,"y el menor es: ",Menor)

    Fin.
*/

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

int main()
{
    int Val,ConjCeros,CantPost,SumaPos,Mayor=0,Menor;

    for(int i=0;i<10;i++)
    {
        printf("Ingrese el valor %d: ",i+1);
        scanf("%d",&Val);
        if(Val == 0)
            ConjCeros += 1;
        else if(Val > 0)
        {
            CantPost += 1;
            SumaPos += Val;
        }
        if(Val > Mayor)
            Mayor = Val;
        else if(Val < Menor)
            Menor = Val;
        if(i == 0)
        {
            Menor = Val;
            Mayor = Val;
        }
    }

    printf("\nCantidad de ceros: %d",ConjCeros);
    printf("\nPromedio de los positivos: %f",(float)SumaPos/CantPost);
    printf("\nEl valor mayor es: %d",Mayor),printf(" y el menor es: %d",Menor);
    printf("\nRango:[%d,%d]",Menor,Mayor);

    getch();
    return 0;
}