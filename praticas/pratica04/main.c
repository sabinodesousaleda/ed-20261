#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100

void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int v[TAM], v1[TAM], v2[TAM], v3[TAM];
    clock_t inicio, fim;

    // gerar números aleatórios
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    // copiar vetor
    copiar_vetor(v, v1, TAM);
    copiar_vetor(v, v2, TAM);
    copiar_vetor(v, v3, TAM);

    // BUBBLE
    inicio = clock();
    bubble_sort(v1, TAM);
    fim = clock();
    printf("Tempo Bubble Sort: %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // SELECTION
    inicio = clock();
    selection_sort(v2, TAM);
    fim = clock();
    printf("Tempo Selection Sort: %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // QUICK
    inicio = clock();
    quick_sort(v3, 0, TAM - 1);
    fim = clock();
    printf("Tempo Quick Sort: %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}