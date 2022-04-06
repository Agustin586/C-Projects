/*
    Autor: Zuliani, Agustin
    Fecha: 19/05/21
    Programa: Practica 3 Ejercicio 18
*/

/*
    Entrada:
        - 7 notas de cada estudiante
        - Estudiantes indefinidamente
        - Fin de ingreso
    Salida:
        - Promedio de cada alumno
        - Promedio general
    Metodologia:
        - Bucle:
            - Leer estudiante 1 las 7 notas
            - Pregunta si desea ingresa de nuevo
        - Calcula el promedio de cada uno
        - Calcula el promedio general
        - Imprime todo
*/

/*
    Algoritmo:
    Variables:
        Reales: PromAlm, PromGen, NotaAlm, SumaAlm, SumaGen,
        Entero: CantAlm, i
        Caracter: Val
    Inicio:

        SumaGen <- 0
        PromGen <- 0
        CantAlm <- 0
        Val <- 'y'

        Repetir Mientras (Val == 'y' OR Val == 'Y')

            SumaAlm <- 0
            PromAlm <- 0

            Repetir Para i <- 1,7,1

                Escribir ("Ingrese la nota ",i+1," del Alumno :",CantAlm+1)
                Leer(NotaAlm)

                Repetir Mientras (NotaAlm < 1 OR NotaAlm > 10)

                    Escribir ("Ingrese una nota valida:")
                    Leer(NotaAlm)

                Fin Mientras.

                SumaAlm <- SumaAlm + NotaAlm 

            Fin Para.

            PromAlm <- SumaAlm / 7.0
            Escribir ("El promedio del alumno ",CantAlm+1,":",PromAlm)

            SumaGen <- SumaGen + SumaAlm
            CantAlm <- CantAlm + 1

            Escribir ("Desea ingresar mas datos, Si(y), No(n):")
            Leer(Val)

            Repetir Mientras (Val <> 'y' AND Val <> 'Y' AND Val <> 'n' AND Val <> 'N')

                Escribir ("Ingrese de nuevo:")
                Leer(Val)

            Fin Mientras.

            Si (Val == 'y' OR Val == 'Y')
                entonces    Escribir ("Siguiente alumno")
                            Escribir ("-----------------\n")
            Fin Si.

        Fin Mientras.

        PromGen <- SumaGen / CantAlm
        Escribir ("El promedio general es:",PromGen)

    Fin.
*/

/*

Metodologia:
    - Ingresar las notas por teclado las 7 notas
    - Se debe calcular y mostrar el promedio de ese alumno y guardarlo en un promedio general
    - Se debe preguntar si se quiere seguir ingresando datos

Algoritmo:

    Variables:
        Entero:     i,ContAlum
        Real:       PromAlum,PromGnerl,SumAlm,Nota
        Caracter:   Valid

    Inicio:
        ContAlm <- 0
        PromGnerl <- 0
        Valid <- 'y'

        Repetir Mientras ( Valid = 'y' )
            SumAlm <- 0
            PromAlm <- 0
            
            Repetir Para i <- 1,7,1
                Escribir ( "Nota ",i,",alumno ",ContAlm+1,":" )
                Leer (Nota)
                Repetir Mientras ( Nota <= 0  OR Nota > 10 )
                    Escribir ( "Ingrese la nota de nuevo:" )
                    Leer ( Nota )
                Fin mientras
                SumAlm <- SumAlm + Nota
            Fin para

            ContAlm <- ContAlm + 1

            PromAlm <- SumAlm / 7.0
            Escribir ( "Promedio de alumno ",ContAlm,":",PromAlm )

            PromGneral <- PromGnerl + PromAlm

            Escribir ("Desea ingresar mas datos:Si(y),No(n)")
            Leer (Valid)
            
            Repetir Mientras ( Valid <> 'y' AND Valid <>'n' )
                Escribir ("Vuelva a ingresar la opcion:Si(y),No(n)")
                Leer (valid)
            Fin mientras

        Fin mientras

        PromGnerl <- PromGnerl / ContAlm
        Escribir ("El promedio general del curso es:",PromGnerl)
    Fin.
*/

#include <stdio.h>
#include <conio.h>

#define CANT_NOTAS 7
#define NOTA_MAX 10
#define NOTA_MIN 1

int main ()
{
    int ContAlm;
    float PromAlm,PromGnr,Nota,SumaAlm;
    char Valid;

    //Inicializacion de datos
    ContAlm = 0;
    PromAlm = 0;
    SumaAlm = 0;
    PromGnr = 0;
    Valid = 'y';

    //Bucle
    while ( Valid == 'y' || Valid == 'Y' )
    {
        SumaAlm = 0;
        PromAlm = 0;
        for ( int i = 0; i < CANT_NOTAS; i++)
        {
            printf ( "Ingrese la nota %d del alumno %d:",i+1,ContAlm+1 );
            scanf ( "%f",&Nota);
            while ( Nota < NOTA_MIN || Nota > NOTA_MAX )
            {
                printf ( "Ingrese una nota valida\n" );
                printf ( "Nota %d,alumno %d:",i+1,ContAlm+1 );
                scanf ( "%f",&Nota );
            }
            SumaAlm = SumaAlm + Nota;
        }
        PromAlm = SumaAlm / CANT_NOTAS;
        PromGnr = PromGnr + PromAlm;
        ContAlm += 1;
        printf ( "El promedio general del alumno %d es:%.2f\n",ContAlm,PromAlm);
        printf ( "Desea seguir ingresando datos.Si(y),No(n):" );
        scanf ( " %c",&Valid );
        while ( Valid != 'y' && Valid != 'n' )
        {
            printf ( "Ingrese una opcion valida\n" );
            printf ( "Si(y),No(n):" );
            scanf ( " %c",&Valid );
        }
    }
    printf ( "El promedio general de los alumnos es %.2f",(PromGnr=PromGnr/ContAlm) );

    getch();
    return 0;    
}