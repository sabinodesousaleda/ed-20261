#include "selecao.h"

// Busca linear
int linear_search(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}

// Função auxiliar (partição)
int particiona(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
    }

    int temp = v[i];
    v[i] = v[fim];
    v[fim] = temp;

    return i;
}

// Quick Select (k-ésimo menor elemento)
int quick_select(int v[], int inicio, int fim, int k) {
    if (inicio <= fim) {
        int p = particiona(v, inicio, fim);

        if (p == k)
            return v[p];
        else if (k < p)
            return quick_select(v, inicio, p - 1, k);
        else
            return quick_select(v, p + 1, fim, k);
    }
    return -1;
}