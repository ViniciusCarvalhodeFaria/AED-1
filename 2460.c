#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *prox; // Ponteiro para o próximo nó
} typedef celula;

// Adiciona um novo elemento ao final da lista
void nova(celula *head, int c) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = c;
    nova->prox = NULL;

    if (head->prox == NULL) {
        head->prox = nova;
    } else {
        celula *p = head->prox;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = nova;
    }
}

// Adiciona vários elementos à lista
void incluir(int vet[], celula *head, int N) {
    for (int x = 0; x < N; x++) {
        nova(head, vet[x]);
    }
}

// Busca e remove o elemento com valor M
void busca_e_remove(celula *head, int M) {
    celula *p = head->prox;
    celula *t = head;

    // Percorre a lista até encontrar o elemento ou o final
    while (p != NULL && p->conteudo != M) {
        t = p;
        p = p->prox;
    }

    // Se o elemento foi encontrado, remove-o
    if (p != NULL) {
        t->prox = p->prox;
        free(p);
    }
}

// Busca e remove múltiplos elementos
void busca(celula *head, int saidas[], int S) {
    for (int x = 0; x < S; x++) {
        busca_e_remove(head, saidas[x]);
    }
}

// Imprime a lista encadeada
void imprimir_lista(celula *head) {
    celula *p = head->prox;
    printf("Lista: ");
    while (p != NULL) {
        printf("%d ", p->conteudo);
        p = p->prox;
    }
    printf("\n");
}

// Libera a memória alocada para a lista
void liberar_lista(celula *head) {
    celula *p = head;
    while (p != NULL) {
        celula *temp = p;
        p = p->prox;
        free(temp);
    }
}

int main() {
    celula *head;
    head = malloc(sizeof(celula));
    head->prox = NULL;

    int N;
    scanf("%i", &N);
    int vet[N];
    for (int x = 0; x < N; x++) {
        scanf("%i", &vet[x]);
    }
    incluir(vet, head, N);

    int S;
    scanf("%i", &S);
    int saidas[S];
    for (int x = 0; x < S; x++) {
        scanf("%i", &saidas[x]);
    }

    busca(head, saidas, S);

    imprimir_lista(head);

    liberar_lista(head);

    return 0;
}
