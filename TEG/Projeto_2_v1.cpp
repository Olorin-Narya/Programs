#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpaCaminho (int *caminho, int vertices) {
	int i;
	for (i = 0; i < vertices; i++) {
  	    caminho[i] = -1;
    }
}

void copiaCaminho (int ** caminhos, int lento, int melhor, int vertices)
{
	limpaCaminho(caminhos[lento], vertices);
	for (int j = 0; j < vertices; j++)
	{
		if (caminhos[melhor][j] == -1)
		{
			caminhos[lento][j] = melhor;
			break;
		}
		else
		{
			caminhos[lento][j] = caminhos[melhor][j];
		}
	}
}

int tamanhoCaminho(int * caminho, int vertices)
{
	int i, tamanho=0;
	for (i = 0; i < vertices; i++)
	{
		if (caminho[i] != -1) tamanho++;
	}
	return tamanho;
}

int menor(int *dist, int *marcados, int vertices){
	int i, menor = -1, d = 10000000;

	for(i = 0; i < vertices; i++){
		if(dist[i] < d && !marcados[i]){
			menor = i;
			break;
        }
    }

	if(menor != -1){
		for(i = 0; i < vertices; i++){
			if(dist[i] < dist[menor] && !marcados[i]) menor = i;
        }
    }
    return menor;
}

int main() {
	setlocale(LC_ALL, "");
	int i, j, k, h, vertices = 15;
	int matriz[vertices][vertices] = {
	// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
	{000, 10,  5, 10, 13,  8, 15, 16, 10,  3,  9,  4,  3,  3,  5}, // 0
	{ 10,000,  4,  5, 10, 10, 20, 21, 17,  4, 20, 10, 12,  9,  8}, // 1
    {  5,  4,000,  4,  9,  5, 14, 13, 10,  5, 13, 10, 10,  9,  9}, // 2
    { 10,  5,  4,000,  5,  3, 10,  9,  7,  7, 15, 11, 14, 13, 12}, // 3
    { 13, 10,  9,  5,000,  4,  7,  4,  4, 10,  8,  7, 11, 12, 13}, // 4
	{  8, 10,  5,  3,  4,000,  6,  6,  4,  6,  3,  2,  5,  7,  9}, // 5

    { 15, 20, 14, 10,  7,  6,000,  2,  2,  11, 4,  5,  7,  9, 12}, // 6
	{ 16, 21, 13,  9,  4,  6,  2,000,  4,  15, 7,  7, 12, 13, 17}, // 7
    { 10, 17, 10,  7,  4,  4,  2,  4,000,   9,  4, 3,  6,  9, 14}, // 8
    {  3,  4,  5,  7, 10,  6, 11, 15,  9,0000, 10, 7,  7,  5,  2}, // 9
    {  9, 20, 13, 15,  8,  3,  4,  7,  4,  10,000, 4,  4,  8, 11}, // 10

    {  4, 10, 10, 11,  7,  2,  5,  7,  3,  7,  4,000,  3,  5,  8}, // 11
    {  3, 12, 10, 14, 11,  5,  7, 12,  6,  7,  4,  3,000,  4,  7}, // 12
    {  3,  9,  9, 13, 12,  7,  9, 13,  9,  5,  8,  5,  4,000,  4}, // 13
    {  5,  8,  9, 12, 13,  9, 12, 17, 14,  2, 11,  8,  7,  4,000}  // 14
    };

    int peso[vertices] = {0, 8, 7, 8, 9, 5, 11, 12, 10, 5, 7, 5, 7, 7, 5};

    int * dist = (int *) malloc(sizeof(int)*vertices);
    int * marcados = (int *) malloc(sizeof(int)*vertices);
    int ** caminhos  = (int **) malloc(sizeof(int *) * vertices);

    int inicio = 0;
    int atual = 0;
	int tamCaminho = vertices*2;
	int MaxPulverizar = 21;
	int AtualCargaPulverizar = 21;

    for (i = 0; i < vertices; i++)
	{
        marcados[i] = 0;
		caminhos[i]  = (int *) malloc(sizeof(int) * (vertices*2));
		limpaCaminho(caminhos[i], tamCaminho);
		caminhos[i][inicio] = inicio;
        dist[i] = matriz[inicio][i];
    }
	//vertice inicial relaxado
	marcados[inicio] = 1;

	while(menor(dist, marcados, vertices) != -1)
	{
        atual = menor(dist, marcados, vertices);
        marcados[atual] = 1;
        for(i = 0; i < vertices; i++)
		{
            if(matriz[atual][i] != 0 && marcados[i] == 0)
			{
                if (dist[atual] + matriz[atual][i] < dist[i])
				{
                    dist[i] = dist[atual] + matriz[atual][i];
					copiaCaminho(caminhos, i, atual, tamCaminho);
                }
				else if (dist[atual] + matriz[atual][i] == dist[i])
				{
					if (tamanhoCaminho(caminhos[atual], tamCaminho) > tamanhoCaminho(caminhos[i], tamCaminho))
					{
						dist[i] = dist[atual] + matriz[atual][i];
						copiaCaminho(caminhos, i, atual, tamCaminho);
					}
				}
            }
        }
		printf("%d\n", atual);
        for(i = 0; i < vertices; i++)
		{
            printf("DIST[%d] =  %d\n", i, dist[i]);
        }
		printf("\n");
    }

	for(i = 0; i < vertices; i++)
	{
		for (j = 0; j < tamCaminho; j++)
		{
			if (caminhos[i][j] == -1) break;
        	if (AtualCargaPulverizar - peso[caminhos[i][j]] >= 0)
				AtualCargaPulverizar -= peso[caminhos[i][j]];
			else
			{
				h = j;
				while (h > 0)
				{
					for (k = tamCaminho-1; k > j; k--)
					{
						caminhos[i][k] = caminhos[i][k-1];
					}
					h--;
				}
				caminhos[i][j] = inicio;
				AtualCargaPulverizar = MaxPulverizar;
			}

		}
		AtualCargaPulverizar = MaxPulverizar;
	}

	for(i = 0; i < vertices; i++)
	{
		printf("Distancia[%d]: %d \t Caminho[%d]: ",i,dist[i],i);
		for (j = 0; j < tamCaminho; j++)
		{
			if (caminhos[i][j] == -1) break;
        	printf(" %d", caminhos[i][j]);
		}
		printf(" %d\n", i);
	}

    return 0;
}
