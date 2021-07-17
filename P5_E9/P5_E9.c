/*
    Autor: Zuliani, Agustin
    Fecha: 16/06/21
    Programa: Practica 5 Ejercicio 9
*/

/*
    Datos: 
        2 horas de un mismo dia en horas, minutos y segundos
    Resultado:
        Diferencia entre esas 2 horas en horas, minutos y segundos
    _________________________________________
    Metodologia:
        En el algoritmo principal ingresamos las 2 horas
        Invocamos la subrutina TIEMPO
        Obtener la diferencia
        Devolvemos la diferencia en HHMMSS
        Mostramos el resultado por pantalla
*/

/*
    funcion HHSas(entero horas, entero minutos, entero segundos): entero
    Variables:
        Entero: seg_totales1
    Incio:

    Fin FUncion HMsaS
    
    Subrutina SaHMS (E: entero segundos, S: entero hs, entero min, entero seg)
    Variables:
    
    Inicio:

    Fin Subrutina SaHMS

    Subrutina TIEMPO (E:entero HH1, entero MM1, entero SS1, entero HH2, entero SS2;S: entero HH, entero MM, entero SS)
    Variables:
        Entero: seg_totales1,seg_totales2,dif
    Inicio:
        seg_totales1 <- HH1*3600 + MM1*60 + SS1
        seg_totales2 <- HH2*3600 + MM2*60 + SS2
        dif <- abs(seg_totales1-seg_totales2)
        HH <- dif/3600
        MM <- mod(dif,3600)/60
        SS <- mod(mod(dif,3600),60)
    Fin Subrutina TIEMPO

    Algoritmo: P5E9
    Variables:
        Entero: hora1,min1,seg1,hora2,min2,seg2,hora_dif,min_dif,seg_dif
    Inicio:
        Escribir("Ingrese la primer hora en HH,MM,SS")
        Leer(hora1,min1,seg1)
        Escribir("Ingrese la segunda hora en HH,MM,SS")
        Leer(hora2,min2,seg2)
        TIEMPO(hora1,min1,seg1,hora2,min2,seg2,hora_dif,min_dif,seg_dif)
        Escribir("La diferencia entre las 2 horas ingresadas:")
        Escribir(hora_dif,":",min_dif,":",seg_dif)
*/