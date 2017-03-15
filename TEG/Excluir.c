#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaMatriz(int ***matriz, int ***matrizInc, int *tamanho,int *numAresta){
    int i, j, origem, destino, vertices,aresta=0;
    *numAresta=0;
    printf("Digite a quantidade de vertices:\n");
    scanf("%i",&vertices);
    *tamanho=vertices;

    FILE *p=fopen("oi.txt", "r");
    *matriz=(int**)malloc(*tamanho * sizeof(int*));
    printf("oi\n\n");
    for(i=0;i<*tamanho;i++){
        (*matriz)[i]= (int*) malloc(*tamanho*sizeof(int));
        for(j=0;j<*tamanho;j++){
            (*matriz)[i][j]=0;
        }
    }


    while(fscanf(p, "%i %i %i #", &origem, &destino, &aresta)!=EOF){
        *numAresta=(*numAresta)+(aresta);
        printf("aresta: %i \n", *numAresta);
    }
     printf("\nNumero de Arestas:%i \n \n", *numAresta);

    (*matrizInc)= (int**)malloc(*tamanho * sizeof(int*));
    for(i=0;i<*tamanho;i++){
        (*matrizInc)[i]= (int*) malloc(*tamanho*sizeof(int));
        for(j=0;j<*numAresta;j++){
            (*matrizInc)[i][j]=0;
        }
    }
    fclose(p);
}

void NaoDirecionada(int ***matriz){
    int i, j, x , y , relacionamento;
    FILE *p= fopen("oi.txt","r");
    while(fscanf(p, "%i %i %i", &x, &y, &relacionamento)!=EOF){
       // printf("%i", matriz[x][y]);
        (*matriz)[x-1][y-1]= relacionamento;
        (*matriz)[y-1][x-1]=relacionamento;

    }
    fclose(p);
}

void Direcionada(int ***matriz){
    int i, j, x , y , relacionamento;
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

        }printf("\n");
    }

}


void GrauNaoDirecionado(int **matriz, int tamanho){
    int no, i, j, cont=0;

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
    int destino, origem,  arestas, i=0, j;
    //printf("ola");
    FILE *a= fopen("oi.txt","r");





            while(fscanf(a, "%i %i  %i \n ", &origem, &destino, &arestas)!= EOF){

               // printf("%i %i \n", origem,  destino);
               // printf("ola\n");
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

void IncidenciaDirecionada(int ***matrizInc){
    int destino, origem,  arestas, i=0, j;
    //printf("ola");
    FILE *a= fopen("oi.txt","r");





            while(fscanf(a, "%i %i  %i \n ", &origem, &destino, &arestas)!= EOF){

               // printf("%i %i \n", origem,  destino);
               // printf("ola\n");
                (*matrizInc)[i][origem-1]= 1;
                (*matrizInc)[i][destino-1]= -1;
                i++;
            }
    fclose(a);
}

void ExcluiVertice(int **matriz, int tamanho){
    int vertice, j=0, i, x, y, relacionamento;
    printf("Digite o vertice que deseja excluir: \n");
    scanf("%i", &vertice);



    FILE *p= fopen("oi.txt","r");
    while(fscanf(p, "%i %i %i", &x, &y, &relacionamento)!=EOF){

            matriz[vertice-1][j]= -10;
            //matriz[x-1][vertice]=-10;
            j++;



    }
    /*
    for(j=0;j<tamanho;j++){
            matriz[vertice][j]==-10;

    }

    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            if(matriz[i][j]!= -10){
                 printf("%i ",matriz[i][j]);
            }

        }printf("\n");
    }*/
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
        }printf("\n");
    }
}




void InsereVertice(int **matriz){


}

int main(){

    int tamanho, i,j, escolha, resposta, origem, destino, numAresta=0, aresta, entra=0, entra2=0;;

    int **matriz=NULL;
    int **matrizInc=NULL;

    //printf("\noi\n\n");
    printf("O grafo eh direcionada? 1= SIM\n");
    scanf("%i", &resposta);
    if(resposta==1){


        do{
            printf("\n1.Mostra Matrizes \n2.Grau do No\n3. Exclui Vertice\n4. Mostra Matriz Complemento\n0. Sair\n");
            printf("Opcao: ");
            scanf("\n%i",&escolha);

            switch(escolha){
                case 1:
                    criaMatriz(&matriz, &matrizInc, &tamanho, numAresta);

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
                    ExcluiVertice(matriz, tamanho);


                break;
                case 4:
                    Complemento(matriz, tamanho);


                break;
                default:
                return 0;
                break;
          }
        }while(escolha!=0);



    }else{

        do{
            printf("\n1.Mostra Matrizes  \n2.Grau do No\n3. Exclui Vertice\n4. Mostra Matriz Complemento\n5. Insere Vertice\n0. Sair\n");
            printf("Opcao: ");
            scanf("%i",&escolha);

            switch(escolha){
                case 1:
                    criaMatriz(&matriz, &matrizInc, &tamanho, &numAresta);
                    printf(">>>>>>>>>>>>>>>>%d\n", numAresta);
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
                    ExcluiVertice(matriz, tamanho);


                break;
                case 4:
                    Complemento(matriz, tamanho);


                break;
                case 5:
                    //printf("@@@@@@oi\n");
                    //InsereVertice(matriz);
                    //printf(">>>>>>>>oi\n\n");
                    FILE *v=fopen("verticeNovo.txt", "r");
                    FILE *p=fopen("oi.txt", "a");

                    char buffer[100];
                    //fseek(p,0,SEEK_END);
                    while(fgets(buffer, 100, v) != NULL){
                    //fprintf(p, buffer);

                        fputs(buffer,p);
                    //printf("%s", buffer);
                    }

                    fclose(p);
                    fclose(v);




                break;


                default:
                return 0;
                break;
            }
        }while(escolha!=0);

    }


    return 0;
}
