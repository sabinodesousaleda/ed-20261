#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    struct no_t* esquerda;
    int valor;
    struct no_t* direita;
} No;

struct arvore_t {
    No* raiz;
};

static No* inserir_no(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));

        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
        }

        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir_no(raiz->direita, valor);
    }

    return raiz;
}

static void exibir_pre_ordem_no(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        exibir_pre_ordem_no(raiz->esquerda);
        exibir_pre_ordem_no(raiz->direita);
    }
}

static void exibir_em_ordem_no(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem_no(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em_ordem_no(raiz->direita);
    }
}

static void exibir_pos_ordem_no(No* raiz) {
    if (raiz != NULL) {
        exibir_pos_ordem_no(raiz->esquerda);
        exibir_pos_ordem_no(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

static void destruir_no(No* raiz) {
    if (raiz != NULL) {
        destruir_no(raiz->esquerda);
        destruir_no(raiz->direita);
        free(raiz);
    }
}

Arvore* arvore_criar() {
    Arvore* a = (Arvore*) malloc(sizeof(Arvore));

    if (a != NULL) {
        a->raiz = NULL;
    }

    return a;
}

int arvore_esta_vazia(Arvore* a) {
    return a->raiz == NULL;
}

void arvore_inserir(Arvore* a, int valor) {
    a->raiz = inserir_no(a->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore* a) {
    exibir_pre_ordem_no(a->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore* a) {
    exibir_em_ordem_no(a->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore* a) {
    exibir_pos_ordem_no(a->raiz);
    printf("\n");
}

void arvore_destruir(Arvore* a) {
    destruir_no(a->raiz);
    free(a);
}