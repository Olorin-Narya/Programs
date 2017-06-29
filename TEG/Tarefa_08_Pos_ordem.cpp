#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void criaMatriz(int ***matriz, int *numAresta, int *vertices){
    int i, j, vertice, raiz, esq, dir;
    FILE *p=fopen("grafo.txt", "r");
    *numAresta=0;                                                               //Número de relacionamentos (3ª coluna)
    printf("Digite a quantidade de vértices:\n");
    scanf("%i",&vertice);
    *vertices=vertice;
    printf(">>> %i vértices \n", *vertices);

    (*matriz)=(int**)malloc(*vertices * sizeof(int*));

    for(i=0;i<*vertices;i++){
        (*matriz)[i]= (int*) malloc(2*sizeof(int));
        for(j=0;j<2;j++){
            (*matriz)[i][j]=0;
        }
    }
    while(fscanf(p, "%i %i %i", &raiz, &esq, &dir)!=EOF){                       //para quando o grafo for direcionado
        (*matriz)[raiz][0]= esq;
        (*matriz)[raiz][1]= dir;
    }
    fclose(p);
}

void mostraMatriz(int **matriz, int vertices){
    int i, j;
    for(i=0;i<vertices;i++){
        for(j=0;j<2;j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
}

void preOrdem(int **matriz,int *ultimo, int *i, int *pai, int vertices){ //raiz esq dir
    int j;
    //printando a raiz principal
    printf("%i | ", *ultimo);
    //printf(" i: %i | ", *i);
    //printf(" pai : %i | \n", pai[*i]);
    for(j=0;j<vertices-2;j++){
        //percorrendo a arvore da esquerda
        if((matriz)[*ultimo][0]!=0){
            (*i)++;
            //printf(" esq i: %i\n", *i);
            pai[*i]=(matriz)[*ultimo][0];
            *ultimo=(matriz)[*ultimo][0];
            //printf(" ultimo %i | ", *ultimo);
            preOrdem(matriz, ultimo, i, pai, vertices);

        }else{//nao tem nenhum filho
            //pai[*i]=NULL;
            //(*i)--;
            //printf(" i modificado: %i\n", *i);
            *ultimo=(pai)[(*i)--];
            //printf (">>>>>>>>>>>> i %i\n", *i);
            //printf (">>>>>>>>>>>>  ultimo %i\n", *ultimo);
            // printf (">>>>>>>>>>>> pai %i\n", pai[*i]);
            if((matriz)[*ultimo][1]!=0){//tem o filho na direita
                (*i)++;
                pai[*i]=(matriz)[*ultimo][1];
                *ultimo=(matriz)[*ultimo][1];
                preOrdem(matriz, ultimo, i, pai, vertices);
            }else{
                return ;
            }
        }
    }
}

void posOrdem(){
    //esq dir raiz

    //pai[i]=0;
}

void simetrico(){}
 //esq raiz dir


int main()
{
    setlocale(LC_ALL, "");
    int vertices, escolha, *ultimo=0, *i=0, numAresta=0;
    int **matriz=NULL;
    int pai[10];
    pai[0]=0;
    do{
        printf("\n1.Pré Ordem \n2.Simetrica\n3.Pós Ordem\n0. Sair\n");
        printf("Opcao: ");
        scanf("\n%i",&escolha);
        switch(escolha){
            case 1: {
                criaMatriz(&matriz, &numAresta, &vertices);
                mostraMatriz(matriz, vertices);
                preOrdem(matriz, ultimo, i, pai, vertices);
            }
            break;
            case 2:
              // Simetrica();

            break;
            case 3:
               //posOrdem();

            break;
            default:
                return 0;
            break;
        }
    }while(escolha!=0);
    return 0;
}
