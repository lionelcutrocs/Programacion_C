

/* arbolbinario .c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolbinario.h"

	/* Funcion de insertar */

	void inserta ( arbol **A , char *x )										// funcion para insertar
	{
	 if (*A == NULL ) {															// verifico que puntero A este vacio, que no apunte a ningun nodo del arbol
		 *A = ( arbol *) malloc ( sizeof ( arbol ) ) ;							// creo un espacio de memoria, para hacer el nodo, con tamaño de la struct arbol
		 (*A )->dato = strdup (x);												// strdup para crear una copia del string y le paso x para que lo almacene 
		 (*A )->h_izq = NULL ;													// establesco al puntero NULL para decir que no tiene hijos 
		 (*A )->h_der = NULL ;													// establesco al puntero NULL para decir que no tiene hijos
		 }
	 else {
		if ( strcmp (x, (*A) -> dato ) < 0 )									// strcmp para comparar x con dato, si es menor a 0
			 inserta ( & ((*A ) -> h_izq ) , x ) ;								// si es < 0, inserta string + nodo en h_izq
		 else if ( strcmp (x, (*A) -> dato) > 0 )								// strcmp para comparar x con dato, si es mayor
			 inserta ( & ((*A ) -> h_der ) , x ) ;								// si es > 0, inserta string + nodo en h_der
		}
	}
	
	/* Funcion verificar si existe el nodo */

    int es_miembro (arbol *A, char *x) 										// la funcion apunta a la estructura
    {
     	if (A == NULL)                                                         // verifico que puntero A este vacio
		{
			printf("Nodo vacio encontrado\n");
			return -1;																// devuelvo -1 para indicar que A está vacio
		}

		printf ("\nComparando %s con %s\n", A->dato, x );

	 	if ( strcmp (x, A-> dato) == 0 )										// evaluo con strcmp si dato, x es == 0
		{	
			printf ("Nodo encontrado: %s\n", A->dato ); 
			return 1;																// si lo es devuelve 1
		
		} else if ( strcmp (x, A-> dato) < 0 )	{									// evaluo con strcmp si dato, x es > 0
		
			printf ("Buscando el subarbol izq\n");
			return es_miembro (A-> h_izq , x ) ;									// si lo es busca en la parte h_izq del arbol
		
		} else {
		 	printf ("Buscando el subarbol der\n");
			return es_miembro (A-> h_der , x ) ;									// si no lo es, busca en la parte h_der del arbol
		}
	}


	/* Main */

 int main ()
{
 arbol * raiz ;															// creo el puntero raiz de tipo arbol, para apuntar hacia él	
 raiz = NULL ;															// inicializo el puntero en NULL para decir que arranca en 0
		 
 char resp1 [5];
 char resp2 [10];
 char resp3 [3];
 char respn [15];

	inserta (&raiz, "manzana");											// inserto de forma manual el string al arbol
	inserta (&raiz, "pera");												// inserto de forma manual el string al arbol
	inserta (&raiz, "fresa");												// inserto de forma manual el string al arbol
	inserta (&raiz, "uva");											// inserto de forma manual el string al arbol
	inserta (&raiz, "naranja");											// inserto de forma manual el string al arbol

	printf("listado en inorden\n");											// llamo funcion para listar el arbol en cierto orden
	listar_inorden(raiz);
		printf ("\n");

	printf ("Que nodo queres verificar?\n");
	printf ("-> ");
	scanf ("%s", resp1 );

	if ( strcmp ( resp1, "raiz" ) == 0 )
	{
		printf ("\nIngrese la raiz\n");
		printf ("-> ");
		scanf ("%s", resp2 );
		
		if (es_miembro ( raiz , resp2 ) == 1)
		{
			printf ("\nLa raiz, si existe.\n");			// llamo funcion para ver si existe la raiz robertos
		}
		else {
			printf ("\nNo existe una raiz\n") ;
		}
	} 
	
	printf ("\nQueres buscar un nodo?\n");
	printf ("-> ");
	scanf ("%s", resp3 );

	if ( strcasecmp ( resp3, "si" ) == 0 )
	{
		printf ("\nIngrese el nodo\n");
		printf ("-> ");
		scanf ("%s", respn );

		if (es_miembro ( raiz, respn ) == 1) 						// llamo funcion para ver si existe el nodo lionel
		{									
			printf ("\nEl nodo ingresado existe\n");
		}
		else {
			printf ("\nNo existe 2\n");
		}
	}
	



	// printf("listado en inorden\n");											// llamo funcion para listar el arbol en cierto orden
	// listar_inorden(raiz);
	// 	printf ("\n");

	// printf("listado en posorden\n");										// llamo funcion para listar el arbol en cierto orden
	// listar_posorden(raiz);
	// 	printf ("\n");

	// printf ("listado en preorden\n");										// llamo funcion para listar el arbol en cierto orden
	// listar_preorden(raiz);
	// 	printf ("\n");

 
	 system ("pause");
	 return 0;
	}

	/*Funciones de listado*/

	void listar_preorden ( arbol* raiz) {
		if ( raiz != NULL) 														// evaluo la raiz si esta vacia, si no, continua
		{													
			printf ("%s \n", raiz -> dato);										// imprimo primero la raiz
			listar_preorden ( raiz -> h_izq);									// me muevo hacia la izquierda (imprimo)
			listar_preorden ( raiz -> h_der);									// me muevo hacia la derecha (imprimo)
		}
	}

	void listar_inorden (arbol* raiz) {
		if ( raiz != NULL)														// evaluo la raiz si esta vacia, si no, continua
		{
			listar_inorden ( raiz -> h_izq );									// me muevo hacia la izquierda (imprimo)
			printf ("%s \n", raiz -> dato);										// imprimo la raiz
			listar_inorden ( raiz -> h_der);									// me muevo hacia la derecha (imprimo)
		}
	}

	void listar_posorden (arbol* raiz) {
		if ( raiz != NULL)														// evaluo la raiz si esta vacia, si no, continua
			{
			listar_posorden ( raiz -> h_izq );									// me muevo hacia la izquierda (imprimo)
			listar_posorden ( raiz -> h_der);									// me muevo hacia la derecha (imprimo)
			printf ( "%s \n", raiz -> dato);									// imprimo la raiz
		}
	}

	/*Funcion para eliminar*/

