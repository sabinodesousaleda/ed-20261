#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100

// Copiar vetor
void copia_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int v[TAM], v1[TAM], v2[TAM], v3[TAM];

    srand(time(NULL));

    // Gerar números aleatórios
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    clock_t inicio, fim;

    // Bubble Sort
    copia_vetor(v, v1, TAM);
    inicio = clock();
    bubble_sort(v1, TAM);
    fim = clock();
    printf("Bubble Sort: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Selection Sort
    copia_vetor(v, v2, TAM);
    inicio = clock();
    selection_sort(v2, TAM);
    fim = clock();
    printf("Selection Sort: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Quick Sort
    copia_vetor(v, v3, TAM);
    inicio = clock();
    quick_sort(v3, 0, TAM - 1);
    fim = clock();
    printf("Quick Sort: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}