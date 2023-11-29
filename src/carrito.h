/*
 * carrito.h
 *
 *  Created on: 29 nov 2023
 *      Author: Usuario
 */

#ifndef CARRITO_H_
#define CARRITO_H_
#define MAXARTICULOS 50
#define MAXNOMBRE 30

#include <string.h>
#include <stdio.h>

	typedef struct  {
		 char nombre[MAXNOMBRE];
		 float precio;
		 float iva;
		 int cantidad;
		} producto;


	producto pedirArticulo(void);
	void pedirArticulo2(producto *p);

	void mostrarArticulo(producto p);


	int insertarArticulo(producto listaArticulos[MAXARTICULOS], int tam, producto p);

	float calculaSubtotal(producto listaArticulos[MAXARTICULOS], int tam);

	float calculaIVA(producto listaArticulos[MAXARTICULOS], int tam);

	float calculaTotal(producto listaArticulos[MAXARTICULOS], int tam);

#endif /* CARRITO_H_ */
