#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} No;

struct lista_t {
    No* primeiro;
    No* ultimo;
};

Lista* lista_criar() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

int lista_esta_vazia(Lista* l) {
    return l->primeiro == NULL;
}

void lista_inserir(Lista* l, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;
    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
    l->ultimo = novo;
}

void lista_remover(Lista* l, int valor) {
    if (lista_esta_vazia(l)) return;
    No* atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual->anterior != NULL)
                atual->anterior->proximo = atual->proximo;
            else
                l->primeiro = atual->proximo;
            if (atual->proximo != NULL)
                atual->proximo->anterior = atual->anterior;
            else
                l->ultimo = atual->anterior;
            free(atual);
            return;
        }
        atual = atual->proximo;
    }
    printf("Valor %d nao encontrado.\n", valor);
}

int lista_buscar(Lista* l, int valor) {
    No* atual = l->primeiro;
    int pos = 0;
    while (atual != NULL) {
        if (atual->valor == valor)
            return pos;
        atual = atual->proximo;
        pos++;
    }
    return -1;
}

void lista_exibir(Lista* l) {
    if (lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    No* atual = l->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void lista_destruir(Lista* l) {
    No* atual = l->primeiro;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(l);
}