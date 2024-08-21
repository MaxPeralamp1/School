import math
def summa(luvut):
    parittomat = []
    for i in luvut:
        if i % 2 == 0:
            parittomat.append(i)
    return parittomat, luvut

lista = [5,5,2]
summa1 = summa(lista)

print(summa1)
