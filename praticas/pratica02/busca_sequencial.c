#include <stdio.h>

int main() {
    int vetor[100], valor, i, encontrado = -1;

    // Preenche o vetor
    for(i = 0; i < 100; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    // Busca sequencial
    for(i = 0; i < 100; i++) {
        if(vetor[i] == valor) {
            encontrado = i;
            break;
        }
    }

    if(encontrado != -1)
        printf("Valor encontrado na posicao %d\n", encontrado);
    else
        printf("Valor nao encontrado\n");

    // Complexidade:
    // Melhor caso: O(1) - elemento na primeira posicao
    // Pior caso:   O(n) - elemento na ultima posicao ou nao encontrado

    return 0;
}
