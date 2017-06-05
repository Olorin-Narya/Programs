#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int matriz[6][6],percorridos[6]; //G:adjacency matrix,x:colors

void color(int k){
    int i,j;
    percorridos[k]=1;  //coloring vertex with color1
    for(i=0;i<k;i++){ //checking all k-1 vertices-backtracking
        if(matriz[i][k]!=0 && percorridos[k]==percorridos[i])  //if connected and has same color
            percorridos[k]=percorridos[i]+1;  //assign higher color than x[i]
    }
}

int main(){
    int vertices,arestas,i,j,k, valor, cont=1;
    setlocale(LC_ALL,"");

    printf("Digite o número de vértices : \n");
    scanf("%d",&vertices);  //total vertices
    printf("Digite o número de arestas: \n");
    scanf("%d",&arestas);  //total edges

    for(i=0;i<vertices;i++) {
        for(j=0;j<vertices;j++) {
            matriz[i][j]=0;  //assign 0 to all index of adjacency matrix
        }
    }
    //valores da matriz
    printf("Digite os valores da matriz para cada posição (1 existe relação, 0 não existe): \n");
    for(i=0;i<(vertices);i++){ //percorre matriz e mostra
        for(j=0;j<(vertices);j++){
            scanf("%d",&valor);
            matriz[i][j]=valor;
            //printf("posicao %i %i : %d \n", i, j, matriz[i][j]);
        }
    }
    for(i=0;i<(vertices);i++){ //percorre matriz e mostra
        for(j=0;j<(vertices);j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<vertices;i++){
        color(i);  //coloring each vertex
    }
    printf("Cor dos vértices: \n");
    for(i=0;i<vertices;i++){  //displaying color of each vertex
        //printf("Vertice[%d] : %d\n",i+1,percorridos[i]);
        if(percorridos[i]>cont){
            cont++;
        }
    }
    printf("Qtd cores: %i", cont);
    return 0;
}
