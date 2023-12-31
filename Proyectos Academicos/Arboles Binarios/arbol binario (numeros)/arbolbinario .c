

/* arbolbinario .c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolbinario.h"

	/* Funcion de insertar */

	void inserta ( arbol ** A , int x )											// funcion para insertar
	{
	 if (*A == NULL ) {															// verifico que puntero A este vacio, que no apunte a ningun nodo del arbol
		 *A = ( arbol *) malloc ( sizeof ( arbol ) ) ;							// creo un espacio de memoria, para hacer el nodo, con tamaño de la struct arbol
		 (*A )->dato = x ;														// asigno el valor entero x a dato, atraves del puntero A 
		 (*A )->h_izq = NULL ;													// establesco al puntero NULL para decir que no tiene hijos 
		 (*A )->h_der = NULL ;													// establesco al puntero NULL para decir que no tiene hijos
		 }
	 else {
		if (  x < (*A ) -> dato) 												// evalua si x es menor al dato que es apuntado por A
			 inserta ( & ((*A ) -> h_izq ) , x ) ;								// llamo funcion insertar para ponerlo en lado izq del arbol
		 else if ( x > (*A ) -> dato)											// evalua si x es mayor al dato A que es apuntado por A
			 inserta ( & ((*A ) -> h_der ) , x ) ;								// llamo funcion insertar para ponerlo en lado der del arbol
		 }
	 }

	
	/* Funcion verificar si existe el nodo */
	
	 int es_miembro ( arbol * A , int x ) {										// la funcion apunta a la estructura
	 if ( A == NULL )															// verifico que puntero A este vacio, sino
		 return -1;																// devuelvo -1 para indicar que el valor no está en el arbol

	 else if  ( A -> dato == x )												// evaluo si la info de dato es igual a x, en caso que si...
		 return 1;																// devuelve un true

	 else if ( A -> dato > x )
		 return es_miembro (A  -> h_izq , x ) ;

	 else
		 return es_miembro (A  -> h_der , x ) ;
	 }


	/* Main */

		 int main ()
		 {
		 arbol * raiz ;
		 raiz = NULL ;


			 /* Armar codigo de main para probar el arbol */

		 inserta (&raiz, 10);													// inserto de forma manual el numero al arbol
		 inserta (&raiz, 5);													// inserto de forma manual el numero al arbol
		 inserta (&raiz, 18);													// inserto de forma manual el numero al arbol
		 inserta (&raiz, 16);													// inserto de forma manual el numero al arbol
		 inserta (&raiz, 3);													// inserto de forma manual el numero al arbol


		if (es_miembro ( raiz , 5) == 1)
			 printf ("\nEl elemento buscado existe en el arbol \n");			// llamo funcion para ver si existe el num en nodo
		else
			 printf ("\nNo existe \n") ;

		if (es_miembro (raiz, 124) == 1)										// llamo funcion para ver si existe el num en nodo
			 printf ("\nEl elemento buscado existe en el arbol \n");
		else
			 printf ("\nNo existe \n");
			 printf ("\n");


		printf("listado en inorden\n");											// llamo funcion para listar el arbol en cierto orden
		listar_inorden(raiz);
			printf ("\n");

		printf("listado en posorden\n");										// llamo funcion para listar el arbol en cierto orden
		listar_posorden(raiz);
			printf ("\n");

		printf ("listado en preorden\n");										// llamo funcion para listar el arbol en cierto orden
		listar_preorden(raiz);
		 	printf ("\n");

		return 0;

	}

	/*Funciones de listado*/

	void listar_preorden ( arbol* raiz) {
		if ( raiz != NULL) 														// evaluo la raiz si esta vacia, si no, continua
		{													
			printf ("%d \n", raiz -> dato);										// imprimo primero la raiz
			listar_preorden ( raiz -> h_izq);									// me muevo hacia la derecha (imprimo)
			listar_preorden ( raiz -> h_der);
		}
	}

	void listar_inorden (arbol* raiz) {
		if ( raiz != NULL)														// evaluo la raiz si esta vacia, si no, continua
		{
			listar_inorden ( raiz -> h_izq );									// me muevo hacia la izquierda (imprimo)
			printf ("%d \n", raiz -> dato);										// imprimo la raiz
			listar_inorden ( raiz -> h_der);									// me muevo hacia la derecha (imprimo)
		}
	}

	void listar_posorden (arbol* raiz) {
		if ( raiz != NULL)														// evaluo la raiz si esta vacia, si no, continua
			{
			listar_posorden ( raiz -> h_izq );									// me muevo hacia la izquierda (imprimo)
			listar_posorden ( raiz -> h_der);									// me muevo hacia la derecha (imprimo)
			printf ( "%d \n", raiz -> dato);									// imprimo la raiz
		}
	}

	/*Funcion para eliminar*/

	int suprime_min ( arbol ** A )
 {
		int v_ref ;
		if ((* A ) -> h_izq == NULL ) {
			v_ref = (* A ) -> dato;
			arbol * tmp = * A;
			* A = (* A ) -> h_der;
			free ( tmp );
			return v_ref;
 		} else {
 			return suprime_min (&((* A ) -> h_izq ) ) ;
 			}
 }
		void suprime ( arbol ** A , int x ) {

 		if (* A != NULL ) {
 			if ( x < (* A ) -> dato )
 				suprime (&((* A ) -> h_izq ) , x ) ;
 		else if ( x > (* A ) -> dato )
 				suprime (&((* A ) -> h_der ) , x ) ;

 // Lo encontre

 		else if ((* A ) -> h_izq == NULL && (* A ) -> h_der == NULL ) {
 			arbol * tmp = * A ;
 			* A = NULL ;
 			free ( tmp ) ;
		} else if ((* A ) -> h_izq == NULL ) {
 			arbol * tmp = * A ;
			 * A = (* A ) -> h_der ;
			 free ( tmp ) ;
 		} else if ((* A ) -> h_der == NULL ) {
 			arbol * tmp = * A ;
 			* A = (* A ) -> h_izq ;
 			free ( tmp ) ;
 		} else { 												// ambos hijos estan presentes
 			(* A ) -> dato = suprime_min (&((*A ) -> h_der ) ) ;
 		}
	}
}
