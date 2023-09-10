# define long_max 25;

    typedef struct nodo {                                         // typedef me permite poder crear un alias de referencia a la structura
        char *dato;                                              // char dato, armo un puntero a un char llamado dato
        struct nodo * h_izq , * h_der ;                           // son mis punteros que voy a utilizar
}arbol;                                                           // es el alias del arbol que usaré como referencia hacia él

  void inserta (arbol** , char*);

  int es_miembro (arbol* , char*);

  int suprime_minimo (arbol**);

  void suprime (arbol** , char );

  void listar_preorden (arbol*);

  void listar_inorden (arbol*);

  void listar_posorden (arbol*);

