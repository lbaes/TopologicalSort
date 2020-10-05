/* Lucas Franchini Baes */
#ifndef GRAFO_H
#define GRAFO_H
#include "linked_list.h"

// grafo com lista de adjacencias
typedef struct grafo {
    node_t** lista;
    int v;
    int a;
} grafo_t;

grafo_t* grafo_init(int nv);
void insere_aresta(grafo_t* g, int v, int w);
void remove_aresta(grafo_t* g, int v, int w);
void print_grafo(grafo_t* grafo);
grafo_t* deletar_grafo(grafo_t* g);
void grafo_caminho(grafo_t* g, int s);
grafo_t* grafo_init_arquivo(const char* fname);
int grafo_existe_caminho(grafo_t *g, int s, int t);
int existe_aresta(grafo_t *g, int v, int w);
void grafo_toposort(grafo_t* g);

#endif