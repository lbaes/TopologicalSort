#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lucas Franchini Baes */
#include "grafo.h"
#include "pert.h"

int main(int argc, char const *argv[]) {

    /*
    node_t *head;
    for (int i = 0; i < 100; i++) {
        head = insert_at_head(head, i);
    }
    printf("List:\n");
    print_list(head);
    printf("List size: %d\n", list_size(head));
    head = remove_node(head, find_node(head, 0));
    printf("List:\n");
    print_list(head);
    head = delete_list(head);
    */

    /*
    grafo_t *g, *g2;
    g = grafo_init(6);
    insere_aresta(g, 0, 1);
    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 4);
    insere_aresta(g, 3, 0);
    insere_aresta(g, 3, 4);
    insere_aresta(g, 4, 5);

    printf("Grafo 1:\n");
    print_grafo(g);
    grafo_caminho(g, 0);
    g = deletar_grafo(g);

    g2 = grafo_init_arquivo("entrada.txt");
    printf("Grafo 2: \n");
    print_grafo(g2);
    grafo_caminho(g2, 0);
    int s = 1;
    int t = 5;
    if (grafo_existe_caminho(g2, s, t))
        printf("Existe caminho entre s=%d e t=%d\n", s, t);
    else
        printf("Nao existe caminho entre s=%d e t=%d\n", s, t);
    g2 = deletar_grafo(g2);

    */
    pert_t * p; 
    if (argc < 2)
        p = criar_pert("pert.txt");
    else 
        p = criar_pert(argv[1]);
    print_pert(p);

    printf("\nOrdem topologica: ");
    grafo_toposort(p->g);
    p = deletar_pert(p);
    return 0;
    
}
