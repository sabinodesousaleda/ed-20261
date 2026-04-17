#include <stdio.h>

// Fatorial com repetição
int fatorial_iterativo(int n) {
    int i, resultado = 1;
    for(i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Fatorial com recursividade
int fatorial_recursivo(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * fatorial_recursivo(n - 1);
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Fatorial (iterativo): %d\n", fatorial_iterativo(n));
    printf("Fatorial (recursivo): %d\n", fatorial_recursivo(n));

    // Complexidade:
    // Iterativo: O(n)
    // Recursivo: O(n)

    return 0;
}