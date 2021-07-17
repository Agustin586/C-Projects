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