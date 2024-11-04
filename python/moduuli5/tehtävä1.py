import random


lukumäärä = int(input("Kuinka monta arpakuutiota: "))
i = 0
summa = 0

for i in range(lukumäärä):
    luku = random.randint(1, 6)
    summa = summa + luku



print(summa)