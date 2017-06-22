#include_<stdio.h>
#include_<stdlib.h>
#include_<string.h>
void_criaMatriz(int_***matriz,_int_*numAresta,_int_*vertices,_int_*tamanho){
____int_i,_j,_origem,_destino,_vertice,aresta,_raiz,_esq,_dir;
____*numAresta=0;_//conta__numero_de_arestas_a_partir_do_numero_de_relacionamento_enviado_no_arquivo_txt_3_coluna

____printf("Digite_a_quantidade_de_vertices:\n");
____scanf("%i",&vertice);
____*vertices=vertice;
____*tamanho=vertice;
____printf(">>>_%i_vertices_\n",_*vertices);


____FILE_*p=fopen("grafo.txt",_"r");_//abre_arquivo
____(*matriz)=(int**)malloc(*vertices_*_sizeof(int*));

______for(i=0;i<*vertices;i++){
________(*matriz)[i]=_(int*)_malloc(2*sizeof(int));
________for(j=0;j<2;j++){
____________(*matriz)[i][j]=0;
________}
____}
____while(fscanf(p,_"%i_%i_%i",_&raiz,_&esq,_&dir)!=EOF){_//mesmo_que_a_anterior_porem_quando_o_grafo_for_direcionado
________(*matriz)[raiz][0]=_esq;
________//printf("%d\n",_(*matriz)[raiz][0]);
________(*matriz)[raiz][1]=_dir;


____}


____fclose(p);


}


void_mostraMatriz(int_**matriz,_int_vertices){


____int_i,_j_,_raiz_,_esq_,_dir;
____//printf_(">>_mostra\n");
____//printf_(">>_mostra__%i_vertices\n",_vertices);

____//FILE_*p=_fopen("grafo.txt","r");


____for(i=0;i<vertices;i++){_//percorre_matriz_e_mostra
________for(j=0;j<2;j++){

_________________printf("%i_",matriz[i][j]);


________}printf("\n");
____}
//_____fclose(p);
}

void_preOrdem(int_**matriz,int_*ultimo,_int_*i,_int_*pai,_int_vertices,_int_*tamanho){_//raiz_esq_dir
____int_j;
_____//printando_a_raiz_principal

____printf("%i_|_",_*ultimo);
_____//printf("_i:_%i_|_",_*i);
_____//printf("_pai_:_%i_|_\n",_pai[*i]);


____for(j=0;j<*tamanho;j++){


__________//percorrendo_a_arvore_da_esquerda
___________if((matriz)[*ultimo][0]!=0){
________________(*i)++;
________________//printf("_esq_i:_%i\n",_*i);
________________pai[*i]=(matriz)[*ultimo][0];
________________*ultimo=(matriz)[*ultimo][0];
________________//_printf("_ultimo_%i_|_",_*ultimo);
________________(*tamanho)--;
________________preOrdem(matriz,_ultimo,_i,_pai,_vertices,_tamanho);




________________}else{//nao_tem_nenhum_filho
____________________//pai[*i]=NULL;

____________________//(*i)--;
____________________//printf("_i_modificado:_%i\n",_*i);
____________________*ultimo=(pai)[(*i)--];
___________________//_printf_(">>>>>>>>>>>>_i_%i\n",_*i);
____________________//printf_(">>>>>>>>>>>>__ultimo_%i\n",_*ultimo);
___________________//_printf_(">>>>>>>>>>>>_pai_%i\n",_pai[*i]);


____________________if((matriz)[*ultimo][1]!=0){//tem_o_filho_na_direita
________________________(*i)++;
________________________pai[*i]=(matriz)[*ultimo][1];
________________________*ultimo=(matriz)[*ultimo][1];
_________________________(*tamanho)--;
________________________preOrdem(matriz,_ultimo,_i,_pai,_vertices,_tamanho);

_______________}else{
____________________return_1;
_______________}
____}



____*tamanho=vertices;
____//return_1;
____}
}


void_posOrdem(int_**matriz,_int_*i,_int_*tamVet,_int_*percorrido,_int_*tamanho,_int_vertices,_int_*t){
____//esq_dir_raiz
____//printf(">>_pos\n");
____int_j,_k;

____________if(matriz[*i][0]!=0){_//percorrendo_filhos_da_esq


_______________//_printf("___t_%i\n",_*t);
________________printf("matriz_elemento_%i\n",_matriz[*i][0]);
________________percorrido[*t]=*i;
________________(*t)++;
_______________(percorrido)[*t]=(matriz)[*i][0];
________________(*tamVet)++;


_______________printf(">>>>>_percorrido_%i\n",_percorrido[*t]);_//vertices_que_ja_a_busca_ja_encontrou
_______________(*i)=(matriz)[*i][1];_//i_sera_a_posicao_na_matriz,_ou_seja,_ira_buscar_os_proximos_filhos_na_linha_da_matriz_do_filho_encontrado
_______________//(*tamanho)++;

_______________posOrdem(matriz,_i,_tamVet,_percorrido,_tamanho,vertices,_t);


____________}if(matriz[*i][1]!=0){_//nao_tem_na_esquerda_mas_tme_filho_a_direita
_______________//(percorrido)=_malloc(sizeof(int));
________________percorrido[*t]=*i;
________________(*t)++;
_______________(percorrido)[*t]=(matriz)[*i][0];
________________(*tamVet)++;


_______________printf(">>>>>_percorrido_%i\n",_percorrido[*t]);_//vertices_que_ja_a_busca_ja_encontrou
_______________(*i)=(matriz)[*i][1];

_______________posOrdem(matriz,_i,_tamVet,_percorrido,_tamanho,vertices,_t);

____________}else{_//acabaram_os_filhos,_vai_printar_a_ordem_e_retornar_na_arvore

_______________percorrido[*t]=*i;




____________________if(matriz[percorrido[*t]][1]!=0){
________________________(*i)--;
________________________posOrdem(matriz,i,_tamVet,_percorrido,_tamanho,_vertices,_t);


____________________}else{
________________________printf("_|_%i_\n",percorrido[*tamanho]);
________________________(*tamanho)--;
____________________}


___________}



____//pai[i]=0;
}


void_simetrico(){




}





int_main()
{

____int_*pai[10],_*percorrido,_tamVet=0;
____pai[0]=0;
____int_**matriz=NULL;
____int_vertices,_i=0,j,_escolha,_ultimo=0,_origem,_destino,_numAresta=0,_aresta,_entra=0,_entra2=0,_tamanho,_t=0;

____(percorrido)=_malloc(10*sizeof(int));

____//printf("\noi\n\n");



________do{
____________printf("\n1.Pre_Ordem_\n2.Simetrica\n3.Pos_Ordem\n0._Sair\n");
____________printf("Opcao:_");
____________scanf("\n%i",&escolha);

____________switch(escolha){
________________case_1:
____________________criaMatriz(&matriz,_&numAresta,_&vertices,_&tamanho);
____________________mostraMatriz(matriz,_vertices);

____________________preOrdem(matriz,&ultimo,_&i,_&pai,_vertices,_&tamanho);


________________break;
________________case_2:
____________________criaMatriz(&matriz,_&numAresta,_&vertices,_&tamanho);
__________________//_Simetrica();

________________break;
________________case_3:
____________________criaMatriz(&matriz,_&numAresta,_&vertices,_&tamanho);
____________________posOrdem(matriz,_&i,_&tamVet,_&percorrido,_&tamanho,_vertices,_&t);


________________break;
________________default:
________________return_0;
________________break;
__________}
________}while(escolha!=0);

____return_0;
}
