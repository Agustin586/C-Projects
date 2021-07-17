/*
    Autor: Zuliani,Agustin
    Fecha: 18/06/21
    Programa: Practica 5 Ejercicio 1
*/

/*
    Algoritmo: principal
    Entrada:
            - Base(real), Exponente(entero)
    Salida:
            - Potencia (real)
    Metodologia:
            - Ingresamos los datos de entrada
            - Llamamos a la funcion
            - Imprimimos el resultado en el programa principal
    Funcion: Entrada: base(real),exponente(entero) Salida: result(real)
            - Calculamos la potencia
            - Devolvemos la potencia
*/

/*
    Funcion POTENCIA (real base, entero exponente): real
    Variables:
        Entero: i
        Real: result
    Inicio:
        result <- 1
        Repetir Para i <- 2,exponente
            result <- result * base
        fin para 
        Devolver(result)
    Fin funcion POTENCIA
    
    Algoritmo: P5_E1
    Variables:
        Entero: exp
        Real: base
    Inicio:
        Escrbir("Ingrese la base y el exponente:")
        Leer(base,exp)
        Escribir("La potencia es:",POTENCIA(base,exp))
    Fin.
*/

/*
    Subrutina POTENCIA (E:real base,entero exp,S:result)
    Variables:
        Entero: i
    Inicio:
        result <- 1
        Repetir Para i <- 2,exponente
            result <- result * base
        fin para 
    Fin subrutina POTENCIA
    
    Algoritmo: P5_E1
    Variables:
        Entero: exp
        Real: base, result
    Inicio:
        Escrbir("Ingrese la base y el exponente:")
        Leer(base,exp)
        POTENCIA(base,exp,result)
        Escribir("La potencia es:",result)
    Fin.
*/

#include <stdio.h>
#include <conio.h>

// float POTENCIA (float base, int exp)
// {
//     float result=1;

//     for(int i=1;i<=exp;i++)  result = result * base;

//     return (result);
// }

// int main()
// {
//     int exp;
//     float base;

//     printf("Ingrese el valor de la base y el exponente:\n");
//     scanf("%f %d",&base,&exp);

//     printf("La potencia es:%.2f",POTENCIA(base,exp));

//     getch();
//     return 0;
// }

void POTENCIA(float *base, int *exp, float *result)
{
    *result = 1;
    for(int i=1;i<=*exp;i++)
    {
        *result = *result * *base;
    }
}

int main()
{
    int exp;
    float base,result;

    printf("Ingrese el valor de la base y el exponente:\n");
    scanf("%f %d",&base,&exp);

    POTENCIA(&base,&exp,&result);
    printf("La potencia es:%.2f",result);

    getch();
    return 0;
}