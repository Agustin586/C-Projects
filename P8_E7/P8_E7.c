#include <stdio.h>
#include <conio.h>

#define CANTDIAS        31
#define CANTCIUDADES    50

typedef struct 
{
    float TempMax[CANTDIAS],TempMaxMayo;
}Temperaturas;

void INICIALIZAR(Temperaturas A[]);
void LECTURA (Temperaturas A[],FILE *F);
void FILTROTEMP(Temperaturas A[],int codigo,float temp);

int main()
{
    Temperaturas ciudades[CANTCIUDADES];
    FILE *Datos;
    int opcion,cod;
    float tempfiltro;

    INICIALIZAR(ciudades);
    LECTURA(ciudades,Datos);
    printf("Menu\n");
    printf("1:Filtro temperatura de ciudad\n2:Mayor Temperatura\n0:Salir\nOpcion:");
    scanf("%d",&opcion);
    while (opcion < 0 || opcion > 2)
    {
        printf("\nMenu\n1:Filtro temperatura de ciudad\n2:Mayor Temperatura\n0:Salir\nOpcion:");
        scanf("%d",&opcion);
    }
    while (opcion != 0)
    {
        switch(opcion)
        {
            case 1:
            {
                printf("\nInfo:Esta opcion lo que realiza es que es filtra por temperatura minima, ingresando una temp. y el codigo de la ciudad se presentan los datos correspondientes");
                printf("\n\nIngrese el codigo de la ciudad.\nCodigo:");
                scanf("%d",&cod);
                while(cod < 1 || cod > 50)
                {
                    printf("\nIngrese el codigo de la ciudad\nCodigo:");
                    scanf("%d",&cod);
                }
                printf("Ingrese la temperatura minima.\nTemperatura:");
                scanf("%f",&tempfiltro);
                FILTROTEMP(ciudades,cod,tempfiltro);
            break;
            }
            case 2:
            {

            break;
            }
        }
        printf("1:Filtro temperatrua de ciudad\n2:Mayor Temperatura\n0:Salir\nOpcion:");
        scanf("%d",&opcion);
        while (opcion < 0 || opcion > 2)
        {
            printf("\nMenu\n1:Filtro temperatrua de ciudad\n2:Mayor Temperatura\n0:Salir\nOpcion:");
            scanf("%d",&opcion);
        }
    }
    getch();
    return 0;
}

void INICIALIZAR(Temperaturas A[])
{
    for (int i = 0; i < CANTCIUDADES; i++)
    {
        A[i].TempMaxMayo = 0;
        for (int j = 0;j < CANTDIAS;j++)
            A[i].TempMax[j] = 0;
    }

    return;
}

void LECTURA (Temperaturas A[],FILE *F)
{
    int dia,cod_ciudad;
    float temp;
    if ((F = fopen("TEMPS.txt","r"))==NULL) printf("No se pudo abrir el archivo");
    else
    {
        while (!feof(F))
        {
            fscanf(F,"%d\t%d\t%f",&dia,&cod_ciudad,&temp);
            A[cod_ciudad].TempMax[dia] = temp;
        }
    }
    fclose(F);
    return;
}

void FILTROTEMP(Temperaturas A[],int codigo,float temp)
{
    int dia;

    printf("\nDIA:\tTEMP:\tCODIGO\n");
    for (dia = 0; dia < CANTDIAS; dia++)
        if (A[codigo].TempMax[dia] > temp)  printf("%d\t%.2f\t%d\n",dia,A[codigo].TempMax[dia],codigo);  

    printf("\n");
    return;
}

