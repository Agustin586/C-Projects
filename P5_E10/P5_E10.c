/*
    Autor: Zuliani, Agustin
    Fecha: 16/06/21
    Programa: Practica 5 Ejercicio 10
*/

/*
    Subalgoritmo para calcular la suma
    1+2+3+....+n -> X1      // Sumatoria 1 (funcion)
    Subalgoritmo para calcular la formula
    n(n+1)/2 -> X2          // Formula 1 (funcion)
    Preguntarnos si X1 - X2 
    ------------------------------------------------------
*/

/*
    Algoritmo: P5E10
    Variables:
        Entero: X1,X2,n,band
    Inicio:
        band <- 0
        Repetir Para n <- 1,50
            X1 <- Sumatoria1(n)
            X2 <- Formula1(n)
            Escribir(X1,"-",X2)
            Si (X1 <> X2)   entoces:
                band <- 1
            fin si
        fin para
        Si (band = 0)  entonces:
            Escribir("Se verifica la igualdad las los 50 primeros enteros")
        Sino:
            Escribir("No se verfican para los 50 primeros enteros")
        fin si
    Fin Algoritmo
    -------------------------------------------------------------------------
    Funcion Sumatoria1(entero n):entero
    Variables:
        Enetero: i,suma
    Incio:
        suma <- 0
        Repetir para i <- 1,n
            suma <- suma + i
        fin para 
        Devolver(suma)
    Fin fncion Sumatoria1
    -------------------------------------------------------------------------
    Funcio Formula1(entero n):entero
    Inicio:
        Devolver(n*(n+1)/2)
    Fin funcion Formula1
    -------------------------------------------------------------------------
*/