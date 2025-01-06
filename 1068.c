#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char expressao[100];
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strlen(expressao) - 1] = '\0';  // Corrigido para usar '\0' ao invés de NULL
    int t = strlen(expressao);
    int cont = 0;
    int indice = 1;

    for (int x = 0; x < t; x++) {  // Corrigida a condição do loop
        if (expressao[x] == '(') {
            cont++;
        } 
        else if (expressao[x] == ')') {
            if (cont > 0) {
                cont--;
            } else {
                indice = 0;
                break;
            }
        }
    }

    if (indice == 0 || cont != 0) {
        printf("incorrect\n");
    } else {
        printf("correct\n");
    }

    return 0;
}
