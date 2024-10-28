#include <stdio.h>

void sudoku(int n, int sdk[n][9][9]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                scanf("%d", &sdk[i][j][k]);
            }
        }
    }
}

void zerarvisto(int v[]) {
    for (int j = 0; j < 10; j++) {
        v[j] = 0;
    }
}

int verif(int v[][9][9], int n) {
    for (int i = 0; i < n; i++) {
        int visto[10] = {0};
        int valido = 1;
        
        // Verificação das linhas
        for (int j = 0; j < 9 && valido; j++) {
            zerarvisto(visto);
            for (int k = 0; k < 9; k++) {
                if (v[i][j][k] < 1 || v[i][j][k] > 9 || visto[v[i][j][k]] == 1) {
                    printf("Instancia %d\n", i+1);
                    printf("NAO\n\n");
                    valido = 0;
                    break;
                }
                visto[v[i][j][k]] = 1;
            }
        }

        // Verificação das colunas
        for (int k = 0; k < 9 && valido; k++) {
            zerarvisto(visto);
            for (int j = 0; j < 9; j++) {
                if (v[i][j][k] < 1 || v[i][j][k] > 9 || visto[v[i][j][k]] == 1) {
                    printf("Instancia %d\n", i+1);
                    printf("NAO\n\n");
                    valido = 0;
                    break;
                }
                visto[v[i][j][k]] = 1;
            }
        }

        // Verificação dos blocos 3x3
        for (int l = 0; l < 9 && valido; l += 3) {
            for (int m = 0; m < 9; m += 3) {
                zerarvisto(visto);
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (v[i][l + j][m + k] < 1 || v[i][l + j][m + k] > 9 || visto[v[i][l + j][m + k]] == 1) {
                            printf("Instancia %d\n", i+1);
                            printf("NAO\n\n");
                            valido = 0;
                            break;
                        }
                        visto[v[i][l + j][m + k]] = 1;
                    }
                    if (!valido) break;
                }
                if (!valido) break;
            }
            if (!valido) break;
        }
        
        // Se passou em todas as verificações
        if (valido) {
            printf("Instancia %d\n", i+1);
            printf("SIM\n\n");
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int sdk[n][9][9];
    sudoku(n, sdk);

    verif(sdk, n);
