#include<stdlib.h>
#include<stdio.h>
void ciclo(int atual, int marcado);
int funcMarcado(int marcado, int i);

int matriz[15][15] = {
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
    {  3,  4,  5,  7, 10,  6, 11, 15,  9, 000, 10, 7,  7,  5,  2}, // 9
    {  9, 20, 13, 15,  8,  3,  4,  7,  4,  10,000, 4,  4,  8, 11}, // 10

    {  4, 10, 10, 11,  7,  2,  5,  7,  3,  7,  4,000,  3,  5,  8}, // 11
    {  3, 12, 10, 14, 11,  5,  7, 12,  6,  7,  4,  3,000,  4,  7}, // 12
    {  3,  9,  9, 13, 12,  7,  9, 13,  9,  5,  8,  5,  4,000,  4}, // 13
    {  5,  8,  9, 12, 13,  9, 12, 17, 14,  2, 11,  8,  7,  4,000}, // 14
    };

    int vertice[15];

int main(){
    int i;

    for(i = 0; i < 15; i++){
        vertice[i] = 0;
    }

    ciclo( 0, 0);
    for(i = 0; i < 15; i++){
        printf("vertice[%d] = %d\n", i, vertice[i]);
    }
    return 0;
}

void ciclo(int atual, int marcado){

    int i, j = 0;
    int menorV = 9999999, menorI;
    vertice[marcado] = atual;
    marcado++;
    for(i = 0; i < 15; i++){
        if(matriz[atual][i] < menorV && funcMarcado(marcado, i) == 0){
            menorV = matriz[atual][i];
            menorI = i;
        }
    }
    if(menorV != 9999999) {
        ciclo(menorI, marcado);
    }
}

int funcMarcado(int marcado, int i){
    int j;

    for(j = 0; j < marcado; j++){
        if(vertice[j] == i){
            return 1;
        }
    }
    return 0;
}
