luku = input("Anna luku: ")
pienin = 1
suurin = 0

while True:
    if luku == '':
        break
    if pienin >= int(luku):
        pienin = int(luku)
    elif suurin <= int(luku):
        suurin = int(luku)
    luku = input("Anna luku: ")

print("Pienin luku: " + str(pienin))
print("Suurin luku: " + str(suurin))