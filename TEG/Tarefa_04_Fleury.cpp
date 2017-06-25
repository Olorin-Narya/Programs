#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void criaMatriz(int ***matriz, int ***matrizModificada , int *tamanho,int *numAresta){
    int i, j, origem, destino, vertices,aresta=0;

    *numAresta=0;
    printf("Digite a quantidade de vértices:\n");
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
     printf("\nNúmero de Arestas:%i \n \n", *numAresta);

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
    printf("Digite o nó: \n"); //mostra grau de no que o usuario digita
    scanf("%i", &no);
        for(j=0;j<tamanho;j++){
            if (matriz[no-1][j]!=0){ //no caso, nao eh direcionado, entao conta apenas a linha ou so coluna pois matriz eh simetrica
                cont+=matriz[no-1][j];
            }
        }
    printf("O grau do nó %i eh: %i\n", no, cont);
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

void Conexo(int **matriz, int verticeAnalisado, int tamanho, int * visto){
    int i;
    for(i = 0; i < tamanho; i++){ //tamanho = qtdVertices
        if (matriz[verticeAnalisado][i] != 0){
            if (visto[i] == 0) {
                visto[i]++;
                Conexo(matriz, i, tamanho, visto);
            }
        }
        //else ja vi esse vertice, fa�o nada... PROXIMO
    }
}

int VerificaConexao(int **matriz, int tamanho){
    int i, componentes=0, visto[tamanho];
    Conexo(matriz, 0, tamanho, visto);
    for (i = 0; i < tamanho; i++){
        if (visto[i] == 0){
            componentes++;
            visto[i]++;
            Conexo(matriz, i,  tamanho, visto);
        }
    }
    if (componentes == 0){
        return 1;
    }else{
        return 0;
    }
}

void Fleury(int **matriz, int **matrizModificada, int numAresta, int tamanho){
    int ultimoVertice, numIncidencia, arestaEliminar, i, j = 1, ciclo[numAresta+1], arestaRestantes, contador = 0;

    VerificaConexao(matrizModificada, tamanho);
    ultimoVertice = 0;
    ciclo[0] = 0;
    arestaRestantes = numAresta;

    while(arestaRestantes != 0) {
        numIncidencia = 0;
        for(i = 0; i < tamanho;i++){
            if(matrizModificada[ultimoVertice][i] !=0){
                numIncidencia += matrizModificada[ultimoVertice][i];
                arestaEliminar = i;
            }
        }
        if (numIncidencia == 1) {
            matrizModificada[ultimoVertice][arestaEliminar]--;
            matrizModificada[arestaEliminar][ultimoVertice]--;
            arestaRestantes--;
            ciclo[j] = arestaEliminar;
            ultimoVertice = arestaEliminar;
            j++;

        }
        else {              //tem mais de 1 aresta ligada ao vertice
            for(i = 0; i < tamanho;i++){
                if(matrizModificada[ultimoVertice][i] != 0){
                    matrizModificada[ultimoVertice][i]--;
                    matrizModificada[i][ultimoVertice]--;
                    if (!(VerificaConexao(matrizModificada,tamanho))) { //se deixar de ser conexo, volta e vamos ver a proxima aresta...
                        matrizModificada[ultimoVertice][i]++;
                        matrizModificada[i][ultimoVertice]++;
                    }
                    else {
                        ciclo[j] = i;
                        ultimoVertice = i;
                        j++;
                        arestaRestantes--;
                    }
                }
            }
        }
        contador++;

        if (contador > numAresta*tamanho) {
            printf("Nao há um circuito Euleriano");
            return;
        }
    }
    printf("\nO circuito Euleriano é ");
    for (i = 0; i < numAresta+1; i++) {
        printf("%i", ciclo[i]+1);
        if (i < numAresta) {
            printf(", aresta%i%i, ", ciclo[i]+1,ciclo[i+1]+1);
        }
        else {
            printf(".");
        }
    }
    printf("\n");
}

int main()
{
    int tamanho, escolha, numAresta=0;
    int **matrizModificada=NULL;
    int **matriz=NULL;
    setlocale(LC_ALL, "");
    do{
        printf("\n1.Mostra Matriz \n2.Fleury\n0. Sair\n");
        printf("Opção: ");
        scanf("\n%i",&escolha);
        switch(escolha){
            case 1: {
                criaMatriz(&matriz, &matrizModificada,&tamanho, &numAresta);
                NaoDirecionada(&matriz);
                NaoDirecionada(&matrizModificada);
                printf("Matriz Adjacente: \n");
                MostraAdjacencia(matriz, tamanho); printf("\n");
                MostraAdjacencia(matrizModificada, tamanho);
            }
            break;
            case 2:
                Fleury(matriz, matrizModificada, numAresta, tamanho);
            break;
            default:
                return 0;
            break;
      }
    }while(escolha!=0);
    return 0;
}
