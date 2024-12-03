#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t


int const TAM = 400000;

void merge(int p, int q, int r, int vet[]){
    int i, j,k;
    int *w;
    w = malloc ((r-p) * sizeof (int));
    i=p;
    j=q;
    k=0;
    while (i < q && j < r) {
     if (vet[i] <= vet[j]) w[k++] = vet[i++];
     else w[k++] = vet[j++];
    }
    while (i < q) 
     w[k++] = vet[i++];
    while (j < r) 
     w[k++] = vet[j++];
   for (i = p; i < r; i++){
     vet[i] = w[i-p];
   }
 free (w);
}

void mergeSort(int p, int r, int vet[]) {
    if (p < r - 1) {  
        int q = (p + r) / 2; 
        mergeSort(p, q, vet); 
        mergeSort(q, r, vet); 
        merge(p, q, r, vet);  
    }
}


int main (){
    int vet[TAM];
    srand((unsigned)time(NULL));
    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % TAM;
    }
    int n=TAM;
    int t = clock();
    mergeSort(0, n, vet);
    t = clock() - t;
    printf("Tempo de execucao: %lf s\n", ((double)t)/((CLOCKS_PER_SEC)));
    return 0;
}
