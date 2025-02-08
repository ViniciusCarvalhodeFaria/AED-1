#include <stdio.h>
#include <stdlib.h>
typedef char vertex;

typedef struct graph{
    int V;
    int A;
    int **adj;
}*Graph;

Graph initGraph (int v){
    Graph G = malloc (sizeof(*G));
    G->V = v;
    G->A=0;
    G->adj = malloc (v * sizeof(int *));
    for (int i=0; i<v; i++){
        G->adj[i]= calloc(v, sizeof(int));
    }
    return G;
}

void insertArc(Graph G, vertex v, vertex w){
    int index_v, index_w;
    index_v = v - 'a';
    index_w = w - 'a';

    G->A++;
    G->adj[index_v][index_w]= 1;
    G->adj[index_w][index_v]=1;
}

typedef struct union_find{
    int V;
    int componentes;
    int *diretor;
}*UnionFind;

UnionFind initUnionfind(int V){
    UnionFind UF = malloc(sizeof(*UF));
    UF->V = V;
    UF->componentes = V;
    UF->diretor = malloc( V * sizeof(*UF));
    for (int v =0; v<V; v++){
        UF->diretor[v]= v;
    }
    return UF;
}

int Find(UnionFind UF, int v){
    return UF->diretor[v];
}

void Union (UnionFind UF, int r, int s){
    for (int v=0;v<UF->V;v++){
        if(UF->diretor[v] == r){
            UF ->diretor[v] = s;
        }
    }
}

UnionFind Componentes(Graph G){
    int v, w, r, s;
    UnionFind UF = initUnionFind (G->V);

    for (v=0; v< G->V; v++){
        for(w=0;w<G->V;w++){
            if(G->adj[v][w]==1){
                r= Find(UF, v);
                s= Find(UF, w);
                if (r != s){
                    Union (UF, r, s);
                    UF->componentes--;
                }
            }
        }
    }
    return UF;
}

void printComponentes(UnionFind UF) {
    int V = UF->V;
    int *printed = calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        int lider = Find(UF, i);
        if (!printed[lider]) {
            for (int j = 0; j < V; j++) {
                if (Find(UF, j) == lider) {
                    printf("%c,", j + 'a');
                }
            }
            printf("\n");
            printed[lider] = 1;
        }
    }

    free(printed);
}

int main (){
    Graph G;
    UnionFind UF;
    int n, a, N, V, A;
    vertex v, w;

    scanf("%d", &N);

    for (n = 1; n<=N; n++){
        scanf("%d %d", &V, &A);
        G = initGraph(V);

        for (a=0; a<A; a++){
            getchar();
            scanf("%c %c", &v, &w);

            insertArc (G,v,w); 
        }

        UF = Componentes (G);

        printf("case #%d:\n", n);
        printComponentes(UF);
        printf("%d connected components\n\n", UF->componentes);
    }
}
