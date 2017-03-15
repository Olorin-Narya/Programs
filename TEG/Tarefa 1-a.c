#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void IncidenciaDirecionada(int ***matrizInc){
    int destino, origem,  arestas, i=0, j;

    FILE *a= fopen("oi.txt","r");

    while(fscanf(a, "%i %i  %i \n ", &origem, &destino, &arestas)!= EOF){
        // printf("%i %i \n", origem,  destino);
        (*matrizInc)[i][origem-1]= 1;
        (*matrizInc)[i][destino-1]= -1;
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

    printf("O grau do no %i é: %i\n", no, cont+cont2);
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
        }
        printf("\n");
    }
}

void InsereVertice(int **matriz){

    FILE *v=fopen("verticeNovo.txt", "r");
    FILE *p=fopen("oi.txt", "a");

    char *buffer[100];

    while(fgets(buffer, 100, v) !=EOF){
                fputs(buffer, p);
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

void Conexo(int **matriz, int verticeAnalisado, int tamanho, int visto[tamanho]){ //
    int i;
    for(i = 0; i < tamanho; i++){ //tamanho = qtdVertices
        if (matriz[verticeAnalisado][i] != 0){
            if (visto[i] == 0) {
                visto[i]++;
                Conexo(matriz, i, tamanho, visto);
            }
        }
        //else ja vi esse vertice, fa篠nada... PROXIMO
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
            printf("Nao ha um caminho Euleriano");
            return 0;
        }
    }
    printf("\nO caminho Euleriano e ");
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

int main(){

    int tamanho, i,j, escolha, resposta, origem, destino, numAresta=0, aresta, entra=0, entra2=0;;

    int **matriz=NULL;
    int **matrizInc=NULL;

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
            printf("\n1.Mostra Matrizes  \n2.Grau do No\n3. Exclui Vertice\n4. Mostra Matriz Complemento\n5. Insere Vertice\n6. Conexividade\n7. Fleury\n0. Sair\n");
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

                case 5:;
                    FILE *v=fopen("verticeNovo.txt", "r");
                    FILE *p=fopen("oi.txt", "a");

                    char buffer[100];
                    while(fgets(buffer, 100, v) != NULL){
                        fputs(buffer,p);
                    }

                    fclose(p);
                    fclose(v);
                    break;

                case 6:
                    VerificaConexao(matriz, tamanho);
                    break;

                case 7:
                    Fleury(matriz, matrizModificada, numAresta, tamanho);
                    break;

                default:
                    return 0;
                    break;
            }
        }while(escolha!=0);
    }
    return 0;
}
