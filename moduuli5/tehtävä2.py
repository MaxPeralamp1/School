luku = input("Kerro ensimmäinen luku: ")
lista = []

while luku != '':
    lista.append(luku)
    luku = input("Kerro luku: ")

lista.sort(reverse=True)
print(lista[:5])