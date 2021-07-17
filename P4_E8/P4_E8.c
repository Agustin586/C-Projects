/*
    Autor: Zuliani,Agustin
    Fecha: 03/06/21
    Programa: Practica 4 Ejercicio 8
*/

/*
    Entrada:
            - La empresa posee 15 talladores --> tallador(entero)
            - Cada tallador esta identificado con un numero del 1 al 15
            - Peso en quilates --> peso(real)
            - Pureza --> pureza(string)
            - Color entre la 'D' y la 'Z' --> color(caracter)
            - Se sabe la cantidad de diamentes por cada tallador --> cant_D(entero)
    Salida:
            - Por cada tallador:
                - Cantidad de diamantes con color entre la 'D' y 'G' --> cantD_DGt(entero)
                - Peso total de diamantes --> PesoT_Dt(real)
            - General:
                - Cantidad de diamantes tallados --> Total_Dg(entero)

    Metodologia:
            - Estructura de repeticion para los 15 talladores --> implementamos un para
            - Con la cantidad de diamantes generamos otra estructura de repeticion para la cantidad de diamantes --> implementamos un para
            - Para obtener la cantidad de diamantes con color entre 'd' y 'g' --> lo podemos implementar con un segun sea
            - Para obtener el peso total de diamantes por cada tallador --> implementamos un acumulador
            - Para la cantidad total de diamantes --> implementamos un acumulador
*/

/*
    Algoritmo: Problema 8
    Variables:
            Entero:     tallador,cant_D,catD_DGt,Total_Dg,diamante
            Real:       PesoT_Dt,peso
            Caracter:   color
            String:     pureza
    Inicio:
        Total_Dg <- 0
        Repetir Para tallador <- 1,15,1
            cantD_DGt <- 0
            PesoT_Dt <- 0
            Escribir("Cantidad de diamantes tallados:")
            Leer(cant_D)
            Repetir Mientras(cant_D < 0)
                Escribir("Ingrese un valor mayor a 0")
                Leer(cant_D)
            fin mientras.
            Repetir Para diamante <- 1,cant_D
                    Escribir("Ingrese el peso,la pureza y el color")
                    Leer(peso,pureza,color)
                    Repetir Mientras(peso < 0 AND color < 'D' AND color > 'Z')
                            Escribir("Algun dato fue incorrecto,ingrese de nuevo:")
                            Leer(peso,pureza,color)
                    fin mientras.
                    Si (color >= 'D' AND color <= 'G') entonces:
                        contD_DGt <- contD_DGt + 1
                    fin si.
                    PesoT_Dt <- PesoT_Dt + peso
            fin para.
            Escribir("Total peso por tallador:",PesoT_Dt)
            Escribir("Diamantes con color entre 'D' y 'G':",cantD_DGt)
            Total_Dg <- Total_Dg + cant_D
        fin para.
        Escribir("Total diamantes en general:",Total_Dg)
    Fin.
*/