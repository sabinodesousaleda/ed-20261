#include <stdio.h>

int main() {
    int valor;

    printf("Digite o valor do saque: ");
    scanf("%d", &valor);

    if(valor > 1000) {
        printf("Valor maximo permitido eh 1000\n");
        return 0;
    }

    int notas200 = valor / 200;
    valor %= 200;

    int notas100 = valor / 100;
    valor %= 100;

    int notas50 = valor / 50;
    valor %= 50;

    int notas20 = valor / 20;
    valor %= 20;

    int notas10 = valor / 10;
    valor %= 10;

    int notas5 = valor / 5;
    valor %= 5;

    int notas2 = valor / 2;

    printf("Notas de 200: %d\n", notas200);
    printf("Notas de 100: %d\n", notas100);
    printf("Notas de 50: %d\n", notas50);
    printf("Notas de 20: %d\n", notas20);
    printf("Notas de 10: %d\n", notas10);
    printf("Notas de 5: %d\n", notas5);
    printf("Notas de 2: %d\n", notas2);

    return 0;
}