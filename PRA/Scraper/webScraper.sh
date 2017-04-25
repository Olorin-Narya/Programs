#!/bin/bash

diariamente(year)
{
    for ( i = 01; i <= 12; i++); do
        for (j = 01; j<= 31; j++); do
            cat dolardiario$( echo $ano | cut -c3- ).html | grep j/i/$ano -A 2 > ./www.yahii.com.br/dia.txt
            if [[  == 0 ]]; then
                cat dolardiario$( echo $ano | cut -c3- ).html | grep , | cut -d ">"
            fi
        done
    done
}

popular(ano)
{
    cd www.yahii*
    diariamente(ano)
}

mkdir -p data
cd ./data
for ( i = 1983; i <= 2017; i++ ); do
    echo "Downloading year $i."$'.\n'
    wget -q -l5 -x http://www.yahii.com.br/dolardiario$( echo $i | cut -c3- ).html
    echo "Estrutruturando dados."$'\n'
    popular(i);
done
