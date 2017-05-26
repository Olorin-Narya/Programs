#include <stdio.h>
#include <stdlib.h>

void criaMatriz(int ***matriz, int ***matrizModificada , int *tamanho,int *numAresta){
    int i, j, origem, destino, vertices,aresta=0;

    *numAresta=0;
    printf("Digite a quantidade de vertices:\n");
    scanf("%i",&vertices);
    *tamanho=vertices;

    FILE *p=fopen("oi.txt", "r"); //abre arquivo
    *matriz=(int**)malloc(*tamanho * sizeof(int*));
    *matrizModificada=(int**)malloc(*tamanho * sizeof(int*));

    for(i=0;i<*tamanho;i++){
        (*matriz)[i]= (int*) malloc(*tamanho*sizeof(int)); //cria matriz de adjacencia
        (*matrizModificada)[i]= (int*)malloc(*tamanho*sizeof(int)); //cria matriz de adjacencia
        for(j=0;j<*tamanho;j++){
            (*matriz)[i][j]=0;              //inicializa adjacencia
            (*matrizModificada)[i][j]=0; //inicializa adjacencia
        }
    }

    while(fscanf(p, "%i %i %i #", &origem, &destino, &aresta)!=EOF){
        *numAresta=(*numAresta)+(aresta);// conta numero de arestas para matriz incidencia
        printf("aresta: %i \n", *numAresta);
    }
     printf("\nNumero de Arestas:%i \n \n", *numAresta);

    fclose(p);
}

void IncidenciaNaoDirecionada(int ***matrizInc ){
    int destino, origem,  arestas, i=0, j;

    FILE *a= fopen("oi.txt","r");

    while(fscanf(a, "%i %i  %i \n ", &origem, &destino, &arestas)!= EOF){
        (*matrizInc)[i][origem-1]= 1;
        (*matrizInc)[i][destino-1]= 1;
        i++;
    }

    fclose(a);
}

void MostraIncidencia(int **matrizInc, int tamanho, int numAresta){
    int i, j;
    printf(">>>%p, %d %d \n",matrizInc, tamanho, numAresta);
    printf("@@%d\n", matrizInc[0][0]);
    for(i=0;i<tamanho;i++){
        for(j=0;j<numAresta;j++){
            printf("%d ",matrizInc[i][j]);
        }printf("\n");
    }

}

void GrauNaoDirecionado(int **matriz, int tamanho){
    int no, i, j, cont=0;

    printf("Digite o no: \n"); //mostra grau de no que o usuario digita
    scanf("%i", &no);
        for(j=0;j<tamanho;j++){
            if (matriz[no-1][j]!=0){ //no caso, nao eh direcionado, entao conta apenas a linha ou so coluna pois matriz eh simetrica
                cont+=matriz[no-1][j];
            }
        }
    printf("O grau do no %i eh: %i\n", no, cont);
}

void NaoDirecionada(int ***matriz){
    int i, j, x , y , relacionamento;
    FILE *p= fopen("oi.txt","r");
    while(fscanf(p, "%i %i %i", &x, &y, &relacionamento)!=EOF){
        (*matriz)[x-1][y-1]= relacionamento; // atribui valor para posicoes enviadas no arquivo
        (*matriz)[y-1][x-1]= relacionamento;
    }
    fclose(p);
}
void MostraAdjacencia(int **matriz, int tamanho){
    int i, j;
    for(i=0;i<tamanho;i++){         //percorre matriz e mostra
        for(j=0;j<tamanho;j++){
            if(matriz[i][j]!= -10){
                 printf("%i ",matriz[i][j]);
            }

        }printf("\n");
    }

}

int ParenteNo(int **matriz, int tamanho, int direcao, int pesquisaNo){
    int i, componentes=0, visto[tamanho], no=0;

    for(i = 0; i < tamanho; i++) {
        visto[i] = 0;
    }

    printf("Digite a raiz:\n");
    scanf("%i",&no);

    visto[no-1]++; //raiz da arvore ja vai marcada, j� que comecamos por ela
    printf(" %i |", no);
    ProcuraNo(matriz, no-1, tamanho, visto, direcao, pesquisaNo);
}

void ProcuraNo(int **matriz, int verticeAnalisado, int tamanho, int visto[tamanho], int direcao, int pesquisaNo){ //
    int i;

    for(i = 0; i < tamanho; i++){
        if (matriz[verticeAnalisado][i] == 1){
            if (visto[i] == 0) {
                visto[i]++;
                if (direcao == 1) {
                    printf(" %d |", i+1);
                    ProcuraNo(matriz, i, tamanho, visto, direcao, pesquisaNo);
                }
                else {
                    ProcuraNo(matriz, i, tamanho, visto, direcao, pesquisaNo);
                    printf(" %d |", i+1);
                }
            }
        }
    }
}

int main()
{
    int tamanho, i,j=0, escolha, resposta, origem, destino, numAresta=0, aresta, entra=0, entra2=0, direcao, pesquisaNo;

    int **matrizInc=NULL;
    int **matrizModificada=NULL;
    int **matriz=NULL;


    //printf("\noi\n\n");


        do{
            printf("\n1.Mostra Matriz \n2.Arvore\n3.Pesquisa\n0. Sair\n");
            printf("Opcao: ");
            scanf("\n%i",&escolha);

            switch(escolha){
                case 1:
                    criaMatriz(&matriz, &matrizModificada,&tamanho, &numAresta);

                    NaoDirecionada(&matriz);
                    NaoDirecionada(&matrizModificada);

                    printf("Matriz Adjacente: \n");
                    MostraAdjacencia(matriz, tamanho); printf("\n");
                    MostraAdjacencia(matrizModificada, tamanho);
                break;
                case 2:
                    ParenteNo(matriz, tamanho, 1);
                break;
                case 3:
                    printf("Digite o no a pesquisar");
                    scanf("%i",&pesquisaNo);

                    printf("1  = filhos\n-1 = pais\n");
                    scanf("%i",&direcao);
                    ParenteNo(matriz,tamanho,direcao,pesquisaNo);
                break;

                default:
                return 0;
                break;
          }
        }while(escolha!=0);

    return 0;
}