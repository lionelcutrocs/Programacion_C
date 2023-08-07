#include <stdio.h>                                        // La libreria proporciona funciones basicas de entrada y salida. 
#include <string.h>                                       // La libreria proporciona funciones para manipular y trabajar cadenas de caracteres.
#include <stdlib.h>                                       // La libreria proporciona funciones de proposito general, (nums aleatorios) srand, rand.
#include <time.h>                                         // La libreria proporciona funciones para trabajar con el tiempo.


#define MAX_INTENTOS 7                                    // Definicion de MACRO para maximos de intentos.
#define MAX_LETRAS 5                                      // Definicion de MACRO para maximos de letras (palabra secreta, palabra del usuario).
#define MAX_PARTIDA 8                                     // Definicion de MACRO para maximo  de partida.


#define PUNTAJE_INICIAL 5000                              // Definicion de MACRO para puntaje inicial.
#define PUNTAJE_PRIMER_ACIERTO 10000                      // Definicion de MACRO para puntaje del primer acierto.
#define PUNTAJE_LETRA_VERDE 100                           // Definicion de MACRO para puntaje de letra correcta (lugar).
#define PUNTAJE_LETRA_AMARILLO 50                         // Definicion de MACRO para puntaje de letra incorrecta (lugar).
#define PUNTAJE_GRIS 0                                    // Definicion de MACRO para puntaje de letra incorrecta (total incorrecto).
#define PUNTAJE_PASOFILA 500                              // Definicion de MACRO para puntaje de resto por cada intento utilizado.
#define PUNTAJE_ACIERTO 2000                              // Definicion de MACRO para puntaje ganador en intento 2 al 6, inclusives.


                            // FUNCIONES DEL PROGRAMA


void palabra_aleatoria (char **prandom, char *box_palabra[], int *longitud )  // Esta funcion genera la palabra secreta.
{
    if (*longitud <= 0)                                             // Con este if verificamos la longitud es menor o = a 0.
    {
        *prandom = NULL;                                            // Si lo es, prandom se inicializa como NULL y sale de la funcion.
        return;
    }

    srand (time(NULL) + clock());                                   // Generamos un indice aleatorio con srand, lo conseguimos con la suma de time NULL + clock.
    int indice_aleatorio = rand () % *longitud;                     // Generamos un num aleatorio en el rango de 0 a *longitud - 1, y guardamos en indice_aleatorio.

    *prandom = box_palabra [indice_aleatorio];                      // Asignamos prandom a box palabra, esto significa que ahora prandom apunta a la palabra aleatoria seleccionada.
    for (int i = indice_aleatorio; i < *longitud - 1; i++)          // Reorganizamos en array de palabras, comenzamos desde indice aleatorio,
    {                                                               // movemos los elementos i+1 en i, y esto produce la eliminacion de la palabra seleccionada.
        box_palabra [i] = box_palabra [i + 1];
    }   
    box_palabra [*longitud - 1] = NULL;                             // Asignamos NULL a la ultima posicion del arreglo box palabra,
    --(*longitud);                                                  // esto asegura que la ultima posision sea nula, indicando el final del arreglo.
    
    printf ("\n");
    printf ("\nla palabra secreta es %5s\n", *prandom);          // Habilitar para realizar pruebas, solo comentando y des-comentando es suficiente.
}

