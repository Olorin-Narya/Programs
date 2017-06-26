% CHEGAMOS AO FIM DO MODELO
% amarelo,peraltas,arthur,0,27,420
% vermelho,fenix,marcio,1,23,410
% branco,biz,oscar,3,25,400
% verde,tratores,juliano,4,26,390
% azul,supinos,carlos,2,24,380
% FIM do imprime_lista
%  T1: 0.056601 	 T2: 1.650411  msec
%  Tempo total: 1.5938100990  msec
% SWISH Prolog online
% https://rachacuca.com.br/logica/problemas/campeonato-de-boliche/

main :-
   %% Tempo inicial
    statistics(cputime,T1),

    modelo( [A1, A2, A3, A4, A5] ),
    imprime_lista( [A1, A2, A3, A4, A5] ),

    %% Tempo final
    statistics(cputime ,T2),
    Tempo_BUSCA is T2 - T1,
    format('\n T1: ~f \t T2: ~f  msec', [T1, T2]),
    format('\n Tempo total: ~10f  msec', Tempo_BUSCA).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
modelo([ (U1, E1, C1, S1, I1, P1),
         (U2, E2, C2, S2, I2, P2),
         (U3, E3, C3, S3, I3, P3),
         (U4, E4, C4, S4, I4, P4),
         (U5, E5, C5, S5, I5, P5)
       ]) :-

    %%%%%%%%%%%%%%%%%%%%%%%% UNIFORME
    uniforme(U1),
    uniforme(U2),
    uniforme(U3),
    uniforme(U4),
    uniforme(U5),

    alldifferent([U1,U2,U3,U4,U5]),

    %A equipe de Branco est� exatamente � esquerda da equipe de Verde.
    (
    (U1==branco, U2==verde);
    (U2==branco, U3==verde);
    (U3==branco, U4==verde);
    (U4==branco, U5==verde)
    ),

    %As equipes verde e azul est�o lado a lado.
    (
    (U1==azul, U2==verde);
    (U1==verde, U2==azul);
    (U2==verde, U3==azul);
    (U2==azul, U3==verde);
    (U3==verde, U4==azul);
    (U3==azul, U4==verde);
    (U4==verde, U5==azul);
    (U4==azul, U5==verde)
	),

    %%%%%%%%%%%%%%%%%%%%%%%% EQUIPE
    equipe(E1),
    equipe(E2),
    equipe(E3),
    equipe(E4),
    equipe(E5),
    alldifferent([E1,E2,E3,E4,E5]),

    %%%%%%%%%%%%%%%%%%%%%%%% CAPITAES
    capitao(C1),
    capitao(C2),
    capitao(C3),
    capitao(C4),
    capitao(C5),

    alldifferent([C1,C2,C3,C4,C5]),

    %A equipe de Carlos est� na quinta posi��o.
    (C5==carlos),

    %M�rcio � o capit�o da equipe Fenix.
    (
    (C1==marcio, E1==fenix);
    (C2==marcio, E2==fenix);
    (C3==marcio, E3==fenix);
    (C4==marcio, E4==fenix);
    (C5==marcio, E5==fenix)
    ),

    %A equipe do Juliano est� exatamente � direita da equipe do Oscar.
    (
    (C1==oscar, C2==juliano);
    (C2==oscar, C3==juliano);
    (C3==oscar, C4==juliano);
    (C4==oscar, C5==juliano)
    ),


    %%%%%%%%%%%%%%%%%%%%%%%% STRIKES
    strikes(S1),
    strikes(S2),
    strikes(S3),
    strikes(S4),
    strikes(S5),

    alldifferent([S1,S2,S3,S4,S5]),

    %A equipe Fenix est� ao lado da equipe que fez 3 strikes.
    (
    (E1==fenix, S2==3);
    (E2==fenix, S1==3);
    (E2==fenix, S3==3);
    (E3==fenix, S2==3);
    (E3==fenix, S4==3);
    (E4==fenix, S3==3);
    (E4==fenix, S5==3);
    (E5==fenix, S4==3)
	),

    %Os Peraltas ainda n�o fizeram Strike.
    (
    (E1==peraltas, S1==0);
    (E2==peraltas, S2==0);
    (E3==peraltas, S3==0);
    (E4==peraltas, S4==0);
    (E5==peraltas, S5==0)
    ),

    %Os Tratores estão ao lado da equipe que fez 2 strikes.
    (
    (E1==tratores, S2==2);
    (E2==tratores, S1==2);
    (E2==tratores, S3==2);
    (E3==tratores, S2==2);
    (E3==tratores, S4==2);
    (E4==tratores, S3==2);
    (E4==tratores, S5==2);
    (E5==tratores, S4==2)
    ),

    %A equipe com 1 strike est� exatamente � esquerda da equipe 14 Biz.
    (
    (S1==1, E2==biz);
    (S2==1, E3==biz);
    (S3==1, E4==biz);
    (S4==1, E5==biz)
    ),
    %%%%%%%%%%%%%%%%%%%%%%%% IDADE
    idade(I1),
    idade(I2),
    idade(I3),
    idade(I4),
    idade(I5),

    alldifferent([I1,I2,I3,I4,I5]),

    %Na terceira posi��o est� a equipe do capit�o de 25 anos
    (I3==25),

    %Oscar est� exatamente � direita da equipe do capit�o mais novo.
    (
    (I1==23, C2==oscar);
    (I2==23, C3==oscar);
    (I3==23, C4==oscar);
    (I4==23, C5==oscar)
    ),

    %O capit�o mais novo est� na equipe de uniforme Vermelho.
    (
    (I1==23, U1==vermelho);
    (I2==23, U2==vermelho);
    (I3==23, U3==vermelho);
    (I4==23, U4==vermelho);
    (I5==23, U5==vermelho)
	),

    %A equipe Vermelha est� em algum lugar entre a equipe do
    %capit�o mais velho e a equipe com mais Strikes, nessa ordem.
    (
    (I1==27, S5==4, U2==vermelho);
    (I1==27, S5==4, U4==vermelho);
    (I1==27, S5==4, U3==vermelho);
    (I1==27, S4==4, U2==vermelho);
    (I1==27, S4==4, U3==vermelho);
    (I1==27, S3==4, U2==vermelho);
    (I2==27, S5==4, U4==vermelho);
    (I2==27, S5==4, U3==vermelho);
    (I2==27, S4==4, U3==vermelho);
    (I3==27, S5==4, U4==vermelho)
    ),

    %%%%%%%%%%%%%%%%%%%%%%%% PONTUACAO
    pontuacao(P1),
    pontuacao(P2),
    pontuacao(P3),
    pontuacao(P4),
    pontuacao(P5),

    alldifferent([P1,P2,P3,P4,P5]),

	%Na segunda posi��o est� a equipe com 410 pontos.
    (P2==410),

    %Oscar est� na equipe que tem 400 pontos.
    (
    (C1==oscar, P1==400);
    (C2==oscar, P2==400);
    (C3==oscar, P3==400);
    (C4==oscar, P4==400);
    (C5==oscar, P5==400)
	),
    %O capit�o de 26 anos est� na equipe que tem 390 pontos.
    (
	(I1==26, P1==390);
    (I4==26, P4==390);
    (I5==26, P5==390);
    (I2==26, P2==390);
    (I3==26, P3==390)
	),
    %A equipe com 390 pontos est� exatamente � direita da equipe que fez 3 strikes.
    (
    (S2==3, P3==390);
    (S3==3, P4==390);
    (S4==3, P5==390);
    (S1\==3)
    ),

    %A equipe com 390 pontos est� exatamente � esquerda da equipe Azul.
    (
    (P1==390, U2==azul);
    (P3==390, U4==azul);
    (P4==390, U5==azul);
    (P2==390, U3==azul)
	),
    %A equipe com 4 strikes est� exatamente � esquerda da que tem 380 pontos.
    (
    (S2==4, P3==380);
    (S3==4, P4==380);
    (S4==4, P5==380);
    (S1==4, P2==380)
    ),

    %A equipe que fez 1 strike est� ao lado da equipe que tem 400 pontos.
    (
    (S1==1, P2==400);
    (S2==1, P1==400);
    (S2==1, P3==400);
    (S3==1, P4==400);
    (S4==1, P3==400);
    (S4==1, P5==400);
    (S5==1, P4==400)
    ),

    nl,

    write('CHEGAMOS AO FIM DO MODELO')

    . %%% <== NAO ESQUECA O PONTO FINAL

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%BASE DE DADOS%%%%

    %UNIFORMES
    uniforme(amarelo).
    uniforme(azul).
    uniforme(branco).
    uniforme(verde).
    uniforme(vermelho).

    %EQUIPES
    equipe(biz).
    equipe(fenix).
    equipe(peraltas).
    equipe(supinos).
    equipe(tratores).

    %CAPITAO
    capitao(arthur).
    capitao(carlos).
    capitao(juliano).
    capitao(marcio).
    capitao(oscar).

    %STRIKES
    strikes(0).
    strikes(1).
    strikes(2).
    strikes(3).
    strikes(4).

    %IDADES
    idade(23).
    idade(24).
    idade(25).
    idade(26).
    idade(27).

    %PONTUACAO
    pontuacao(380).
    pontuacao(390).
    pontuacao(400).
    pontuacao(410).
    pontuacao(420).

% DEFINICAO DE ALLDIFERENT
	alldifferent([]).
	alldifferent([H|T]):- not(member(H,T)),
	                      alldifferent(T).
	imprime_lista([]):- nl, write(' FIM do imprime_lista ').
	imprime_lista([H|T]):- nl, write(H), imprime_lista(T).

/**********************************************************/
