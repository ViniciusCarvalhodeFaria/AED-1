#include <stdio.h>
int main (){
    int n,multiplicacao;
    scanf("%i",&n);

    if (n<0 ||n>1000){
        return 0;
    }
    for (int i=1;i<=10;i++){
        multiplicacao= n*i;
        printf("%i x %i = %i\n", i,n,multiplicacao);
    }
}
