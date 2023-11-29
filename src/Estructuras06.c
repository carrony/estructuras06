/*
 ============================================================================
 Name        : Estructuras06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "carrito.h"

int main(void) {

	int opcion,i;
	producto p;
	float subtotal,iva, total;

	producto carrito[MAXARTICULOS] = {
			{"ratón", 10.9, 0.21, 4 },
			{"arroz", 0.9, 0.04, 10},
			{"cerveza", 0.45, 0.04, 30},
			{"Paq folios", 6.5, 0.11, 1}
	};
	int tam=4;

	puts("Programa de carrito de la compra");

	do{
		puts("Menu de opciones");
		puts("1. Insertar articulo");
		puts("2. Mostrar carrito");
		puts("3. Calcular el subtotal");
		puts("4. Calcular el IVA");
		puts("5. Total del carrito");
		puts("opción:");
		fflush(stdout);
		scanf("%d",&opcion);

		switch(opcion){
		case 1:
			puts("Introduce arículo nuevo");
			p=pedirArticulo();

			//pedirArticulo(&p);

			puts("insertando...");
			tam=insertarArticulo(carrito,tam,p);
			break;
		case 2:
			puts("El carrito es ");
			for (i=0;i<tam;i++) {
				mostrarArticulo(carrito[i]);
			}
			break;
		case 3:
			subtotal= calculaSubtotal(carrito, tam);
			printf("\nEl subtotal es %.2f",subtotal);
			break;
		case 4:
			iva= calculaIVA(carrito, tam);
			printf("\nEl IVA es %.2f",iva);
			break;
		case 5:
			total= calculaTotal(carrito, tam);
			printf("\nEl total es %.2f",total);
			break;
		}
	}while (opcion!=0);
	return EXIT_SUCCESS;
}
