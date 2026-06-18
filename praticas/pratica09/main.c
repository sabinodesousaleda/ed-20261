#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore* a = arvore_criar();

    arvore_inserir(a, 50);
    arvore_inserir(a, 30);
    arvore_inserir(a, 70);
    arvore_inserir(a, 20);
    arvore_inserir(a, 40);
    arvore_inserir(a, 60);
    arvore_inserir(a, 80);

    printf("Pre-ordem: ");
    arvore_exibir_pre_ordem(a);

    printf("Em ordem: ");
    arvore_exibir_em_ordem(a);

    printf("Pos-ordem: ");
    arvore_exibir_pos_ordem(a);

    printf("Arvore vazia? %s\n",
           arvore_esta_vazia(a) ? "Sim" : "Nao");

    arvore_destruir(a);

    return 0;
}