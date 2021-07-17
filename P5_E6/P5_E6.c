/*
    Autor: Zuliani, Agustin
    Fecha: 18/06/21
    Programa: Practica 5 Ejercicio 6
*/

/*
    Algoritmo: principal
    Entrada:
        - Ingreso de x,y,n 
    Salida:
        - Imprime (x+y)**n
        - Imprime la operacion combinatoria
        - Verificar si el resultado es el mismo
    Metodologia:
        - Ingresamos x,y,n
        - Llamada a la funcion POTENCIA
        - Llamada a la funcion SUMATORIA
    Funcion: SUMATORIA: Entrada: entero x,y,n Salida: real resut
        - Repeticion de k hasta n veces --> Llamada de operaciones correspondientes
        - Acumulacion
        - Devuelve el valor
*/

/*
    Funcion SUMATORIA (entero x,entero y, entero n):real
        Variables:
            Entero: k
            Real: acum
        Inicio:
            acum <- 0
            Repetir Para k <- 0,n
                acum <- acum + (COMBINATORIO (n,k) * POTENCIA (x,n-k) * POTENCIA (y,k))
            fin para
            Devolver (acum)
    Fin funcion SUMATORIA

    Algoritmo: P5_E6
    Variables:
        Entero: x,y,n
        Real: pot,sumat
    Inicio:
        Escribir("Ingrese x,y,n:")
        Leer(x,y,n)
        pot <- POTENCIA (x+y,n)
        sumat <- SUMATORIA (x,y,n)
        Si (pot = sumat)    entonces:
            Escribir("Se verifican")
        Sino:
            Escribir("No se verfican")
        fin si
    Fin.
*/