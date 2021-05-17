/*
    Autor: Zuliani,Agustin
    Fecha: 16/05/21
    Programa: Dadas las notas de los alumnos que rindieron un examen final, calcular e informar el porcentaje de notas superiores a 6.
              Con una nota negativa se indica el fin de ingreso de datos.
*/

/*
    Entrada: Notas
    Salida:  Porcentaje aprobados
    Metodologia:
            - Bucle: Sale del bucle si no quiere ingresar mas notas o si ingresa una nota negativa 
                - Leer las notas
                - Suma la cantidad de alumnos por cada nota ingresa
                - Pregunta si quiere terminar de ingresar
            - Calcula el porcentaje 
            - Imprime el porcentaje
*/

/*
    Algoritmo:
    Variables:
        Enteros: cantAlumno,readNota,cantAprobado
        Caracter: IngresoDato
    Inicio:

        cantAlumno <- 0
        cantAprobado <- 0
        IngresoDato <- 'y'
        readNota <- 10

        Repetir Mientras ((IngresoDato == 'Y' OR IngresoDato == 'y') AND (readNota >= 1 AND readNota <= 10))
            
            Escribir("Ingrese la nota:")
            Leer(readNota)

            Si (readNota >= 1 AND readNota <= 10)
                entonces    
                            cantAlumno <- cantAlumno + 1   
                            Si (readNota >= 6)
                                entonces    cantAprobado <- cantAprobado + 1
                            Fin Si
                
                            Escribir("\nPara ingresar mas notas presiones 'y' o 'Y'\n Para finalizar presione 'n' o 'N'")
                            Escribir("\nOpcion:")
                            Leer(IngresoDato)

                            Repetir Mientras (IngresoDato <> 'y' AND IngresoDato <> 'Y' AND IngresoDato <> 'n' AND IngresoDato <> 'N')
                                
                                Escribir("\nIngrese de nuevo:")
                                Leer(IngresoDato)

                            Fin Mientras

                Sino        Escribir("Ingreso una nota invalida")
            Fin Si

        Fin Mientras

        Si (cantAlumno > 0)
            entonces    Escribir("El porcentaje de aprobados es: ",cantAprobado*100.0/cantAlumno)
            Sino        Escribir("No se ingreso ninguna nota o el valor fue invalido")
        Fin Si.

    Fin.
*/

/*
    Prueba de escritorio:

    - Ingreso Nota -> 0 ==> Error
    - Ingreso Nota -> 1 ==> cantAlumno -> 1, cantAprobado -> 0
    - Ingreso IngresoDato -> 'y'
    - Ingreso Nota -> 10 ==> cantAlumno -> 2, cantAprobado -> 1
    - Ingreso IngresoDato -> 'y'
    - Ingreso Nota -> -5 ==> cantAlumno -> 2, cantAprobado -> 1, Imprime -> "Ingreso una nota invalida"

    
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    int cantAlumno=0,readNota=10,cantAprobado=0;
    char IngresoDato='y';

    while ((IngresoDato == 'Y' || IngresoDato == 'y') && (readNota >= 1 && readNota <= 10))
    {
        printf("Ingrese la nota:");
        scanf("%d",&readNota);

        if (readNota >= 1 && readNota <= 10)
        {
            cantAlumno += 1;   
            if (readNota >= 6)  cantAprobado += 1;
            printf("\nPara ingresar mas notas presiones 'y' o 'Y'\nPara finalizar presione 'n' o 'N'");
            printf("\nOpcion:");
            scanf(" %c",&IngresoDato);
            printf("\n");

            while (IngresoDato != 'y' && IngresoDato != 'Y' && IngresoDato != 'n' && IngresoDato != 'N')
            {
                printf("Ingrese de nuevo:");
                scanf(" %c",&IngresoDato);
                printf("\n");
            }
        }
        else printf("Ingreso una nota invalida\n");
    }

    if (cantAlumno > 0)    printf("\nEl porcentaje de aprobados es: %%%.2f",cantAprobado*100.0/cantAlumno);
    else                   printf("\nNo se ingreso ninguna nota o el valor fue invalido");

    getch();
    return 0;
}