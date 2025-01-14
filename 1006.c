#include <stdio.h>

int main() {
    double A, B, C, MEDIA;

    // Lê os três números com ponto flutuante
    scanf("%lf %lf %lf", &A, &B, &C);

    // Calcula a média ponderada
    MEDIA = (A * 2.0 + B * 3.0 + C * 5.0) / 10.0;

    // Exibe o resultado com 1 casa decimal
    printf("MEDIA = %.1lf\n", MEDIA);

    return 0;
}
