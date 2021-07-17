/*
    Autor: Zuliani,Agustin
    Fecha: 29/05/21
    Programa: Practica 4 Problema 2
*/

/*
    Entrada: 
            - Segundos de duracion de una llamada
    Salida: 
            - Duracion de llamada en formato hh:mm:ss
            - Cantidad de veces que se supero los 10 minutos
            - Promedio de duracion
            - Minimo de duracion
    Metodologia:
            - Inicializa las variables
            - Repetir mientras (Desea ingresar llamadas)
                    - Leer (duracion)
                    - Imprime en formato deseado
                    - Determina si suero los 10 min --> A) Si, suma x contador; B) No, nada
                    - Determina si es la menor duracion --> A) Si, nuevo minimo de duracion; B) No, nada
                    - Suma al total de duracion y suma la cantidad de llamadas
                    - Quiere ingresar mas datos?
            - Imprime datos correspondientes
*/

/*
    Algoritmo: Problema 2

    Variables: 
            Entero: duracion, hora, min, seg, suma_seg, cant_llamada, cont_10min, min_duracion
            Reales: prom_duracion
            Caracter: Valid
    
    Inicio:

        Suma_Seg <- 0 
        Prom_duracion <- 0
        Cont_10min <- 0
        Cant_llamada <- 0

        Escribir("Desea ingresar datos s(si),n(no):")
        Leer(Valid)

        Repetir Mientras (Valid <> 's' AND Valid <> 'S' AND Valid <> 'n' AND Valid <> 'N')
                        
                        Escribir("Ingrese de nuevo:")
                        Leer(Valid)

        fin mientras

        Repetir Mientras (Valid == 's' OR Valid == 'S')
                
                Escribir("Ingrese la duracion de la llamada:",cant_llamada+1)
                Leer(duracion)

                hora <- duracion / 3600
                min <- mod(duracion,3600)/60
                seg <- mod(mod(duracion,3600),60)

                Escribir("",hora,":",min,":",seg)

                Si ((hora > 1) OR (min > 10) OR (min == 10 AND seg == 1))
                    entonces:
                            Cont_10min <- Cont_10min + 1
                fin si

                Cant_llamada <- Cant_llamada + 1

                Si (Cant_llamada == 1)
                    entonces:
                            Min_duracion <- duracion
                    Sino:
                        Si (duracion < Min_duracion)
                            entonces:
                                    Min_duracion <- duracion
                        fin si
                fin si

                Suma_Seg <- Suma_Seg + duracion
                
                Escribir("Desea ingresar mas datos:")
                Leer(Valid)

                Repetir Mientras (Valid <> 's' AND Valid <> 'S' AND Valid <> 'n' AND Valid <> 'N')
                        
                        Escribir("Ingrese de nuevo:")
                        Leer(Valid)

                fin mientras

        fin mientras

        Escribir("La cantidad de llamadas fue superaron los 10 minutos fueron:",Cont_10min)
        
        Si (Cant_llamada > 0)
            entonces:
                    Prom_duracion <- Suma_Seg / Cant_llamada
                    Escribir("El promedio de duracion es:",Prom_duracion)
                    Escribir("La minima duracion es:",Min_duracion)
            Sino:
                    Escribir("No se ingreso ninguna llamada")
        fin si

    Fin.
*/

#include <stdio.h>
#include <conio.h>


int main()
{
    int duracion,hora,min,seg,suma_seg,cant_llamada,cont_10min,Min_duracion;
    float prom_duracion;
    char valid;

    suma_seg = 0;
    prom_duracion = 0;
    cont_10min = 0;
    cant_llamada = 0;

    printf("Desea ingresa llamadas:\n");
    scanf(" %c",&valid);

    while (valid != 's' && valid != 'n')
    {
        printf("Ingrese de nuevo:");
        scanf(" %c",&valid);
    }

    while (valid == 's')
    {
        printf("\nIngrese la duracion de la llamada %d:",cant_llamada+1);
        scanf("%d",&duracion);
        
        hora = duracion / 3600;
        min = (duracion % 3600) / 60;
        seg = ((duracion % 3600) % 60);

        printf("%d:%d:%d",hora,min,seg);

        if (duracion > 600)    cont_10min += 1;

        cant_llamada += 1;

        if (cant_llamada == 1)  Min_duracion = duracion;
        else if(duracion < Min_duracion)    Min_duracion = duracion;

        suma_seg = suma_seg + duracion;

        printf("\nDesea ingresar mas datos:\n");
        scanf(" %c",&valid);

        while (valid != 's' && valid != 'n')
        {
            printf("Ingrese de nuevo:");
            scanf(" %c",&valid);
        }  
    }

    if (cant_llamada > 0)
    {
        printf("\nLa cantidad de llamadas que superaron los 10 minutos fueron:%d",cont_10min);
        prom_duracion = suma_seg / cant_llamada;
        printf("\nEl promedio de duracion es:%.2f",prom_duracion);
        printf("\nLa minima duracion:%d",Min_duracion);
    }
    else
    {
        printf("\nNo se ingreso ningun dato");
    }
     

    getch();
    return 0;
}