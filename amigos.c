#include <stdio.h>
#include <string.h>
struct cel{
    char amigo[15];
    struct cel *seg;
};
typedef struct cel celula;

void insere(char amigo[], celula *p, int tamanho){
    char y[15]
    célula *nova;
    nova = malloc (sizeof (célula));
    for (int i=0;x<tamanho;x++)
        nova
nova->seg = p->seg;
p->seg = nova;
}
    
int main(){
    struct cel amigo;
    gets(amigo.cel);
    int tamanho = strlen(amigo.cel);
    
    
}







void Imprima (célula *lst) {
célula *p;
for (p = lst; p != NULL; p = p->seg)
printf ("%d\n", p->conteúdo);
}
