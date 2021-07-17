/*
    Autor: Zuliani, Agustin
    Fecha: 13/07/21
    Programa: Practica 6 Ejercicio 1
*/

/*
    Algoritmo Principal:
    Entrada:
        - Ingreso de 100 numeros reales (Nums)

    Salida:
        - Promedio de mayores a 0 --> PromMay0 (real)
        - Cantidad mayor al promedio --> CantMayProm (entero)
        - Porcentaje de valores negativos --> PorcjNeg (real)

    Metodologia:
        - Carga de datos en subrutina
        - Subrutina Procesamiento de datos:
                            - Funcion Contar la cantidad de mayores a 0 --> ContMay0 (entero)
                            - Funcion Acumular los datos ingresados --> AcumDatos (real)
                            - Funcion Contar cantidad de negativos --> ContNeg (entero)
    Subrutina: CargaDatos (Entrada: Arreglo, Salida: Datos en el arreglo)
        - Carga de datos
        - Devuelve todos los datos en el arreglo
*/

/*
    subrutina CARGARDATOS (E/S Nums[100]:real)
    Variables:
            Entero: i
    Inicio:
        Escribir("Ingrese los valores:")
        Repetir Para i <- 1,100
            Escribir(":",i)
            Leer(Nums[i])
        fin para 
    fin subrutina CARGARDATOS

    subrutina PROCESAMIENTO(E/S PromMay0:real, CantMayProm:entero, PorcjNeg:real, Nums[100]:real)
    Inicio:
        PromMay0    <- PromedioMay0(Nums)
        CantMayProm <- CantidadMayProm(Nums)
        PorcjNeg    <- PorcentajeNeg(Nums) 
    fin subrutina PROCESAMIENTO

    funcion PromedioMay0 (Nums[100]:real):real
    Variables:
            Entero: ContMay0,i
            Real: May0,Promedio
    Inicio:
        ContMay0 <- 0
        May0 <- 0

        // Calculamos la cantidad de numeros mayores a cero y acumulamos los valores //
        Repetir Para i <- 1,100
            Si (Nums[i] > 0) entonces:
                ContMay0 <- ContMay0 + 1
                May0 <- May0 + Nums[i]
            fin si
        fin para

        // Calculamos el promedio de mayores a 0 //
        Si (ContMay0 > 0) entonces:
            Promedio <- May0 / ContMay0
        sino    
            Promedio <- 0
        fin si

        Devolver (Promedio)
    fin funcion PromedioMay0

    funcion CantidadMayProm (Nums[100]:real):entero
    Variables:
            Entero: i,ContMayProm
            Real: AcumNums,Promedio
    Inicio:
        AcumNums <- 0
        ContMayProm <- 0

        // Calculamos el Promedio //
        Repetir Para i <- 1,100
            AcumNums <- AcumNums + Nums[i]
        fin para
        Promedio <- AcumsNums / 100.0

        // Calculamos la cantidad que supera al promedio //
        Repetir Para i <- 1,100
            Si (Nums[i] > Promedio) entonces:
                ContMayProm <- ContMayProm + 1
            fin si
        fin para

        Devolver (ContMayProm)
    fin funcion CantidadMayProm

    funcion PorcentajeNeg (Nums[100]:real):real
    Varibales:
            Entero: i,ContNeg
            Real: Porcentaje
    Inicio:
        ContNeg <- 0
        Repetir Para i <- 1,100
            Si (Nums[i] < 0) entonces:
                ContNeg <- ContNeg + 1
            fin si
        fin para
        Porcentaje <- ContNeg * 100.0 / 100.0
        Devolver (Porcentaje)
    fin funcion PorcentajeNeg

    Algoritmo: P6_E1
    Variables:
            Real: Nums[100],PromMay0,ProcjNeg
            Entero: CantMayProm
    Inicio:
        CARGADATOS(Nums)
        PROCESAMIENTO(PromMay0,CantMayProm,PorcjNeg,Nums)
        Escribir("Promedio de mayores a 0:",PromMay0)
        Escribir("Mayores al promedio:",CantMayProm)
        Escribir("Porcentaje de negativo:",PorcjNeg)
    Fin.
*/

#include <conio.h>
#include <stdio.h>

/*===============================================================================================*/
void CARGARDATOS(float Nums[])
{
    printf("Ingrese los valores:\n");
    for (int i=0;i<10;i++)
    {
        printf("%d:",i+1);
        scanf("%f",&Nums[i]);
    }
    // for (int i=0;i<10;i++)
    // {
    //     printf("Valor %.2f\n",Nums[i]);
    // }
    return;
}
/*===============================================================================================*/

/*===============================================================================================*/
float PromedioMay0 (float Nums[])
{
    int i,ContMay0;
    float May0,Promedio;

    ContMay0 = 0;
    May0 = 0;

    for (i=0;i<10;i++)
    {
        if (Nums[i] > 0) entonces:
        {
            ContMay0 += 1;
            May0 = May0 + Nums[i];
        }
    }

    if (ContMay0 > 0)   Promedio = May0 / ContMay0;
    else    Promedio = 0;

    return Promedio;
}

int CantidadMayProm (float Nums[])
{
    int ContMayProm;
    float AcumNums,Promedio;

    AcumNums = 0;
    ContMayProm = 0;

    // Calculamos el Promedio //
    for(int i=0; i<=9;i++)
    { 
        AcumNums = AcumNums + Nums[i];
    }
    Promedio = AcumNums / 10.0;

    // Calculamos la cantidad que supera al promedio //
    for (int i=0;i<=9;i++)
    {
        if (Nums[i] > Promedio) ContMayProm = ContMayProm + 1;
    }

    return ContMayProm;
}

float PorcentajeNeg (float Nums[])
{
    int ContNeg;
    float Porcentaje;

    ContNeg = 0;
    for(int i=0; i<=9;i++)
    {
        if (Nums[i] < 0)    ContNeg ++;
    }
    Porcentaje = (ContNeg * 100.0) / 10.0;

    return Porcentaje;
}

void PROCESAMIENTO (float *PromMay0,int *CantMayProm,float *PorcjNeg,float Nums[])
{
    *PromMay0    = PromedioMay0(Nums);
    *CantMayProm = CantidadMayProm(Nums);
    *PorcjNeg    = PorcentajeNeg(Nums);

    return;
}
/*===============================================================================================*/

int main ()
{
    float Nums[10],PromMay0,PorcjNeg;
    int CantMayProm;

    CARGARDATOS(Nums);
    PROCESAMIENTO(&PromMay0,&CantMayProm,&PorcjNeg,Nums);

    printf("Mayores a 0:%.2f",PromMay0);
    printf("\nMayores al promedio:%d",CantMayProm);
    printf("\nPorcentaje de negativos:%%%.2f",PorcjNeg);

    getch();
    return 0;
}