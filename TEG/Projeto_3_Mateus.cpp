#include <stdio.h>
#include <stdlib.h>

/*

0 4 0 2
4 0 5 1
0 5 0 3
2 1 3 0

=======

0 5 0 3
5 0 2 1
2 0 0 8
3 1 8 0

========

0 1 3 0 0
1 0 5 10 0
3 5 0 9 7
0 10 9 0 4
0 0 7 4 0

*/

int **matriz;
int *dist;
int *marcados;
int  ** caminho;
int segundaVez = 0;

void limpaCaminho (int *caminho, int vertices) {
	int i;
	for (i = 0; i < (vertices); i++) {
  	    caminho[i] = -1;
    }
}

int menor(int vertices){
    int i, menor = -1;

    //algum vértice ainda não relaxado?
    for (i = 0; i < vertices; i++){
        if (!marcados[i]){
            menor = i;
            break;
        }
    }

    //se alguém não tenha sido relaxado, vamos relaxar
    if (menor != -1) {
        for (i = 0; i < vertices; i++){
            if ((dist[i] < dist[menor]) && !(marcados[i])) {
                menor = i;
            }
        }
    }
    return menor;
}

void Dijkstra(int inicio, int vertices){
    int i,j,atual;

    //Não posso alocar mais memoria, sendo que nem dei free da primeira vez
    if (!segundaVez) {
        dist     = (int *) malloc(sizeof(int) * vertices);
        marcados = (int *) malloc(sizeof(int) * vertices);
        caminho  = (int **) malloc(sizeof(int **) * vertices);
    }

    // alimentando as distancias
    for (i = 0; i < vertices; i++){
        if (!segundaVez) {
            caminho[i]  = (int *) malloc(sizeof(int) * (vertices));
        }

        // limpando vetores
        marcados[i] = 0;
        limpaCaminho(caminho[i], vertices);

        // Os caminhos começam pelo inicio
        // caminho[i][0] = inicio; por que eu fiz isso?

        if (i == inicio) {
            // Distancia para o vertice de inicio é 0
            dist[i] = 0;
            marcados[i] = 1;
            continue;
        }

        if (matriz[inicio][i] == 0){
            dist[i] = 99999999;     //"Infinito"
        }
        else {
            dist[i] = matriz[inicio][i];
            // caminhando do inicio para os primeiros vertices
            caminho[i][1] = i;
        }
    }

    while (menor(vertices) != -1) {
        atual = menor(vertices);
        marcados[atual] = 1;
        for (i = 0; i < vertices; i++) {
            if (matriz[atual][i] != 0 && !marcados[i]) {
                if (dist[atual] + matriz[atual][i] < dist[i]) {
                    dist[i] = dist[atual] + matriz[atual][i];

                    limpaCaminho(caminho[i],vertices);
                    for (j = 0; j < vertices; j++) {
                    	if (caminho[atual][j] == -1) {
                    		caminho[i][j] = i;
                    		break;
                    	}
                    	else {
	                   	    caminho[i][j] = caminho[atual][j];
	                   	}
                    }
                }
            }
        }
    }
}

int main()
{
    int i, j, k;
    int inicio, destino, vertices, inicioAresta, custo;
    int linha, coluna, peso, x;

    FILE *p=fopen("oi.txt", "r");

    if (!p) {
        printf("Erro com o arquivo\n");
        return 1;
    }

    fscanf(p, "%i %i", &vertices, &x);
    matriz = (int **) malloc(sizeof(int*) * vertices);
    for (i = 0; i < vertices; i++){
        matriz[i] = (int *) malloc(sizeof(int) * vertices);
    }

    for (i = 0; i < vertices; i++){
        for(j = 0; j < vertices; j++){
            (matriz)[i][j] = 0;
        }
    }

    //INICIALIZANDO A MATRIZ COM ARQUIVO TXT
    fscanf(p, "%i %i", &inicio, &destino);
    while (fscanf(p, "%i %i %i", &linha, &coluna, &peso) != EOF) {
        matriz[linha][coluna] = peso;
    }

    printf(">>>>>>>>> MATRIZ: \n");
    for(i = 0; i < vertices; i++){
        for(j = 0; j < vertices; j++){
            printf(" %i", matriz[i][j]);
        }
        printf("\n");
    }
    Dijkstra(inicio, vertices);

    printf("1 IMPRIMINDO O VETOR DE DISTANCIAS A PARTIR DE %d:\n",inicio);
    for (i = 0; i < vertices; i++) {
    	printf("Distância[%d]: %d \tCaminho[%d] = %d", i, dist[i], i, caminho[i][0]);
    	for (j = 1; j < vertices; j++) {
    		if (caminho[i][j] != -1) {
		        printf("-%d", caminho[i][j]);
		    }
		}
		printf("\n");
    }

    custo = dist[destino];
    printf("Custo total para o destino %d\n",dist[destino]);

    segundaVez++;

    while (custo == dist[destino]) {
        inicioAresta = inicio;
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                for (k = 0; k < vertices; k++) {
                    if (caminho[destino][k] != -1) {
	                    matriz[inicioAresta][caminho[destino][k]] = 0;
                        inicioAresta = caminho[destino][k];
                    }
                }
            }
        }
        Dijkstra(inicio, vertices);
    }

    printf(">>>>>>>>> MATRIZ 2: \n");
    for(i = 0; i < vertices; i++){
        for(j = 0; j < vertices; j++){
            printf(" %i", matriz[i][j]);
        }
        printf("\n");
    }

    printf("2 IMPRIMINDO O VETOR DE DISTANCIAS A PARTIR DE %d:\n",inicio);
    for (i = 0; i < vertices; i++) {
    	printf("Distância[%d]: %d \tCaminho[%d] = %d", i, dist[i], i, caminho[i][0]);
    	for (j = 1; j < vertices; j++) {
    		if (caminho[i][j] != -1) {
		        printf("-%d", caminho[i][j]);
		    }
		}
        printf("\n");
    }
    printf("Custo total para o destino %d\n",dist[destino]);

    return 0;
}
