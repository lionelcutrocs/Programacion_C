# define long_max 25;

    typedef struct nodo {
        int *dato ;
        struct nodo * h_izq , * h_der ;
}arbol;

  void inserta (arbol** , int);

  int es_miembro (arbol* , int);

  int suprime_minimo (arbol**);

  void suprime (arbol** , int );

  

  void listar_preorden (arbol*);

  void listar_inorden (arbol*);

  void listar_posorden (arbol*);

