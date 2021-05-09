/*
    Autor: Zuliani,Agustin
    Fecha: 03/05/21
    Programa: Practica 3 ejercicio 7
*/

/*
    Entrada: Calificacion
    Resultado: Valor numerica
    Metodologia: I:5,A:6,B:7,M:8,D:9,E:10
*/

/*
    Algoritmo: P3_E7

    Variables:
        Logico: Flag
        Caracter: Calif_Alf
        Entero: Calif_Num

    Inicio:

        Escribir("Ingrese la calificacion:")
        Leer(Calificacion)

        Segun Sea(Calif_Alf)
            caso 'I': Calif_Num <- 5
            caso 'A': Calif_Num <- 6
            caso 'B': Calif_Num <- 7
            caso 'M': Calif_Num <- 8
            caso 'D': Calif_Num <- 9
            caso 'E': Calif_Num <- 10
            Sino Escribri("error calificacion inexistente"),Flag <- true
        Fin Segun Sea

        Si (Flag == false)
            Escribir("Nota:",Calif_Num)
        Fin Sin
    Fin.
*/

#include <conio.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main()
{
    bool Flag=false;
    char Calif_Alf;
    uint8_t Calif_Num;

    printf("Ingrese la calificacion:"),scanf("%c",&Calif_Alf);

    switch(Calif_Alf)
    {
        case 'I': case'i':
        {   
            Calif_Num = 5;
            break;
        } 
        case 'A': case 'a':
        {
            Calif_Num = 6;
            break;
        }
        case 'B': case 'b':
        {
            Calif_Num = 7;
            break;
        }
        case'M': case 'm':
        {
            Calif_Num = 8;
            break;
        }
        case'D': case 'd':
        {
            Calif_Num = 9;
            break;
        }
        case'E': case 'e':
        {
            Calif_Num = 10;
            break;
        }
        default: 
        {
            printf("error calificicacion inexistente");
            Flag = true;
            break;
        }
    }

    if(!Flag)   printf("Nota: %d",Calif_Num);

    getch();
    return 0;
}