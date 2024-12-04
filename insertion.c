#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 50000;

void insertion(int n, int vet[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = vet[j];
        for (i = j - 1; i >= 0 && vet[i] > x; i--) {
            vet[i + 1] = vet[i];
        }
        vet[i + 1] = x;
    }
}

int main() {
    int vet[TAM];
    int n = TAM;

    srand((unsigned)time(NULL));
    for (int i = 0; i < TAM; i++) {
        vet[i] = rand() % TAM;
    }

    clock_t t = clock();
    insertion(n, vet);
    t = clock() - t;

    printf("Tempo de execucao: %lf s\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}
