/**/

/**/

#include <stdio.h>
#include <conio.h>

int main()
{
    int hora,min,i,aux_max,aux_min,cont_25;
    float maxtemp,mintemp,temp;
    char valid;

    printf("Desea ingresar datos:");
    scanf(" %c",&valid);
    while (valid != 's' && valid != 'n')
    {
        printf("Ingrese de nuevo:");
        scanf(" %c",&valid);
    }

    cont_25 = 0;
    aux_min = 0;
    aux_max = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Ingrese la temperatura %d:",i+1);
        scanf("%f",&temp);

        if (i == 0)
        {
            maxtemp = temp,aux_max = i+1;
            mintemp = temp,aux_min = i+1;
        }
        else if (maxtemp < temp)
        {
            maxtemp = temp;
            aux_max = i+1;
        }
        else if (temp < mintemp)
        {
            mintemp = temp;
            aux_min = i+1;
        }
        
        if (temp > 25)
        {
            cont_25 = cont_25 + 1;
        }
    }

    if (valid == 's')
    {
        printf("Cantidad de veces superado los 25 C:%d",cont_25);

        hora = (aux_max * 30) / 60;
        min = (aux_max * 30) % 60;
        printf("\nLa temperatura maxima fue:%.2f C,a las:%02d:%02d hs",maxtemp,hora,min);

        hora = (aux_min * 30) / 60;
        min = (aux_min * 30) % 60;
        printf("\nLa temperatura minima fue:%.2f C,a las:%02d:%02d hs",mintemp,hora,min);
    }
    else
    {
        printf("No se ingreso ningun dato");
    }

    getch();
    return 0;
}
