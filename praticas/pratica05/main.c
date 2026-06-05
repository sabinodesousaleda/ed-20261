#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

// Copiar vetor
void copia_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int v[TAM], v2[TAM];

    srand(time(NULL));

    // Gerar números aleatórios
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    int alvo = v[TAM / 2]; // valor para busca
    int k = TAM / 2;       // posição para quick select

    clock_t inicio, fim;

    // Linear Search
    inicio = clock();
    int pos = linear_search(v, TAM, alvo);
    fim = clock();
    printf("Linear Search: posicao=%d tempo=%lf segundos\n",
           pos, (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Quick Select
    copia_vetor(v, v2, TAM);
    inicio = clock();
    int valor = quick_select(v2, 0, TAM - 1, k);
    fim = clock();
    printf("Quick Select: valor=%d tempo=%lf segundos\n",
           valor, (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}