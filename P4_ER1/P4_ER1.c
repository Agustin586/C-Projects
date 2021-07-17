/*
    Autor: Zuliani,Agustin
    Fecha: 01/06/21
    Programa: Practica 4 Ejercicio resueltos problema 1
*/

/*
    Entrada:
            - Cantidad de reactivos 
            - Por cada reactivo se tiene su peso en mg y su tempetarua de fusion
            - Pregunta si desea ingresar datos
    Salida:
            - Por cada analisis: 
                                - Su peso total de los materiales reactivos
                                - Los reactivos que estan entre 10 y 20 mg
                                - El porcentaje de reactivos que superan los 50 °C
            - En total:
                        - Cual categoria consume mayor cantidad de reactivos en mg y cual es esa cantidad
    Metodologia:
            - Variables que vamos a tener son:
                                            - Cantidad de reactivos
                                            - Peso en mg x reactivo
                                            - Temperatura de fusion x reactivo
                                            - Peso total de los materiales reactivos x categoria 
                                            - Reactivos entre 10 y 20 mg
                                            - Suma de reactivos en mg x categoria
                                            - Suma de reactivos que superan los 50 °C x categoria
                                            - Porcentaje de reactivos que superan los 50 °C x categoria
                                            - Mayor cantidad de reactivos x total de categorias
            - Primero pedi si desea ingresar datos
            - Si, es verdadero ingresa al bucle
            - Bucle de repeticion para 27 reactivos:
                                - Inicilizar contador de reactivos entre 10 y 20 mg
                                - Inicilizar contador de reactivo que superan los 50 °C
                                - Inicializar aucumulador de total de mg por categoria
                                - Primero debe ingresar la cantidad de reactivos que tiene
                                - Bucle donde su repeticion depende de la cantidad de reactivos:
                                                        - Ingresa los mg del reactivo x
                                                        - Ingresa la temeperatura de fusion del reactivo x
                                                        - Suma al total de mg por categoria <- mg del reactivo x
                                                        - Si los mg del reactivo x se encuentran entre 10 y 20 mg: aumenta el contador
                                                        - Si la temperatura de fusion del reactivo x es mayor a 50: entonces aumenta un contador
                                - Una vez finalizado el bucle, compara si la cantidad total en mg de esa categoria es mayor a la actual:
                                            - Si esto sucede entonces, guarda la categoria que lo tiene y el peso total
                                - Imprime los datos por categoria
                                - Solamente en la primera categoria se toma el mayor peso de reactivos en mg y se guarda su categoria
            - Una vez finalizado el ingreso de datos de las 27 categorias imprime las respuestas.
*/

/*
    Algoritmo: Problema 1 de ejercicios resueltos de la practica 4
    Variables:
            Entero: cant_reactivo,temp_reactivo,cont_10y20,cont_mayor50,mayorcatg_total,categoria,reactivo
            Real:   peso_reactivo,mayorpeso_total,totalpeso_catg,porc_mayor50
            Caracter: valid

    Inicio:

        Escribir("Desea ingresar datos:")
        Leer(valid)

        Repetir Mientras (valid <> 's' AND valid <> 'n')
            Escribir("Ingrese de nuevo:")
            Leer(valid)
        fin mientras.

        Si (valid == 's')   entonces:
            Repetir Para categoria <- 1,27,1
                    Escribir("Ingrese la cantidad de reactivos de la categoria:",categoria)
                    Leer(cant_reactivo)
                    
                    pesototal_catg <- 0
                    porc_mayor50 <- 0
                    cont_10y20 <- 0
                    cont_mayor50 <- 0

                    Repetir Para reactivo <- 1,cant_reactivo,1
                            Escribir("Ingrese el peso en mg:")
                            Leer(peso_reactivo)
                            Escribir("Ingrese la temeperatura de fusion")
                            Leer(temp_reactivo)

                            pesototal_catg <- pesototal_catg + peso_reactivo
                            Si (peso_reactivo > 10 AND peso_reactivo < 20)  entonces:
                                cont_10y20 <- cont_10y20 + 1
                            fin si.
                            Si (temp_reactivo > 50) entonces:
                                cont_mayor50 <- cont_mayor50 + 1
                            fin si.
                    fin para.
                    
                    Escribir("El peso total de los materiales reactivos es:",pesototal_catg)
                    Escribir("La cantidad de reactivos entre 10 y 20 mg es:",cont_10y20)
                    porc_mayor50 <- (cont_mayor50*100)/cant_reactivo
                    Escribir("El porcentaje de reactivos con temperatura mayor a 50 C es:",porc_mayor50)

                    Si (categoria == 1) entonces:
                        mayorcatg_total <- categoria
                        mayorpeso_total <- pesototal_catg
                    Sino:
                        Si (pesotota_catg > mayorpeso_total)    entonces:
                            mayorpeso_total <- pesototal_catg
                            mayorcatg_total <- categoria
                        fin si.
                    fin si.
            fin para.
            Escribir("La categoria con el mayor peso en mg es:",mayorcatg_total,"con un peso de:",mayorpeso_total)
        Sino:
            Escribir("No se ingreso ningun dato")
        fin si.

    Fin.
*/

#include <stdio.h>
#include <conio.h>

int main() 
{
    int     cant_reactivo,temp_reactivo,cont_10y20,cont_mayor50,mayorcatg_total,categoria,reactivo;
    float   peso_reactivo,mayorpeso_total,pesototal_catg,porc_mayor50;
    char    valid;

    printf("Desea ingresar datos:");
    scanf(" %c",&valid);
    while (valid != 's' && valid != 'n')
    {
        printf("Ingrese de nuevo:");
        scanf(" %c",&valid);
    }

    if (valid == 's')
    {
        for ( categoria = 1; categoria <= 3; categoria++)
        {
            printf("Cantidad de reactivos de la categoria %d:",categoria);
            scanf(" %d",&cant_reactivo);

            pesototal_catg = 0;
            porc_mayor50 = 0;
            cont_10y20 = 0;
            cont_mayor50 = 0;

            for ( reactivo = 1; reactivo <= cant_reactivo ; reactivo++)
            {
                printf("Peso del reactivo %d:",reactivo);
                scanf("%f",&peso_reactivo);
                printf("Temperatura de fusion del reactivo %d:",reactivo);
                scanf("%d",&temp_reactivo);

                pesototal_catg = pesototal_catg + peso_reactivo;

                if (peso_reactivo > 10 && peso_reactivo < 20)
                {
                    cont_10y20 = cont_10y20 + 1;
                }
                if (temp_reactivo > 50)
                {
                    cont_mayor50 = cont_mayor50 + 1;
                }           
            }
            printf("Peso total categoria %d:%.2f",categoria,pesototal_catg);
            printf("\nReactivos entre 10 y 20 mg de categoria %d:%d",categoria,cont_10y20);
            porc_mayor50 = (cont_mayor50*100.0)/cant_reactivo;
            printf("\nReactivos mayor a 50 C de categoria %d:%%%.2f\n",categoria,porc_mayor50);

            if (categoria == 1)
            {
                mayorcatg_total = categoria;
                mayorpeso_total = pesototal_catg;
            }
            else
            {
                if (pesototal_catg > mayorpeso_total)
                {
                    mayorpeso_total = pesototal_catg;
                    mayorcatg_total = categoria;
                }
            }
        }
        printf("Categoria con mayor peso:%d,con peso:%.2f",mayorcatg_total,mayorpeso_total);
    }
    else
    {
        printf("No se ingreso ningun dato");
    }

    getch();
    return 0;
}