#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash* hash = hash_criar(10);

    hash_inserir(hash, 15);
    hash_inserir(hash, 25);
    hash_inserir(hash, 35);
    hash_inserir(hash, 42);
    hash_inserir(hash, 52);

    printf("Tabela Hash:\n");
    hash_exibir(hash);

    printf("\nBuscar 25: %s\n",
           hash_buscar(hash, 25) ? "Encontrado" : "Nao encontrado");

    printf("Buscar 99: %s\n",
           hash_buscar(hash, 99) ? "Encontrado" : "Nao encontrado");

    printf("\nRemovendo 25...\n");
    hash_remover(hash, 25);

    printf("\nTabela apos remocao:\n");
    hash_exibir(hash);

    printf("\nHash vazia? %s\n",
           hash_esta_vazia(hash) ? "Sim" : "Nao");

    hash_destruir(hash);

    return 0;
}