void comparar_palabra ( char *xrandom , char *x)                              // Esta funcion compara la palabra de usuario con la secreta.
{                                                                   

    int longitud2 = strlen (xrandom);                               // Creo la variable longitud2 y designo la longitud de xrandom mediante strlen.
    int i;                                                          // Defino en int i para usarlo luego en for's.
    int coincidencias [longitud2];                                  // Creo la variable coincidencias de tipo array, almacenando la longitud de la palabra secreta.
                                                                    // a su vez es donde se guardaran las coincidencias.

    if  ( strcmp ( xrandom , x ) == 0 )                             // Comparo los strings, pero pasamos directo a los casos a evaluar.
    {

    } else {                                                        // Este caso es cuando se no encuentra la exatitud de la comparacion,
                                                                    // debido que se resuelve en otra parte del programa.
        for ( i = 0; i < longitud2; i++)                            // Hacemos el recorrido del arreglo coincidencias.
        {
            coincidencias [i] = 0;                                  // Incializamos el array de coincidencias en 0.
        }
        for ( i = 0; i < longitud2; i++)                            // Recorremos los strings, palabra secreta y la del usuario.
        {
            if ( xrandom [i] == x [i] )                             // Comparo las coincidencias exactas de los strings palabra del usuario y la secreta.
            {
                coincidencias [i] = 1;                              // Vamos a guardar las coincidencias segun las posiciones y marcamos un 1.
            }   
        }
        

        printf ("\nResultado ");                                    // Comenzamos a imprimir el resultado de la comparacion para hacerlo visual al usuario.

        for ( i = 0; i < longitud2; i++)                            // Recorremos el string de coincidencias, buscando los 1.
        {
            if ( coincidencias [i] == 1)                            // Caso 1, comparo las letras exactas en lugares exactos.
            {
                printf (" %c ", xrandom [i] );                      // Las que sean exactas en su lugar, se imprimen directamente.

            } else if ( strchr ( xrandom, x [i]) != NULL) {         // Usamos strchr para buscar los caracteres, esta logica solo es por una vez el conteo de la busqueda.
                printf (" * ");                                     // Cuando encontramos la letra pero en una posicion incorrecta, la marcamos con " * " .

            } else {                                                // Caso 3, si la letra no pertenece al string, la marcamos con " - ".
                printf (" - ");
            }    
        }
    }           
}

int configuro_partida ()                                                      // Esta funcion configura la cantidad de partidas para el usuario.
{
    int i;                                                          // Definimos el i para el for mas abajo.
    int numpartidas = 0;                                            // Definimos la variable numpartidas, para guardar el valor de cantidad de partidas.
    

    printf ("---- Comencemos a configurar su partida ----\n\n");
    printf ("--------------------------------------------------------\n\n");

    printf (" - Va a poder elegir hasta 8 partidas.\n\n");
    printf (" - Tambien tendra la opcion de anular su partida,\n");
    printf ("   cuando finalice 1 jugada o partida.\n\n");
    printf (" - Cuando vea la  ( letra ) en su resultado, sera por acertar la letra en el lugar exacto.\n");
    printf (" - Cuando vea una ( * ) sera por acertar la letra en una posicion diferente.\n");
    printf (" - Cuando vea un  ( - ) sera por no acertar la letra en ningun lugar.\n\n");

    printf ("--------------------------------------------------------\n\n");
    printf ("%cListo para iniciar? -- Presione la tecla ENTER --\n", 168);
    getchar ();
    system ("cls");

    printf ("%cCuantas partida/as quieres jugar?\n\n", 168);
    printf ("-> ");
    scanf ("%d", &numpartidas);                                     // Hacemos el pedido de la cantidad de partidas y almacenamos.    

    if ( numpartidas >= 1 && numpartidas <= MAX_PARTIDA )           // Este if, nos ayuda a establecer la cantidad de partidas MAX 8.
     {
        printf ("\nHas elegido jugar %d partida/as\n", numpartidas );
     } else {                                                       

     for ( i = 0; i < numpartidas && i <= MAX_PARTIDA; i++)         // En caso de poner un num > a 8, lo volvemos a pedir con un recordatorio.
        {
            printf ("Recuerde el maximo de partida es 8, ingrese nuevamente\n");
            scanf ("%d", &numpartidas);

            if ( numpartidas <= MAX_PARTIDA  && numpartidas >= 0)   // Cuando se indica el num correcto en el rango, le selañamos la cantidad elegida.
            {
                printf ("Has elegido jugar %d partida/as\n", numpartidas );
            }   
        }  
    }
    return numpartidas;                                             // Esta funcion nos devuelve el valor de las partidas que el usuario quiere jugar.
}

