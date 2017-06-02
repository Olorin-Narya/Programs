import requests

endereco = "http://www.yahii.com.br/dolardiario"
tabela = range(2018-1985)
for i in range(1985,2018):
    
    print (str(i)[2:])
    
    tabela[i-1985-1] = range(12)
    
    endfinal = endereco + str(i)[2:] + ".html"
    page = requests.get(endfinal)
    
    for j in range(1,13):
        tabela[i-1985-1][j-1] = range(31)
        
        for h in range(1,32):
            tabela[i-1985-1][j-1][h-1] = range(2)

            print ("%02d" % (h)+"/"+"%02d" % (j)+"/"+str(i))
            inicio = page.text.find("%02d" % (h)+"/"+"%02d" % (j)+"/"+str(i))

            compra = page.text[inicio+83:inicio+90]
            venda = page.text[inicio+91+72:inicio+91+79]

            #try:
            if h > 1 :
                print (float(compra))
            tabela[i-1985-1][j-1][h-1][0] = compra
            tabela[i-1985-1][j-1][h-1][1] = venda
            #except ValueError:
            #    tabela[i-1985-1][j-1][h-1][0] = "Nao cotado"
            #    tabela[i-1985-1][j-1][h-1][1] = "Nao cotado"

            print (tabela[i-1985-1][j-1][h-1][0])
            print (tabela[i-1985-1][j-1][h-1][1])
