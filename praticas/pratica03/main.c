#include <stdio.h>
#include "conta.h"

int main() {
    Conta* c1 = conta_criar(123);

    conta_depositar(c1, 500);
    conta_sacar(c1, 200);

    printf("Saldo atual: %.2f\n", conta_ver_saldo(c1));

    conta_destruir(c1);

    return 0;
}
