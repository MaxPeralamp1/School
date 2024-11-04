import random
class Auto:

    def __init__(self, rekisteritunnus, huippunopeus):
        self.rekisteritunnus = rekisteritunnus
        self.huippunopeus = huippunopeus
        self.nopeus = 0
        self.kuljettumatka = 0

    def kiihdytä(self, muutos):
        self.nopeus += muutos
        if self.nopeus > self.huippunopeus:
            self.nopeus = self.huippunopeus
        elif self.nopeus < 0:
            self.nopeus = 0

    def kulje(self, tuntimäärä):
        self.kuljettumatka += self.nopeus * tuntimäärä




kilpailijat = []
for i in range(1, 11):
    rekisteritunnus = "ABC-" + str(i)
    huippunopeus = random.randint(100, 200)
    kilpailija = Auto(rekisteritunnus, huippunopeus)
    kilpailijat.append(kilpailija)

while True:
    for auto in kilpailijat:
        nopeuden_muutos = random.randint(-10, 15)
        auto.kiihdytä(nopeuden_muutos)

        auto.kulje(1)
        if auto.kuljettumatka >= 10000:
            break
    else:
        continue
    break

for auto in kilpailijat:
    print("Kilpailija: " + auto.rekisteritunnus, auto.huippunopeus, auto.kuljettumatka, auto.nopeus)






