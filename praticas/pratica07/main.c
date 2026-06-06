#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = pilha_criar();

    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    pilha_empilhar(p, 40);

    printf("Pilha: ");
    pilha_exibir(p);

    printf("Topo: %d\n", pilha_topo(p));

    printf("Desempilhando: %d\n", pilha_desempilhar(p));
    printf("Desempilhando: %d\n", pilha_desempilhar(p));

    printf("Pilha apos desempilhar: ");
    pilha_exibir(p);

    printf("Pilha vazia? %s\n", pilha_esta_vazia(p) ? "Sim" : "Nao");

    pilha_destruir(p);

    return 0;
}