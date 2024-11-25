#include <stdio.h>
#include <string.h>
void ordenarnomes(char palavra[][100], int n) {
    char tempo[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) { // Bubble Sort para ordenar
            if (strcmp(palavra[j], palavra[j + 1]) > 0) {
                // Troca os nomes
                strcpy(tempo, palavra[j]);
                strcpy(palavra[j], palavra[j + 1]);
                strcpy(palavra[j + 1], tempo);
            }
        }
    }
}

int main() {
    char palavra[100][100];
    int n, k;

    scanf("%i", &n);
    scanf("%i", &k);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(palavra[i], 100, stdin);
        palavra[i][strcspn(palavra[i], "\n")] = '\0'; 
    }

    ordenarnomes(palavra, n);
    if (k < 1 || k > n) {
        printf("erro");
        return 1;
    }

    printf("%s\n", palavra[k - 1]);

    return 0;
}
