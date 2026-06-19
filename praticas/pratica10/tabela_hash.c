#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct hash_t {
    no_t** tabela;
    int tamanho;
};

static int funcao_hash(TabelaHash* hash, int valor) {
    return valor % hash->tamanho;
}

TabelaHash* hash_criar(int tamanho) {
    TabelaHash* hash = malloc(sizeof(TabelaHash));

    hash->tamanho = tamanho;
    hash->tabela = calloc(tamanho, sizeof(no_t*));

    return hash;
}

void hash_inserir(TabelaHash* hash, int valor) {
    int indice = funcao_hash(hash, valor);

    no_t* novo = malloc(sizeof(no_t));
    novo->valor = valor;
    novo->proximo = hash->tabela[indice];

    hash->tabela[indice] = novo;
}

int hash_buscar(TabelaHash* hash, int valor) {
    int indice = funcao_hash(hash, valor);

    no_t* atual = hash->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor)
            return 1;

        atual = atual->proximo;
    }

    return 0;
}

void hash_remover(TabelaHash* hash, int valor) {
    int indice = funcao_hash(hash, valor);

    no_t* atual = hash->tabela[indice];
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL)
                hash->tabela[indice] = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }
}

void hash_exibir(TabelaHash* hash) {
    int i;

    for (i = 0; i < hash->tamanho; i++) {
        printf("[%d]: ", i);

        no_t* atual = hash->tabela[i];

        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }

        printf("NULL\n");
    }
}

int hash_esta_vazia(TabelaHash* hash) {
    int i;

    for (i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL)
            return 0;
    }

    return 1;
}

void hash_destruir(TabelaHash* hash) {
    int i;

    for (i = 0; i < hash->tamanho; i++) {
        no_t* atual = hash->tabela[i];

        while (atual != NULL) {
            no_t* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}