#include <stdio.h>
#include <stdlib.h>

int quick(int p, int r, int vet[]) {
    int c, j, k, t;
    c = vet[r];
    j = p;
    for (k = p; k < r; k++) {
        if (vet[k] <= c) {
            t = vet[j];
            vet[j] = vet[k];
            vet[k] = t;
            j++;
        }
    }
    vet[r] = vet[j];
    vet[j] = c;
    return j;
}

void Quicksort(int p, int r, int vet[]) {
    if (p < r) {
        int j = quick(p, r, vet);
        Quicksort(p, j - 1, vet);
        Quicksort(j + 1, r, vet);
    }
}

int main() {
    int N, Q, caseNumber = 1;

    while (1) {
        // Leitura do tamanho dos vetores
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0)
            break;

        // Alocação dinâmica para os vetores
        int *vet = (int *)malloc(N * sizeof(int));
        int *busca = (int *)malloc(Q * sizeof(int));

        // Entrada do vetor principal
        for (int x = 0; x < N; x++) {
            scanf("%d", &vet[x]);
        }

        // Ordenação do vetor principal
        Quicksort(0, N - 1, vet);

        // Entrada dos valores de busca
        for (int x = 0; x < Q; x++) {
            scanf("%d", &busca[x]);
        }

        // Saída com o número do caso
        printf("CASE# %d:\n", caseNumber);

        // Busca dos elementos
        for (int i = 0; i < Q; i++) {
            int p = busca[i];
            int found = 0;

            for (int j = 0; j < N; j++) {
                if (vet[j] == p) {
                    printf("%d found at %d\n", p, j + 1);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("%d not found\n", p);
            }
        }

        // Liberação da memória alocada
        free(vet);
        free(busca);

        caseNumber++;
    }

    return 0;
}
