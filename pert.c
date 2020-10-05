#include <stdlib.h>
#include <stdio.h>
#include "pert.h"

// forca a saida do programa em caso de erro
static void crash(const char* msg){
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

//printa os nos adjacentes da tarefa t
void pert_print_adjacentes(pert_t* p, int t){
    node_t *cursor = p->g->lista[t];
    while (cursor != NULL) {
        printf("%d, ", cursor->n + 1);
        cursor = cursor->next;
    }
}

// printa um tabela representando o pert em stdout
void print_pert(pert_t* p) {
    printf("Numero de tarefas: %d\n\n", p->n_tarefas);
    printf("%-5s| %-50s| %s", "Num", "Descricao", "Adjacentes(teste)\n");
    for (int i = 0; i < p->n_tarefas; ++i) {
        printf("%-5d| %-50s| ", i+1, p->descricoes[i]);
        pert_print_adjacentes(p, i);
        printf("\n");
    }
}

// cria um diagrama pert usando um grafo a partir do arquivo fname
pert_t * criar_pert(const char* fname){
    FILE * fp;
    pert_t * pert;
    int n_tarefas;
    int n_pares;
    int x, y;

    fp = fopen(fname, "r");
    if (fp == NULL ) crash("Erro ao ler o arquivo de entrada em criar_pert()");

    fscanf(fp, "%d\n", &n_tarefas);

    //aloca memoria para a struct pert
    pert = malloc(sizeof(pert));
    if (pert == NULL) 
        crash("Erro ao alocar memoria para o struct pert em criar_pert()");
    pert->n_tarefas = n_tarefas;

    // Aloca memoria para as descricoes
    pert->descricoes = malloc(n_tarefas * sizeof(char *));
    if (pert->descricoes == NULL) 
        crash("Erro ao alocar memoria para as descricoes do pert em criar_pert()");
    for (int i = 0; i < n_tarefas; i++ ){
        pert->descricoes[i] = malloc(51 * sizeof(char));
        if (pert->descricoes[i] == NULL)
            crash("Erro ao alocar memoria para as descricoes do pert em criar_pert()");
    }

    // aloca memoria para o grafo de tarefas
    pert->g = grafo_init(n_tarefas);

    //inicializa tarefas usando o arquivo fname
    for (int i = 0; i < n_tarefas; i++){
        fscanf(fp, "%s\n", pert->descricoes[i]);
    }
    fscanf(fp, "%d\n", &n_pares);
    pert->n_pares = n_pares;
    for (int i = 0; i < n_pares; i++){
        fscanf(fp, "%d %d\n", &x, &y);
        if (!grafo_existe_caminho(pert->g, y-1, x-1)){
            if (!existe_aresta(pert->g, x-1, y-1))
                insere_aresta(pert->g, x-1, y-1);
            else
                printf("Aviso: Tarefas (%d, %d) ja foram inseridas! ignorando..\n", x, y);
        }
        else
            printf("Aviso: Tarefas (%d, %d) formam ciclo e nao serao incluidas!\n", x, y);
        
    }
    fclose(fp);

    return pert;
}


// deleta um struct pert
pert_t* deletar_pert(pert_t * p){

    for (int i = 0; i < p->n_tarefas; i++){
        free(p->descricoes[i]);
    }
    free(p->descricoes);
    p->g = deletar_grafo(p->g);
    free(p);

    return NULL;
}
