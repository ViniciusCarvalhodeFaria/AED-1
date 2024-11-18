#include <stdio.h>
#include <math.h>
int main(){
    float a, b,c,delta,R1,R2;
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    
    if (a==0){
        printf("Impossivel calcular\n");
        return 0;
    }
    delta=b*b-4*a*c;
    if (delta<0){
        printf("Impossivel calcular\n");
        return 0;
    }
    R1=(-b+sqrt(delta))/(2*a);
    R2=(-b-sqrt(delta))/(2*a);
    printf("R1 = %.5f\n",R1);
    printf("R2 = %.5f\n",R2);
}
