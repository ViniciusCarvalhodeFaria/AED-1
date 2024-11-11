#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

typedef struct cel {
    char conteudo[TAM_MAX];
    struct cel *prox;
} celula;

// Função para inserir um novo amigo no final da lista
void insere_final(celula *head, char nome[]) {
    celula *nova = (celula *)malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    strncpy(nova->conteudo, nome, TAM_MAX - 1);
    nova->conteudo[TAM_MAX - 1] = '\0';
    nova->prox = NULL;

    celula *p = head;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = nova;
}

// Função para inserir os novos amigos antes de um amigo indicado
int insere_antes(celula *head, char novos_amigos[], char indicado[]) {
    celula *p = head;
    celula *anterior = NULL;

    // Procura o amigo indicado na lista
    while (p != NULL && strcmp(p->conteudo, indicado) != 0) {
        anterior = p;
        p = p->prox;
    }

    // Se o amigo indicado não for encontrado
    if (p == NULL) return 0;

    // Adiciona cada novo amigo antes do indicado
    char *nome = strtok(novos_amigos, " ");
    while (nome != NULL) {
        celula *nova = (celula *)malloc(sizeof(celula));
        if (nova == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }

        strncpy(nova->conteudo, nome, TAM_MAX - 1);
        nova->conteudo[TAM_MAX - 1] = '\0';
        nova->prox = p;

        if (anterior != NULL) {
            anterior->prox = nova;
        } else {
            head->prox = nova;
        }

        anterior = nova;
        nome = strtok(NULL, " ");
    }

    return 1;
}

// Função para imprimir a lista de amigos sem espaço extra no final
void Imprima(celula *head) {
    celula *p = head->prox;
    while (p != NULL) {
        printf("%s", p->conteudo);
        if (p->prox != NULL) {
            printf(" "); // Adiciona espaço apenas entre os elementos
        }
        p = p->prox;
    }
    printf("\n");
}

// Função principal
int main() {
    celula *head = (celula *)malloc(sizeof(celula));
    if (head == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    head->prox = NULL;

    char lista_atual[TAM_MAX], novos_amigos[TAM_MAX], indicado[TAM_MAX];

    // Entrada da lista atual de amigos
    fgets(lista_atual, sizeof(lista_atual), stdin);
    lista_atual[strcspn(lista_atual, "\n")] = '\0';

    // Adiciona os amigos da lista atual na estrutura
    char *nome = strtok(lista_atual, " ");
    while (nome != NULL) {
        insere_final(head, nome);
        nome = strtok(NULL, " ");
    }

    // Entrada dos novos amigos
    fgets(novos_amigos, sizeof(novos_amigos), stdin);
    novos_amigos[strcspn(novos_amigos, "\n")] = '\0';

    // Entrada do amigo indicado
    fgets(indicado, sizeof(indicado), stdin);
    indicado[strcspn(indicado, "\n")] = '\0';

    // Verifica se deve inserir antes de um amigo indicado ou no final
    if (strcmp(indicado, "nao") == 0) {
        // Adiciona no final
        nome = strtok(novos_amigos, " ");
        while (nome != NULL) {
            insere_final(head, nome);
            nome = strtok(NULL, " ");
        }
    } else {
        // Tenta inserir antes do amigo indicado
        if (!insere_antes(head, novos_amigos, indicado)) {
            // Amigo indicado não encontrado, adiciona no final
            nome = strtok(novos_amigos, " ");
            while (nome != NULL) {
                insere_final(head, nome);
                nome = strtok(NULL, " ");
            }
        }
    }

    // Imprime a lista final de amigos
    Imprima(head);

    // Libera memória alocada
    celula *p = head;
    while (p != NULL) {
        celula *temp = p;
        p = p->prox;
        free(temp);
    }

    return 0;
}
