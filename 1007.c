#include <stdio.h>

int main() {
    int A, B, C, D, DIFERENCA;

    // Lê os quatro números inteiros
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // Calcula a diferença entre os produtos
    DIFERENCA = (A * B) - (C * D);

    // Exibe o resultado
    printf("DIFERENCA = %d\n", DIFERENCA);

    return 0;
}
