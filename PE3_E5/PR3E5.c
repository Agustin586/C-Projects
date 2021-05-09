/*
	Autor: Zuliani,Agustin
	Fecha: 30/04/21
	Programa: Practica de repaso 3, ejercicio 5
*/

//Algoritmo: PR3E5
//Variables: entero num
//Inicio:
//	Escribir(“Ingrese el número según el día de la semana”)
//	Leer(num)
//	Según Sea (num)
//		caso 1: Escribir(“Lunes”)
//		caso 2: Escribir(“Martes”)
//		caso 3: Escribir(“Miercoles”)
//		caso 4: Escribir(“Jueves”)
//		caso 5: Escribir(“Viernes”)
//		caso 6: Escribir(“Sabado”)
//		caso 7: Escribir(“Domingo”)
//Fin Según
//Fin.

#include <stdio.h>
#include <stdint.h>

int main()
{
	uint8_t num;
	
	printf("Ingrese el numero:");
	scanf("%d",&num);
	
	// Menu //
	switch(num)
	{
		case 1: 
		{	printf("Lunes");break;		}
		case 2: 
		{	printf("Martes");break;		}
		case 3: 
		{	printf("Miercoles");break;	}
		case 4:
		{	printf("Jueves");break;		} 
		case 5:
		{	printf("Viernes");break;	} 
		case 6: 
		{	printf("Sabado");break;		}
		case 7: 
		{	printf("Domingo");break;	}
		default:
		{	printf("Ingrese de nuevo");break;	} 
	}
	
	return 0;
}


