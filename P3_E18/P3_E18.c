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