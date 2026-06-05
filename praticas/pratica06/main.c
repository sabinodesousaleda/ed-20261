#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista* l = lista_criar();

    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    lista_inserir(l, 40);

    printf("Lista: ");
    lista_exibir(l);

    lista_remover(l, 20);
    printf("Apos remover 20: ");
    lista_exibir(l);

    int pos = lista_buscar(l, 30);
    if (pos != -1)
        printf("Valor 30 encontrado na posicao %d\n", pos);
    else
        printf("Valor 30 nao encontrado\n");

    printf("Lista vazia? %s\n", lista_esta_vazia(l) ? "Sim" : "Nao");

    lista_destruir(l);

    return 0;
}