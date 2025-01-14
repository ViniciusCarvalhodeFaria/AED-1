#include <stdio.h>

int main() {
    char nome[50];
    double salario_fixo, vendas, salario_total;

    // Lê o nome do vendedor, salário fixo e o total de vendas
    scanf("%s", nome);
    scanf("%lf %lf", &salario_fixo, &vendas);

    // Calcula o salário total com a comissão de 15% sobre as vendas
    salario_total = salario_fixo + (vendas * 0.15);

    // Exibe o salário total com 2 casas decimais
    printf("TOTAL = R$ %.2lf\n", salario_total);

    return 0;
}
