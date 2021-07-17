/*
    Autor: Zuliani,Agustin
    Fecha: 30/05/21
    Programa: Practica 4 Problema 5
*/

/*
    Entrada: numero de dia, id del empleado, cantidad de horas extras
    Salida: 
        - En el dia: 
                - Empleado con mayor hora extra
                - Promedio de horas extras trabajadas en el dia
        - En el periodo:
                - Cantidad de dias que se trabajo
    Metodologia:
        - Inicializacion de variables
        - Repetir mientras (valid == 's')
                - Lectura del dia 
                - Valida que se encuentre dentro de [1;31]
                - id_emp <- 1
                - Repetir mientras (id_emp <> 0)
                        - Valida si realizo horas extras y actua en consecuencia
                                - Si es verdad:
                                            leer sus horas extras
                                            compararla con la mayor
                                            sumarla a ambos totales
                - Obtener el promedio 
*/

/*
    Algoritmo: P3_E5

    Variables:
            Entero: dia,id_emp,cant_he,totalhe_periodo,totalhe_dia,emp_mhe,cont_empD,mayorhe,cont_dia
            Reales: promhe
            Caracter: valid

    Inicio:

        cont_dia <- 0

        Escribir("Desea ingresar datos de un periodo:")
        Leer(valid)
        
        Repetir Mientras(valid <> 's' AND valid <> 'n')
            Escribir("Ingrese de nuevo:")
            Leer(valid)
        fin mientras

        Repetir Mientras(valid == 's')

                cont_dia <- cont_dia + 1
                Escribir("Ingrese el dia:")
                Leer(dia)
                
                Repetir Mientras(dia < 1 OR dia > 31)
                        Escribir("Ingrese de nuevo:")
                        Leer(dia)
                fin mientras

                id_emp <- 1
                cont_empD <- 0
                mayor_he <- 0

                Repetir Mientras(id_emp <> 0)
                        
                        Escribir("Ingrese el id del empleado:")
                        Leer(id_emp)
                        
                        Si(id_emp > 0)  entonces:
                            
                            Escribir("Realizo horas extras:")
                            Leer(valid)
                            
                            Repetir Mientras(valid <> 's' AND valid <> 'n')
                                    Escribir("Ingrese de nuevo:")
                                    Leer(valid)
                            fin mientras

                            Si (valid == 's') entonces:

                                cont_empD <- cont_empD + 1
                                Escribir("Ingrese la horas extras del empleado con id:",id_emp)
                                Leer(cont_he)

                                Si (cont_empD == 1) entonces:
                                    
                                    mayorhe <- cont_he
                                    emp_mhe <- id_emp

                                Sino:

                                    Si (cont_he > mayorhe)  entonces:

                                        mayorhe <- cont_he
                                        emp_mhe <- id_emp
                                    
                                    fin si

                                fin si

                                totalhe_dia <- totalhe_dia + cont_he
                                totalhe_periodo <- totalhe_periodo + cont_he

                            fin si

                        fin si

                fin mientras

                prom_he <- totalhe_dia / cont_empD
                Escribir("El promedio de horas extras es:",prom_he)

                Escribir("Desea ingresar datos de un periodo:")
                Leer(valid)
                
                Repetir Mientras(valid <> 's' AND valid <> 'n')
                    Escribir("Ingrese de nuevo:")
                    Leer(valid)
                fin mientras
                
        fin mientras

    Fin.
*/

#include <stdio.h>
#include <conio.h>

int main()
{
    int dia,id_emp,cant_he,totalhe_periodo,totalhe_dia,emp_mhe,mayorhe,cant_dia,cont_empD,total_emphe;
    float prom_he;
    char valid;

    cant_dia = 0;
    totalhe_periodo = 0;
    total_emphe = 0;
    
    printf("Desea ingresar datos:");
    scanf(" %c",&valid);

    while (valid != 's' && valid != 'n')
    {
        printf("Ingrese de nuevo:");
        scanf(" %c",&valid);
    }

    while (valid == 's')
    {
        cant_dia += 1;

        printf("---------------------------------------------");
        printf("\nIngrese el dia:");
        scanf("%d",&dia);

        while (dia < 1 || dia > 31)
        {
            printf("Ingrese un dia valido:");
            scanf("%d",&dia);
        }

        id_emp = 1;
        cont_empD = 0;
        totalhe_dia = 0;
        prom_he = 0;

        while (id_emp != 0)
        {
            printf("Ingrese la identificacion del empleado:");
            scanf("%d",&id_emp);

            if (id_emp > 0)
            {
                printf("Realizo horas extras el empleado %d:",id_emp);
                scanf(" %c",&valid);

                while (valid != 's' && valid != 'n')
                {
                    printf("Ingrese de nuevo:");
                    scanf(" %c",&valid);
                }

                if (valid == 's')
                {
                    total_emphe += 1;
                    cont_empD += 1;

                    printf("Ingrese las horas extras:");
                    scanf("%d",&cant_he);

                    if (cont_empD == 1)
                    {
                        emp_mhe = id_emp;
                        mayorhe = cant_he;
                    }
                    else if (cant_he > mayorhe)
                    {
                        mayorhe = cant_he;
                        emp_mhe = id_emp;
                    }
                    
                    totalhe_dia = totalhe_dia + cant_he;
                    totalhe_periodo = totalhe_periodo + cant_he;
                }
                                
            }
            
        }
        
        prom_he = (float) totalhe_dia / cont_empD;
        printf("\nEmpleado con mayor horas extras:%d",emp_mhe);
        printf("\nPromedio de horas extras:%.2f",prom_he);

        printf("\n\nDesea ingresar mas dias:");
        scanf(" %c",&valid);

        while (valid != 's' && valid != 'n')
        {
            printf("Ingrese de nuevo:");
            scanf(" %c",&valid);
        }
        
    }

    printf("---------------------------------------------");
    printf("\nLa cantidad de dia de trabajo fueron:%d",cant_dia);

    getch();
    return 0;
}