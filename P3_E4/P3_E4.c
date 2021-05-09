/*
	Autor: Zuliani Agustin
	Fecha: 28/04/21
	Practica: 3
	Ejercicio: 4
*/

/*
	Algoritmo: Ejercicio 4 Practica 4
	
	Variables: 
		Entero: SegIn,SegOut,Horas,Minutos
	Inicio:
		Escribir("Ingrese los segundos:")
		Leer(SegIn)
		
		Horas = SegIn / 3600
		Minutos = mod(SegIn,3600)/60
		SegOut = mod(mod(SegIn,3600),60)
	Fin.
*/

// Incluimos las librerias //
#include <stdio.h>
#include <stdint.h>

int main()
{
	uint32_t SegIn,SegOut,Horas,Minutos;
	
		// Ingreso de valores //
		printf("En este programa se calcula las horas,minutos y segundos");
		printf("Ingrese los segundos:");
		scanf("%d",&SegIn);
		
		// Proceso de resolucion // 	
		Horas = SegIn / 3600;
		Minutos = (SegIn % 3600) / 60;
		SegOut = ((SegIn % 3600) % 60);
		
		// Imprime los valores //
		printf("%d hs %d min %d seg",Horas,Minutos,SegOut);
//		printf("\n Segundos:%d",SegOut);
//		printf("\t Minutos:%d",Minutos);
//		printf("\t Horas:%d",Horas);
//		printf("\n \n");
	
	return 0;
}

