#include "grafo.h"

typedef struct pert {
    int n_tarefas;
    int n_pares;
    char** descricoes;
    grafo_t* g;
} pert_t;

pert_t* criar_pert(const char* fname);
pert_t* deletar_pert(pert_t * p);
void print_pert(pert_t* p);
void pert_print_requisitos(pert_t* p, int t);
