% CHEGAMOS AO FIM DO MODELO
% verde,juliano,pessoa,24,morango,costela
% amarela,bruno,barros,27,uva,cupim
% azul,samuel,lopes,30,limao,maminha
% vermelha,marcelo,teixeira,32,laranja,fraldinha
% branca,ivo,assis,22,maracuja,picanha
% FIM do imprime_lista
%  T1: 0.090027 	 T2: 8.827453  msec
%  Tempo total: 8.7374257000  msec
% SWISH Prolog online
% https://rachacuca.com.br/logica/problemas/churrasco-de-domingo/

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
modelo([ (Camiseta1, Nome1, Sobre1, I1, Suco1, Carne1),
         (Camiseta2, Nome2, Sobre2, I2, Suco2, Carne2),
         (Camiseta3, Nome3, Sobre3, I3, Suco3, Carne3),
         (Camiseta4, Nome4, Sobre4, I4, Suco4, Carne4),
         (Camiseta5, Nome5, Sobre5, I5, Suco5, Carne5)
       ]) :-

    %%%%%%%%%%%%%%%%%%%%%%%% CAMISETA
    camiseta(Camiseta1),
    camiseta(Camiseta2),
    camiseta(Camiseta3),
    camiseta(Camiseta4),
    camiseta(Camiseta5),

    alldifferent([Camiseta1,Camiseta2,Camiseta3,Camiseta4,Camiseta5]),

    % O rapaz de camiseta Verde está em algum lugar à esquerda do rapaz de camiseta Branca.
    (
    (Camiseta1==verde, Camiseta2==branca);
    (Camiseta1==verde, Camiseta3==branca);
    (Camiseta1==verde, Camiseta4==branca);
    (Camiseta1==verde, Camiseta5==branca);
    (Camiseta2==verde, Camiseta3==branca);
    (Camiseta2==verde, Camiseta4==branca);
    (Camiseta2==verde, Camiseta5==branca);
    (Camiseta3==verde, Camiseta4==branca);
    (Camiseta3==verde, Camiseta5==branca);
    (Camiseta4==verde, Camiseta5==branca)
    ),


    %%%%%%%%%%%%%%%%%%%%%%%% IDADE
    idade(I1),
    idade(I2),
    idade(I3),
    idade(I4),
    idade(I5),

    alldifferent([I1,I2,I3,I4,I5]),

    % O amigo mais velho está usando uma camiseta Vermelha.
    (
    (I1==32, Camiseta1==vermelha);
    (I2==32, Camiseta2==vermelha);
    (I3==32, Camiseta3==vermelha);
    (I4==32, Camiseta4==vermelha);
    (I5==32, Camiseta5==vermelha)
    ),

    %%%%%%%%%%%%%%%%%%%%%%%% NOME
    nome(Nome1),
    nome(Nome2),
    nome(Nome3),
    nome(Nome4),
    nome(Nome5),
    alldifferent([Nome1,Nome2,Nome3,Nome4,Nome5]),

    % Ivo está em uma das pontas.
    (
    (Nome1==ivo);
    (Nome5==ivo)
    ),

    % Marcelo está em algum lugar à direita do rapaz de camiseta Azul.
    (
    (Camiseta1==azul, Nome2==marcelo);
    (Camiseta1==azul, Nome3==marcelo);
    (Camiseta1==azul, Nome4==marcelo);
    (Camiseta1==azul, Nome5==marcelo);
    (Camiseta2==azul, Nome3==marcelo);
    (Camiseta2==azul, Nome4==marcelo);
    (Camiseta2==azul, Nome5==marcelo);
    (Camiseta3==azul, Nome4==marcelo);
    (Camiseta3==azul, Nome5==marcelo);
    (Camiseta4==azul, Nome5==marcelo)
    ),

    % Bruno está em algum lugar entre o amigo de 24 anos e o Samuel, nessa ordem.
    (
    (I1==24, Nome5==samuel, Nome2==bruno);
    (I1==24, Nome5==samuel, Nome3==bruno);
    (I1==24, Nome5==samuel, Nome4==bruno);
    (I1==24, Nome4==samuel, Nome2==bruno);
    (I1==24, Nome4==samuel, Nome3==bruno);
    (I1==24, Nome3==samuel, Nome2==bruno);
    (I2==24, Nome5==samuel, Nome3==bruno);
    (I2==24, Nome5==samuel, Nome4==bruno);
    (I2==24, Nome4==samuel, Nome3==bruno);
    (I3==24, Nome5==samuel, Nome4==bruno)
    ),

    %%%%%%%%%%%%%%%%%%%%%%%% SUCO
    suco(Suco1),
    suco(Suco2),
    suco(Suco3),
    suco(Suco4),
    suco(Suco5),

    alldifferent([Suco1,Suco2,Suco3,Suco4,Suco5]),

    % Na terceira posição está o homem que gosta de suco de Limão.
    (Suco3==limao),

    % O amigo que gosta de suco de Morango está em uma das pontas.
    (
    (Suco1==morango);
    (Suco5==morango)
    ),

    % O rapaz que gosta de suco de Laranja está em algum lugar entre quem está de camiseta Amarela e quem gosta de suco de Maracujá, nessa ordem.
    (
    (Camiseta1==amarela, Suco5==maracuja, Suco2==laranja);
    (Camiseta1==amarela, Suco5==maracuja, Suco4==laranja);
    (Camiseta1==amarela, Suco5==maracuja, Suco3==laranja);
    (Camiseta1==amarela, Suco4==maracuja, Suco2==laranja);
    (Camiseta1==amarela, Suco4==maracuja, Suco3==laranja);
    (Camiseta1==amarela, Suco3==maracuja, Suco2==laranja);
    (Camiseta2==amarela, Suco5==maracuja, Suco4==laranja);
    (Camiseta2==amarela, Suco5==maracuja, Suco3==laranja);
    (Camiseta2==amarela, Suco4==maracuja, Suco3==laranja);
    (Camiseta3==amarela, Suco5==maracuja, Suco4==laranja)
    ),

    % O homem de 30 anos está em algum lugar entre quem gosta de suco de Uva e quem tem 32 anos, nessa ordem.
    (
    (Suco1==uva, I5==32, I2==30);
    (Suco1==uva, I5==32, I4==30);
    (Suco1==uva, I5==32, I3==30);
    (Suco1==uva, I4==32, I2==30);
    (Suco1==uva, I4==32, I3==30);
    (Suco1==uva, I3==32, I2==30);
    (Suco2==uva, I5==32, I4==30);
    (Suco2==uva, I5==32, I3==30);
    (Suco2==uva, I4==32, I3==30);
    (Suco3==uva, I5==32, I4==30)
    ),

    %%%%%%%%%%%%%%%%%%%%%%%% CARNE
    carne(Carne1),
    carne(Carne2),
    carne(Carne3),
    carne(Carne4),
    carne(Carne5),

    alldifferent([Carne1,Carne2,Carne3,Carne4,Carne5]),

    % Em uma das pontas está o rapaz que gosta de Picanha.
    (
    (Carne1==picanha);
    (Carne5==picanha)
    ),

    % Quem gosta de Cupim está em algum lugar entre quem gosta de Costela e quem gosta de Fraldinha, nessa ordem.
    (
    (Carne1==costela, Carne5==fraldinha, Carne2==cupim);
    (Carne1==costela, Carne5==fraldinha, Carne4==cupim);
    (Carne1==costela, Carne5==fraldinha, Carne3==cupim);
    (Carne1==costela, Carne4==fraldinha, Carne2==cupim);
    (Carne1==costela, Carne4==fraldinha, Carne3==cupim);
    (Carne1==costela, Carne3==fraldinha, Carne2==cupim);
    (Carne2==costela, Carne5==fraldinha, Carne4==cupim);
    (Carne2==costela, Carne5==fraldinha, Carne3==cupim);
    (Carne2==costela, Carne4==fraldinha, Carne3==cupim);
    (Carne3==costela, Carne5==fraldinha, Carne4==cupim)
    ),

    % O homem de 32 anos gosta de Fraldinha.
    (
    (Carne1==fraldinha, I1==32);
    (Carne2==fraldinha, I2==32);
    (Carne3==fraldinha, I3==32);
    (Carne4==fraldinha, I4==32);
    (Carne5==fraldinha, I5==32)
    ),

    % O homem que gosta de Maminha gosta de suco de Limão.
    (
    (Carne1==maminha, Suco1==limao);
    (Carne2==maminha, Suco2==limao);
    (Carne3==maminha, Suco3==limao);
    (Carne4==maminha, Suco4==limao);
    (Carne5==maminha, Suco5==limao)
    ),

    % O homem de 27 anos está em algum lugar entre quem gosta de Costela e quem tem 32 anos, nessa ordem.
    (
    (Carne1==costela, I5==32, I2==27);
    (Carne1==costela, I5==32, I4==27);
    (Carne1==costela, I5==32, I3==27);
    (Carne1==costela, I4==32, I2==27);
    (Carne1==costela, I4==32, I3==27);
    (Carne1==costela, I3==32, I2==27);
    (Carne2==costela, I5==32, I4==27);
    (Carne2==costela, I5==32, I3==27);
    (Carne2==costela, I4==32, I3==27);
    (Carne3==costela, I5==32, I4==27)
    ),

    % O rapaz da camiseta Amarela está em algum lugar entre quem gosta de Costela e quem está com a camiseta Azul, nessa ordem.
    (
    (Carne1==costela, Camiseta5==azul, Camiseta2==amarela);
    (Carne1==costela, Camiseta5==azul, Camiseta4==amarela);
    (Carne1==costela, Camiseta5==azul, Camiseta3==amarela);
    (Carne1==costela, Camiseta4==azul, Camiseta2==amarela);
    (Carne1==costela, Camiseta4==azul, Camiseta3==amarela);
    (Carne1==costela, Camiseta3==azul, Camiseta2==amarela);
    (Carne2==costela, Camiseta5==azul, Camiseta4==amarela);
    (Carne2==costela, Camiseta5==azul, Camiseta3==amarela);
    (Carne2==costela, Camiseta4==azul, Camiseta3==amarela);
    (Carne3==costela, Camiseta5==azul, Camiseta4==amarela)
    ),

    % O homem de camiseta Amarela está em algum lugar entre quem gosta de suco de Morango e quem gosta de Picanha, nessa ordem.
    (
    (Suco1==morango, Carne5==picanha, Camiseta2==amarela);
    (Suco1==morango, Carne5==picanha, Camiseta4==amarela);
    (Suco1==morango, Carne5==picanha, Camiseta3==amarela);
    (Suco1==morango, Carne4==picanha, Camiseta2==amarela);
    (Suco1==morango, Carne4==picanha, Camiseta3==amarela);
    (Suco1==morango, Carne3==picanha, Camiseta2==amarela);
    (Suco2==morango, Carne5==picanha, Camiseta4==amarela);
    (Suco2==morango, Carne5==picanha, Camiseta3==amarela);
    (Suco2==morango, Carne4==picanha, Camiseta3==amarela);
    (Suco3==morango, Carne5==picanha, Camiseta4==amarela)
    ),

    %%%%%%%%%%%%%%%%%%%%%%%% SOBRENOME
    sobrenome(Sobre1),
    sobrenome(Sobre2),
    sobrenome(Sobre3),
    sobrenome(Sobre4),
    sobrenome(Sobre5),

    alldifferent([Sobre1,Sobre2,Sobre3,Sobre4,Sobre5]),

    % Lopes está exatamente à esquerda de quem gosta de suco de Laranja.
    (
    (Sobre1==lopes, Suco2==laranja);
    (Sobre2==lopes, Suco3==laranja);
    (Sobre3==lopes, Suco4==laranja);
    (Sobre4==lopes, Suco5==laranja)
    ),

    % Assis está ao lado de quem gosta de suco de Laranja.
    (
    (Sobre1==assis, Suco2==laranja);
    (Sobre2==assis, Suco1==laranja);
    (Sobre2==assis, Suco3==laranja);
    (Sobre3==assis, Suco2==laranja);
    (Sobre3==assis, Suco4==laranja);
    (Sobre4==assis, Suco3==laranja);
    (Sobre4==assis, Suco5==laranja);
    (Sobre5==assis, Suco4==laranja)
    ),

    % Teixeira está em algum lugar à direita do homem de camiseta Amarela.
    (
    (Camiseta1==amarela, Sobre2==teixeira);
    (Camiseta1==amarela, Sobre3==teixeira);
    (Camiseta1==amarela, Sobre4==teixeira);
    (Camiseta1==amarela, Sobre5==teixeira);
    (Camiseta2==amarela, Sobre3==teixeira);
    (Camiseta2==amarela, Sobre4==teixeira);
    (Camiseta2==amarela, Sobre5==teixeira);
    (Camiseta3==amarela, Sobre4==teixeira);
    (Camiseta3==amarela, Sobre5==teixeira);
    (Camiseta4==amarela, Sobre5==teixeira)
    ),

    % Lopes e Teixeira estão lado a lado.
    (
    (Sobre1==lopes, Sobre2==teixeira);
    (Sobre2==lopes, Sobre1==teixeira);
    (Sobre2==lopes, Sobre3==teixeira);
    (Sobre3==lopes, Sobre2==teixeira);
    (Sobre3==lopes, Sobre4==teixeira);
    (Sobre4==lopes, Sobre3==teixeira);
    (Sobre4==lopes, Sobre5==teixeira);
    (Sobre5==lopes, Sobre4==teixeira)
    ),

    % O homem de camiseta Amarela está em algum lugar entre Pessoa e Ivo, nessa ordem.
    (
    (Sobre1==pessoa, Nome5==ivo, Camiseta2==amarela);
    (Sobre1==pessoa, Nome5==ivo, Camiseta4==amarela);
    (Sobre1==pessoa, Nome5==ivo, Camiseta3==amarela);
    (Sobre1==pessoa, Nome4==ivo, Camiseta2==amarela);
    (Sobre1==pessoa, Nome4==ivo, Camiseta3==amarela);
    (Sobre1==pessoa, Nome3==ivo, Camiseta2==amarela);
    (Sobre2==pessoa, Nome5==ivo, Camiseta4==amarela);
    (Sobre2==pessoa, Nome5==ivo, Camiseta3==amarela);
    (Sobre2==pessoa, Nome4==ivo, Camiseta3==amarela);
    (Sobre3==pessoa, Nome5==ivo, Camiseta4==amarela)
    ),

    % O homem da camiseta Amarela está em algum lugar entre Pessoa e quem tem 22 anos, nessa ordem.
    (
    (Sobre1==pessoa, I5==22, Camiseta2==amarela);
    (Sobre1==pessoa, I5==22, Camiseta4==amarela);
    (Sobre1==pessoa, I5==22, Camiseta3==amarela);
    (Sobre1==pessoa, I4==22, Camiseta2==amarela);
    (Sobre1==pessoa, I4==22, Camiseta3==amarela);
    (Sobre1==pessoa, I3==22, Camiseta2==amarela);
    (Sobre2==pessoa, I5==22, Camiseta4==amarela);
    (Sobre2==pessoa, I5==22, Camiseta3==amarela);
    (Sobre2==pessoa, I4==22, Camiseta3==amarela);
    (Sobre3==pessoa, I5==22, Camiseta4==amarela)
    ),

    % Barros está em algum lugar entre quem gosta de suco de Morango e quem gosta de Fraldinha, nessa ordem.
    (
    (Suco1==morango, Carne5==fraldinha, Sobre2==barros);
    (Suco1==morango, Carne5==fraldinha, Sobre4==barros);
    (Suco1==morango, Carne5==fraldinha, Sobre3==barros);
    (Suco1==morango, Carne4==fraldinha, Sobre2==barros);
    (Suco1==morango, Carne4==fraldinha, Sobre3==barros);
    (Suco1==morango, Carne3==fraldinha, Sobre2==barros);
    (Suco2==morango, Carne5==fraldinha, Sobre4==barros);
    (Suco2==morango, Carne5==fraldinha, Sobre3==barros);
    (Suco2==morango, Carne4==fraldinha, Sobre3==barros);
    (Suco3==morango, Carne5==fraldinha, Sobre4==barros)
    ),

    nl,

    write('CHEGAMOS AO FIM DO MODELO')

    . %%% <== NAO ESQUECA O PONTO FINAL

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%BASE DE DADOS%%%%

    %CAMISETAS
    camiseta(amarela).
    camiseta(azul).
    camiseta(branca).
    camiseta(verde).
    camiseta(vermelha).

    %IDADES
    idade(22).
    idade(24).
    idade(27).
    idade(30).
    idade(32).

    %NOMES
    nome(bruno).
    nome(ivo).
    nome(juliano).
    nome(marcelo).
    nome(samuel).

    %SUCO
    suco(laranja).
    suco(limao).
    suco(maracuja).
    suco(morango).
    suco(uva).

    %CARNE
    carne(costela).
    carne(cupim).
    carne(fraldinha).
    carne(maminha).
    carne(picanha).

    %SOBRENOME
    sobrenome(assis).
    sobrenome(barros).
    sobrenome(lopes).
    sobrenome(pessoa).
    sobrenome(teixeira).

% DEFINICAO DE ALLDIFERENT
	alldifferent([]).
	alldifferent([H|T]):- not(member(H,T)),
	                      alldifferent(T).
	imprime_lista([]):- nl, write(' FIM do imprime_lista ').
	imprime_lista([H|T]):- nl, write(H), imprime_lista(T).

/**********************************************************/
