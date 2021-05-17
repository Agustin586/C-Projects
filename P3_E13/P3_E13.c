/*
    Autor:Zuliani,Agustin
    Fecha:14/05/21
    Programa: Practica 3 Ejercicio 13
*/

/*
    Algoritmo: 
    Variables:
        Entero: Peso,ContP,Portj,PMen40kg,PEnt40y60kg,PEnt60y80kg,PEnt80y100kg,PMas100kg
        Caracter: Val

    Inicio:
        PMen40kg <- 0
        PEnt40y60kg <- 0
        PEnt60y80kg <- 0
        PEnt80y100kg <- 0
        PMas100kg <- 0
        Cont <- 0
        
        Escibir("Desea ingresar datos:")
        Leer(Val)

        Repetir Mientras (Val == 'Y' OR Val == 'y')
            Cont <- Cont + 1

            Escribir("Ingrese el peso de la personas:")
            Leer(Peso)
        
            Si (Peso < 40)
                entonces    PMen40kg <- PMen40kg + 1
                Sino Si (Peso >= 40 AND Peso <= 60)
                    entonces    PEnt40y60kg <- PEnt40y60kg + 1
                Sino Si (Peso > 60 AND Peso < 80)
                    entonces    PEnt60y80kg <- PEnt60y80kg + 1
                Sino Si (Peso >= 80 AND Peso < 100)
                    entonces    PEnt80y100kg <- PEnt80y100kg + 1
                Sino Si (Peso >= 100)
                    entonces    PMas100kg <- PMas100kg + 1
            Fin Si

            Escribir("Desea ingresar mas datos Si(y), NO(n):")
            Leer(Val)

            Repetir Mientras (Val <> 'N' OR Val <> 'n' OR Val <> 'Y' OR Val <> 'y')
                Escribir("Ingrese de nuevo:")
                Leer(Val)
            Fin Mientras

        Fin Mientras

        Escribir("Porcentaje personas menos a 40kg: ",PMen40kg/Cont*100)
        Escribir("Porcentaje personas entre (40 y 60)kg:",PEnt40y60/Cont*100)
        Escribir("Porcentaje personas entre (60 y 80)kg:",PEnt60y80/Cont*100)
        Escribir("Porcentaje personas entre (80 y 100)kg:",PEnt80y100/Cont*100)
        Escribir("Porcentaje personas entre 100kg:",PMas100kg)
    Fin.
*/

#include <stdio.h>
#include <conio.h>
#include <stdint.h>


int main()
{
    unsigned int Peso,Cont,PMen40kg,PEnt40y60kg,PEnt60y80kg,PEnt80y100kg,PMas100kg;
    char Val;

    PMen40kg = 0;
    PEnt40y60kg = 0;
    PEnt60y80kg = 0;
    PEnt80y100kg = 0;
    PMas100kg = 0;
    Cont = 0;

    printf("Desea ingresar datos Si(y),No(n):");
    scanf(" %c",&Val);

    while (Val != 'Y' && Val != 'y' && Val != 'N' && Val != 'n')
    {
        printf("\nIngrese de nuevo: ");
        scanf(" %c",&Val);
    }

    while (Val == 'Y' || Val == 'y')
    {
        printf("\nIngrese el peso %d:",Cont+1);   
        scanf("%d",&Peso);
        Cont+=1;

        if (Peso < 40)                      PMen40kg += 1;
        else if (Peso >= 40 && Peso <= 60)  PEnt40y60kg += 1;
        else if (Peso > 60 && Peso <= 80)   PEnt60y80kg += 1;
        else if (Peso >= 80 && Peso < 100)  PEnt80y100kg += 1;
        else if (Peso >= 100)               PMas100kg += 1;
        
        printf("\nDesea ingresar mas datos Si(y),No(n): ");
        scanf(" %c",&Val);

        while (Val != 'Y' && Val != 'y' && Val != 'N' && Val != 'n')
        {
            printf("\nIngrese de nuevo: ");
            scanf(" %c",&Val);
        }
    }
    
    printf("\n----------------------------------------------------");
    if(Cont > 0)
    {
        printf("\nPorcentaje personas menos a 40kg: %%%.2f",PMen40kg*100.0/Cont);
        printf("\nPorcentaje personas entre (40 y 60)kg: %%%.2f",PEnt40y60kg*100.0/Cont);
        printf("\nPorcentaje personas entre (60 y 80)kg: %%%.2f",PEnt60y80kg*100.0/Cont);
        printf("\nPorcentaje personas entre (80 y 100)kg: %%%.2f",PEnt80y100kg*100.0/Cont);
        printf("\nPorcentaje personas entre 100kg: %%%.2f",PMas100kg*100.0/Cont);
    }
    else    printf("\nNo se ingreso ningun dato");
    printf("\n----------------------------------------------------");
    printf("\nGracias.");

    getch();
    return 0;
}