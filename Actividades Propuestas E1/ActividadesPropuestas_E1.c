/*
    Autor: Zuliani,Agustin
    Fecha: 1/05/21
    Programa: Se tiene como datos los sueldos de tres empleados: Suel1, Sueld2, Sueld3 y tres descuenctos variables expresados como porcentajes: 
    Porc1, Porc2, Porc3, respectivamente. Calcular y mostrar cada uno de los sueldos netos.
*/

/*
    Entradas: Sueldos y Porcs
    Salida: SueldoNetos
    Metodologia: SueldosNetos: Sueldos - (Sueldos*Porc/100)

    Algoritmo: ActividadesPropuestas_E1
    Variables: 
        Reales: Suel1,Suel2,Suel3,SuelNeto1,SuelNeto2,SuelNeto3
        Enteros: Porc1,Porc2,Porc3
    Inicio:
        Escribir("Ingrese el sueldo 1 y el porcetanje de descuento:")
        Leer(Suel1,Porc1)
        Escribir("Ingrese el sueldo 2 y el porcentaje de descuento:")
        Leer(Suel2,Porc2)
        Escribir("Ingrese el sueldo 3 y el porcentaje de descuento:")
        Leer(Suel3,Porc3)

        SuelNeto1 <- Suel1 - (Suel1*Porc1/100.0)
        SuelNeto2 <- Suel2 - (Suel2*Porc2/100.0)
        SuelNeto3 <- Suel3 - (Suel3*Porc3/100.0)

        Escribir("El sueldo neto 1 es:",SuelNeto1)
        Escribri("El sueldo neto 2 es:",SuelNeto2)
        Escribir("El sueldo neto 3 es:",SuelNeto3)
    Fin.
*/

#include <conio.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
    float Suel1=0,Suel2=0,Suel3=0,SuelNeto1,SuelNeto2,SuelNeto3;
    int Porc1=0,Porc2=0,Porc3=0;

    printf("Ingrese el sueldo 1 y el porcentaje de descuento:\n");
    scanf("%f %d",&Suel1, &Porc1);
    printf("\nIngrese el sueldo 2 y el porcentaje de descuento:\n");
    scanf("%f %d",&Suel2, &Porc2);
    printf("\nIngrese el sueldo 3 y el porcentaje de descuento:\n");
    scanf("%f %d",&Suel3, &Porc3);

    SuelNeto1 = Suel1 - (Suel1*Porc1)/100.0;
    SuelNeto2 = Suel2 - (Suel2*Porc2)/100.0;
    SuelNeto3 = Suel3 - (Suel3*Porc3)/100.0;

    printf("\nEl sueldo neto 1 es: %f \n",SuelNeto1);
    printf("El sueldo neto 2 es: %f \n",SuelNeto2);
    printf("El sueldo neto 3 es: %f",SuelNeto3);

    getch();
    return 0;
}