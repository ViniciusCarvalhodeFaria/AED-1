#include <string.h>
#include <stdio.h>

int main(){
    char S[101];
    int T, total;
    int segmentos[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    scanf("%d\n", &T);

    for(int i = 0; i < T; ++i){
        scanf("%s", &S);

        total = 0;
        for(int j = 0; j < strlen(S); ++j){
            total += segmentos[S[j] - '0'];
        }

        printf("%d leds\n", total);
    }

    return 0;
}
