int **matriz;
int *dist;
int *marcados;

int menor(vertices){
    int i,menor=-1,d=10000000;

    for(i=0;i<vertices;i++){
        if(dist[i]<d && !marcados[i]){
            menor=i;
            break;
        }
    }

    if(menor!=-1){
        for(i=0;i<vertices;i++){
            if(dist[i]<dist[menor] && !marcados[i]) menor=i;
        }
    }
    return menor;
}

void Dijkstra(int inicio, int vertices){
   int i,j,atual;

   dist=malloc(sizeof(int)*vertices);
   marcados=malloc(sizeof(int)*vertices);

   dist[inicio]=0;
   marcados[inicio]=1;


   for(i=1;i<vertices;i++){
     marcados[i]=0;
    if(matriz[inicio][i]==0){
      dist[i]=1000; //INF
    }
    else{
      dist[i]=matriz[inicio][i];
  }
   }

   /*
   for(i=0;i<vertices;i++){
     printf("DIST[%d]= %d\n",i,dist[i]);
    }
 */

    while(menor(vertices)!=-1){

     atual=menor(vertices);
        //printf("EM %d:\n",atual);
     marcados[atual]=1;
     for(i=0;i<vertices;i++){
      //printf("DIST[%d]: %d\n DITANCIA RELATIVA[%d]: %d\n",i,dist[i],i,dist[atual]+matriz[atual][i]);
      if(matriz[atual][i]!=0 && marcados[i]==0){
       if(dist[atual]+matriz[atual][i]<dist[i]) {
        dist[i]=dist[atual]+matriz[atual][i];
      }
   }
     }
  for(i=0;i<vertices;i++){
     printf("DIST[%d]= %d\n",i,dist[i]);
     }
   }
}

int main()
{
    int i,j, valor;
    int inicio=0, prox=0, vertices;

 printf("Digite a quantidade de vertices?\n");
 scanf("%d",&vertices);

 printf("Qual o vertice inicial?\n");
 scanf("%d",&inicio);

 matriz = malloc(sizeof(int*)*vertices);
 for(i=0;i<vertices;i++){
  matriz[i]=malloc(sizeof(int)*vertices);
 }

    printf("Digite os valores da matriz para cada posicao (0 se nao existir): \n");
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            scanf("%d",&matriz[i][j]);
        }
    }

    Dijkstra(inicio, vertices);

    //printf("IMPRIMINDO O VETOR DE DISTANCIAS  A PARTIR DE %d:\n",inicio);
    for(i=0;i<vertices;i++){
        printf("Distancia[%d]: %d\n",i,dist[i]);
    }

    return 0;
}
