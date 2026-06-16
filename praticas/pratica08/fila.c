#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

struct fila_t {
    No* inicio;
    No* fim;
};

Fila* fila_criar() {
    Fila* f = (Fila*) malloc(sizeof(Fila));

    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }

    return f;
}

int fila_esta_vazia(Fila* f) {
    return f->inicio == NULL;
}

void fila_enfileirar(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
}

int fila_desenfileirar(Fila* f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return -1;
    }

    No* temp = f->inicio;
    int valor = temp->valor;

    f->inicio = temp->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);

    return valor;
}

int fila_inicio(Fila* f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return -1;
    }

    return f->inicio->valor;
}

void fila_exibir(Fila* f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    No* atual = f->inicio;

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void fila_destruir(Fila* f) {
    while (!fila_esta_vazia(f)) {
        fila_desenfileirar(f);
    }

    free(f);
}