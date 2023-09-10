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

 int opcion;		 
 char resp1 [5];
 char resp2 [10];
 char resp3 [3];
 char respn [15];
 
//																		// insercion de nodos
	inserta (&raiz, "manzana");											// 7
	inserta (&raiz, "uva");												// 3
	inserta (&raiz, "pera");											// 4
	inserta (&raiz, "fresa");											// 5
	inserta (&raiz, "naranja");											// 7

	// printf("listado en inorden\n");									// llamo funcion para listar el arbol en cierto orden
	// listar_inorden(raiz);
	// 	printf ("\n");

	printf ("Bienvenidx al manejo de Arbol Binario.\n");
	printf ("Eliga la siguiente opcion para comenzar.\n");
	printf ("\n1. Opcion de Busqueda de Raiz.\n");
	printf ("2. Opcion de Busqueda de Nodos.\n");

	printf ("\nIngrese el numero correspondiente\n");
	printf ("-> ");
	scanf ("%d", &opcion );

	switch ( opcion )
	{
	case 1:
		printf ("Busqueda de Raiz, seleccionado.\n");
		
		printf ("\nIngrese la raiz\n");
		printf ("-> ");
		scanf ("%s", resp2 );
		
		if (es_miembro ( raiz , resp2 ) == 1)
		{
			printf ("\nLa raiz, si existe.\n");							// llamo funcion para ver si existe la raiz robertos
		
		} else {
			printf ("\nNo existe una raiz\n") ;
		
		}
		break;

	case 2:
		printf ("Busqueda de Nodo, seleccionado.\n");

		printf ("\nIngrese el nodo\n");
		printf ("-> ");
		scanf ("%s", respn );

		if (es_miembro ( raiz, respn ) == 1) 							// llamo funcion para ver si existe el nodo lionel
		{									
			printf ("\nEl nodo ingresado existe\n");
		}
		else {
			printf ("\nEl nodo, no existe\n");
		}

	default:
		printf ("Numero no reconocido.\n");
		break;
	}

	



	// printf("listado en inorden\n");									// llamo funcion para listar el arbol en cierto orden
	// listar_inorden(raiz);
	// 	printf ("\n");

	// printf("listado en posorden\n");									// llamo funcion para listar el arbol en cierto orden
	// listar_posorden(raiz);
	// 	printf ("\n");

	// printf ("listado en preorden\n");								// llamo funcion para listar el arbol en cierto orden
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

 int suprime_min ( arbol ** A )
{
	int v_ref ;
	if ((* A ) -> h_izq == NULL ) 
	{
		v_ref = (* A ) -> dato;
		arbol * tmp = * A;
		* A = (* A ) -> h_der;
		free ( tmp );
		return v_ref;
	} else {
		return suprime_min (&((* A ) -> h_izq ) );
	}
}

 void suprime ( arbol ** A , char x )
{
	if (* A != NULL ) 														// Verifico que haya un nodo en la posicion actual
	{
 		if ( x < (* A ) -> dato )											// Elimino un nodo simple en lado Izquierdo
 			suprime (&((* A ) -> h_izq ) , x );

 		else if ( x > (* A ) -> dato )										// Elimino un nodo simple en lado Derecho
 			suprime (&((* A ) -> h_der ) , x );
//																		 	// Encuentro nodo, adapto varios casos de eliminacion
 		else if ((* A ) -> h_izq == NULL && (* A ) -> h_der == NULL ) {		// Caso, el nodo sin hijos.
			 arbol * tmp = * A;												// Creo un puntero temporal "tmp" apuntando al nodo a eliminar
			 * A = NULL;													// Indico que el nodo se elimino en el arbol
 			 free ( tmp );													// Libero memoria ocupada por "tmp"

		} else if ((* A ) -> h_izq == NULL ) {								// Elimino nodo en lado Derecho
 			 arbol * tmp = * A;
			 * A = (* A ) -> h_der;
			 free ( tmp );

 		} else if ((* A ) -> h_der == NULL ) {								// Elimino nodo en lado Izquierdo
 			 arbol * tmp = * A;
 			 * A = (* A ) -> h_izq;
 			 free ( tmp );

 		} else {			
 			(* A ) -> dato = suprime_min (&((*A ) -> h_der ) );				// Elimino un padre con hijos, se llama a suprimir en el valor minimo a la derecha
 		}																	// y reemplazo el valor minimo entre los valores mayores y se actualiza,
 	}																		// este metodo ayuda a mantener el arbol en equilibrio.
}
