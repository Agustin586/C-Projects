/*
    Autor: Zuliani, Agustin
    Fecha: 19/05/21
    Programa: Practica 3 Ejercicio 19
*/

/*
    Entrada:
        - Ingresa datos de la primera comision elegida
        - Cambio de comision e ingreso de datos
        - ...
        - Finaliza con 0
    Salida:
        - Mayor promedio
    Metodologia:
        - Limpia todos los contadores y sumas
        - Bucle:
            - Ingresa el numero de comision
            - Bucle:
                - Ingresa la edad 
                - Suma la edad de los alumnos de esa comision
                - Cuenta la cantidad de alumnos de esa comision
                - Pregunta si quiere seguir ingresando alumnos
                    - Verdadero: sigue en bucle
                    - Falso: sale del bucle
            - Calcula el promedio de esta comision
            - Compara con el mayor promedio que existe
            - Si este ultimo promedio es mayor al promedio maximo
                        - Verdadero: se guarda el promedio y el numero
                                     de comision que tenia ese promedio
                        - Falso: nada
            - Pregunta si quiere seguir ingresando comisiones
                    Verdadero: sigue ingresando comisiones y edades
                    Falso (0): sale del bucle
        - Calcula e imprime el promedio maximo y la comision que lo tuvo

*/

/*

Metodologia:
  - Ingresan el valor de la edad de los estudiantes de esa comision
  - Calcular el promedio de la edad de los estudiantes
  - Bucle de comision
    - Bucle de los estudiantes
      - Ingresa los datos del estudiante
  - Determina si se superó la promedio de edad

Algoritmo:
    Variables:
        Entera: Edad,Comi,SumComi,ContAlm,ComiMayor
        Real: PromComi,Aux
    Inicio:
        // Inicializacion
        PromComi <- 0 
        SumaComi <- 0
        ContAlm <- 1
        ComiMayor <- 0

        // Algoritmo
        Escribir ( "Comision:" )
        Leer ( Comi )
        Repetir Mientras ( Comi <> 0 )
            SumAlm <- 0
            ContAlm <- 1
            Escribir ( "Comision ",Comi," Almuno:",ContAlm )
            Leer ( Edad )
            Repetir Mientras ( Edad >= 0  AND Edad <= 100 )
                SumaComi <- SumaComi + Edad
                ContAlm <- ContAlm + 1
                Escribir ( "Comision ",Comi," Almuno:",ContAlm )
                Leer ( Edad )
                Si ( Edad = 0 ) entonces:
                    ContAlm <- ContAlm - 1
                Fin si
            Fin mientras
            Aux <- SumaComi / ContAlm
            Si ( PromComi < Aux ) entonces:
                PromComi <- Aux
                ComiMayor <- Comi
            Fin si
            Escribir ( "Nueva Comision:" )
            Leer ( Comi )
        Fin mientras
        Escribir ( "Comision con mayor promedio:",ComiMayor )
    Fin.
 */

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

int main ()
{
    uint8_t Edad,SumaComi,ContAlm,ComiMayor;
    float PromComi,Aux;
    int Comi;

    // Inicializacion
    PromComi = 0;
    SumaComi = 0;
    ContAlm = 1;
    ComiMayor = 0;

    printf ( "Nueva Comision:" );
    scanf ( "%d",&Comi );

    while ( Comi != 0 )
    {
        SumaComi = 0;
        ContAlm =  1;
        printf ( "Comision:%d\nAlumno %d:",Comi,ContAlm );
        scanf ( "%d",&Edad );
        while ( Edad > 0 && Edad < 100 )
        {
            ContAlm += 1;
            SumaComi = SumaComi + Edad;
            printf ( "Comision:%d\nAlmumno %d:",Comi,ContAlm );
            scanf  ( "%d",&Edad );
            if ( Edad == 0 )    ContAlm --;
        }
        Aux = SumaComi / ContAlm;
        if ( PromComi < Aux )
        {
            PromComi = Aux;
            ComiMayor = Comi;
        }
        printf ( "Nueva Comision:" );
        scanf ( "%d",&Comi );
    }
    printf ( "Comision de mayor promedio:%d",ComiMayor );

    getch();
    return 0;
}