int adivina_palabra ( char *xrandom, char *x )                                // Esta funcion nos ayuda a resolver uno de los casos. Adivinar al primer intento.
{

    int puntaje_inicial = PUNTAJE_INICIAL;                          // Definimos puntaje incial, para manipular los 5000 pts.
    int puntaje_ganador = PUNTAJE_PRIMER_ACIERTO;                   // Definimos puntaje ganador, para aplicar el putaje de 10000 pts.
    int puntaje_final = 0;                                          // Definimos e inicializamos puntaje final en 0, para trabajar
                                                                    // y lograr devolver un valor de la fucion.
   if ( strcmp ( xrandom, x ) == 0 )                                // Comparamos los strings con srtcmp, esta funcion utiliza 0 para true, 1 para false.
    {
        puntaje_final = puntaje_inicial + puntaje_ganador;          // Cuando sean iguales, adjuntamos los puntajes y hacemos devolver un 1.
        return 1;
    } else {                                                        // Si no lo son, devuelve un 0.
        return 0; 
    }
}

void calculo_puntaje ( char *xrandom, char *x, int *puntaje, int box_puntaje [] )    // Esta funcion nos ayuda a resolver los puntajes de los intentos.
{

    int conteo_exacto = PUNTAJE_LETRA_VERDE;                        // Definimos conteo exacto para el caso de palabras correctas (lugar).
    int conteo_parcial = PUNTAJE_LETRA_AMARILLO;                    // Definimos conteo parcial para el caso de palabras incorrectas (lugar).
    int longitud = strlen ( x );                                    // Vamos usar una logica similar a la funcion de comparacion. para el resto de la logica.
    int coincidencias [longitud];
    int i;


    for ( i = 0; i < longitud; i++)                             
    {
        coincidencias [i] = 0;                                      // Incializamos el array de coincidencias en 0.
    }
    
    for ( i = 0; i < longitud; i++)
    {
        if ( xrandom [i] == x [i] ) 
        {
            coincidencias [i] = 1;                                  // Vamos a guardar las coincidencias segun las posiciones y marcamos un 1.
        }
    }
    printf ("\n");
    printf ("\n|-> Result: ");                                      // Comenzamos a imprimir los resultados en las posiciones,
                                                                    // segun la palabra ingresada por el usuario.
    for ( i = 0; i < longitud; i++)                                 // Recorremos strings.
    {
        
        if ( coincidencias [i] == 1 )                               // Si encontramos coincidencias 1.
        {
            if ( box_puntaje [i] == 0 )                             // En main, definimos box puntaje en 0, para poder ahora darle valores a los elementos.
            {
                box_puntaje  [i] = conteo_exacto;                   // Por cada 1 encontrado, definimos 100 pts.
                *puntaje += conteo_exacto;                          // Puntaje lo definimos en main como el incial 5000 pts.
            }                                                       // entonces, sumamos un 100 al valor inicial y lo ubicamos en un arreglo.
            
        } else if ( strchr ( xrandom, x [i] ) != NULL ) {           // Vamos a buscar las letras que esten, y no sean en posicion exactas.

            box_puntaje [i] = conteo_parcial;                       // Cuando lo encuentre, definimos 50pts.
            *puntaje += conteo_parcial;                             // Igual que antes, sumamos 50 al valor inicial y lo ubicamos en un arreglo.

        } else {
            box_puntaje [i] = PUNTAJE_GRIS;                         // Vamos a definir un 0 cuando no existan coincidencias.
        }

        printf ("%d", box_puntaje [i] );                            // Imprimimos el arreglo que construimos antes, con los puntajes y
                                                                    // en las posisiones que correspondan segun la letra.
        if ( i < longitud -1 )                                      // Vamos a imprimir una " , ", para separar los elementos del arreglo.
        {
            printf (",");                                           // Esto es un adicional para mostrar al jugador de mejor manera los puntajes.
        }                                                           // Se puede optar por quitar la impresion unicamente.
    }
  
    if ( strcmp ( xrandom, x ) != 0 )                               // Este es el caso de cuando los strings no coincidan.
    {
        *puntaje -= PUNTAJE_PASOFILA;                               // Cuando en el intento jugado no adivinamos, restamos 500 pts.
    }


    printf ("\n|-> Puntaje total del intento:%d\n", *puntaje );     // Mostramos el puntaje actual en el intento jugado.
    printf ("\n-------------------->\n");
}



