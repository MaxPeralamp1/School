import random
from random import randint

luku = random.randint(1, 10)
arvaus = int(input("Arvaa luku väliltä 1-10: "))
arvaukset = 1
while arvaus != luku:
    if arvaus == luku:
        print("Oikein!")
    elif arvaus < luku:
        print("Suurempi")
    elif arvaus > luku:
        print("Pienempi")
    arvaus = int(input("Arvaa luku väliltä 1-10: "))
    arvaukset = arvaukset + 1
print("Oikein")
print(arvaukset)