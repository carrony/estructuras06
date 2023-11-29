/*
 * carrito.c
 *
 *  Created on: 29 nov 2023
 *      Author: Usuario
 */

#include "carrito.h"


producto pedirArticulo(void){

	producto pr;
	puts("Nombre Artículo: ");
	fflush(stdin);
	fflush(stdout);
	fgets(pr.nombre, MAXNOMBRE, stdin);
	pr.nombre[strlen(pr.nombre)-1]='\0';

	puts("Precio: ");
	fflush(stdout);
	scanf("%f", &(pr.precio));

	puts("IVA: ");
	fflush(stdout);
	scanf("%f", &(pr.iva));
	pr.iva=pr.iva/100;

	puts("Cantidad: ");
	fflush(stdout);
	scanf("%d", &(pr.cantidad));

	return pr;
}



	void pedirArticulo2(producto *p){
		puts("Nombre Artículo: ");
		fflush(stdin);
		fflush(stdout);
		fgets(p->nombre, MAXNOMBRE, stdin);
		p->nombre[strlen(p->nombre)-1]='\0';

		puts("Precio: ");
		fflush(stdout);
		scanf("%f", &(p->precio));


		puts("IVA (numero entero): ");
		fflush(stdout);
		scanf("%f", &(p->iva));
		p->iva=p->iva/100;

		puts("Cantidad: ");
		fflush(stdout);
		scanf("%d", &(p->cantidad));
	}

	void mostrarArticulo(producto p){
		printf("\nNombre: %s",p.nombre);
		printf("\nPrecio: %.2f",p.precio);
		printf("\nIVA: %.2f %%",p.iva*100);
		printf("\nNum. unidades: %d",p.cantidad);
	}


	int insertarArticulo(producto listaArticulos[MAXARTICULOS], int tam, producto p) {
		if (tam>=MAXARTICULOS) {
			return tam;
		}
		listaArticulos[tam]=p;
		tam++;
		return tam;
	}

	float calculaSubtotal(producto listaArticulos[MAXARTICULOS], int tam) {
		int i=0;
		float subtotal=0;

		for(i=0;i<tam;i++) {
			subtotal=subtotal+listaArticulos[i].cantidad*listaArticulos[i].precio;
		}
		return subtotal;
	}

	float calculaIVA(producto listaArticulos[MAXARTICULOS], int tam){
		int i=0;
		float iva=0;

		for(i=0;i<tam;i++) {
			iva=iva+listaArticulos[i].cantidad*listaArticulos[i].precio
					*listaArticulos[i].iva;
		}
		return iva;
	}

	float calculaTotal(producto listaArticulos[MAXARTICULOS], int tam){
		return calculaSubtotal(listaArticulos,tam)+calculaIVA(listaArticulos,tam);
	}
