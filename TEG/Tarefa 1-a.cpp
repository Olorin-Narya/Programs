/*
 * main.c
 *
 *  Created on: 21 de mai de 2017
 *      Author: mateus
 */

#include <stdio.h>
#include <stdlib.h>

void criaMatriz(int ***matriz, int ***matrizInc, int *tamanho,int *numAresta){
    int i, j, origem, destino, vertices,aresta=0;
    *numAresta=0;
    printf("Digite a quantidade de vertices:\n");
    scanf("%i",&vertices);
    *tamanho=vertices;

    *matriz=(int**)malloc(*tamanho * sizeof(int*));
    for(i=0;i<*tamanho;i++){
        (*matriz)[i]= (int*) malloc(*tamanho*sizeof(int));
        for(j=0;j<*tamanho;j++){
            (*matriz)[i][j]=0;
        }
    }
    FILE *p=fopen("oi.txt", "r");

    while(fscanf(p, "%i %i %i #", &origem, &destino, &aresta)!=EOF){
        *numAresta=(*numAresta)+(aresta);
        printf("aresta: %i \n", *numAresta);
    }
    printf("\nNumero de Arestas:%i \n \n", *numAresta);

    (*matrizInc) = (int**)malloc(*numAresta * sizeof(int*));
    for(i=0;i<*numAresta;i++) {
        (*matrizInc)[i] = (int*) malloc(*tamanho*sizeof(int));
        for(j=0;j<*tamanho;j++){
            (*matrizInc)[i][j] = 0;
        }
    }
    fclose(p);
}

void NaoDirecionada(int ***matriz){
    int x , y , relacionamento;
    FILE *p= fopen("oi.txt","r");
    while(fscanf(p, "%i %i %i", &x, &y, &relacionamento)!=EOF){
        (*matriz)[x-1][y-1]= relacionamento;
        (*matriz)[y-1][x-1]=relacionamento;
    }
    fclose(p);
}

void Direcionada(int ***matriz){
    int x , y , relacionamento;
    FILE *p= fopen("oi.txt","r");
    while(fscanf(p, "%i %i %i", &x, &y, &relacionamento)!=EOF){
        (*matriz)[x-1][y-1]= relacionamento;
    }
    fclose(p);
}

void MostraAdjacencia(int **matriz, int tamanho){
    int i, j;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            if(matriz[i][j]!= -10){
                printf("%i ",matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void GrauNaoDirecionado(int **matriz, int tamanho){
    int no, j, cont=0;

    printf("Digite o no: \n");
    scanf("%i", &no);
    for(j=0;j<tamanho;j++){
        if (matriz[no-1][j]!=0){
            cont+=matriz[no-1][j];
        }
    }
    printf("O grau do no %i eh: %i\n", no, cont);
}

void GrauDirecionado(int **matriz, int tamanho){
    int no, i, j, cont=0, cont2=0;

    printf("Digite o no: \n");
    scanf("%i", &no);
    for(j=0;j<tamanho;j++){
        if (matriz[no-1][j]!=0){
            cont+=matriz[no-1][j];
        }
    }
    for(i=0;i<tamanho;i++){
        if (matriz[i][no-1]!=0){
            cont2+=matriz[i][no-1];
        }
    }
    printf("O grau do no %i eh: %i\n", no, cont+cont2);
}

void IncidenciaNaoDirecionada(int ***matrizInc ){
    int destino, origem,  arestas, i=0;

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
    for(i=0;i<numAresta;i++){
        for(j=0;j<tamanho;j++){
            printf("%d ",matrizInc[i][j]);
        }
        printf("\n");
    }
}

void IncidenciaDirecionada(int ***matrizInc){
    int destino, origem,  arestas, i=0;

    FILE *a= fopen("oi.txt","r");

    while(fscanf(a, "%i %i  %i \n ", &origem, &destino, &arestas)!= EOF){
        (*matrizInc)[i][origem-1]= 1;
        (*matrizInc)[i][destino-1]= -1;
        i++;
    }
    fclose(a);
}

void ExcluiVertice(int** matriz, int* tamanho, int* numAresta) {
    int vertice, j=0, x, y, relacionamento;
    printf("Digite o vertice que deseja excluir: \n");
    scanf("%i", &vertice);

    FILE *p= fopen("oi.txt","rw");
    FILE *a= tmpfile();
    while(fscanf(p, "%i %i %i", &x, &y, &relacionamento)!=EOF){
        if (!(x == vertice) && !(y == vertice)) {
            fprintf(a,"%i %i %i\n", x, y, relacionamento);
        }
        j++;
    }
    fclose(p);
    rewind(a);
    p = fopen("oi.txt","w");
    while(fscanf(a, "%i %i %i", &x, &y, &relacionamento)!=EOF){
        fprintf(p,"%i %i %i\n", x, y, relacionamento);
    }
    fclose(a);
    fclose(p);
}

void Complemento(int **matriz, int tamanho){
    int i, j;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            if(matriz[i][j]==0){
                matriz[i][j]=1;
            }else{
                matriz[i][j]=0;
            }
        }
    }

    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
                printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}

void InsereVertice(int **matriz){

    FILE *v=fopen("verticeNovo.txt", "r");
    FILE *p=fopen("oi.txt", "a");

    char buffer[100];

    while(*(fgets(buffer, 100, v)) != EOF){
        fputs(buffer, p);
    }
}

int main(){

    int tamanho, escolha, resposta, numAresta=0;

    printf("O grafo eh direcionada? 1= SIM\n");
    scanf("%i", &resposta);
    int **matriz=NULL;
    int **matrizInc=NULL;
    if(resposta==1){
        do{
            printf("\n1.Mostra Matrizes\n2.Grau do No\n3. Exclui Vertice\n4. Insere Vertice\n0. Sair\n");
            printf("Opcao: ");
            scanf("\n%i",&escolha);

            switch(escolha){
                case 1:
                    criaMatriz(&matriz, &matrizInc, &tamanho, &numAresta);

                    Direcionada(&matriz);
                    IncidenciaDirecionada(&matrizInc);

                    printf("Matriz Adjacente: \n");
                    MostraAdjacencia(matriz, tamanho);
                    printf("Matriz Incidencia: \n");
                    MostraIncidencia(matrizInc, tamanho, numAresta);

                break;
                case 2:
                    GrauDirecionado(matriz, tamanho);

                break;
                case 3:
                    ExcluiVertice(matriz, &tamanho, &numAresta);

                break;
                case 4:
                    InsereVertice(matriz);

                break;
                default:
                return 0;
                break;
          }
        }while(escolha!=0);
    }else{
        do{
            printf("\n1.Mostra Matrizes\n2.Grau do No\n3. Exclui Vertice\n4. Insere Vertice\n0. Sair\n");
            printf("Opcao: ");
            scanf("%i",&escolha);

            switch(escolha){
                case 1:
                    criaMatriz(&matriz, &matrizInc, &tamanho, &numAresta);
                    NaoDirecionada(&matriz);
                    IncidenciaNaoDirecionada(&matrizInc);

                    printf("Matriz Adjacente: \n");
                    MostraAdjacencia(matriz, tamanho);
                    printf ("Matriz Incidencia: \n");
                    MostraIncidencia(matrizInc, tamanho, numAresta);

                break;
                case 2:
                    GrauNaoDirecionado(matriz, tamanho);

                break;
                case 3:
                    ExcluiVertice(matriz, &tamanho, &numAresta);

                break;
                case 4:
                    InsereVertice(matriz);

                break;

                default:
                return 0;
                break;
            }
        }while(escolha!=0);
    }
    return 0;
}
