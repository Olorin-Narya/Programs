#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//conta  numero de arestas a partir do numero de relacionamento enviado no arquivo txt 3 coluna
void criaMatrizUm(int **matrizUm, int *tamanhoUm,int *numArestaUm){
    int i, j, origem, destino, relacionamento, verticesUm;
    *numArestaUm=0;
    FILE *p=fopen("oi1.txt", "r+");
    printf("Digite a quantidade de vértices:  ");
    scanf("%i",&verticesUm);
    *tamanhoUm=verticesUm;
    printf("\n");
    matrizUm=(int**)malloc(*tamanhoUm * sizeof(int*));

    for(i=0;i<*tamanhoUm;i++){
        matrizUm[i]= (int*) malloc(*tamanhoUm*sizeof(int));                  //cria matriz de adjacencia
        for(j=0;j<*tamanhoUm;j++){
            matrizUm[i][j]=0;                                                //inicializa adjacencia
        }
    }
    while(fscanf(p, "%i %i %i", &origem, &destino, &relacionamento)!=EOF){      //mesmo que a anterior porem quando o grafo for direcionado
        matrizUm[origem-1][destino-1]= relacionamento;
        matrizUm[destino-1][origem-1]= relacionamento;
        *numArestaUm=(*numArestaUm)+(relacionamento);                           //conta numero de arestas para matriz incidencia
        printf("aresta: %i \n", *numArestaUm);
    }
    printf("\nNúmero de Arestas Matriz Um:%i \n \n", *numArestaUm);
    for(i=0;i<*tamanhoUm;i++){                                                  //percorre matriz e mostra
        for(j=0;j<*tamanhoUm;j++){
            if(matrizUm[i][j]!= -10){
                printf("%i ",matrizUm[i][j]);
            }
        }
        printf("\n");
    }
    fclose(p);
}

void criaMatrizDois(int **matrizDois, int *tamanhoDois,int *numArestaDois){
    int i, j, origem, destino, verticesDois, relacionamento;
    FILE *p=fopen("oi2.txt", "r");
    *numArestaDois=0;                                                           //Número de relacionamentos 3ª coluna
    printf("\nDigite a quantidade de vértices:  ");
    scanf("%i",&verticesDois);
    *tamanhoDois=verticesDois;
    printf("\n");

    matrizDois=(int**)malloc(*tamanhoDois * sizeof(int*));

    for(i=0;i<*tamanhoDois;i++){
        matrizDois[i]= (int*) malloc(*tamanhoDois*sizeof(int));              //cria matriz de adjacencia
        for(j=0;j<*tamanhoDois;j++){
            matrizDois[i][j]=0;                                              //inicializa adjacencia
        }
    }
    while(fscanf(p, "%i %i %i", &origem, &destino, &relacionamento)!=EOF){      //direcionado
        matrizDois[origem-1][destino-1]= relacionamento;
        matrizDois[destino-1][origem-1]= relacionamento;
        *numArestaDois=(*numArestaDois)+(relacionamento);                       //para matriz incidencia
        printf("aresta: %i \n", *numArestaDois);
    }
    printf("\nNúmero de Arestas Matriz Dois:%i \n \n", *numArestaDois);
    for(i=0;i<*tamanhoDois;i++){                                                //percorre matriz e mostra
        for(j=0;j<*tamanhoDois;j++){
            if(matrizDois[i][j]!= -10){
                printf("%i ",matrizDois[i][j]);
            }
        }
        printf("\n");
    }
    fclose(p);
}

//grava cada grau respectivamente com seu vertice num vetor
void GrauUm(int **matrizUm, int tamanhoUm, int *grauUm){
    int i, j, cont=0;
    printf("\nMatriz Um: \n");
    for(i=0;i<tamanhoUm;i++){
        for(j=0;j<tamanhoUm;j++){
            if (matrizUm[i][j]!=0){                                             //matriz é simetrica (nao direcionada) leio só uma linha
                cont+=matrizUm[i][j];
                grauUm[i]=cont;
            }
        }
        printf("O grau do nó %i eh: %i\n", i+1, cont);
        cont=0;
    }
    for(i=0;i<tamanhoUm;i++){
        printf(" %i | ", grauUm[i]);
    }
    printf("\n");
}

void GrauDois(int **matrizDois, int tamanhoDois, int *grauDois){
    int i, j, cont=0;
    printf("\nMatriz Dois: \n");
    for(i=0;i<tamanhoDois;i++){
        for(j=0;j<tamanhoDois;j++){
            if (matrizDois[i][j]!=0){                                           //matriz é simetrica (nao direcionada) leio só uma linha
                cont+=matrizDois[i][j];
                grauDois[i]=cont;
            }
        }
        printf("O grau do nó %i é: %i\n", i+1, cont);
        cont=0;
    }
    for(i=0;i<tamanhoDois;i++){
        printf(" %i | ", grauDois[i]);
    }
    printf("\n");
}

//compara vetores
//se forem todos iguais ao outros, isomorfo alem da condicao de vertices e arestas
void ComparaMatrizes(int *grauUm, int *grauDois, int tamanho){
    int visto[tamanho], i, j, combi = 0;
    for (i = 0; i < tamanho; i++) {
        visto[i] = 0;
    }
    for(i = 0; i < tamanho; i++) {
        for(j = 0; j < tamanho; j++) {
            if (!(visto[j])) {
                if (grauUm[i] == grauDois[j]) {
                    visto[j] = 1;
                    combi++;
                    break;                                                      //começo o for novamente...
                }
            }
        }
    }
    if (combi == tamanho) {
        printf("São isomorfos!\n");
    }
    else {
        printf("Nao são isomorfos!\n");
    }
}

int main()
{
    setlocale(LC_ALL,"");
    int **matrizUm=NULL, **matrizDois=NULL;
    int tamanhoUm, tamanhoDois, numArestaUm, numArestaDois;

    criaMatrizUm(matrizUm, &tamanhoUm, &numArestaUm);
    criaMatrizDois(matrizDois, &tamanhoDois, &numArestaDois);

    if ((tamanhoUm == tamanhoDois) && (numArestaUm == numArestaDois)) {
        int grauUm[tamanhoUm], grauDois[tamanhoUm];

        GrauUm(matrizUm, tamanhoUm, grauUm);
        GrauDois(matrizDois, tamanhoUm, grauDois);

        ComparaMatrizes(grauUm, grauDois, tamanhoUm);
    }
    else {
        printf("Nao são isomorfos!\n");
    }
    return 0;
}
