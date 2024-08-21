import random
def noppa(tahkot):
    luku = random.randint(1,tahkot)
    return luku

tahkot = int(input("Montako tahkoa nopassa on: "))


while True:
    luku = noppa(tahkot)
    print(luku)
    if luku == tahkot:
        break
