#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define V 6                           // Número total de nodos
#define INFINITO 9999                 



    /* Funcion para hallar el minimo, reemplaza la macro propuesta */

int min ( int a, int b )
{//                                                                         // Si a es menor que b, devuelve a;
    return a < b ? a : b;                                                   // de lo contrario, devuelve b.
}

    /* Funcion para imprimir la actualizacion del GF en cada iteracion */

void imprimir_grafo ( int GF [ V ] [ V ] )                                  // Parametro el GF para imprimirlo.
{
    printf("\nGrafo con el flujo actualizado:\n\n");                        // Imprimo cabecera para marcar el comienzo.

    for (int i = 0; i < V; i++)                                             // Recorro segun nodos e indices del GF.
    {
        for (int j = 0; j < V; j++)                                         // Recorro para tener el otro sentido del GF.
        {
            printf("%d ", GF [ i ] [ j ] );                                 // Imprimo el nodo que corresponde.
        }
        printf("\n");                                                       // Dejo un espacio para que se entienda.
    }
}

    /* Funcion de algoritmo BFA Busqueda en lo Ancho */

int BFS ( int GF [ V ] [ V ], int T, int visitado [ V ], int padre [ V ] )  // Parametros necesarios para que funcione.
{   
    memset ( visitado, 0, sizeof ( *visitado ) * V );               // Establezco primero el arreglo de visitas en 0.
    memset ( padre, -1, sizeof ( *padre ) * V );                    // Establezo primero el arreglo de padre en 0.

 int cola [ V ];                                                    // Defino la cola con la cantidad de nodos en total.
 int primero = 0;                                                   // Inicializo el indice de la cola primer elemento en 0.
 int ultimo = 0;                                                    // Inicializo el indice de la cola ultimo elemento en 0.
 int s = 0;                                                         // Inicializo la variable " s " en 0.

    cola [ ultimo++ ] = s;                                          // Inicializo la cola indicando a S como ultimo y aumento.
    visitado [ s ] = 1;                                             // Indico al nodo S como ya visitado "= 1".
    padre [ s ] = -1;                                               // Indico que S como raiz no tiene padre "-1".

    while ( primero < ultimo )                                      // While para iterar mientras haya nodos en la cola.
    {
        s = cola [ primero++ ];                                     // En cada iteracion, se toma el 1er elemento de la cola y se asigna a S.
        for ( int i = 0; i < V; i++)                                // Itera sobre todos los posibles nodos i, recorriendo vecinos de S.
        {
            if ( visitado [ i ] == 0 && GF [ s ] [ i ] > 0 )        // Verifico si el nodo i aun no se visito.
            {
                cola [ ultimo ++ ] = i;                             // Este nodo se agrega al ultimo de la cola, y aumento para asegurar espacio disponible.
                padre [ i ] = s;                                    // Indico S como padre de i, asi luego rastreo el camino de los padres de cada nodo visitado.
                visitado [ i ] = 1;                                 // Indico al nodo que corresponda como visitado.
            }   
        }  
    }
    return ( visitado [ T ] == 1 );                                 // Verifico si se visito T y si es true, hay un camino de S a T.
}

    /* Funcion Ford - Fulkerson, Algoritmo */

