#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void criaMatriz(int ***matriz, int *numAresta, int *vertices){
    int i, j, origem, destino, vertice,aresta, raiz, esq, dir;
    *numAresta=0; //conta  numero de arestas a partir do numero de relacionamento enviado no arquivo txt 3 coluna

    printf("Digite a quantidade de vertices:\n");
    scanf("%i",&vertice);
    *vertices=vertice;
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


    int i, j , raiz , esq , dir;
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
                // printf(" ultimo %i | ", *ultimo);

                preOrdem(matriz, ultimo, i, pai, vertices);




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

    int *pai[10];
    pai[0]=0;
    int **matriz=NULL;
    int vertices, i=0,j, escolha, ultimo=0, origem, destino, numAresta=0, aresta, entra=0, entra2=0;;



    //printf("\noi\n\n");



        do{
            printf("\n1.Pre Ordem \n2.Simetrica\n3.Pos Ordem\n0. Sair\n");
            printf("Opcao: ");
            scanf("\n%i",&escolha);

            switch(escolha){
                case 1:
                    criaMatriz(&matriz, &numAresta, &vertices);
                    mostraMatriz(matriz, vertices);

                    preOrdem(matriz,&ultimo, &i, &pai, vertices);


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