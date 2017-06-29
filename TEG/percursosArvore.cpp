#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaMatriz(int ***matriz, int *numAresta, int *vertices, int *tamanho){
    int i, j, vertice, raiz, esq, dir;
    *numAresta=0; //conta  numero de arestas a partir do numero de relacionamento enviado no arquivo txt 3 coluna

    printf("Digite a quantidade de vertices:\n");
    scanf("%i",&vertice);
    *vertices=vertice;
    *tamanho=vertice;
    printf(">>> %i vertices \n", *vertices);


    FILE *p=fopen("grafo.txt", "r"); //abre arquivo
    (*matriz)=(int**)malloc(*vertices * sizeof(int*));

      for(i=0;i<*vertices;i++){
        (*matriz)[i]= (int*) malloc(2*sizeof(int));
        for(j=0;j<2;j++){
            (*matriz)[i][j]=0;
        }
    }
    while(fscanf(p, "%i %i %i", &raiz, &esq, &dir)!=EOF){ //mesmo que a anterior porem quando o grafo for direcionado
        (*matriz)[raiz][0]= esq;
        //printf("%d\n", (*matriz)[raiz][0]);
        (*matriz)[raiz][1]= dir;


    }
    fclose(p);
}

void mostraMatriz(int **matriz, int vertices){
    int i, j;
    //printf (">> mostra\n");
    //printf (">> mostra  %i vertices\n", vertices);
    //FILE *p= fopen("grafo.txt","r");

    for(i=0;i<vertices;i++){ //percorre matriz e mostra
        for(j=0;j<2;j++){

                 printf("%i ",matriz[i][j]);


        }printf("\n");
    }
//     fclose(p);
}

int preOrdem(int **matriz,int *ultimo, int *i, int *pai, int vertices, int *tamanho){ //raiz esq dir
    int j;
     //printando a raiz principal
    printf("%i | ", *ultimo);
     //printf(" i: %i | ", *i);
     //printf(" pai : %i | \n", pai[*i]);

    for(j=0;j<*tamanho;j++){
        //percorrendo a arvore da esquerda
        if((matriz)[*ultimo][0]!=0){
            (*i)++;
            //printf(" esq i: %i\n", *i);
            pai[*i]=(matriz)[*ultimo][0];
            *ultimo=(matriz)[*ultimo][0];
            // printf(" ultimo %i | ", *ultimo);
            (*tamanho)--;
            preOrdem(matriz, ultimo, i, pai, vertices, tamanho);

        }else{//nao tem nenhum filho
            //pai[*i]=NULL;
            //(*i)--;
            //printf(" i modificado: %i\n", *i);
            *ultimo=(pai)[(*i)--];
            // printf (">>>>>>>>>>>> i %i\n", *i);
            //printf (">>>>>>>>>>>>  ultimo %i\n", *ultimo);
            // printf (">>>>>>>>>>>> pai %i\n", pai[*i]);
            if((matriz)[*ultimo][1]!=0){//tem o filho na direita
                (*i)++;
                pai[*i]=(matriz)[*ultimo][1];
                *ultimo=(matriz)[*ultimo][1];
                (*tamanho)--;
                preOrdem(matriz, ultimo, i, pai, vertices, tamanho);

            }else{
                return 1;
            }
        }
        *tamanho=vertices;
    }
    return 0;
}

void posOrdem(int **matriz, int *i, int *tamVet, int *percorrido, int *tamanho, int vertices, int * t){
    //esq dir raiz
    //printf(">> pos\n");

    if(matriz[*i][0]!=0){ //percorrendo filhos da esq
        // printf("   t %i\n", *t);
        printf("matriz elemento %i\n", matriz[*i][0]);
        percorrido[*t]=*i;
        (*t)++;
        (percorrido)[*t]=(matriz)[*i][0];
        (*tamVet)++;
        printf(">>>>> percorrido %i\n", percorrido[*t]); //vertices que ja a busca ja encontrou
        (*i)=(matriz)[*i][1]; //i sera a posicao na matriz, ou seja, ira buscar os proximos filhos na linha da matriz do filho encontrado
        //(*tamanho)++;
        posOrdem(matriz, i, tamVet, percorrido, tamanho,vertices, t);
    }if(matriz[*i][1]!=0){ //nao tem na esquerda mas tme filho a direita
        //(percorrido)= malloc(sizeof(int));
        percorrido[*t]=*i;
        (*t)++;
        (percorrido)[*t]=(matriz)[*i][0];
        (*tamVet)++;
        printf(">>>>> percorrido %i\n", percorrido[*t]); //vertices que ja a busca ja encontrou
        (*i)=(matriz)[*i][1];
        posOrdem(matriz, i, tamVet, percorrido, tamanho,vertices, t);
    }else{ //acabaram os filhos, vai printar a ordem e retornar na arvore
        percorrido[*t]=*i;
        if(matriz[percorrido[*t]][1]!=0){
            (*i)--;
            posOrdem(matriz,i, tamVet, percorrido, tamanho, vertices, t);
        }else{
            printf(" | %i \n",percorrido[*tamanho]);
            (*tamanho)--;
        }
    }
    //pai[i]=0;
}

void simetrico(){

}

int main()
{
    int pai[10], *percorrido, tamVet=0;
    pai[0]=0;
    int **matriz=NULL;
    int vertices, *i=0, escolha, ultimo=0, numAresta=0, tamanho, *t=0;
    (percorrido)= (int *) malloc(10*sizeof(int));
    do{
        printf("\n1.Pre Ordem \n2.Simetrica\n3.Pos Ordem\n0. Sair\n");
        printf("Opcao: ");
        scanf("\n%i",&escolha);

        switch(escolha){
            case 1:
                criaMatriz(&matriz, &numAresta, &vertices, &tamanho);
                mostraMatriz(matriz, vertices);
                preOrdem(matriz, &ultimo, i, pai, vertices, &tamanho);
            break;
            case 2:
                criaMatriz(&matriz, &numAresta, &vertices, &tamanho);
              // Simetrica();
            break;
            case 3:
                criaMatriz(&matriz, &numAresta, &vertices, &tamanho);
                posOrdem(matriz, i, &tamVet, percorrido, &tamanho, vertices, t);
            break;
            default:
                return 0;
            break;
      }
    }while(escolha!=0);
    return 0;
}