int ford_fulkerson ( int GF [ V ] [ V ], int S, int T, int visitado [ V ], int padre [ V ] ) 
{

 int flujo_maximo = 0;                                                  // Inicializo el flujo maximo en 0.

    /* Miestras haya un camino aumentante en el GF Aux*/        

    while ( BFS( GF, T, visitado, padre ) )                             // Bucle principal de la fucion.
    {
        int nodo_actual = T;                                            // Inicializo el nodo actual con el valor de "T = 1".
        int capacidad_minima = INFINITO;                                // Inicializo la capacidad minima 9999, para poder actualizar en el camino aumentante.
           

        /* Busco la capacidad minima en el camino aumentante de T a S */

        while ( nodo_actual != S )                                      // Esta condicion, hace retroceder por el camino aumentante T a S
        {                                                                                   // Nodo siguiente es el padre de nodo actual
            int nodo_siguiente = padre [nodo_actual];                                       // Obtengo nodo siguiente, por el camino aumentante.
            capacidad_minima = min(capacidad_minima, GF [nodo_siguiente][nodo_actual] );    // Actualizo la capacidad minima.
            nodo_actual = nodo_siguiente;                                                   // Me muevo al siguiente para seguir retrocediendo por el camino.
        }                                                               // Ademas hallar la CM es ver el flujo maximo que se puede mandar por ese camino
                
            nodo_actual = T;                                            // Reinicio el nodo actual para actualizar el flujo

        /* Actualizo el flujo */

        while ( nodo_actual != S )
        {
            int nodo_siguiente = padre [ nodo_actual ];                 // Obtengo nodo siguiente, por el camino aumentante.
            GF [ nodo_siguiente ] [ nodo_actual ] -= capacidad_minima;  // Resto la CM a la arista del camino actual, para disminuir el flujo en esa arista.
            GF [ nodo_actual ] [ nodo_siguiente ] += capacidad_minima;  // Sumo la CM a la arista en direccion opuesta del camino actual, para aumentar el flujo en esa arista.
            nodo_actual = nodo_siguiente;                               // Me muevo al siguiente para seguir retrocediendo por el camino.
        }

        /* Calculo del flujo maximo */
                
            flujo_maximo += capacidad_minima;                           // Sumo la CM del camino al flujo maximo.


        /* Imprimo la matriz de adyacencia del GF en cada iteracion */

            // printf ("\n-------------------->\n");
            // imprimir_grafo ( GF );
            // printf ("\n-------------------->\n");
            

        /* Imprimo los recorridos en cada iteracion, nodos por indices de arreglo */

            printf ("\nRecorrido en esta iteracion\n");
            nodo_actual = T;

        while ( nodo_actual != S )
        {
            printf ("%d,", nodo_actual );                               // Imprimo el nodo actual del camino.
            if ( padre [ nodo_actual ] != -1 )                          // Si, nodo actual tiene un padre, excepto " S ".
            {
                printf (" <- ");                                        // Imprimo la flecha para mostrar el sentido del camino.
                nodo_actual = padre [ nodo_actual ];                    // Me muevo al siguiente para seguir retrocediendo por el camino.
            }
        }
            printf ("%d,", S );                                         // Imprimo el nodo fuente " S " al final del camino.
            printf ("\n");

    } return flujo_maximo;
}



int main() {
    
 int S = 0;                                            // Inicializo el nodo S en 0, corresponde al indice del arreglo.
 int T = 5;                                            // Inicializo el nodo T en 0, corresponde al indice del arreglo.
 char resp [5];                                        // Defino variable para guardar la respuesta.

 int GF [ V ] [ V ] =                                  // Defino la Red del Grafo Figura 8.
 {
    {0, 4, 6, 0, 0, 0},
    {0, 0, 0, 3, 5, 0},
    {0, 0, 0, 0, 4, 0},
    {0, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0},
 }; 

 int visitado [ V ];                                   // Es un arreglo para los nodos visitados.
 int padre [ V ];                                      // Es un arreglo para el
 //                                                    // registro de los nodos padres en el recorrido BFS.

    printf ("Este es la Red Original\n\n");            // Cabecera para la Red del grafo.

    for ( int i = 0; i < V; i++)                       // Recorro segun nodos e indices del GF.
    {
        for ( int j = 0; j < V; j++)                   // Recorro para tener el otro sentido del GF.
        {
            printf ("%d ", GF [ i ] [ j ] );           // Imprimo el nodo correspondiente.
        }
        printf ("\n");
    }
    
    printf ("\n-------------------->\n");              // Marcador de separación.

    printf ("\n%cQuieres ver el calculo de su flujo maximo? Si o No\n", 168 );  // Pregunto para avanzar el programa.
    printf ("-> ");
    scanf  ("%s", resp );                              // Guardo respuesta en " resp ".

    if ( strcmp ( resp, "si" ) == 0 )                  // Si es " si ", se ejecuta todo el algoritmo.
    {
        int flujo_maximo = ford_fulkerson ( GF, S, T, visitado, padre );    // Invoco la función principal.
        printf ("\n-------------------->\n");                               // Marcador de separación.
        printf ("\nEl flujo maximo es: %d\n", flujo_maximo );               // Imprimo el resultado del flujo.

    } else {                                           // Si es " no ", se cierra el programa.

        printf ("\n%cHasta luego!\n", 173 );
    }
    
    printf ("\n-------------------->\n");              // Marcador de separación.

    system ("pause");
    return 0;
}