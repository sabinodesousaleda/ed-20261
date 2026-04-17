#include <stdio.h>
#include <time.h>

int main() {
    int matriz[10][10];
    int i, j;

    // Preenchendo a matriz
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            matriz[i][j] = i + j;
        }
    }

    clock_t inicio, fim;

    // Método 1: dois laços
    inicio = clock();
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    fim = clock();
    printf("Tempo (2 loops): %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("\n");

    // Método 2: um laço
    inicio = clock();
    for(i = 0; i < 100; i++) {
        printf("%d ", matriz[i / 10][i % 10]);
        if((i + 1) % 10 == 0) printf("\n");
    }
    fim = clock();
    printf("Tempo (1 loop): %lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Complexidade:
    // Ambos: O(n²)

    return 0;
}