int main() 
{
                            // CARTEL BIENVENIDA

 int ladov = 10;                                                                // Definimos ladov, para valores verticales.
 int ladoh = 42;                                                                // Definimos ladoh, para valores horizontales.
 char mensaje [] = "Bienvenido a WordlE";                                       // Definimos el arreglo con el texto. 
    

    for (int i = 0; i < ladov; i++) 
    {                                                                           // for anidado para dibujar el cuadrado del cartel, lado vertical.
        for (int j = 0; j < ladoh; j++)                                         // Lado horizontal.
        {
            if (i == 0 || i == ladov - 1 || j == 0 || j == ladoh - 1 )          // Son las condiciones para poder dibujar los * y darle forma al cuadrado.
            {             
                printf("*");                                                    // En cada iteracion, ponemos un " * ".

            } else if (i == ladov/2 && j == ( ladoh-strlen (mensaje) ) /2 ) {   // Vemos las condiciones para posicionar el texto en el centro.
                       
                printf( "%s", mensaje );                                        // Imprimimos el mensaje que aparecera dentro del cuadrado.
                j += strlen ( mensaje ) - 1;                                    // Vamos a posicionar el comienzo del texto. 

            } else {

                printf(" ");                                                    // En caso contrario, dejara espacio en blanco.
            }
        }
        printf("\n");                                                           // Imprime un salto de linea al final de cada fila.
    }

                            // INSTRUCCIONES PUNTAJES

    printf ("\nPresione la tecla ENTER para continuar...\n\n");
    getchar ();                                                                 // Utilizamos getchar para saltar a lo siguinte.

    printf ("----------------------------------------------------------------------------------------\n\n");

    printf ("|> Reglas para tener en cuenta durante la partida.\n\n");
    printf (" - Iniciaras con 5.000 pt.\n");
    printf (" - Acertas la palabra en primer intento, ganas la jugada con 10.000 pt.\n");
    printf (" - En cada intento sumas 50 pt, en las nuevas letras acertadas (en un lugar incorrecto.)\n");
    printf (" - En cada intento sumas 100 pt, en las nuevas letras acertadas (en un lugar exacto.)\n");
    printf (" - Al ganar recibis 2.000 pt adicionales y si no logras descubrir la palabra sera 0 pt.\n");
    printf (" - Las vocales no se repiten en la misma palabra\n");
    printf (" - Las consonantes no se repiten en la misma palabra\n\n");

    printf ("----------------------------------------------------------------------------------------\n\n");

    printf ("Presione la tecla ENTER para configurar su partida.\n\n");
    getchar ();                                                                 // Ademas lo usamos para hacer una pausa y poder leer la pagina actual.
    system ("cls");                                                             // Usamos system "cls" para limpiar la consola.

                            // PROGRAMA DEL JUEGO

char *box_palabra [31]= {                                                       // Definicion de arreglo  para guardar todas las palabras para el juego.
 "ALTOS", "BARCO", "CANES", "CANTE", "CANTO", "CEJAS",
 "COBRA", "COTAS", "COPAS", "CORTE", "DOBLA", "ESTAN",
 "HILOS", "GATOS", "GOTAS", "LAPIZ", "LICOR", "LOMAS",
 "NARIZ", "NUBES", "NYLON", "PELOS", "POLEN", "PULSO",
 "REGLA", "RUEDA", "SUELO", "SURCO", "TIMON", "VALES",
 NULL
 };
                            // DECLARACION DE VARIABLES

 char p [6];                                                                    // Definicion de variable para guardar la palabra del usuario.
 char r_nuevapartida [3];                                                       // Definicion de variable para guardar la respuesta de "seguir jugando".
 char *xrandom = NULL;                                                          // Definicion de variable para inciar en NULL, esta contiene la palabra secreta.
 char resp [3];                                                                 // Definicion de variable para guardar la respuesta de "ver puntajes de partidas".

 int longitud = sizeof ( box_palabra ) / sizeof ( box_palabra [0] ) - 1;        // Definicion de variable para obtener el tamaño del arrreglo de palabras secretas a usar.
 int puntaje = PUNTAJE_INICIAL;                                                 // Definicion de variable para guardar el PUNTAJE INICIAL.
 int box_puntaje [MAX_LETRAS] = { 0, 0, 0, 0, 0};                               // Definicion de arreglo  para guardar el puntaje designado en cada intento.
 int box_puntaje_partidas [8] = {0, 0, 0, 0, 0, 0, 0};                          // Definicion de arreglo  para guardar los puntajes de cada partida.
 int partida_actual = 1;                                                        // Definicion de variable para controlar la partida actual que se este jugando.
 int final_puntaje = 0;                                                         // Definicion de variable para guardar el puntaje final de la partida.
 int contador_victorias = 0;
 int suma_puntajes = 0;
 int j;

                            // DECLARACION DE RETURNS DE FUNCIONES

 int cantidad_de_partidas = configuro_partida ();                               // Definicion de variable para guardar el resultado de la funcion "configurar partida".

                            // COMIENZO DEL PROGRAMA
    
 while ( partida_actual <= cantidad_de_partidas )                                       // El While controlara todo el juego en base a la cantidad de partidas configuradas.

    {   
        puntaje = PUNTAJE_INICIAL;                                                      // En cada partida nueva, reiniciamos la variable "puntaje".
        printf ("\n-------------------->\n");
        printf ("Partida: %d --> %d\n", partida_actual , cantidad_de_partidas );     // Imprimimos el controlador de partidas para el usuario.
        printf ("-------------------->\n");

        palabra_aleatoria ( &xrandom, box_palabra, &longitud );                         // Generamos desde el comienzo la palabra secreta a adivinar.

        int seguir_jugando = 1;                                                         // DeCDfinicion de variable para controlar si el usuario seguira jugando o no.

        for ( int i = 1; i < MAX_INTENTOS; i++)                                         // El For controlara los 6 intentos que tiene el usuario para adivinar la palabra.
        {
        
            printf ("\n");
            printf ("-------------------->\n");
            printf ("Puntos de comienzo: %d\n", puntaje );                              // Imprimimos el valor inicial, puede usarse o no, en caso de usar para controlar el inicio correcto.
            printf ("-------------------->\n\n");
            printf ("Intento --> %d\n", i );                                          // Imprimmos el controlador de intentos de las jugadas por partida.
            printf ("Ingrese su palabra\n" );                                           // Pedimos al usuario por texto que ingrese la palabra.
            printf ("-> ");
            scanf  ("%5s", p );                                                         // Al momento de ingresar la palabra que usara, se guarda en p.


                if ( xrandom == NULL )                                                  // Vamos a verificar el arreglo de palabras tenga palabras.
                {
                    printf ("\nNo hay mas palabras disponibles.\n");
                }

                adivina_palabra ( xrandom, p );                                         // Con el resultado de la funcion, podemos evaluar los siguientes casos del juego.

            if ( adivina_palabra ( xrandom, p ) == 1 && i == 1 )                        // Si el usuario adivina la palabra en el primer intento.
            {
                printf ("--------------------\n");                                      // Le indicamos que lo hizo a primera.
                printf ("\n%cAdivino la palabra!\n", 173);
                printf ("La palabra secreta era --> %5s\n", xrandom );                  // indicamos cual era la palabra.

                puntaje += PUNTAJE_PRIMER_ACIERTO;                                      // Hacemos la suma de los 10000 pts.
                printf ("Ha sumado --> %d pts, resultado de su partida:%d\n", PUNTAJE_PRIMER_ACIERTO, puntaje );    // Vamos a mostrar cuanto suma y en cuanto queda final.
                printf ("\n<----------------------------->\n\n");
                printf ("%cDesea seguir jugando? Si o No\n", 168);                      // Le preguntamos al usuario si quiere continuar jugando o no.
                scanf ("%s", r_nuevapartida );                                          // Su respuesta se guarda en r nuevapartida y se usa adelante.
                printf ("\n--------------------\n");

                final_puntaje = puntaje;                                                // El puntaje que se modifica en este caso lo almacenamos en final puntaje y 
                contador_victorias ++;
                suma_puntajes += final_puntaje;
                box_puntaje_partidas [ partida_actual - 1 ] = final_puntaje;            // lo guardamos en el arreglo de box puntaje intentos, en el numero de partida correspondiente.


                if ( strcmp( r_nuevapartida, "SI" ) == 0 ) {                            // Si el usuario opta por seguir jugando.
                    
                    cantidad_de_partidas++;                                             // Incrementamos la cantidad de partidas para continuar con la siguiente.
                    break;                                                              // Salimos del for actual.

                } else {                                                                // Caso contrario.
                    seguir_jugando = 0;                                                 // Establece seguir jugando en 0 para salir del bucle.
                    break;                                                              // Salimos del for actual.
                }

            } else if ( adivina_palabra ( xrandom, p ) == 1 && i > 1 ) {                // Caso contrario al anterior, si estamos en intento +2 inclusive, 
                                                                                        // tenemos el caso de adivinar la palabra luego del 1er intento y sumar 2000 pts.
                printf ("-------------------->\n");
                printf("\n%cAdivino la palabra en el intento %d!\n", 173, i);
                printf("La palabra secreta era: %5s\n", xrandom);                       // Indicamos cual era la palabra.

                puntaje += PUNTAJE_ACIERTO;                                             // Hacemos la suma de los 2000 pts.
                printf("Ha sumado --> %d pts, resultado de su partida:%d\n", PUNTAJE_ACIERTO, puntaje);             // Vamos a mostrar cuanto suma y e cuanto queda final.
                printf ("\n<----------------------------->\n\n");
                printf("%cDesea seguir jugando? Si o No\n", 168);                       // Le preguntamos al usuario si quiere continuar jugando o no.
                scanf("%s", r_nuevapartida);                                            // Su respuesta se guarda en r nuevapartida y se usa adelante.
                printf ("-------------------->\n");

                final_puntaje = puntaje;                                                // El puntaje que se modifica en este caso lo almacenamos en final puntaje y 
                contador_victorias ++;
                suma_puntajes += final_puntaje;                
                box_puntaje_partidas [ partida_actual - 1 ] = final_puntaje;            // lo guardamos en el arreglo de box puntaje intentos, en el numero de partida correspondiente.


                if (strcmp(r_nuevapartida, "SI") == 0) {                                // Si el usuario opra por seguir jugando.
                    
                    cantidad_de_partidas++;                                             // Incrementamos la cantidad de partidas para continuar con la siguiente.
                    break;                                                              // Salimos del for actual.

                } else {
                    seguir_jugando = 0;                                                 // Establece seguir jugando en 0 para salir del bucle.
                    break;                                                              // Salimos del for actual.
                }
            
            } else if ( adivina_palabra ( xrandom, p ) != 1 || i != 1) {                // Evaluamos cuando no sea 1 adivina palabra y se encuentre fuera del 1er intento,
                                                                                        // para poder comparar y calcular en cada intento ! al 1.
                comparar_palabra( xrandom, p );                                         // Llamamos la funcion para que realice la comparacion.
                calculo_puntaje( xrandom, p, &puntaje, box_puntaje );                   // Llamamos la funcion para que realice el calculo.
            
            }

            if ( i == 6 && adivina_palabra ( xrandom, p ) != 1 )                        // Si el jugador no adivina para el 6to intento.
            {
                printf ("\n-------------------->\n");
                printf ("\nNo adivinaste la palabra en el intento %d\n", i );          // Informamos al jugador que perdio la partida.
                printf ("La palabra secreta era %s\n", xrandom );                       // Revelamos cual era la palabra secreta.
                printf ("\n|> Puntaje total de la partida: %d\n\n", puntaje );          // Mostramos su puntaje logrado en la partida.

                final_puntaje = puntaje;                                                // El puntaje que se modifica en este casi lo almacenamos en final puntaje y
                box_puntaje_partidas [ partida_actual - 1 ] = final_puntaje;            // lo guardamos en el arreglo de box puntaje intentos, en el numero de partida correspondiente.
                
                if ( strcmp( r_nuevapartida, "SI" ) == 0 ) {                            // Si el usuario opta por seguir jugando.
                    
                    cantidad_de_partidas++;                                             // Incrementamos la cantidad de partidas para continuar con la siguiente.
                    break;                                                              // Salimos del for actual.

                } else {                                                                // Caso contrario.
                    seguir_jugando = 0;                                                 // Establece seguir jugando en 0 para salir del bucle.
                    break;                                                              // Salimos del for actual.
                }
            }
        }                                                                               // FUERA DEL BUCLE FOR HALLAMOS LO SIGUIENTE.

            if ( partida_actual == cantidad_de_partidas )                               // Si la partida actual coincide con la cantidad de partidas a jugar.
            {                                                                           // Es decir, en la ultima partida si el usuario opta puede ver sus resultados.
                printf ("%cDesea ver los puntajes finales de sus partidas? Si o no\n", 168 );   // Le preguntamos al usuario si quiere ver cada puntaje por cada partida.
                scanf ("%s", resp );                                                    // Su respuesta se guarda en resp.

                if ( strcmp ( resp, "SI" ) == 0 )                                       // Si el usuario ingreso un SI en mayus.
                {
                    printf ("\nPuntajes final de su partida: \n");                      // Indicamos donde se vera el resultado de cada partida.
                    printf ("\n-------------------->\n");
                    for ( j = 0; j < cantidad_de_partidas; j++)                         // Recorremos con otro indice para contar las partidas jugadas e
                    {
                        printf ("\nPartida %d, %d\n", j + 1, box_puntaje_partidas [j] );  // imprimimos cada resultado del arreglo con cada partida correspondiente.                    
                    }
                    printf ("\n-------------------->\n");
                }
            }
            
            if ( contador_victorias > 0 )
            {
                int promedio_puntajes =  ( int ) suma_puntajes / contador_victorias;
                printf ("\nEl promedio de puntajes es: %d\n", promedio_puntajes );
            }
            

            if ( seguir_jugando == 0 )                                                  // Evaluamos si cerramos el juego no, si es 0,
            {                                                                           // cerramos el programa con una despedida.
                printf ("\n%cGracias por jugar!. %cHasta la proxima!\n", 173, 173 );
                break;
            }

        cantidad_de_partidas --;                                                        // Reducimos la variable de cantidad de partidas a jugar por el usuario.
        partida_actual ++;                                                              // Incrementamos las particas actuales que el usuario complete.
    }
    printf ("\n");
    system ("pause");                                                                   // El system "pause", es para no cerrar automaticamente el juego y poder leer lo jugado.
    return 0;
}



