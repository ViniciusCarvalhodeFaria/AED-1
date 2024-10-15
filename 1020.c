#include <stdio.h>

int main() {
    int dias, ano, mes, dia;
    
    scanf("%i", &dias);
    
    ano = dias / 365;
    dias = dias % 365;
    mes = dias / 30;
    dia = dias % 30;
    
    printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n", ano, mes, dia);
    
    return 0;
}
