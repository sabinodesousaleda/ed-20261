#include <stdio.h>

int main() {
    int n;
    float soma = 0, valor;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    if(n > 100) {
        printf("Valor maximo permitido eh 100\n");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i+1);
        scanf("%f", &valor);
        soma += valor;
    }

    printf("Media: %.2f\n", soma / n);

    return 0;
}