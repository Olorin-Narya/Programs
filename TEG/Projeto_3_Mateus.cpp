#include_<stdio.h>
#include_<stdlib.h>

/*
__
0_4_0_2
4_0_5_1
0_5_0_3
2_1_3_0

=======

0_5_0_3
5_0_2_1
2_0_0_8
3_1_8_0

========

0_1_3_0_0
1_0_5_10_0
3_5_0_9_7
0_10_9_0_4
0_0_7_4_0

*/

int_**matriz;
int_*dist;
int_*marcados;
int__**_caminho;
int_segundaVez_=_0;

void_limpaCaminho_(int_*caminho,_int_vertices)_{
	int_i;
	for_(i_=_0;_i_<_(vertices_+_1);_i++)_{
__	____caminho[i]_=_-1;
____}
}

int_menor(int_vertices){
____int_i,_menor_=_-1;
____
____//algum_vértice_ainda_não_relaxado?
____for_(i_=_0;_i_<_vertices;_i++){
________if_(!marcados[i]){
____________menor_=_i;
____________break;
________}
____}
____
____//se_alguém_não_tenha_sido_relaxado,_vamos_relaxar
____if_(menor_!=_-1)_{
________for_(i_=_0;_i_<_vertices;_i++){
____________if_((dist[i]_<_dist[menor])_&&_!(marcados[i]))_{
________________menor_=_i;
____________}
________}
____}
____return_menor;
}

void_Dijkstra(int_inicio,_int_vertices){
____int_i,j,atual;

____//Não_posso_alocar_mais_memoria,_sendo_que_nem_dei_free_da_primeira_vez
____if_(!segundaVez)_{
________dist_____=_malloc(sizeof(int)_*_vertices);
________marcados_=_malloc(sizeof(int)_*_vertices);
________caminho__=_(int_**)_malloc(sizeof(int_**)_*_vertices);
____}

____//alimentando_as_distancias
____for_(i_=_0;_i_<_vertices;_i++){
________if_(!segundaVez)_{
____________caminho[i]__=_(int_*)_malloc(sizeof(int)_*_(vertices+1));
________}
________
________//limpando_vetores
________marcados[i]_=_0;
________limpaCaminho(caminho[i],_vertices);
________
________//Os_caminhos_começam_pelo_inicio
________caminho[i][0]_=_inicio;

________if_(i_==_inicio)_{
____________//Distancia_para_o_vertice_de_inicio_é_0
____________dist[i]_=_0;
____________marcados[i]_=_1;
____________continue;
________}

________if_(matriz[inicio][i]_==_0){
____________dist[i]_=_99999999;_____//"Infinito"
________}
________else_{
____________dist[i]_=_matriz[inicio][i];
____________//caminhando_do_inicio_para_os_primeiros_vertices
____________caminho[i][1]_=_i;
________}
____}

____while_(menor(vertices)_!=_-1)_{
________atual_=_menor(vertices);
________marcados[atual]_=_1;
________for_(i_=_0;_i_<_vertices;_i++)_{
____________if_(matriz[atual][i]_!=_0_&&_!marcados[i])_{
________________if_(dist[atual]_+_matriz[atual][i]_<_dist[i])_{
____________________dist[i]_=_dist[atual]_+_matriz[atual][i];

____________________limpaCaminho(caminho[i],vertices);
____________________for_(j_=_0;_j_<_(vertices_+_1);_j++)_{
____________________	if_(caminho[atual][j]_==_-1)_{
____________________		caminho[i][j]_=_i;
____________________		break;
____________________	}
____________________	else_{
	___________________	____caminho[i][j]_=_caminho[atual][j];
	___________________	}
____________________}
________________}
____________}
________}
____}
}

int_main()
{
____int_i,_j,_k;
____int_inicio,_destino,_vertices,_inicioAresta,_custo;
____int_linha,_coluna,_peso,_x;

____FILE_*p=fopen("oi.txt",_"r");

____if_(!p)_{
________printf("Erro_com_o_arquivo\n");
________return_1;
____}

____fscanf(p,_"%i_%i",_&vertices,_&x);
____matriz_=_malloc(sizeof(int*)_*_vertices);
____for_(i_=_0;_i_<_vertices;_i++){
________matriz[i]_=_malloc(sizeof(int)_*_vertices);
____}

____for_(i_=_0;_i_<_vertices;_i++){
________for(j_=_0;_j_<_vertices;_j++){
____________(matriz)[i][j]_=_0;
________}
____}

____//INICIALIZANDO_A_MATRIZ_COM_ARQUIVO_TXT
____fscanf(p,_"%i_%i",_&inicio,_&destino);
____while_(fscanf(p,_"%i_%i_%i",_&linha,_&coluna,_&peso)_!=_EOF)_{
________matriz[linha][coluna]_=_peso;
____}

____printf(">>>>>>>>>_MATRIZ:_\n");
____for(i_=_0;_i_<_vertices;_i++){
________for(j_=_0;_j_<_vertices;_j++){
____________printf("_%i",_matriz[i][j]);
________}
________printf("\n");
____}
____Dijkstra(inicio,_vertices);

____printf("1_IMPRIMINDO_O_VETOR_DE_DISTANCIAS_A_PARTIR_DE_%d:\n",inicio);
____for_(i_=_0;_i_<_vertices;_i++)_{
____	printf("Distância[%d]:_%d_\tCaminho[%d]_=_%d",_i,_dist[i],_i,_caminho[i][0]);
____	for_(j_=_1;_j_<_vertices;_j++)_{
____		if_(caminho[i][j]_!=_-1)_{
		________printf("-%d",_caminho[i][j]);
		____}
		}
		printf("\n");
____}

____custo_=_dist[destino];
____printf("Custo_total_para_o_destino_%d\n",dist[destino]);

____segundaVez++;

____while_(custo_==_dist[destino])_{
________inicioAresta_=_inicio;
________for_(i_=_0;_i_<_vertices;_i++)_{
____________for_(j_=_0;_j_<_vertices;_j++)_{
________________for_(k_=_0;_k_<_(vertices+1);_k++)_{
____________________if_(caminho[destino][k]_!=_-1)_{
	____________________matriz[inicioAresta][caminho[destino][k]]_=_0;
________________________inicioAresta_=_caminho[destino][k];
____________________}
________________}
____________}
________}
________Dijkstra(inicio,_vertices);
____}

____printf(">>>>>>>>>_MATRIZ_2:_\n");
____for(i_=_0;_i_<_vertices;_i++){
________for(j_=_0;_j_<_vertices;_j++){
____________printf("_%i",_matriz[i][j]);
________}
________printf("\n");
____}

____printf("2_IMPRIMINDO_O_VETOR_DE_DISTANCIAS_A_PARTIR_DE_%d:\n",inicio);
____for_(i_=_0;_i_<_vertices;_i++)_{
____	printf("Distância[%d]:_%d_\tCaminho[%d]_=_%d",_i,_dist[i],_i,_caminho[i][0]);
____	for_(j_=_1;_j_<_vertices;_j++)_{
____		if_(caminho[i][j]_!=_-1)_{
		________printf("-%d",_caminho[i][j]);
		____}
		}
________printf("\n");
____}
____printf("Custo_total_para_o_destino_%d\n",dist[destino]);

____return_0;
}
