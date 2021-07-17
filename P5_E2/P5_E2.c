/*
    Autor: Zuliani,Agustin
    Fecha: 18/06/21
    Programa: Practica 5 Ejercicio 1
*/

/*
    Algoritmo: principal
    Entrada:
        - Valor del intervalor (real)
        - Valor2 (real)
        - Valor3(real)
    Salida:
        - Saber si el valor pertenece al interval cerrado o no
    Metdologia:
        - Ingreso de valor y los limites del intervalo
        - Ingreso a la funcion con salida logica
    Funcion: Entrada: val(real),val2(real),val3(real) Salida: logica
        - Define cual limite es el superior con limSup y limInf 
        - Verifica si se encuentra entre el intervalo
        - Genera una respuesta
*/

/*
    Funcion VERFICAR (real val, real val2, real val3):logico
        Variables:
            Real: limSup,limInf
        Inicio:
            Si (val2 > val3)    entonces:
                limSup <- val2
                limInf <- val3
            Sino:
                limSup <- val3
                limInf <- val2
            fin si
            Si (val >= limInf AND val <= limSup)    entonces:
                Devolver (1)
            Sino:
                Devolver (0)
            fin si
    Fin funcion VERIFICAR

    Algoritmo: P5_E2
    Variables:
        Real: val,val2,val3
        Logica: verif
    Inicio:
        Escribir("Ingrese el valor 1,2,3:")
        Leer(val,val2,val3)
        verif <- VERFICAR(val,val2,val3)
        Si (verif = 1)  entonces:   
            Escribir("Pertenece al intervalo cerrado")
        Sino:
            Escribir("No pertecene al intervalo cerrado")
    Fin.
*/

#include <stdio.h>
#include <conio.h>

_Bool VERIFICAR (float val1, float val2, float val3)
{
    float limSup,limInf;
    
    if (val2 > val3)    limSup = val2, limInf = val3;
    else                limSup = val3, limInf = val2;

    if (val1 >= limInf && val1 <= limSup)   return (1);
    else                                    return (0);
}

int main()
{
    float val,val2,val3;
    _Bool verif;

    printf("Ingrese el valor 1,2,3:\n");
    scanf("%f %f %f",&val,&val2,&val3);

    verif = VERIFICAR (val,val2,val3);

    if (verif)  printf("Pertecene al intervalo");
    else        printf("No pertecene al intervalo");

    getch();
    return 0;
}