#include <stdio.h>
#include "fila.h"

int main() {
    Fila* f = fila_criar();

    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);

    printf("Fila: ");
    fila_exibir(f);

    printf("Inicio: %d\n", fila_inicio(f));

    printf("Desenfileirando: %d\n", fila_desenfileirar(f));
    printf("Desenfileirando: %d\n", fila_desenfileirar(f));

    printf("Fila apos desenfileirar: ");
    fila_exibir(f);

    printf("Fila vazia? %s\n",
           fila_esta_vazia(f) ? "Sim" : "Nao");

    fila_destruir(f);

    return 0;
}