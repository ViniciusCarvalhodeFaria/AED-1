#include <stdio.h>

int main() {
    int number, hours;
    double value_per_hour, salary;

    // Lê o número do funcionário, as horas trabalhadas e o valor por hora
    scanf("%d %d %lf", &number, &hours, &value_per_hour);

    // Calcula o salário
    salary = hours * value_per_hour;

    // Exibe o número do funcionário e o salário com 2 casas decimais
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2lf\n", salary);

    return 0;
}