// 	int suprime_min ( arbol ** A )
//  {
// 		int v_ref ;
// 		if ((* A ) -> h_izq == NULL ) {
// 			v_ref = (* A ) -> dato;
// 			arbol * tmp = * A;
// 			* A = (* A ) -> h_der;
// 			free ( tmp );
// 			return v_ref;
//  		} else {
//  			return suprime_min (&((* A ) -> h_izq ) ) ;
//  			}
//  }
// 		void suprime ( arbol ** A , char x ) {

//  		if (* A != NULL ) {
//  			if ( x < (* A ) -> dato )
//  				suprime (&((* A ) -> h_izq ) , x ) ;
//  		else if ( x > (* A ) -> dato )
//  				suprime (&((* A ) -> h_der ) , x ) ;

//  // Lo encontre

//  		else if ((* A ) -> h_izq == NULL && (* A ) -> h_der == NULL ) {
//  			arbol * tmp = * A ;
//  			* A = NULL ;
//  			free ( tmp ) ;
// 		} else if ((* A ) -> h_izq == NULL ) {
//  			arbol * tmp = * A ;
// 			 * A = (* A ) -> h_der ;
// 			 free ( tmp ) ;
//  		} else if ((* A ) -> h_der == NULL ) {
//  			arbol * tmp = * A ;
//  			* A = (* A ) -> h_izq ;
//  			free ( tmp ) ;
//  		} else { 										
//  			(* A ) -> dato = suprime_min (&((*A ) -> h_der ) ) ;
//  		}
// 	}
// }
