/*
    Autor: Zuliani,Agustin
    Fecha: 16/05/21
    Programa: Dados 50 numeros reales, mostrar cada numero mayor a 200 y la posicion que ocupa dentro de los 50 numeros dados.
              Si no se encuentran ninguno, mostrar el mensaje: "No hay mayores a 200"
*/

/*
    Entrada:
        - 50 numeros reales
    Salida:
        - Si hay numeros mayores a 200 se imprimen por pantalla y se dice su ubicacion
        - Si no hay se envia un mensaje de error
    Metodologia:
        - Bucle: Sale despues de 50 ciclos
            - Lee el numero ingresado
            - Verifica si es mayor a 200: 
                                - Verdadero: imprimi el numero y la ubicacion
                                - Falso: nada
        - Si salio del bucle y no imprimio ningun numero:
                                - Verdadero: imprime el mensaje de error
                                - Nada
*/

/*
    Algoritmo:
    Variables:
        Real: Numero
        Entero: contMayor_200,i
    Inicio:
        i <- 0
        contMayor_200 <- 0

        Repetir Para i <- 1,50,1
            Escribir("Ingrese el numero :\n",i)
            Leer(Numero)
            Si(Numero > 200)
                entonces    Escribir("El valor es:  ,y se encuentra en la posicion: ",Numero,i)
                            contMayor_200 <- contMayor_200 + 1
            Fin Si
        Fin Para

        Si (contMayor_200 == 0)
            entonces    Escribir("No hay mayores a 200")
        Fin Si.
    Fin. 
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    float Numero;
    int contMayor_200=0,i=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese el numero %d:",i+1);
        scanf("%f",&Numero);
        printf("\n");

        if (Numero > 200)
        {
            printf("El valor es: %.2f, y se encuentra en la posicion: %d",Numero,i+1);
            contMayor_200 += 1;
            printf("\n");
        }
    }

    if (contMayor_200 == 0) printf("No hay mayores a 200");

    getch();
    return 0;
}