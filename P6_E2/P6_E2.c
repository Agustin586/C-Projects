/*
    Autor: Zuliani,Agustin
    Fecha: 13/07/21
    Programa: Practica 6 Ejercicio 2

    NOTA: Se modificó brebemente el enunciado, haciendo que la id del vendedor
    sea el nombre del mismo y no un valor.
*/

/*
    Algoritmo principal:
    Entradas:
            - Nombre del vendedor 
            - Ventas del vendedor
    Salidas:
            - Genera dos arreglos que son apareados relacionados con su indice
            - El primer contiene el nombre del vendedor y el segundo la cantidad de ventas que realizo
    Metodologia:
            - Funcion cargar datos vendedor --> Nombre y ventas
            - Funcion procesar datos --> La cual se encarga de detectar cuantos y cuales vendedores 
              vendieron
            - Funcion que genera los arreglos correspondientes 
*/

/*
    Subrutina CargaDatos(E/S Ventas[20]:entero,Nombres[20][30]:caracter)
    Variables:
            Entero: i
    Inicio:
        Repetir Para i <- 1,20
            Escribir("Vendedor :",i)
            Escribir("Nombre:")
            Leer(Nombre[i])
            Escribir("Ventas:")
            Leer(Ventas[i])
            Mientras (Ventas[i] < 0)
                Escribir("Ingrese una venta mayor o igual a 0:")
                Leer(Ventas[i])
            fin mientras
        fin para
    Fin subrutina CargaDatos

    Subrutina Inicializar(E/S VentasTotales[20]:entero,Vendores[20][30]:caracter)
    Variables:
            Entero: i,j
    Inicio:
        Repetir Para i <- 1,20
            VentasTotales[i] <- 0
            Repetir Para j <- 1,30
                Vendedores[i][j] <- 0
            fin para
        fin para
    Fin subrutina Inicilizar

    Subrutina GeneracionLista(E Ventas[20]:entero,Nombres[20][30]:caracter; S VentasTotales[20]:entero,Vendedores[20][30]:caracter)
    Variables:
            Entero: i,i2
    Inicio:
        Inicializar(VentasTotales,Vendedores)
        i2 <- 1
        Repetir Para i <- 1,20
            Si (Ventas[i] > 0) entonces
                VentasTotales[i2] <- Ventas[i]
                copiar(Vendedores[i2],Nombre[i])
                i2 <- i2 + 1
            fin si
        fin para
    Fin subrutina GeneracionLista

    Subrutina MostrarLista(E/S VentasTotales[20]:entero,Vendedores[20][30]:caracter)
    Variables:
            Entero: i
    Inicio:
        Escribir("Vendedor:         Ventas:")
        Repetir Para i <- 1,20
            Escribir(Vendedores[i],Ventas[i])
        fin para
    Fin subrutina MostrarLista

    Algoritmo: P6_E2
    Variables:
            Entero: Ventas[20],VentasTotales[20]
            Caracter: Nombres[20][30],Vendedores[20][30]
    Inicio:
        CargaDatos(Ventas,Nombre)
        GeneracionLista(Ventas,Nombres,VentasTotales,Vendedores)
        MostrarLista(VentasTotales,Vendedores)
    Fin.
*/

#include <conio.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGHT  30
#define NUM_FILAS   5

void CargaDatos(int Ventas[],char Nombres[][MAX_LENGHT])
{
    int i;
    for (i=0;i<5;i++)
    {
        printf("Vendedor %d:",i+1);
        printf("\nNombre:");
        scanf(" %s",Nombres[i]);
        printf("Ventas:");
        scanf("%d",&Ventas[i]);
        printf("\n");
        while(Ventas[i] < 0)
        {
            printf("Ingrese una venta mayor o igual a 0:");
            scanf("%d",Ventas[i]);
        }
    }
    return;
}

void Inicializar(int VentasTotales[],char Vendedores[][MAX_LENGHT])
{
    int i,j;
    for (i=0;i<NUM_FILAS;i++)
    {
        VentasTotales[i] = 0;
        for (j=0;j<MAX_LENGHT;j++)
        {
            Vendedores[i][j] = 0;
        }
    }
    return;
}

void GeneracionLista(int Ventas[],char Nombres[][MAX_LENGHT],int VentasTotales[],char Vendedores[][MAX_LENGHT],int *longindice)
{
    int i,i2;
    Inicializar(VentasTotales,Vendedores);
    i2 = 0;
    for (i=0;i<5;i++)
    {
        if (Ventas[i] > 0)
        {
            VentasTotales[i2] = Ventas[i];
            strcpy(Vendedores[i2],Nombres[i]);
            i2 += 1;
        }
    }
    *longindice = i2;
    return;
}

void MostrarLista(int VentasTotales[],char Vendedores[][MAX_LENGHT],int *longindice)
{    
    int i;
    printf("Vendedor:\tVentas:\n");
    for (i=0;i<*longindice;i++)
    {
        printf("%s\t\t%d\n",Vendedores[i],VentasTotales[i]);
    }

    return;
}
int main()
{
    int Ventas[NUM_FILAS],VentasTotales[NUM_FILAS],longindice;
    char Nombres[NUM_FILAS][MAX_LENGHT],Vendedores[NUM_FILAS][MAX_LENGHT];

    CargaDatos(Ventas,Nombres);
    GeneracionLista(Ventas,Nombres,VentasTotales,Vendedores,&longindice);
    MostrarLista(VentasTotales,Vendedores,&longindice);

    getch();
    return 0;
}