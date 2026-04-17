#include "ordenacao.h"

// BUBBLE SORT
void bubble_sort(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// SELECTION SORT
void selection_sort(int v[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

// QUICK SORT
void quick_sort(int v[], int inicio, int fim) {
    int i = inicio, j = fim;
    int pivo = v[(inicio + fim) / 2];
    int temp;

    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;

        if (i <= j) {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (inicio < j)
        quick_sort(v, inicio, j);
    if (i < fim)
        quick_sort(v, i, fim);
}